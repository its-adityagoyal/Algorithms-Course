#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,K;
    cin>>n>>K;
    vector<int> w(n),v(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<int> knapsack(K+1,0);
    vector<vector<pair<int,int>>> Taken(K+1);
    for(int i=1;i<=K;i++){
        for(int j=0;j<n;j++){
            if(w[j]<=i){
                knapsack[i]=max(knapsack[i],knapsack[i-w[j]]+v[j]);
                
                // Bookeeping
                if(knapsack[i]==knapsack[i-w[j]]+v[j]){
                    Taken[i]=Taken[i-w[j]];
                    Taken[i].push_back({w[j],v[j]});
                }
            }
        }
    }
    for(auto it: Taken[K]){
        cout<<"Weight: "<<it.first<<" Value: "<<it.second<<"\n";
    }
    cout<<"Maximum Value: "<<knapsack[K]<<'\n';
    return 0;
}