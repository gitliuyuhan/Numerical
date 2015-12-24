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

//改进的欧拉法
void Euler(double x0,double y0,double h)
{
    double     yp,yc,xk=x0,yk=y0;
    int        i = 0;

    printf("求解结果\n");
    printf("y[%.2f] = %.6f\n",x0,y0);
    for(i=1;i<=N;i++)
    {
        yp = yk + h*f(xk,yk);
        xk = xk + h; //x(k+1)
        yc = yk + h*f(xk,yp);
        yk = (yp+yc)/2.0;
        printf("y[%.2f] = %.6f\n",xk,yk);
    }
}

int main()
{
    //已知
    double x0 = 0,y0 = 0;
    //步长
    double h = 0.05;
    Euler(x0,y0,h);    
    return 0;
}
