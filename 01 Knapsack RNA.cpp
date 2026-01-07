#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,K;
    cin>>n>>K;
    vector<int> w(n),v(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(K+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=K;j++){
            // Not Taken
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            
            //Taken
            if(w[i-1]<=j){
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i-1]]+v[i-1]);
            }
        }
    }
    cout<<dp[n][K]<<'\n';
    return 0;
}