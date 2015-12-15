/*======================================================
    > File Name: newton.c
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2015年12月15日 星期二 17时29分34秒
 =======================================================*/

#include<stdio.h>

//计算多项式的系数
double ratio(double y[],double x[],int i,int j)
{
    if(i == j)
        return y[j];
    return (ratio(y,x,i+1,j) - ratio(y,x,i,j-1))/(x[j]-x[i]);
}

//计算牛顿插值多项式结果
double newton(double x[],double r[],double x_)
{
    double    sum = 0.0;
    double    mul = 1.0;
    int       i = 0;
    int       j = 0;

    for(i=0;i<4;i++)
    {
        mul = 1.0;
        for(j = 0;j<i;j++)
        {
            mul = mul * (x_ - x[j]);   
        }
        sum = sum + r[i] * mul;
    }
    return sum;
}

int main()
{
    double   x[4] = {0.0,0.523599,1.047198,1.570796};
    double   y[4] = {0.0,0.5,0.866025,1.0};
    //需要代入的数据
    double   t[] = {0.142800,0.428399,0.642598,0.856798,1.142397,1.427997,1.570796};
    //保存多项式系数
    double   r[4] = {0.0};

    int      i = 0;

    printf("系数：\n");
    for(i=0;i<4;i++)
    {
        r[i] = ratio(y,x,0,i);
        printf("r[%d] = %f\n",i,r[i]);
    }
    printf("结果：\n");
    for(i = 0;i<7;i++)
    {
        printf("P[%f] = %f\n",t[i],newton(x,r,t[i]));
    }
    return 0;
}

