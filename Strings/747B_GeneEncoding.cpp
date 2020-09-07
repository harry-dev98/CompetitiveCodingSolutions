#include<bits/stdc++.h>
using namespace std;

bool comp(pair<char, int> p1, pair<char, int> p2){
    return p1.second<p2.second;
}

int main(){
    int t;
    string s;
    cin>>t;
    cin>>s;
    unordered_map<char, int> M = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
    int q = 0;
    for(auto c:s){
        if(c=='?'){
            q++;
        }
        else{
            M[c]++;
        }
    }
    auto p = max_element(M.begin(), M.end(), comp);
    int mxx = p->second, req=0;
    queue<char> Q;
    for(auto p:M){
        M[p.first] = mxx-p.second;
        while(M[p.first]--){
            Q.push(p.first);
        }
    }
    int diff = (q - Q.size()); 
    if((diff%4!=0) || diff<0){
        cout<<"===";
    }
    else{
        for(int i=0; i<diff/4; i++){
            Q.push('A');
            Q.push('C');
            Q.push('G');
            Q.push('T');
        }
        for(int i=0; i<t; i++){
            if(s[i] == '?'){
                s[i] = Q.front();
                Q.pop();
            }
        }
        cout<<s;
    }
    cout<<"\n";
    return 0;
}