#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define p pair<int, pair<int,int>>

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n;
        vector<int> Arr[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>x;
                Arr[i].push_back(x);
            }
        }
        priority_queue<p, vector<p>, greater<p>>pq;
        for(int i=0; i<n; i++){
            pq.push(mp(Arr[i][0], mp(i, 0)));
        }
        int ans[n*n];
        int ind = 0;
        while(!pq.empty()){
            // cout<<"here\n";
            p top = pq.top();
            pq.pop();
            ans[ind++] = top.first;
            cout<<top.first<<" ";
            if(top.second.second+1<Arr[top.second.first].size()){
                int val = Arr[top.second.first][top.second.second+1];
                pq.push(mp(val, mp(top.second.first, top.second.second+1)));
            }
        }
        
    }
    return 0;
}