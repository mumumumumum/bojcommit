#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct Node{
	int node;
	int sum;
};

Node bfs(vector<pair<int,int>> v[],queue<Node> &q,vector<bool> visited){
	visited[q.front().node]=true;
	Node max;
	max.sum=0;
	while(!q.empty()){
		Node n=q.front();
		q.pop();
		if(max.sum<n.sum){
			max.sum=n.sum;
			max.node=n.node;
		}
		for(int i=0;i<v[n.node].size();i++){
			if(!visited[v[n.node][i].first]){
				q.push({v[n.node][i].first,n.sum+v[n.node][i].second});
				visited[v[n.node][i].first]=true;
			}
		}
	}
	return max;
}

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	vector<pair<int,int>> v[n+1];
	vector<bool> visited(n+1,false);
	for(int i = 0;i < n-1;i++){
		int pm,cm,w;
		cin>>pm>>cm>>w;
		v[pm].push_back(make_pair(cm,w));
		v[cm].push_back(make_pair(pm,w));
	}
	queue<Node> q;
	q.push({1,0});
	q.push({bfs(v,q,visited).node,0});
	cout<<bfs(v,q,visited).sum;
    return 0;
}