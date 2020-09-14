#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    bool ans = false;
    for(char ch:s){
        if(ch == 'H' || ch == 'Q' || ch == '9'){
            ans = true;
            break;
        }
    }   
    cout<<(ans?"YES":"NO")<<"\n";
    return 0;
}