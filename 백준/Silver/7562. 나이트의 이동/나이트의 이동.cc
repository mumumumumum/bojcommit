#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
 
using namespace std;

struct Node{
    int x;
    int y;
    int node;
};


int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dc[8]={1,-1,2,-2,2,-2,1,-1};
vector<int> v;
void bfs(queue<Node> q,vector<vector<bool>> &visited,int num,int ex,int ey){
    while(!q.empty()){
        Node a=q.front();
        if(a.x==ex&&a.y==ey){
            v.push_back(a.node);
            return;
        }
        q.pop();
        for(int i=0;i<8;i++){
            int x=a.x+dx[i];
            int y=a.y+dc[i];
            if(x<0||x>=num||y<0||y>=num)continue;
            if(visited[x][y])continue;
            q.push({x,y,a.node+1});
            visited[x][y]=true;
        }
    }
}


int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        queue<Node> q;
        int l,x,y,ex,ey;
        cin>>l>>x>>y>>ex>>ey;
        vector<vector<bool>> visited(l,vector<bool>(l,false));
        q.push({x,y,0});
        visited[x][y]=true;
        bfs(q,visited,l,ex,ey);
    }
    for(auto iter=v.begin();iter!=v.end();iter++){
        cout<<*iter<<"\n";
    }
    return 0;
}