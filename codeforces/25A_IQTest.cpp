#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin>>n;
    vector<int> N(n);
    for(int& _: N)cin>>_;
    int flag[2];
    int even = 0;
    for(int i = 0; i < n; i++){
        flag[N[i]%2] = i;
        if(N[i]%2==0)even++;
    }
    cout<<1+(even==1?flag[0]:flag[1])<<"\n";
    return 0;
}