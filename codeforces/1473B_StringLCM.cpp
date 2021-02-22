#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a.size() > b.size()){
            swap(a, b);
        }
        int n = a.size();
        int m = b.size();
        char ch = a[0];
        bool f = true;
        for(char _: a){
            if(ch != _)f=false;
        }
        for(char _: b){
            if(ch != _)f=false;
        }
        if(f){
            for(int i=0; i<n*m; i++){
                cout<<ch;
            }cout<<"\n";
        } else {
            bool f1 = true;
            for(int i=0; i<m; i+=n){
                if(a != b.substr(i, n)){f1 = false;}
            }
            if(f1)cout<<b<<"\n";
            else cout<<-1<<"\n";
        }
    }
    return 0;
}