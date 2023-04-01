#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;


int main(void)
{
    int n;
    cin>>n;
    vector<int> arr(n+1);
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
    for(int i=4;i<=n;i++){
        if(i%3==0&&i%2==0)arr[i]=min(arr[i/2]+1,arr[i/3]+1);
        else if(i%3==0)arr[i]=min(arr[i/3]+1,arr[i-1]+1);
        else if(i%2==0)arr[i]=min(arr[i/2]+1,arr[i-1]+1);
        else arr[i]=arr[i-1]+1;
    }
    cout<<arr[n];
    return 0;
}