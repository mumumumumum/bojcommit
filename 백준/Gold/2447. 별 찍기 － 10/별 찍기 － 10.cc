#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
 
using namespace std;


void star(int i,int j,int k){
    if(k==0)cout<<'*';
    else if((i/k)%3==1&&(j/k)%3==1)cout<<" ";
    else star(i,j,k/3);
    
} 

int main() {
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            star(i,j,n);
        }
        cout<<"\n";
    }
    return 0;
}