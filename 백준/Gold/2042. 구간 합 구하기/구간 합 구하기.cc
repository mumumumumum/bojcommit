#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

void init(vector<long long> &arr, vector<long long> &tree,int node,int start,int end){
    if(start==end)tree[node]=arr[start];
    else {
        int mid=(start+end)/2;
        init(arr,tree,node*2,start,mid);
        init(arr,tree,node*2+1,mid+1,end);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}

void update(vector<long long> &arr,vector<long long> &tree,int node,int start,int end,long long index,long long val){
    if(start>index||end<index)return;
    if(start==end){
        arr[index]=val;
        tree[node]=val;
        return;
    }
    int mid=(start+end)/2;
    update(arr,tree,node*2,start,mid,index,val);
    update(arr,tree,node*2+1,mid+1,end,index,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}

long long seg(vector<long long> &tree,int node,int start,int end,long long left,long long right){
    if(left>end||right<start)return 0;
    if(left<=start&&right>=end)return tree[node];
    int mid=(start+end)/2;
    return seg(tree,node*2,start,mid,left,right)+seg(tree,node*2+1,mid+1,end,left,right);
}


int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    vector<long long> arr(n);
    vector<long long> tree(n*4);
    vector<long long> v;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    init(arr,tree,1,0,n-1);
    for(int i=0;i<m+k;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        if(a==1)update(arr,tree,1,0,n-1,b-1,c);
        else v.push_back(seg(tree,1,0,n-1,b-1,c-1));
    }
    for(auto i=v.begin();i!=v.end();i++)cout<<*i<<"\n";
    return 0;
}