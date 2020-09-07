#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s1, s2;
    cin>>t;
    unordered_map<char, int> M1, M2;
    while(t--){
        M1.clear();M2.clear();
        cin>>s1>>s2;
        for(auto c:s1){
            M1[c]++;
        }
        for(auto c:s2){
            M2[c]++;
        }
        bool ans = true;
        for(auto m:M1){
            if(M2.find(m.first)==M2.end()){
                ans = false;
                break;
            }
            else{
                if(M2[m.first]-m.second < 0){
                    ans=false;
                    break;
                }
            }
        }
        cout<<(ans?"YES":"NO")<<"\n";
    }
    return 0;
}