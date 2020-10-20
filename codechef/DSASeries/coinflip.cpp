#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, g, n, i, q;
    cin>>t;
    while(t--){
        cin>>g;
        while(g--){
            cin>>i>>n>>q;
            int heads = n/2, tails = n/2; //assumed tail first 
            if(n%2){
                heads++;
            }
            if(i == q)cout<<tails<<"\n";
            else cout<<heads<<"\n";
        }
    }
    return 0;
}