#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, n, s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        int x=0;
        long long _ = n, ans=0;
        while(_){
            x++;
            _/=10;
        }
        cout<<x<<" x\n";
        int sum = 0;
        for(int i=0; i<x; i++){
            long long _ = (n/pow(10, x-1-i));
            int __ = pow(10, i);
            cout<<_<<" "<<__<<endl;
            if(sum + _%__ >= s){
                ans = (((_%10) + 1 ) * pow(10, x-i)) - n;
                break;
            }
            sum += _ % __;
        }
        cout<<ans<<"\n";
    }
    return 0;
}