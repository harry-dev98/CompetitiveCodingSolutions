#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}