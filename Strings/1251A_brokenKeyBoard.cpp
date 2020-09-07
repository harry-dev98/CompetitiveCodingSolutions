#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    string s, a="";
    vector<string>V;
    unordered_set<char> S;
    while(t--){
        a = "";
        S = {};
        cin>>s;
        int n = s.length();
        int j;char ch;
        for(int i=0; i<n; i){
            j = i+1;
            ch = s[i];
            while(s[j]==ch){
                j++;
            }
            if((j-i)%2){
                S.insert(ch);
            }
            i = j;
        }
        for(auto _:S){
            a+=_;
        }
        sort(a.begin(), a.end());
        V.push_back(a);
    }
    for(auto v:V){
        cout<<v<<"\n";
    }
    return 0;
}