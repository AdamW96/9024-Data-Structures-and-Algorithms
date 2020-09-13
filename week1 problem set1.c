//
// Created by WZZ on 2020/6/4.
//
#include <stdio.h>
#include <stdlib.h>

/* Puzzle L13 -- print integers from 1 to n that are not multiples of 3 or 5
|  Print 10 integers per line.
|  End the last line with "\n", even if the line has fewer than
|  ten numbers on it.
|
*/
int main(){
    int a,b,c,d,e;
    int left,right;
    for(int i=1;i<=2;i++){
        a=i;
        for(int j=0;j<=5;j++){
            b=j;
            for(int k=0;k<=9;k++){
                c=k;
                for(int l=0;l<=9;l++){
                    d=l;
                    for(int n=1;n<=9;n++){
                        if(n==3||n==8){
                            e=n;
                            left=a*10000+b*1000+c*100+d*10+e;
                            right=e*10000+d*1000+c*100+b*10+a;
                            if(left*4==right){
                                printf("the number is %d\n",left);
                            }
                        }
                    }
                }
            }
        }

    }


}
