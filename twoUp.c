#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RUNS 125
#define BET  10

int main(void) {
    srand(time(NULL));

    int coin1, coin2, n, sum = 0;
    for (n = 0; n < RUNS; n++) {

        do {
            coin1 = rand() % 2;
            coin2 = rand() % 2;
        } while (coin1 != coin2);

        if (coin1==1 && coin2==1)
            sum += BET;
        else
            sum -= BET;
    }

    printf("Final result: %d\n", sum);
    printf("Average outcome: %.3f\n", (float) sum / RUNS);
    return 0;
}