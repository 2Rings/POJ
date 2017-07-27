#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

//const int MaxSize=100001;
//template <class int>
typedef class
{
    public:
        int len[6];
        int next;
}snowflake;

bool flakecmp(snowflake* a,snowflake* b)
{
    int k=0;
    for(int i=0;i<6;i++)
    {

    }
}

int main()
{
    int n;
    cin>>n;
    snowflake* flake=new snowflake[n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            cin>>flake[i].len[j];
        }
        
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=5;j++)
        {
            cout<<flake[i].len[j]<<' ';
        }
        cout<<endl;
        
    }
    system("pause");
    return 0;
}