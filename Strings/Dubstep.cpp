#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int ind = 0;
    // int eind = n;
    // while(s.substr(eind-3, eind)=="WUB"){
    //     eind-=3;
    // }
    vector<string>ans;
    string tmp="";
    for(ind=0; ind<n; ind++){
        if(s.substr(ind, 3)=="WUB"){
            if(tmp!="")
            ans.push_back(tmp);
            tmp="";
            while(s.substr(ind, 3)=="WUB" && ind<n){
                ind+=3;
            }
            ind--;
        }
        else{
            tmp+=s[ind];
        }
    }
    for(auto a:ans)
        cout<<a<<" ";
    if(tmp!="")cout<<tmp;
    cout<<"\n";
    return 0;
}