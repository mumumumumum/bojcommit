#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;

void binary(vector<int> &v){
    sort(v.begin(),v.end());
    int left=1,end=v.back(),ans=0;
    while(left<=end){
        long long int sum=0;
        int mid=(left+end)/2;
        
        for(int i=0;i<n;i++){
            if(v[i]-mid>0)sum+=(v[i]-mid);
        }
        if(sum>=m){
            ans=max(ans,mid);
            left=mid+1;
        }
        else end=mid-1;
    }
    cout<<ans;
}



int main(void)
{
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    binary(v);
    return 0;
}