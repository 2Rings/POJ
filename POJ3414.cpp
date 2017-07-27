#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;
typedef class
{
    public:
        int A;
        int B;
        int K;
        int father;
        int operation;
}pots;

int a,b,c;
pots Pour_A(int i, int j)//Pour(i,j)
{
    //a,b
    pots P;
    if(i+j>b)
    {
        int tmp;
        tmp=b-j;
        i=i-tmp;
        j=b;
    }
    else if(i+j<=b)
    {
        j=i+j;
        i=0;
    }
    P.A=i;
    P.B=j;
    P.K=P.father=P.operation=0;
    return P;
}

pots Pour_B(int j, int i)//Pour(j,i)
{
    //a,b
    pots P;
    if(i+j>a)
    {
        int tmp;
        tmp=a-i;
        j=j-tmp;
        i=a;
    }
    else if(i+j<=a)
    {
        i=i+j;
        j=0;
    }
    P.A=i;
    P.B=j;
    P.K=P.father=P.operation=0;
    return P;
}

pots queue[524286];
bool Vi[101][101];
int Op[10001];
void Pots_BFS(int a, int b,int c)
{
    int head,tail; 
    queue[head=0].A=0;
    queue[tail=0].B=0;
    queue[tail].father=queue[tail].operation=0;
    queue[tail++].K=0;
    Vi[0][0]=true;

    while(head<tail)
    {
        pots x=queue[head];
        if(x.A==c||x.B==c)
        {
            cout<<x.K<<endl;
            int i=1;
            int Fa=x.father;
            Op[i++]=x.operation;
            while(Fa)
            {
                Op[i++]=queue[Fa].operation;
                Fa=queue[Fa].father;
            }
            while(i)
            {
                if(Op[i]==110)
                    cout<<"DROP(1)"<<endl;
                else if(Op[i]==120)
                    cout<<"DROP(2)"<<endl;
                else if(Op[i]==210)
                    cout<<"FILL(1)"<<endl;
                else if(Op[i]==220)
                    cout<<"FILL(2)"<<endl;
                else if(Op[i]==312)
                    cout<<"POUR(1,2)"<<endl;
                else if(Op[i]==321)
                    cout<<"POUR(2,1)"<<endl;
                i--;
            }
            return;
        }

        if(!Vi[a][x.B])//FILL(x.A)
        {
            queue[tail].A=a;
            queue[tail].B=x.B;
            queue[tail].operation=210;//FILL(x.A)
            queue[tail].father=head;//记录x的下标
            queue[tail++].K=x.K+1;
        }
        
        if(!Vi[x.A][b])
        {
            queue[tail].A=x.A;
            queue[tail].B=b;
            queue[tail].operation=220;//FILL(x.B)
            queue[tail].father=head;//记录x的下标
            queue[tail++].K=x.K+1;
        }
        
        
        if(x.A!=0&&x.B!=b)
        {
            pots y=Pour_A(x.A,x.B);
            if(!Vi[y.A][y.B])
            {
                queue[tail]=y;
                queue[tail].operation=312;//Pour(x.A,x.B)
                queue[tail].father=head;//记录x的下标
                queue[tail++].K=x.K+1;
            }           
        }
       
        if(x.B!=0&&x.A!=a)
        {
            pots y=Pour_B(x.B,x.A);
            if(!Vi[y.A][y.B])
            {
                queue[tail]=y;
                queue[tail].operation=321;//Pour(x.B,x.A)
                queue[tail].father=head;//记录x的下标
                queue[tail++].K=x.K+1;
            } 
        }

        if(x.A!=0&&!Vi[0][x.B])//DropA
        {
            queue[tail].A=0;
            queue[tail].B=x.B;
            queue[tail].operation=110;//Drop(x.A)
            queue[tail].father=head;//记录x的下标
            queue[tail++].K=x.K+1;
        }
        if(x.B!=0&&!Vi[x.A][0])//DropB
        {
            queue[tail].A=x.A;
            queue[tail].B=0;
            queue[tail].operation=120;//Drop(x.B)
            queue[tail].father=head;//记录x的下标
            queue[tail++].K=x.K+1;
        }
        head++;
    }
    cout<<"impossible"<<endl;
    return;
            
}

int main()
{
    cin>>a>>b>>c;
    memset(Vi,false,sizeof(Vi));
    Pots_BFS(a,b,c);
    system("pause");
    return 0;
}