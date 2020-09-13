#include "stdio.h"
#include "stdlib.h"

int main(int argc,char *argv[]){
    if( argc!=3){
        return 0;
    }
    else{
    int length= atoi(argv[1]);
    int seed = atoi(argv[2]);
    srand(seed);
    for (int i =0; i<length;i++){
        int loss= rand()%26;
        char c= 'a'+loss;
        printf("%c", c);
    }}
}
