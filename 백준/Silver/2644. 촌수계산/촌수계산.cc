#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
 
using namespace std;

struct Node{
    int num;
    int node;
};
queue<Node> q;
vector<bool> visited(101);
vector<int> v[101];
void bfs(int n){
    while(!q.empty()){
        Node a=q.front();
        if(a.num==n){
            cout<<a.node;
            return;
        }
        q.pop();
        for(int i=0;i<v[a.num].size();i++){
            if(visited[v[a.num][i]])continue;
            q.push({v[a.num][i],a.node+1});
            visited[v[a.num][i]]=true;
        }
    }
    cout<<-1;
}

int main() {
    int n,start,end,m;
    cin>>n>>start>>end>>m;
   
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push({start,0});
    visited[start]=true;
    bfs(end);
    return 0;
}