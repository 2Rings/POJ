#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef class
{
    public:
        int prime;
        int cost;
}Primes;

bool Visit[10000];
Primes queue[10000];

bool Judge_Prime(int digits)
{
    if(digits==2||digits==3)
        return true;
    else if(digits<=1||digits%2==0)
        return false;
    else if(digits>3)
    {
        for(int i=3;i*i<=digits;i+=2)
        {
            if(digits%i==0)
                return false; 
        }
        return true;
    }
}

int a,b;

void Prime_BFS()
{
    int i, head, tail;
    queue[head=tail=0].prime=a;
    queue[tail++].cost=0;
    Visit[a]=true;

    while(head<tail)
    {
        Primes x=queue[head++];
        if(x.prime==b)
        {
            cout<<x.cost<<endl;
            return;
        }

        int unit=x.prime%10;
        int deca=(x.prime/10)%10;

        for(i=1;i<=9;i+=2)
        {
            int y=(x.prime/10)*10+i;
            if(!Visit[y]&&Judge_Prime(y)&&y!=x.prime)
            {
                Visit[y]=true;
                queue[tail].prime=y;
                queue[tail++].cost=x.cost+1;
            }
        }

        for(i=0;i<=9;i++)
        {
            int y=(x.prime/100)*100+i*10+unit;
            if(!Visit[y]&&Judge_Prime(y)&&y!=x.prime)
            {
                Visit[y]=true;
                queue[tail].prime=y;
                queue[tail++].cost=x.cost+1;
            }
        }

        for(i=0;i<=9;i++)
        {
            int y=(x.prime/1000)*1000+i*100+deca*10+unit;
            if(!Visit[y]&&Judge_Prime(y)&&y!=x.prime)
            {
                Visit[y]=true;
                queue[tail].prime=y;
                queue[tail++].cost=x.cost+1;
            }
        }
        
        for(i=1;i<=9;i++)
        {
            int y=x.prime%1000+i*1000;
            if(!Visit[y]&&Judge_Prime(y)&&y!=x.prime)
            {
                Visit[y]=true;
                queue[tail].prime=y;
                queue[tail++].cost=x.cost+1;
            }
        }

    }
    cout<<"impossible"<<endl;
    return;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>a>>b;
        memset(Visit,false,sizeof(Visit));
        Prime_BFS();
    }
    system("pause");
    return 0;
}