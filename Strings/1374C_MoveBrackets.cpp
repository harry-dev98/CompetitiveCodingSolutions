#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, openB, closeB;
    cin>>t;
    string s;
    char c;
    pair<char, int> P={' ', 0};
    while(t--){
        cin>>n>>s;
        openB=0;closeB=0;
        if(s[0] == ')')closeB++;
        else openB++;
        P = {s[0], 1};
        for(int i=1; i<n; i++){
            c = s[i];
            if(P.second == 0) P = {c, 0};
            if(c == P.first){
                P.second++;
            } 
            else{
                if(P.first == ')'){
                    closeB += P.second;
                    P = {c, 1};
                }
                else{
                    P.second--;
                }
            }
            // cout<<P.first<<P.second<<endl; 
        }
        if(P.first == ')')closeB+=P.second;
        else openB+=P.second;
        cout<<min(openB, closeB)<<"\n";
    }
    return 0;
}