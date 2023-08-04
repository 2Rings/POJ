//Online Judge
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef class
{
    public:
        int l;
        int r;
        int c;
        int min;
}Loc;

bool Maze[40][40][40];
int ShortTime;
Loc S,E;

bool Dungeon_BFS(int i,int j, int k)
{
    bool Visited[40][40][40]={false};
    Loc queue[64000];
    int head,tail;
    queue[head=0].l=i;
    queue[tail=0].r=j;
    queue[tail].c=k;
    queue[tail++].min=0;
    Visited[i][j][k]=true;

    while(head<tail)
    {
        Loc x=queue[head++];
        if(x.l==E.l&&x.r==E.r&&x.c==E.c)
        {
            ShortTime=x.min;
            return true;
        }

        if(Maze[x.l][x.r-1][x.c]&&!Visited[x.l][x.r-1][x.c])
        {
            queue[tail].l=x.l;
            queue[tail].r=x.r-1;
            queue[tail].c=x.c;
            queue[tail++].min=x.min+1;
            Visited[x.l][x.r-1][x.c]=true;
        }
        if(Maze[x.l][x.r][x.c-1]&&!Visited[x.l][x.r][x.c-1])
        {
            queue[tail].l=x.l;
            queue[tail].r=x.r;
            queue[tail].c=x.c-1;
            queue[tail++].min=x.min+1;
            Visited[x.l][x.r][x.c-1]=true;
        }
        if(Maze[x.l][x.r+1][x.c]&&!Visited[x.l][x.r+1][x.c])
        {
            queue[tail].l=x.l;
            queue[tail].r=x.r+1;
            queue[tail].c=x.c;
            queue[tail++].min=x.min+1;
            Visited[x.l][x.r+1][x.c]=true;
        }
        if(Maze[x.l][x.r][x.c+1]&&!Visited[x.l][x.r][x.c+1])
        {
            queue[tail].l=x.l;
            queue[tail].r=x.r;
            queue[tail].c=x.c+1;
            queue[tail++].min=x.min+1;
            Visited[x.l][x.r][x.c+1]=true;
        }
        if(Maze[x.l-1][x.r][x.c]&&!Visited[x.l-1][x.r][x.c])
        {
            queue[tail].l=x.l-1;
            queue[tail].r=x.r;
            queue[tail].c=x.c;
            queue[tail++].min=x.min+1;
            Visited[x.l-1][x.r][x.c]=true;
        }
        if(Maze[x.l+1][x.r][x.c]&&!Visited[x.l+1][x.r][x.c])
        {
            queue[tail].l=x.l+1;
            queue[tail].r=x.r;
            queue[tail].c=x.c;
            queue[tail++].min=x.min+1;
            Visited[x.l+1][x.r][x.c]=true;
        }
    }
    return false;
}

int main()
{
    int L,R,C;
    cin>>L>>R>>C;
    memset(Maze,false,sizeof(Maze));

    for(int i=1;i<=L;i++)
        for(int j=1;j<=R;j++)
            for(int k=1;k<=C;k++)
            {
                char tmp;
                cin>>tmp;
                if(tmp=='S')
                {
                    S.l=i;S.r=j;S.c=k;S.min=0;
                    Maze[i][j][k]=true;
                }
                if(tmp=='.')
                    Maze[i][j][k]=true;
                if(tmp=='E')
                {
                    E.l=i;E.r=j;E.c=k;E.min=0;
                    Maze[i][j][k]=true;                    
                }
            }
    if(Dungeon_BFS(S.l,S.r,S.c))
        cout<<"Escaped in "<<ShortTime<<" minute(s)."<<endl;
    else 
        cout<<"Trapped"<<endl;
    system("pause");
    return 0;
}
