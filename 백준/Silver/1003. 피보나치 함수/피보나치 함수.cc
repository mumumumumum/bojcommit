#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int, int>> v(41);
    v[0]={1,0};
    v[1]={0,1};
    for(int i=2;i<41;i++){
        v[i]={v[i-1].first+v[i-2].first,v[i-1].second+v[i-2].second};
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ans.push_back({v[a].first,v[a].second});
    }
   
    for(int i=0;i<n;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    return 0;
}