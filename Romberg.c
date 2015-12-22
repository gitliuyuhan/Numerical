/*======================================================
    > File Name: Romberg.c
    > Author: lyh
    > E-mail:  
    > Other : 编译加 -lm  
    > Created Time: 2015年12月22日 星期二 17时28分58秒
 =======================================================*/

#include<stdio.h>
#include<math.h>

#define N 20

//被积函数 (sinx)/x
double f(double x)
{
    return sin(x)/x;
}

double Romberg(double a,double b,double wuch)
{
    //区间长度
    double h = b-a;
    int i,j,k,m,n;
    //保存计算过程
    double T[N][N];
    double s;

    T[0][0] = h*(f(a)+f(b))/2.0;
    for(k = 1;k<N;k++)
    {
        h = (b-a)*pow(0.5,k);
        n = (int)pow(2,k-1);
        s = 0.0;
        for(m=1;m<=n;m++)
        {
            s += f(a + (2*m-1)*h);
        }
        T[k][0] = 0.5*T[k-1][0] + h*s;
    }
    for(k=1;k<N;k++)
    {
        for(m=1;m<=k;m++)
        {
            T[k][m] = pow(4,m)/(pow(4,m)-1)*T[k][m-1]-1/(pow(4,m)-1)*T[k-1][m-1];
        }
        if(fabs(T[k][k]-T[k-1][k-1]) < wuch)
            break;
    }
    //输出计算过程
    printf("计算过程：\n");
//    printf("R=%.6f\n",T[k][k]);
    printf("k=%d\n",k);
    printf("T:\n");
    for(i=0;i<=k;i++)
    {
        for(j=0;j<=i;j++)
            printf("%.6f  ",T[i][j]);
        printf("\n");
    }
    return T[k][k];
}

int main()
{
    double a,b,wuch;
    printf("输入积分下限a：");
    scanf("%lf",&a);
    printf("输入积分上限b：");
    scanf("%lf",&b);
    printf("输入计算误差：");
    scanf("%lf",&wuch);
    printf("最终结果：%.6f\n",Romberg(a,b,wuch));
    return 0;
}

