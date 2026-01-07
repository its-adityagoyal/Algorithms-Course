# include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> cost(n,INT_MAX),previous(n,-1);
    cost[0]=0;
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
        s.insert({cost[i],i});
    }
    
    vector<int> visited(n,0);
    while(!s.empty()){
        auto [c,u]=*(s.begin())  ;
        s.erase(s.begin());
        visited[u]=1;
        
        for(auto it: adj[u]){
            auto [v,w]=it;
            if(visited[v]==0 && cost[v]>w){
                s.erase({cost[v],v});
                cost[v]=w;
                s.insert({cost[v],v});
                previous[v]=u;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<"Cost["<<i<<"] = "<<cost[i]<<" Parent["<<i<<"] = "<<previous[i]<<'\n';
    }
    return 0;
}