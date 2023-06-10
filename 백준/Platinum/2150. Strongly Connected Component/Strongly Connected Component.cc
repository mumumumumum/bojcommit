#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
int n,m,t=0,sccNum=1;
vector<int> node[10001];
vector<int> color(10001);
vector<int> discoverTime(10001);
vector<int> scc(10001);
vector<int> low(10001);
stack<int> ds;
vector<int> v[10001];
int dfs(int  u){
    color[u]=1;
    discoverTime[u]=++t;
    low[u]=discoverTime[u];
    ds.push(u);
    for(int i=0;i<node[u].size();i++){
        int v=node[u][i];
        if(!color[v])low[u]=min(low[u],dfs(v));
        else if(!scc[v])low[u]=min(low[u],discoverTime[v]);
    }
    if(low[u]>=discoverTime[u]){
        priority_queue<int,vector<int>,greater<>> pq;
        while(1){
            int y=ds.top();
            ds.pop();
            scc[y]=sccNum;
            pq.push(y);
            if(y==u){
                sccNum++;
                break;
            }
        }
        int top=pq.top();
        while(!pq.empty()){
            v[top].push_back(pq.top());
            pq.pop();
        }
        
    }
    return low[u];
}


int main(void)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        node[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(color[i]==0)dfs(i);
    }
    cout<<sccNum-1<<"\n";
    for(int i=1;i<=n;i++){
        if(!v[i].empty()){
            for(int j=0;j<v[i].size();j++){
                cout<<v[i][j]<<" ";
            }
            cout<<-1<<"\n";
        }
    }
    return 0;
}