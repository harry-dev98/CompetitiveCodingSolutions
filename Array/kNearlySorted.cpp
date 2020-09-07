#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<k; i++){
            pq.push(A[i]);
        }
        int ind = k;
        while(ind<n){
            cout<<pq.top()<<" ";
            pq.pop();
            pq.push(A[ind++]);
        }
        while(!pq.empty()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<"\n";
    }
    return 0;
}