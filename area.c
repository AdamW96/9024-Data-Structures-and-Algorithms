// Monte Carlo estimation for areas ... COMP9024 20T2
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define XMIN -1.5
#define XMAX 1.5
#define YMIN -1.5
#define YMAX 1.5
#define NSTEPS 100000000

// unit circle
bool inside(double x, double y) {
    return (sqrt(x*x+y*y) <= 1.0);
}

int main(void) {
    srand(time(NULL));

    int steps;
    for (steps = 1; steps <= NSTEPS; steps *= 10) {
        int count = 0;
        int i;
        for (i = 0; i < steps; i++) {
            // generate random numbers between 0.0 and 1.0
            double r1 = (double) rand()/RAND_MAX;
            double r2 = (double) rand()/RAND_MAX;

            double x = XMIN + r1 * (XMAX-XMIN);
            double y = YMIN + r2 * (YMAX-YMIN);

            count += inside(x,y);
        }
        printf("steps = %9d, count = %8d, area = %.6f\n",
               steps, count, (double)count/steps*(XMAX-XMIN)*(YMAX-YMIN));
    }
    return 0;
}