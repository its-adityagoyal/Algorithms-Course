#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=i;
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=min(dp[i][j-1]+1, min(dp[i-1][j-1]+1, dp[i-1][j]+1));
            }
        }
    }
    cout<<"Edit Distance: "<<dp[n][m]<<'\n';
    
    // Space Optimized
    vector<int> v1(m+1);
    for(int i=0;i<=m;i++){
        v1[i]=i;
    }
    for(int i=1;i<=n;i++){
        vector<int> v2(m+1,0);
        v2[0]=i;
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                v2[j]=v1[j-1];
            }else{
                v2[j]=min(v2[j-1]+1, min(v1[j-1]+1, v1[j]+1));
            }
        }
        v1=v2;
    }
    cout<<"Edit Distance (Space Optimized): "<<v1[m]<<'\n';
    return 0;
}