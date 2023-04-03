#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }
    vector<int> sum(n);
   
    for(int i=1;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            if(j==0) v[i][j]+=v[i-1][j];
            else if(j==v[i].size()-1)v[i][j]+=v[i-1][j-1];
            else v[i][j]+=max(v[i-1][j-1],v[i-1][j]);
        }
    }
    cout<<*max_element(v[n-1].begin(),v[n-1].end());
    
    return 0;
}