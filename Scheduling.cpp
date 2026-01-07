# include <bits/stdc++.h>
using namespace std;

bool custom(pair<int,int> & p1, pair<int,int> &p2){
    if(p1.second<p2.second){
        return true;
    }else if(p1.second==p2.second){
        return p1.first<p2.first;
    }else{
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> schedules;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        schedules.push_back({l,r});
    }
    sort(schedules.begin(),schedules.end(),custom);
    
    vector<pair<int,int>> X;
    int last_end=0;
    for(int i=0;i<n;i++){
        if(schedules[i].first>=last_end){
            X.push_back(schedules[i]);
            last_end=schedules[i].second;
        }
    }
    
    for(auto it: X){
        cout<<"["<<it.first<<","<<it.second<<"]\n";
    }
    
    return 0;
}