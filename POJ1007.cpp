#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;


int n;

typedef class
{
    public:
        int num;
        char DNAsq[110];
}DNAstr;

int unsorted(char* DNAsq)
{
    int dif=0;
    int j=0;
    while(j<n)
    {
        
        if(DNAsq[j]=='A')
            j++;
        else 
        {
            for(int k=j+1;k<n;k++)
            {
                if(DNAsq[j]>DNAsq[k])
                {
                    cout<<DNAsq[j]<<'>'<<DNAsq[k]<<endl;
                    dif++;
                }
            }          
            j++;
        }
    }
    return dif;
}

int cmp(const void* a, const void* b)
{
    DNAstr* x=(DNAstr*) a;
    DNAstr* y=(DNAstr*) b;
    return (x->num)-(y->num);
}
int main()
{
    int m;
    cin>>n>>m;
    DNAstr* DNA= new DNAstr[m+1];
    for(int i=0;i<m;i++)
    {
        cin>>DNA[i].DNAsq;
        DNA[i].num=unsorted(DNA[i].DNAsq);
    }
    qsort(DNA,m,sizeof(DNAstr),cmp);
    for(int i=0;i<m;i++)
    {
        cout<<DNA[i].DNAsq<<endl;
        cout<<DNA[i].num<<endl;
    }
        
    system("pause");
    return 0;
}