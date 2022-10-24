#include <bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<string> com={"abc","acb","bac","bca","cab","cba"};
    vector<string> str(6,"");
    vector<vector<ll int>> dp(6,vector<ll int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++)
        str[j]+=com[j][i%3];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            int prev=0;
            if(i>0) prev=dp[j][i-1];
            dp[j][i]=prev+(s[i]!=str[j][i]);
        }
    }
    // for(int i=0;i<6;i++){
    //     cout<<str[i]<<" ";
    //     for(int j=0;j<n;j++){
            
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // abcab 1 2 3 4 4 
    // acbac 1 2 3 4 5 
    // bacba 0 0 1 2 3 
    // bcabc 0 1 1 2 3 
    // cabca 1 1 2 2 3 
    // cbacb 1 2 2 2 2
    while(m--){
        int x,y;
        cin>>x>>y;
        ll int ans=1e6;
        for(int i=0;i<6;i++){
            ll int ans1=dp[i][y-1];
            ll int ans2=((x-1)>0 ? dp[i][x-2] : 0);
            ans=min(ans,ans1-ans2);
        }
        cout<<ans<<endl;
    }
}
