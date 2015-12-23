/*======================================================
    > File Name: SOR.c
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2015年12月24日 星期四 00时10分45秒
 =======================================================*/

#include<stdio.h>
#include<math.h>

#define   N   20

void Sor(double a[N][N],double b[],double x[],double w,double wuch)
{
    double t[N];
    int    flag = 0;
    int    n = 0;
    int    i,j;
    while(!flag)
    {
        flag = 1;
        n++;
        for(i = 0;i<N;i++)
            t[i] = x[i];
        for(i=0;i<N;i++)
        {
            double m = b[i];
            for(j=0;j<N;j++)
            {
                m = m - a[i][j]*x[j];
            }
            x[i] = x[i] + w*m/a[i][i];
        }
        int   k;
        for(k=0;k<N;k++)
        {
            if(fabs(x[k]-t[k]) >= wuch)
            {
                flag = 0;
                break;
            }
        }
    }
    printf("迭代次数 %d\n",n);
}

int main()
{
    double   a[N][N]={0};
    double   b[N] = {1};
    double   x[N] = {0}; //解
    double   w = 0.6,wuch = 0.0001;//松弛因子，误差
    int      i,j;
    //填充系数矩阵
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i == j)
                a[i][j] = 2;
            if(fabs(i-j) == 1)
                a[i][j] = 0.5;
            if(fabs(i-j) == 2)
                a[i][j] = 0.25;
        }
        b[i] = 1;
    }
    printf("线性方程组\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%.2f ",a[i][j]);
        printf("| %f\n",b[i]);
    }
    Sor(a,b,x,w,wuch);
    printf("方程解\n");
    for(i=0;i<N;i++)
        printf("%2.6f\n",x[i]);   
    return 0;
}
