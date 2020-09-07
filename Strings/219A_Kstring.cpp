#include<bits/stdc++.h>
using namespace std;


int main(){
    int k;
    string s;
    cin>>k>>s;
    unordered_map<char, int> M;
    for(auto c:s){
        M[c]++;
    }
    bool ans = true;
    string a = "";
    int n = M.begin()->second;
    if(n%k!=0){
        ans=false;
    }
    else{
        for(auto itr:M){
            if(itr.second%k!=0){
                ans=false;
                break;
            }
            else{
                for(int i=0; i<itr.second/k; i++){
                    a+=itr.first;
                }
            }
        }
    }
    if(ans){
        while(k--)cout<<a;
    }
    else{
        cout<<-1;
    }
    cout<<"\n";
    return 0;
}