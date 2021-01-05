#include<bits/stdc++.h>
using namespace std;

int powOfTwo(int x){
    int ans = 0;
    while(x%2==0){
        ans++;
        x = x/2;
    }
    return (int)pow(2, ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, w, h, n;
    cin>>t;
    while(t--){
        cin>>w>>h>>n;
        cout<<((powOfTwo(w)*powOfTwo(h)>=n)?"YES":"NO")<<"\n";
    }
    return 0;
}