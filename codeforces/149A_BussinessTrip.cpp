#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    vector<int> Growth(12);
    for(int& _:Growth)cin>>_;
    sort(Growth.begin(), Growth.end());
    int k_ = 0, ans = 0;
    if(k_<k){
        for(int i = 11; i>=0; i--){
            k_ += Growth[i];
            ans ++;
            if(k_>=k){
                break;
            }
        }
    }
    cout<<(k_>=k?ans:-1)<<"\n";
    return 0;
}