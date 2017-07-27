#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef class
{
    public:
        int row;
        int col;
        int depth;
}Location;

int Left_Step, Right_Step;
Location S,E;

bool Maze[41][41];

void Left_DFS(int i, int j, int d)
{
    Left_Step++;
    if(i==E.row&&j==E.col)
        return;   
    switch(d)
    {
        case 0:
            {
                if(Maze[i][j-1])
                    Left_DFS(i,j-1,1);
                else if(Maze[i-1][j])
                    Left_DFS(i-1,j,0);
                else if(Maze[i][j+1])
                    Left_DFS(i,j+1,3);
                else if(Maze[i+1][j])
                    Left_DFS(i+1,j,2);
                break;
            }
        case 1:
            {
                if(Maze[i+1][j])
                    Left_DFS(i+1,j,2);
                else if(Maze[i][j-1])
                    Left_DFS(i,j-1,1);   
                else if(Maze[i-1][j])
                    Left_DFS(i-1,j,0);
                else if(Maze[i][j+1])
                    Left_DFS(i,j+1,3);
                break;
            }
        case 2:
            {
                if(Maze[i][j+1])
                    Left_DFS(i,j+1,3);
                else if(Maze[i+1][j])
                    Left_DFS(i+1,j,2);
                else if(Maze[i][j-1])
                    Left_DFS(i,j-1,1);   
                else if(Maze[i-1][j])
                    Left_DFS(i-1,j,0);
                break;
            }
        case 3:
            {
                if(Maze[i-1][j])
                    Left_DFS(i-1,j,0); 
                else if(Maze[i][j+1])
                    Left_DFS(i,j+1,3);
                else if(Maze[i+1][j])
                    Left_DFS(i+1,j,2);
                else if(Maze[i][j-1])
                    Left_DFS(i,j-1,1);   
                break;
            }
    }
    return;
}

void Right_DFS(int i, int j, int d)
{
    Right_Step++;
    if(i==E.row&&j==E.col)
        return;   
    switch(d)
    {
        case 0:
            {
                if(Maze[i][j+1])
                    Right_DFS(i,j+1,3);
                else if(Maze[i-1][j])
                    Right_DFS(i-1,j,0);
                else if(Maze[i][j-1])
                    Right_DFS(i,j-1,1); 
                else if(Maze[i+1][j])
                    Right_DFS(i+1,j,2);
                break;
            }
        case 1:
            {            
                if(Maze[i-1][j])
                    Right_DFS(i-1,j,0);
                else if(Maze[i][j-1])
                    Right_DFS(i,j-1,1); 
                else if(Maze[i+1][j])
                    Right_DFS(i+1,j,2);
                else if(Maze[i][j+1])
                    Right_DFS(i,j+1,3);
                break;
            }
        case 2:
            {                
                if(Maze[i][j-1])
                    Right_DFS(i,j-1,1); 
                else if(Maze[i+1][j])
                    Right_DFS(i+1,j,2);
                else if(Maze[i][j+1])
                    Right_DFS(i,j+1,3);
                else if(Maze[i-1][j])
                    Right_DFS(i-1,j,0);
                break;
            }
        case 3:
            {                 
                if(Maze[i+1][j])
                    Right_DFS(i+1,j,2);
                else if(Maze[i][j+1])
                    Right_DFS(i,j+1,3);
                else if(Maze[i-1][j])
                    Right_DFS(i-1,j,0);
                else if(Maze[i][j-1])
                    Right_DFS(i,j-1,1);
                break;
            }
    }
    return;
}

void MSS_BFS(int i, int j)
{
    bool Visited[41][41]={ false };
    Location queue[1600];
    int head,tail;
    queue[head=0].row=i;
    queue[tail=0].col=j;
    queue[tail++].depth=1;//i++是后赋值
    
    Visited[i][j] = true;
    
    while(head<tail)
    {
        Location x = queue[head++];
        if(x.row==E.row&&x.col==E.col)
        { 
           cout<<x.depth<<endl;
           return;
        }  
        if(Maze[x.row][x.col-1]&&!Visited[x.row][x.col-1])
        {
            Visited[x.row][x.col-1]=true;
            queue[tail].row=x.row;
            queue[tail].col=x.col-1;
            queue[tail++].depth=x.depth+1;
        }
        if(Maze[x.row-1][x.col]&&!Visited[x.row-1][x.col])
        {
            Visited[x.row-1][x.col]=true;
            queue[tail].row=x.row-1;
            queue[tail].col=x.col;
            queue[tail++].depth=x.depth+1;
        }
        if(Maze[x.row][x.col+1]&&!Visited[x.row][x.col+1])
        {
            Visited[x.row][x.col+1]=true;
            queue[tail].row=x.row;
            queue[tail].col=x.col+1;
            queue[tail++].depth=x.depth+1;
        }
        if(Maze[x.row+1][x.col]&&!Visited[x.row+1][x.col])
        {
            Visited[x.row+1][x.col]=true;
            queue[tail].row=x.row+1;
            queue[tail].col=x.col;
            queue[tail++].depth=x.depth+1;
        }
    }
    return;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int Direction;
        int w, h;
        cin>>w>>h;

        Left_Step=1;
        Right_Step=1;
        memset(Maze,false,sizeof(Maze));

        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                char tmp;
                cin>>tmp;
                if(tmp=='.')
                    Maze[i][j]=true;
                if(tmp=='E')
                {
                    Maze[i][j]=true;
                    E.row=i;
                    E.col=j;
                }                    
                if(tmp=='S')
                {
                    Maze[i][j]=true;
                    S.row=i;
                    S.col=j;
                    if(i==1) 
                        Direction=2;
                    else if(i==h) 
                        Direction=0; 
                    else if(j==1) 
                        Direction=3; 
                    else if(j==w) 
                        Direction=1;                          
                }
  
            }
        }
        switch(Direction)
        {
            case 0:{Left_DFS(S.row-1,S.col,0);break;}
            case 1:{Left_DFS(S.row,S.col-1,1);break;}
            case 2:{Left_DFS(S.row+1,S.col,2);break;}
            case 3:{Left_DFS(S.row,S.col+1,3);break;}
        }
        cout<<Left_Step<<' ';
        
        switch(Direction)
        {
            case 0:{Right_DFS(S.row-1,S.col,0);break;}
            case 1:{Right_DFS(S.row,S.col-1,1);break;}
            case 2:{Right_DFS(S.row+1,S.col,2);break;}
            case 3:{Right_DFS(S.row,S.col+1,3);break;}
        }
        cout<<Right_Step<<' ';

        MSS_BFS(S.row,S.col);
    }
    system("pause");
    return 0;
}