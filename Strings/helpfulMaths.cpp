#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<int>A(n/2+1);
    int ind = 0;
    for(auto ch:s){
        if(ch != '+'){
            A[ind++] = ch-'0';
        }
    }
    sort(A.begin(), A.end());
    string ans = "";
    for(auto itr:A){
        char ch = itr+'0';
        ans += ch;
        ans += '+';
    }
    cout<<ans.substr(0, n)<<"\n";
    return 0;
}