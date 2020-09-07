#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, s1;
    cin>>s;
    unordered_map<string, int> M;
    for(int i=0; i<10; i++){
        cin>>s1;
        M[s1] = i;
    }
    for(int i=0; i<8; i++){
        cout<<M[s.substr(10*i, 10)];
    }
    cout<<"\n";
    return 0;
}