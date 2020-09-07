#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin>>n>>t;
    string s;
    cin>>s;
    for(int i=0; i<t; i++){
        string tmp = s;
        for(int j=0; j<n-1; j++){
            if(tmp[j] == 'B' && tmp[j+1] == 'G'){
                swap(s[j], s[j+1]);
            }
        }
    }
    cout<<s<<"\n";
    return 0;
}