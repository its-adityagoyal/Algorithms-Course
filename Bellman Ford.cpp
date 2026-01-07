# include <bits/stdc++.h>
using namespace std;

// Example: 
// 8 11
// 0 1 10
// 0 7 8
// 7 6 1
// 6 5 -1
// 6 1 -4
// 1 5 2
// 2 1 1
// 2 3 1
// 5 2 -2
// 3 4 3
// 4 5 -1

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int,int>,int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({{u,v},w});
    }
    vector<int> distance(n,1e8);
    distance[0]=0;
    
    for(int i=1;i<=n-1;i++){
        for(auto it: edges){
            auto [nodes,w]=it;
            auto [u,v] = nodes;
            distance[v]=min(distance[v],distance[u]+w);
        }
    }
     for(int i=0;i<n;i++){
        cout<<"distance["<<i<<"] = "<<distance[i]<<'\n';
    }
    
    return 0;
}