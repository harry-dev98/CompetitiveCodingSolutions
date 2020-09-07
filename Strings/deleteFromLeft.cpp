#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;
    int ptri= s1.length();
    int ptrj = s2.length();
    while(ptri>0&&ptrj>0){
        if(s1[ptri-1]==s2[ptrj-1]){
            ptri--;
            ptrj--;
        }
        else{
            break;
        }
    }
    cout<<ptri+ptrj<<"\n";
    return 0;
}