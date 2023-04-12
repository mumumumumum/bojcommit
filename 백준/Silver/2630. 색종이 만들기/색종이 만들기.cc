#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
 
using namespace std;
vector<vector<int>> map(129,vector<int>(129));
int ans0=0,ans1=0;

void func(int x,int y,int n){
    int a=0;
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(map[i][j]==1)a++;
        }
    }
    if(a==0)ans0++;
    else if(a==n*n)ans1++;
    else {
        func(x,y,n/2);
        func(x+n/2,y+n/2,n/2);
        func(x,y+n/2,n/2);
        func(x+n/2,y,n/2);
    }
    return;
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>map[i][j];
    }
    func(0,0,n);
    cout<<ans0<<"\n"<<ans1<<"\n";
    return 0;
}