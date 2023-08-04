//Online Judge
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef class HASH
{
    public:
        class HASH* next;
        int X,Y;
        HASH()
        {
            next=0;
        }
}HashTable;

class Node
{
    public:
        int x;
        int y;
};

Node point[1001];

int prime=1999;
HashTable* hash[20000];

void Hash_insert(int k)
{  
    int key=(point[k].x*point[k].x)+(point[k].y*point[k].y)%prime+1;
    if(!hash[key])
    {
        HashTable* tmp=new HashTable;
        tmp->X=point[k].x;  
        tmp->Y=point[k].y;
        hash[key]=tmp;
    }
    else
    {
        HashTable* tmp=hash[key];
        while(tmp->next)
            tmp=tmp->next;
        tmp->next= new HashTable ;  
        tmp->next->X=point[k].x;  
        tmp->next->Y=point[k].y;    
    }
    return;
}

bool find(int x,int y)
{
    int key=((x*x)+(y*y))%prime+1;

    if(!hash[key])
        return false;
    else
    {
        HashTable* tmp=hash[key];
        while(tmp)
        {
            if(tmp->X==x&&tmp->Y==y)
                return true;
            tmp=tmp->next;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    memset(hash,0,sizeof(hash));
    for(int i=0;i<n;i++)
    {
        cin>>point[i].x>>point[i].y;
        Hash_insert(i);    
    }
    int num=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int a=point[j].x-point[i].x;
            int b=point[j].y-point[i].y;

            int x3=point[i].x+b;
            int y3=point[i].y-a;
            int x4=point[j].x+b;
            int y4=point[j].y-a;
            if(find(x3,y3)&&find(x4,y4))
                num++;

            x3=point[i].x-b;
            y3=point[i].y+a;
            x4=point[j].x-b;
            y4=point[j].y+a;
            if(find(x3,y3)&&find(x4,y4))
                num++;
        }
    }
    cout<<num/4<<endl;
    system("pause");
    return 0;

}
