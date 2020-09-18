#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>Seats(m);
    for(int& s: Seats)cin>>s;
    priority_queue<int> Q1;
    priority_queue<int, vector<int>, greater<int>>Q2;
    for(int s: Seats)Q1.push(s);
    for(int s: Seats)Q2.push(s);

    int peep = n;
    int ans1 = 0;
    while(peep){
        int _ = Q1.top();
        ans1+=_;
        Q1.pop();
        if(_>1){
            Q1.push(_-1);
        }
        peep--;
    }
    peep = n;
    int ans2 = 0;
    while(peep){
        int _ = Q2.top();
        ans2+=_;
        Q2.pop();
        if(_>1){
            Q2.push(_-1);
        }
        peep--;
    }
    cout<<ans1<<" "<<ans2<<"\n";
    return 0;
}