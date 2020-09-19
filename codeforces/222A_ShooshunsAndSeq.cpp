#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> A(n);
    for(int& _: A)cin>>_;
    bool ans = true;
    for(int i=k; i<n; i++){
        if(A[i-1] == A[i])continue;
        ans = false;
        break;
    }
    int a_ = k-1;
    for(int i=k-1; i>0; i--){
        if(A[i] == A[i-1]){
            a_ = i;
            continue;
        }
        break;
    }
    cout<<(ans ? a_-1 : -1)<<"\n";
    return 0;
}