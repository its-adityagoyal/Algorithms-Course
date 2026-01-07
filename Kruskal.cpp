# include <bits/stdc++.h>
using namespace std;

bool custom(pair<int,pair<int,int>> &p1, pair<int,pair<int,int>>& p2){
    if(p1.first<p2.first) return true;
    else return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end(),custom);
    
    // Make Set
    vector<int> A(n);
    for(int i=0;i<n;i++){
        A[i]=i;
    }
    
    vector<pair<int,pair<int,int>>> MST;
    for(int i=0;i<m;i++){
        auto [w, nodes] = edges[i];
        auto [u, v] = nodes;
        if(A[u]!= A[v]){
            MST.push_back(edges[i]);
            
            int representative_u = A[u];
            int representative_v = A[v];
            // Union 
            for(int i=0;i<n;i++){
                if(A[i]==representative_u){
                    A[i]= representative_v;
                }
            }
        }
    }
    
    for(auto it: MST){
        auto [w, nodes] = it;
        auto [u, v] = nodes;
        cout<<"Node1: "<<u<<" Node2: "<<v<<" Distance: "<<w<<'\n';
    }
    return 0;
}