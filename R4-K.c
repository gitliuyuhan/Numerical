/*======================================================
    > File Name: Euler.c
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2015年12月24日 星期四 09时29分00秒
 =======================================================*/

#include<stdio.h>
#define   N   20    //次数

double f(double x,double y)
{
    return 1-(2*x*y)/(1+x*x);
}

//R-K 四阶-龙格库塔
void RK4(double x0,double y0,double h)
{
    double     xk=x0,yk=y0;
    double     k1,k2,k3,k4;
    int        i = 0;

    printf("求解结果\n");
    printf("y[%.2f] = %.6f\n",x0,y0);
    for(i=1;i<=N;i++)
    {
        k1 = f(xk,yk);
        k2 = f(xk+h/2,yk+h*k1/2);
        k3 = f(xk+h/2,yk+h*k2/2);
        k4 = f(xk+h,yk+h*k3);
        yk = yk + h*(k1 + 2*k2 + 2*k3 + k4)/6; //y(k+1)
        xk = xk + h;
        printf("y[%.2f] = %.6f\n",xk,yk);
    }
}

int main()
{
    //已知
    double x0 = 0,y0 = 0;
    //步长
    double h = 0.05;
    RK4(x0,y0,h);    
    return 0;
}
