#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<string>
#include<stack>
using namespace std;
#define Num 4*1e9


vector<int> v(300000);
vector<int> prime;


void func(){
    for(int i=2;i<300000;i++){
        if(v[i]==1)continue;
        prime.push_back(i);
        for(int j=2*i;j<300000;j+=i)v[j]=1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n;
    func();
    while(1){
        cin>>n;
        if(n==0)break;
        cout<<upper_bound(prime.begin(),prime.end(),n*2)-upper_bound(prime.begin(),prime.end(),n)<<"\n";
    }
    return 0;
}