#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int n,r,q;
vector<int> tree[100001];
vector<int> sum(100001);
int dfs(int node,int prev){
	sum[node]=1;
	for(int i=0;i<tree[node].size();i++){
		if(tree[node][i]==prev)continue;
		sum[node]+=dfs(tree[node][i],node);
	}
	return sum[node];
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>n>>r>>q;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(r,0);
	vector<int> v;
	for(int i=0;i<q;i++){
		int a;
		cin>>a;
		v.push_back(sum[a]);
	}
	for(int i=0;i<q;i++)cout<<v[i]<<"\n";
	return 0;
}