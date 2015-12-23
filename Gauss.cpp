/*======================================================
    > File Name: Gauss.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2015年12月23日 星期三 23时05分54秒
 =======================================================*/

#include<iostream>
#include<stdio.h>

using namespace std;

#define   N   4  //个数
double a[N+1][N+1] = {0,0,0,0,0,
                   0,1,0.333,1.5,-0.333,
                   0,-2.01,1.45,0.5,2.95,
                   0,4.32,-1.95,0,2.08,
                   0,5.11,-4,3.33,-1.11};
double x[N+1];
double b[N+1] = {0,3,5.4,0.13,3.77};
int n = N;//n方程个数，n未知数个数
/*
int set( )
{
	cout<<"请输入方程的个数和未知数个数： "<<endl;
	cin>>n;
	int i,j;
	cout<<"请输入方程组（逐个输入方程 i）"<<endl;
	for(i = 1;i <= n;i++)
	{
        cout<<"第"<<i<<"行"<<endl;
		for(j = 1;j<=n;j++)
		{
			cin>>a[i][j];//系数
		}
        cout<<"结果"<<endl;
		cin>>b[i];//结果
	}
	return 0;
}
*/
int find(int k)//寻找第k列主元
{
	int i,tag = k;
	double maxv=0;
	for(i = k;i <= n;i++)
	{
		if(a[i][k] > maxv)
		{
			maxv = a[i][k];
			tag = i;
		}
	}
	return tag;
}
void exchange(int i1,int i2)//将第 i1 i2行互换
{
	int j;
	for(j = 1;j <= n;j++)
	{
		swap(a[i1][j],a[i2][j]);
	}
	swap(b[i1],b[i2]);
}
void div(int k)//让第k个方程的首项系数为1
{
	double temp = a[k][k];
	for(int j = k; j <= n;j++)
	{
		a[k][j]/=temp;
	}
	b[k]/=temp;
}
/*
void disME(int k)
{
	int i,j;
	for(i =1 ;i<=n;i++)
	{
		for(j = i;j<= n;j++)
		{
			if(a[i][j])
			{
				if(a[i][j]==1)
 				{	if(j==n)
			           cout<<"x"<<j;
					else
					   cout<<"x"<<j<<" + ";
				}
				else
				{
					if(j==n)
			           cout<<a[i][j]<<"x"<<j;
					else
					   cout<<a[i][j]<<"x"<<j<<" + ";
 	 		    }
			}
		}
//		cout<<" = "<<b[i]<<endl;
	}
}
*/
void eliminate(int k)//消元
{
	int i,j;
	double t;
	for(i = k+1;i<= n;i++)
	{
		t = a[i][k]/a[k][k];
		for(j = k;j <= n;j++)
		{
			a[i][j]-=a[k][j] * t;
		}
		b[i] -= b[k] * t;
	}
}
void Gauss()//高斯消元法
{
	int i,j,k;
	for(k = 1;k < n;k++)//共进行n - 1次消元
	{
		int l = find(k);//寻找第k次消元法的主元方程
	    if(l!=k)
		{
			exchange(l,k);
		}
		//消元
		div(k);
		eliminate(k);
		//cout<<"第"<<k<<"次消元结果："<<endl;
		//disME(k);
	}
	div(k);
	x[k] = b[k];
	//disM();
	for(i = n - 1;i>=1;i--)
	{
		for(j = i+1;j <=n ;j++)
		{
			 b[i] -= a[i][j] * b [j]; 
		}
		x[i] = b[i];
	}
}
void show()
{
	int i;
	cout<<"解方程得："<<endl;
	for(i = 1;i<=n;i++)
	{
		cout<<"x"<<i<<"  =  ";
		printf("%.6f\n",x[i]);
	}
}
int main()
{
    int   i,j;
    cout<<"线性方程组"<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=N;j++)
            cout<<a[i][j]<<"  ";
        cout<<"    |    "<<b[i]<<endl;
    }
    
	Gauss();
	show();
	return 0;
}
