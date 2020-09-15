#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin>>n>>k;
    long long mid = (n+1)/2;
    if(k > mid){
        k -= mid;
        cout<<k*2;
    }
    else{
        cout<<k*2-1;
    }
    cout<<"\n";
    return 0;
}