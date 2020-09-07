#include<bits/stdc++.h>
using namespace std;


int kthSmallest(int A[], int l, int r, int k){
        
}

int main(){
    int n; 
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    int k;cin>>k;
    int ans = kthSmallest(A, 0, n, k);
    cout<<ans<<"\n";
    return 0;
}