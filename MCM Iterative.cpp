# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> r(n+1);
    for(int i=0;i<=n;i++){
      cin>>r[i];
    }
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,1e8));
    vector<vector<int>> bookkeeping(n+1,vector<int>(n+1,-1));
    for(int i=0;i<=n;i++) dp[i][i]=0;
    
    for(int s=1;s<=n-1;s++){
      for(int i=1;i<=(n-s);i++){
          int j=i+s;
          for(int k=i;k<j;k++){
            dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+r[i-1]*r[k]*r[j]);
            
            // bookkeeping
            if(dp[i][j] == dp[i][k]+dp[k+1][j]+r[i-1]*r[k]*r[j]){
              bookkeeping[i][j] = k;
            }
          }
      }
    }
    cout<<"Cost: "<<dp[1][n]<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<bookkeeping[i][j]<<" ";
        }cout<<'\n';
    }
    return 0;
}