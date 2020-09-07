#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
    SPEED;
    int t;
    cin>>t;
    while(t--){
        int n, k, x;
        priority_queue<int, vector<int>, greater<int>>pq;
        cin>>n;
        while(n--){
            cin>>x;
            pq.push(x);
        }
        cin>>k;
        while(--k){
            pq.pop();
        }
        cout<<pq.top()<<"\n";
    }
}