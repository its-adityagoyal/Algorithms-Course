# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(auto &it: arr){
        cin>>it;
    }
    
    vector<vector<int>> sequence(n);
    for(int i=0;i<n;i++){
        sequence[i].push_back(arr[i]);
    }
    
    vector<int> LIS(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                LIS[i]=max(LIS[i],LIS[j]+1);
                if(LIS[i]==LIS[j]+1){
                    sequence[i]=sequence[j];
                    sequence[i].push_back(arr[i]);
                }
            }
        }
    }
    

    int index=0, past_length=0;
    for(int i=0;i<n;i++){
        if(LIS[i]>past_length){
            past_length=LIS[i];
            index=i;
        }
    }
    
    cout<<"Longest Increasing Subsequence: ";
    for(auto it: sequence[index]){
        cout<<it<<" ";
    }cout<<'\n';

    return 0;
}