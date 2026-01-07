# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> frequency(n);
    for(int i=0;i<n;i++){
        cin>>frequency[i];
    }
    multiset<int> ms;
    int cost=0;
    for(auto it: frequency){
        ms.insert(it);
        cost+=it;
    }
    for(int k=n+1;k<=2*n-1;k++){
        int fi = *ms.begin();
        ms.erase(ms.begin());
        int fj = *ms.begin();
        ms.erase(ms.begin());
        cost+= (fi+fj);
        frequency.push_back(fi+fj);
        ms.insert(fi+fj);
    }
    cost = cost - *frequency.rbegin();
    cout<<cost<<'\n';
    return 0;
}