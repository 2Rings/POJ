#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int N,K,gap;
int mod=99991;
int sum[100001][30];
int features[100001][30];
int c[100001][30];


typedef class HASH
{
    public:
        int ptr;
        class HASH* next;
        HASH()
        {
            next=0;
        }
}HashTable;

HashTable* hash[100001];

bool cmp(int a, int b)
{
    for(int i=0;i<K;i++)
    {
        if(c[a][i]!=c[b][i])
            return false;
    }
    return true;
}

void Hash(int k)
{
    int key=0;
    for(int i=0;i<K;i++)
    {
        key+=c[k][i]*i;
    }
    key=abs(key)%mod;

    if(!hash[key])//new key
    {
        HashTable* tmp= new HashTable;
        tmp->ptr=k;
        hash[key]=tmp;
    }
    else //conflict
    {
        HashTable* tmp=hash[key];
        if(cmp(tmp->ptr,k))
        {
            int dist=k-(tmp->ptr);
            if(gap<dist)
                gap=dist;
            return;
        }
        else
        {
            while(tmp->next)
            {
                if(cmp(tmp->next->ptr,k))
                {
                    int dist=k-(tmp->next->ptr);
                    if(gap<dist)
                        gap=dist;
                    return;
                }
                tmp=tmp->next;
            }

            HashTable* temp=new HashTable;
            temp->ptr=k;
            tmp->next=temp;

        }
    }
    return;
}


int main()
{
    cin>>N>>K;
    int id;
    for(int p=0;p<K;p++)
    {
        sum[0][p]=0;
        c[0][p]=0;
    }

    memset(hash,0,sizeof(hash));
    gap=0;
    Hash(0);
    for(int i=1;i<=N;i++)
    {
        cin>>id;
        
        for(int j=0;j<K;j++)
        {
            features[i][j]=id%2;//逆序二进制
            id/=2;
            sum[i][j]=sum[i-1][j]+features[i][j];
            c[i][j]=sum[i][j]-sum[i][0];
        }
            
        
        Hash(i);
    }
    
    cout<<gap<<endl;
    system("pause");
    return 0;
}