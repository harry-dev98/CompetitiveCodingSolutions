#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n;
    vector<int> N(n);
    for(int& _: N)cin>>_;
    cin>>m;
    vector<int> M(m);
    for(int& _: M)cin>>_;
    int ans = 0;
    int maxR = 0;
    for(int a: N){
        for(int b: M){
            if(b%a == 0 && b/a > maxR){
                maxR = b/a;
                ans = 1;
            }
            else if(b%a==0 && b/a == maxR)ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}