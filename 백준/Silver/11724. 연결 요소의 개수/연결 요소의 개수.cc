#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;
int n,m;
vector<int> v[1001];
vector<bool> visited(1001);
void dfs(int num){
    visited[num]=true;
    for(int i=0;i<v[num].size();i++){
        if(!visited[v[num][i]]){
            dfs(v[num][i]);
        }
    }
}

int main(void)
{
    cin>>n>>m;
    int cnt=0;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}