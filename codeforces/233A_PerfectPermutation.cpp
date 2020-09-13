#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(n%2 == 1){
        cout<<-1<<"\n";
    }
    else{
        for(int i=n; i>0; i--){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    return 0;
}