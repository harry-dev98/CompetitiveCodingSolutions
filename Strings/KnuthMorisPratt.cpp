#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){
    int j, n = s.length();
    vector<int> pi(n, 0);
    for(int i=1; i<n; i++){
        j = pi[i-1];
        while(j > 0 && s[i]!=s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

vector<int> prefix_func(string str){
    int n = str.length();
    vector<int> pi(n, 0);
    int j;
    for(int i=1; i<n; i++){
        j = pi[i-1];
        while(j>0 && str[i] != str[j]){
            j = pi[j-1];
        }
        if(str[i] == str[j])j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    // string str = "261020406030";
    // string s = "261020406030";
    string str = "ABACABAB";
    string s = "402060103026";
    vector<int> pi = prefix_function(str);
    for(auto itr:pi){
        cout<<itr<<" ";
    }
    cout<<"\n";
     pi = prefix_func(str);
    for(auto itr:pi){
        cout<<itr<<" ";
    }
    cout<<"\n";
    int j=0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == str[j]){
            j++;
        }
        else{
            j = pi[j];
        }
        if(j==str.length()){
            cout<<"Pattern starts at "<<i-str.length()+1<<endl;
            cout<<"Pattern ends at "<<i<<endl;
            cout<<s.substr(i-str.length()+1, str.length())<<endl;
        }
    }
    return 0;
}