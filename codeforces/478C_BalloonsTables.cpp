#include<bits/stdc++.h>
using namespace std;

int main(){
    long long arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr, arr+3);
    long long ans = min(arr[0] + arr[1], (arr[0]+arr[1]+arr[2])/3);
    cout<<ans<<"\n";
}