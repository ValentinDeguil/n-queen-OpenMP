#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

//data to scale x/y coordinate
static const double x0min = -2.0;
static const double x0max = 0.47;
static const double y0min = -1.12;
static const double y0max = 1.12;

int main(int argc, char *argv[]) {
    const int width = atoi(argv[1]);
    const int height = atoi(argv[1]);
    const int maxIteration = atoi(argv[2]);
    const int numberOfPixel = width * height;

    //scaled x/y coordinate
    double pixelWidth = (x0max - x0min) / width;
    double pixelHeight = (y0max - y0min) / height;

    //creating pixel array
    typedef char aPixel[3];
    aPixel *pixels = malloc(sizeof(aPixel) * numberOfPixel);

    int nbThread = atoi(argv[3]);

    double start, end;
    start = omp_get_wtime();

    #pragma omp parallel shared(pixels) num_threads (nbThread)
    {

    int currentY;

    #pragma omp for schedule (static)
    for (currentY = 0; currentY < height; currentY++) {
        double yInFrame = y0min + currentY * pixelHeight;

        int currentX, iteration;

        for (currentX = 0; currentX < width; currentX++) {

            double xInFrame = x0min + currentX * pixelWidth;
            //printf("pixelWidth : %d\n", currentX);
            double x = 0;
            double y = 0;

            for (iteration = 0; (x * x + y * y < 2 * 2) && iteration < maxIteration; iteration++) {
                //printf("iteration : %d\n", iteration);
                double xtemp = x * x - y * y + xInFrame;
                y = 2 * x * y + yInFrame;
                x = xtemp;
            }

            if (iteration == maxIteration) { //pixel has to be black
                pixels[currentY * width + currentX][0] = 0;
                pixels[currentY * width + currentX][1] = 0;
                pixels[currentY * width + currentX][2] = 0;
            } else { //pixel has to be white
                pixels[currentY * width + currentX][0] = 255;
                pixels[currentY * width + currentX][1] = 255;
                pixels[currentY * width + currentX][2] = 255;
            }
        }

    }

    }

    end = omp_get_wtime();
    FILE *fp;
    fp = fopen("res", "a");
    fprintf(fp,"STATIC : taille : %d, nbThreads : %d, time : %f\n",width, nbThread, end-start);
    fclose(fp);
    printf("STATIC : taille : %d, nbThreads : %d, time : %f\n",width, nbThread, end-start);
    free(pixels);
    return 0;
}