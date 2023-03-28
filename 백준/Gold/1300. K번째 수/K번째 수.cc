#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

long long k,n;

void binary(){
    long long ans=0,left=1,end=n*n;
    while(left<=end){
        long long cnt=0;
        long long  mid=(left+end)/2;
        for(int i=1;i<=n;i++){
            if(i>mid)break;
            cnt+=min(n,mid/i); 
            
        }
        if(cnt>=k){
            ans=mid;
            end=mid-1;
        } 
        else left=mid+1;
    }   
    cout<<ans;
}

int main(void)
{
    
    cin>>n>>k;
    binary();
    
    return 0;
}