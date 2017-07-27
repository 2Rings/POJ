#include<iostream>
#include<stdlib.h>
#include<stdio.h>
//归并排序可以求逆序数。《线代》的知识

using namespace std;

const int inf=1000000000;
__int64 v=0;
//用merge来计算
void merge(int r[], int r1[], int s, int m, int t)
{
    int i=s; int j=m+1; int k=s;

    while(i<=m&&j<=t)
    {
        if(r[i]<=r[j])
            r1[k++]=r[i++];
        else 
        {
            v+=m-i+1;
            r1[k++]=r[j++];
        }
    }
        if(i<=m)
            while(i<=m)
                r1[k++]=r[i++];
        else
            while(j<=t)
                r1[k++]=r[j++];          

    return;     
}

void mergePass(int r[], int r1[], int n, int h)
{
    int i=1;
    while(i<=n-2*h+1)//length_unsorted is larger than 2h
    {
        merge(r, r1, i, i+h-1, i+2*h-1);
        i+=2*h;
    }
    if(i<n-h+1)
        merge(r,r1,i,i+h-1,n);
    else   
        for(int k=i;k<=n;k++)
            r1[k]=r[k];
    return;
}

void mergesort(int r[], int r1[], int n)
{
    int h=1;
    while(h<n)
    {
        mergePass(r,r1,n,h);
        h=2*h;
        mergePass(r1,r,n,h);
        h=2*h;
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(!n)
            break;
        int* r= new int[n+1];
        int* r1= new int[n+1];
        for(int i=1;i<=n;i++)
            cin>>r[i];
        for(int i=1;i<=n;i++)
            cout<<r[i];
        
        v=0;
        cout<<endl;
        mergesort(r,r1,n);

        printf("%I64d\n",v);
        for(int i=1;i<=n;i++)
            cout<<r[i]<<endl;
        delete r;
        delete r1;
    }
    system("pause");
    return 0;
}