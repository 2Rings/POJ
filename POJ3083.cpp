#include<iostream>
#include<stdlib.h>

using namespace std;

int i,j,d;
int x,y;
int Left_Step=1,Right_Step=1,Shortest_Step=1;

typedef class
{
    public:
    char mark;
    int row,col;
    int depth;
}Location;

void path(int i,int j, int d)
{
    switch(d)
    {
        case 0: {x=i-1;y=j;break;}
        case 1: {x=i;y=j-1;break;}
        case 2: {x=i+1;y=j;break;}
        case 3: {x=i;y=j+1;break;}
    }
}

bool Left_DFS(Location** Maze, int i, int j, int d)//左转优先深搜
{
    path(i,j,d);
    while(Maze[x][y].mark=='#')
    {
        d=(d-1)%4;
        path(i,j,d);
    }  
    i=x;
    j=y;
    Left_Step++;
    if(Maze[x][y].mark=='E')
        return true;
    Left_DFS(Maze,i,j,(d+1)%4);
}

bool Right_DFS(Location** Maze, int i, int j, int d)//右转优先深搜
{
    path(i,j,d);
    while(Maze[x][y].mark=='#')
    {
        d=(d+1)%4;
        path(i,j,d);
    }   
    i=x;
    j=y;
    Right_Step++;
    if(Maze[x][y].mark=='E')
        return true;
    Right_DFS(Maze,i,j,(d+1)%4);
}
/*
bool Shortest_BFS(Location* Maze, int i, int j)//宽搜找最短路径
{

}
*/
int main()
{
    int test;
    int w,h;
    int ii,jj;
    cin>>test;
    int t=1;
    while(t<=test)
    {
        cin>>w>>h;
        Location** Maze = new Location*[h];
        for(int k=0;k<h;k++)
            Maze[k] = new Location[w];
        for(int m=0;m<h;m++)
        {
            for(int n=0;n<w;n++)
            {
                cin>>Maze[m][n].mark;
                if(Maze[m][n].mark=='S')
                {
                    ii=m;
                    jj=n;
                }  
            }    
        } 
        int dd;
        if(ii==0)    
            dd=3;
        if(ii==h-1)
            dd=0;
        if(jj=00)
            dd=2;
        if(jj==w-1)
            dd=1;
        Left_DFS(Maze,ii,jj,dd);
        Right_DFS(Maze,ii,jj,dd);
        //Shortest_BFS(Maze,ii,jj);
        cout<<Left_Step<<' '<<Right_Step<<' '<<Shortest_Step;           
    }
    system("pause");
    return 0;
}