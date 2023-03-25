#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main(void)
{
    int t,cnt=0;
    bool arr[101][101]={0,};
    cin>>t;
    for(int i=0;i<t;i++){
        int r,c;
        cin>>r>>c;
        for(int j=c;j<c+10;j++){
            for(int k=r;k<10+r;k++){
                if(!arr[j][k]){
                    arr[j][k]=true;
                    cnt++;
                }
                
            }
        }
    }
    cout<<cnt;
    return 0;
}