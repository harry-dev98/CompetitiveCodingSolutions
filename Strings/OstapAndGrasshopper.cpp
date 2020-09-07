#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    string s;
    cin>>n>>k>>s;
    int G=-1, I=-1;
    for(int i=0; i<n; i++){
        if(s[i] == 'G'){
            G = i;
        }
        if(s[i] == 'T'){
            I = i;
        }
        if(G!=-1&&I!=-1){
            break;
        }
    }
    if(G>I){
        swap(G, I);
        s[G] = 'G';
        s[I] = 'T';
    }
    bool ans = false;
    for(int i=G; i<=I; i+=k){
        // cout<<i<<endl;
        if(s[i]=='T'){
            ans = true;
            break;
        }
        if(s[i] == '#'){
            break;
        }
    }
    if(ans){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    cout<<"\n";
    return 0;
}