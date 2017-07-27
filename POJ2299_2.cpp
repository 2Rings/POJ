#include<iostream>
#include<stdlib.h>
#include<stdio.h>
//归并排序可以求逆序数。《线代》的知识

using namespace std;

const int inf=1000000000;
__int64 iv=0;
//用merge来计算
void merge(int* r, int s, int m, int t)
{
    int len_L=m-s+1;
    int len_R=t-m;
    int* left=new int[len_L+2];
    int* right=new int[len_R+2];
    int i,j;
    for(i=1;i<=len_L;i++)
        left[i]=r[s+i-1];
    left[len_L+1]=inf;

    for(j=1;j<=len_R;j++)
        right[j]=r[m+j];
    right[len_R+1]=inf;
    
    i=j=1;
    for(int k=s;k<=t;)
    {
        if(left[i]<=right[j])
            r[k++]=left[i++];
        else
        {
            r[k++]=right[j++];
            iv+=len_L-i+1;
        }
    }
    delete left;
    delete right;
    return;        
}

void mergesort(int* r, int s, int t)
{
    if(s<t)
    {
        int mid=(s+t)/2;
        mergesort(r,s,mid);
        mergesort(r,mid+1,t);
        merge(r,s,mid,t);
    }
    return;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(!n)
            break;
        int* r= new int[n+1];
        //int* r1= new int[n+1];
        for(int i=1;i<=n;i++)
            cin>>r[i];
        for(int i=1;i<=n;i++)
            cout<<r[i];
        
        
        iv=0;
        cout<<endl;
        mergesort(r,1,n);
        printf("%I64d\n",iv);
        for(int i=1;i<=n;i++)
           cout<<r[i]<<endl;
        
        delete r;
        //delete r1;
    }
    system("pause");
    return 0;
}