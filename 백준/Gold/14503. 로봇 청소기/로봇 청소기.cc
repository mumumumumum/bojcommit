#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<vector<int> > RobotMap(51,vector<int>(51));
vector<vector<bool> > visited(51,vector<bool>(51,false));
int dx[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int n,m,r,c,d,cnt=0;
void dfs(int row,int col,int Direction){
    if(!visited[row][col]){
        cnt++;
        visited[row][col]=true;
    }
   
    bool check=false;
    for(int i=0;i<4;i++){
        if(Direction-1<0)Direction=3;
        else Direction--;
        
        int r=row+dx[Direction];
        int c=col+dc[Direction];

        if(r<0||r>=n||c<0||c>=m)continue;
        if(visited[r][c]||RobotMap[r][c]==1)continue;
        check=true;
        dfs(r,c,Direction);
        
    }
    if(!check){
        int newDirection = (Direction+2 > 3) ? Direction-2 : Direction+2;
        int r=row+dx[newDirection];
        int c=col+dc[newDirection];
        if(RobotMap[r][c]==1) {
            cout<<cnt;
            exit(0);
        }
        else dfs(r,c,Direction);

    }
}

int main(void)
{
    vector<int> v;
    
    cin>>n>>m>>r>>c>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>RobotMap[i][j];
        }
    }
    dfs(r,c,d);
    
    return 0;
}