#include<bits/stdc++.h>
using namespace std;

// on circle shortest path between x and y is always 
// min(|x-y|, l-|x-y|) where l is size of circle..

int main(){
    string s;
    cin>>s;
    int moves=0;
    int ptr = 0;
    for(auto ch:s){
        int dif = abs(ptr-(ch-'a'));
        moves += min(dif, 26-dif);
        ptr = ch - 'a';
    }
    cout<<moves<<"\n";
    return 0;
}