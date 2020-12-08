#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> Arr, int mid, int n, int k){
    long long s = 0;
    for(int i=n/2; i<n; i++){
        s += max(0, mid-Arr[i]);
    }
    return s <= k;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> Arr(n);
    for(int& a: Arr)cin>>a;
    sort(Arr.begin(), Arr.end());
    int low = Arr[n/2], high = INT32_MAX, mid;
    while(low<high){
        mid = low + (high-low+1)/2;
        // cout<<low<<mid<<high<<"\n";
        if(isValid(Arr, mid, n, k)){
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout<<low<<"\n";
    return 0;
}