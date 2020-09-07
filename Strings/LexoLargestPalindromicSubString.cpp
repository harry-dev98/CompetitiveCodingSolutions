#include<bits/stdc++.h>
using namespace std;

bool ispali(string s){
    string rev = s;
    reverse(rev.begin(), rev.end());
    return rev==s?true:false;
}

int main(){
    string s, a="";
    cin>>s;
    int n = s.length();
    int A[26];
    memset(A, 0, sizeof(A));
    for(auto ch:s){
        A[ch-'a']++;
    }
    int i;
    for(i=25; i>=0; i--){
        if(A[i]){
            break;
        }
    }
    char start = i + 'a';
    string llps = "";
    for(i=0; i<A[start-'a']; i++)
        llps += start; 
    
    for(i=0; i<n; i++){
        if(s[i] == start){
            for(int j=0; j<n; j++){
                if(ispali(s.substr(i, j+1))){
                    // cout<<llps<<" "<<s.substr(i, j+1);
                    llps = max(llps, s.substr(i, j+1));
                    // cout<<" = "<<llps<<endl;
                }
            }
        }
    }
    cout<<llps<<"\n";
    return 0;
}