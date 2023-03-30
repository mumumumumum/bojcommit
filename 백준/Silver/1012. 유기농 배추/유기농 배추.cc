#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;
int cnt=0;
int map[51][51];
bool visited[51][51];
vector<int> v;
int dx[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};

void dfs(int row,int col,int x,int c){
    visited[row][col]=true;
    //cout<<row<<" "<<col<<"\n";
    for(int i=0;i<4;i++){
        int xr=row+dx[i];
        int cy=col+dc[i];
        if(xr<0||xr>=x||cy<0||cy>=c)continue;
        if(visited[xr][cy]||map[xr][cy]==0)continue;
        //cout<<xr<<cy<<map[xr][cy]<<"\n";
        dfs(xr,cy,x,c);
    }
}

int main(void)
{
    int t,m,n,ba;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>m>>n>>ba;
        cnt=0;
        memset(map,0,sizeof(map));
        memset(visited,false,sizeof(visited));
        
        for(int j=0;j<ba;j++){
            int a,b;
            cin>>a>>b;
            map[b][a]=1;
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(!visited[j][k]&&map[j][k]==1){
                    dfs(j,k,n,m);
                    cnt++;
                }
            }
        }
        v.push_back(cnt);
    }
    for(auto iter=v.begin();iter!=v.end();iter++)cout<<*iter<<"\n";
    return 0;
}