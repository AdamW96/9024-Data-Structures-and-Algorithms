//
// Created by WZZ on 2020/8/3.
//
#include "math.h"
#include "stdio.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double function(double x){
    return 3*x*x*x-5*x*x+3*x-5;
}

double functionsin(double x){
    return sin(x);
}

double functionsincos(double x){
    double result=sin(10*x)+cos(5*x)+pow(x,2.0)/10;
    return result;
}

double bisection(double x1,double x2,double (* f)(double)){
    double mid=1;
    while(f(mid)!=0 && x2-x1>=pow(10.0,-10.0)){
        mid=(x1+x2)/2;
        if (f(x1)*f(mid)<0){
            x2=mid;
        }else{
            x1=mid;
        }
    }
    return mid;
}
int main(){
    printf("%.20f\n",bisection(0.0,10.0,function));
    printf("%.10f\n",bisection(-4.0,-2.0,functionsin));
    printf("%.10f\n",bisection(0.0,1.0,functionsincos));
    printf("%.10f\n",bisection(1.0,2.0,functionsincos));


}