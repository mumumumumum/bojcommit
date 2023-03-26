#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;




int main(void)
{
    vector<string> v;
    while(1){
        bool cnt=true;
        string s;
        stack<char> check;
        getline(cin,s);
        if(s.size()==1&&s==".")break;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')check.push('(');
            if(s[i]==')'){
                if(check.empty()||check.top()!='('){
                    cnt=false;
                    break;
                }
                else {
                    check.pop();
                    cnt=true;
                }
            }
            if(s[i]=='[')check.push('[');
            if(s[i]==']'){
                if(check.empty()||check.top()!='['){
                    cnt=false;
                    break;
                }
                else {
                    check.pop();
                    cnt=true;
                }
            }
        }
        if(check.empty()&&cnt)v.push_back("yes");
        else v.push_back("no");
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }
    return 0;
}