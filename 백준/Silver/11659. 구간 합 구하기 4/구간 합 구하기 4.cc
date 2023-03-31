#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;


int main(void)
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    vector<int> sum(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i==0)sum[i]=v[i];
        else sum[i]=sum[i-1]+v[i];
    }
    vector<int> ans;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ans.push_back(sum[b-1]-sum[a-2]);
    }
    for(auto iter=ans.begin();iter!=ans.end();iter++)cout<<*iter<<"\n";
    return 0;
}