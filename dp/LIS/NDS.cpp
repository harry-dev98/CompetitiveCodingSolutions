#include<iostream>
#include<algorithm>
using namespace std;

int LIS(int A[], int n, int k){
    int I[n+1];
    for(int i=0; i<=n; i++){
        I[i] = INT32_MAX;
    }
    I[0] *= -1;
    int ptr, lis=1, minn = INT32_MAX;
    for(int i=0; i<n; i++){
        ptr = lower_bound(I, I+n+1, A[i]) - I;
        I[ptr] = A[i];
        if(ptr == k){
            minn = min(A[i], minn);
        }
    }
    return minn==INT32_MAX?-1:minn;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        cin>>k;
        cout<<LIS(A, n, k)<<"\n";
    }
    return 0;
}