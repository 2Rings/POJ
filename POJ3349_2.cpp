#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//use key to distinguish different snowflakes
using namespace std;

const __int64 prime=999983;

class
{
    public:
        __int64 len[6];
}leaf[100001];

typedef class HashTable
{
    public:
        __int64 len[6];
        HashTable* next;

        HashTable()
        {
            next=0;
        }
}HashTable;

HashTable* hash[prime+1];

__int64 compute_key(int k)
{
    __int64 key=0;
    for(int i=0;i<6;i++)
    {
        key+=(leaf[k].len[i])%prime;
        key%=prime;
    }
    return ++key;
}

bool clockwise(HashTable* p, int k)
{
    for(int j=0;j<6;j++)
    {
        bool flag=true;
        for(int i=0;i<6;i++)
        {
            if(leaf[k].len[i]!=p->len[(i+j)%6])
            {
                flag=false;
                break;//inner round unmatched
            }
        }
        if(flag)
            return true;//out-round matched
    }
    return false;//no matched under clockwise
}

bool counterclockwise(HashTable* p, int k)
{
    for(int j=0;j<6;j++)
    {
        bool flag=true;
        for(int i=0;i<6;i++)
        {
            if(leaf[k].len[i]!=p->len[(5-i-j+6)%6])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            return true;
    }
    return false;
}

bool insert(int k)
{
    __int64 key=compute_key(k);

    if(!hash[key])
    {
        HashTable* tmp =new HashTable;

        for(int i=0;i<6;i++)
            tmp->len[i]=leaf[k].len[i];
        
        hash[key]=tmp;
    }
    else
    {
        HashTable* tmp=hash[key];

        if(clockwise(tmp,k)||counterclockwise(tmp,k))
            return true;
        
        while(tmp->next)
        {
            tmp=tmp->next;
            if(clockwise(tmp,k)||counterclockwise(tmp,k))
                return true;
        }

        tmp->next=new HashTable;
        for(int i=0;i<6;i++)
            tmp->next->len[i]=leaf[k].len[i];
    }
    return false;
}

int main()
{
    int n;
    while(cin>>n)
    {
        memset(hash,0,sizeof(hash));

        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<6;j++)
                scanf("%I64d",&leaf[i].len[j]);
            
            if(!flag)
                flag=insert(i);
        }

        if(flag)
            cout<<"Twin snowflakes found."<<endl;
        else  
            cout<<"No two snowflakes are alike."<<endl;
    }
    return 0;
}
