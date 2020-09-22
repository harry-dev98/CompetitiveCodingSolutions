#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    string s;
    map<string, int> M;
    while(t--){
        cin>>s;
        if(M.find(s) == M.end()){
            M[s] = 1;
            cout<<"OK\n";
        }
        else{
            int _ = M[s];
            M[s]++;
            s += to_string(_);
            M[s] = 1;
            cout<<s<<"\n";
        }
    }
    return 0;
}