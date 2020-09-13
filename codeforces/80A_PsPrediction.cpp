#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    bool ans = true;
    for(int i=n+1; i<m; i++){
        if(isprime(i)){
            ans = false;
        }
    }
    if(ans && isprime(m)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}