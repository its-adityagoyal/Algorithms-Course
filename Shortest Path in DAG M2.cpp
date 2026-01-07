# include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> G(n,vector<pair<int,int>>());
    vector<vector<pair<int,int>>> GR(n,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        GR[v].push_back({u,w});
    }
    
    vector<int> distance(n,1e8);
    distance[0]=0;
    
    auto spdag=[&](int node, auto & spdag)->int{
        if(distance[node]!=1e8) return distance[node];
        for(auto it: GR[node]){
            auto [v,w]=it;
            int spdag_v = spdag(v,spdag);
            distance[node]=min(distance[node], spdag_v+w);
        }
        return distance[node];
    };
    
    for(int i=n-1;i>=0;i--){
        if(distance[i]==1e8) spdag(i,spdag);
    }
    for(int i=0;i<n;i++){
        cout<<"distance["<<i<<"]= "<<distance[i]<<'\n';
    }
    
    return 0;
}