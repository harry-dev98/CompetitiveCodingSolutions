#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t, n, one, two, x;
    cin>>t;
    while(t--){
        cin>>n;
        one = two = 0;
        for(int i=0; i<n; i++){
            cin>>x;
            if(x == 1)one++;
            else two++;
        }
        cout<<(((one%2==0 && one>0) || (two%2==0 && one%2 == 0))?"YES":"NO")<<"\n";
    }
    return 0;
}