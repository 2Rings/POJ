//Online Judge
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int X[101];
int a1,a2,a3,a4,a5;
typedef class HASH
{
    public:
        class HASH* next;
        int pi;
}HashTable;

int prime=999983;
int hash[25000000];

void Hash(int i,int j)
{
    __int64 key=0;
    key=(a1*X[i]+a2*X[j])*(-1);
    if(key<0)
        key+=25000000;
    hash[key]++;
}

int main()
{
    
    cin>>a1>>a2>>a3>>a4>>a5;
    memset(hash,0,sizeof(hash));
    for(int i=0;i<50;i++)
    {
        int tmp=i-50;
        X[i]=tmp*tmp*tmp;//attention: i=50 => x[50]=0;
    }
    for(int i=50;i<100;i++)
    {
        int tmp=i-50+1;
        X[i]=tmp*tmp*tmp;//attention: i=50 => x[50]=0;
    }
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            Hash(i,j);
    int solution=0;
    for(int x3=0;x3<100;x3++)
        for(int x4=0;x4<100;x4++)
            for(int x5=0;x5<100;x5++)
            {
                int sum=a3*X[x3]+a4*X[x4]+a5*X[x5];
                if(sum<0)
                    sum+=25000000;
                if(hash[sum])
                    solution+=hash[sum];
            }
    cout<<solution<<endl;

    system("pause");
    return 0;
    
}
