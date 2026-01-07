# include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> G(n,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
    }
    
    vector<int> visited(n,0),topo;
    auto dfs=[&](int node, auto & dfs)->void{
        visited[node]=1;
        for(auto it: G[node]){
            auto [v,w]=it;
            if(visited[v]==0){
                dfs(v,dfs);
            }
        }
        topo.push_back(node);
    };
    dfs(0,dfs);
    reverse(topo.begin(),topo.end());
    
    
    vector<int> distance(n,1e8);
    distance[0]=0;
    for(int i=0;i<n;i++){
        int node=topo[i];
        for(auto it: G[node]){
            auto [v,w] = it;
            distance[v]=min(distance[v],distance[node]+w);
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<distance[i]<<" ";
    }cout<<'\n';
    
    return 0;
}