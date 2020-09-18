#include<bits/stdc++.h>
using namespace std; 
int main(){
    string s; 
    cin>>s;
    int ch[256];
    memset(ch, 0, sizeof(ch));
    for(auto c:s){
        ch[c]++;
    }
    int odd = 0;
    for(int i=0; i<255; i++){
        if(ch[i]%2==1)odd++;
    }
    if(odd == 0 || odd%2==1){
        cout<<"First";
    }
    else if(odd%2 == 0){
        cout<<"Second";
    }
    cout<<"\n";
    return 0;
}