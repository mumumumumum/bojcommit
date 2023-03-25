#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main(void)
{
    int k,sum=0;
    cin>>k;
    stack<int> s;
    for(int i=0;i<k;i++){
        int n;
        cin>>n;
        if(n==0)s.pop();
        else s.push(n);
    }
    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    cout<<sum;
    return 0;
}