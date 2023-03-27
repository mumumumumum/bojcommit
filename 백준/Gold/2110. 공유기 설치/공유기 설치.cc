#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
int n,c;
void binary(vector<int> &v){
    sort(v.begin(),v.end());
    int left=1,end=v.back(),ans=0;
    while(left<=end){
        int minus=v[0];
        int cnt=1;
        int mid=(left+end)/2;
        for(int i=1;i<n;i++){
            if(v[i]-minus>=mid){
                cnt++;
                minus=v[i];
            }
        }
        if(cnt>=c){
            left=mid+1;
            ans=mid;
        }
        else end=mid-1;
    }
    cout<<ans;
}


int main(void)
{
 
    cin>>n>>c;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    binary(v);
    return 0;
}