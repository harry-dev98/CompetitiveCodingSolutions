#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    
    unordered_set<char> S = {'a', 'e', 'i', 'o', 'u'};
    int one = 0;
    for(auto ch:s1){
        if(S.find(ch) != S.end()){
            one++;
        }
    }
    int two = 0;
    for(auto ch:s2){
        if(S.find(ch) != S.end()){
            two++;
        }
    }
    int three = 0;
    for(auto ch:s3){
        if(S.find(ch) != S.end()){
            three++;
        }
    }
    if(one==5 && two==7 && three==5){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    cout<<"\n";
    return 0;
}