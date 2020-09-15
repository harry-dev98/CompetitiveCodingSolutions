#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, _;
    cin>>n;
    int Days[7];
    for(int i=0; i<7; i++){
        cin>>Days[i];
    }
    for(int i=1; i<7; i++){
        Days[i] += Days[i-1];
    }
    n = n%Days[6];
    int ans;
    if(n == 0){
        int mx=0;
        for(int i=0; i<7; i++){
            if(Days[i] > mx){
                ans = i+1;
                mx = Days[i];
            }
        }
    }
    else{
        for(int i=0; i<7; i++){
            if(Days[i] >= n){
                ans = i+1;
                break;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}