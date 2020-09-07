#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1, s2, s3, ans="";
   cin>>s1>>s2>>s3;
   unordered_map<int, int> M;
   for(int i=0; i<26; i++){
       M[s1[i]-'a'] = s2[i] - s1[i];
   }
   for(auto ch:s3){
       if(ch>='a' && ch<='z'){
           ans+= ch + M[ch-'a'];
       }
       else if(ch>='A' && ch<='Z'){
           ans+= ch + M[ch-'A'];
       }
       else{
           ans+=ch;
       }
   }
   cout<<ans<<"\n";
    return 0;
}