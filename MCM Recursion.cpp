# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> r(n+1);
    for(int i=0;i<=n;i++){
      cin>>r[i];
    }
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
    for(int i=0;i<=n;i++) dp[i][i]=0;
    
    auto MCM=[&](int i,int j,auto && MCM)->int{
        if(dp[i][j]!=1e9) return dp[i][j];
        
        for(int k=i;k<j;k++){
            int ans1 = MCM(i,k,MCM);
            int ans2 = MCM(k+1,j,MCM);
            dp[i][j]=min(dp[i][j], ans1 + ans2 +r[i-1]*r[k]*r[j]);
        }
        return dp[i][j];
    };
    
    cout<<MCM(1,n,MCM)<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }cout<<'\n';
    }
    return 0;
}