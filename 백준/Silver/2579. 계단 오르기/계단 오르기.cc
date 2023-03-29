#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;




int main(void)
{
    int n;
    cin>>n;
    vector<int> v(n+1);
    vector<int> sum(n+1);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sum[0]=v[0];
    sum[1]=v[0]+v[1];
    sum[2]=max(v[1]+v[2],v[0]+v[2]);
    for(int i=3;i<n;i++){
        sum[i]=max(v[i]+sum[i-2],v[i]+v[i-1]+sum[i-3]);
    }
    cout<<sum[n-1];
    return 0;
}