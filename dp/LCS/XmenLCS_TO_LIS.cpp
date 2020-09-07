#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int LIS(int A[], int n){
    int I[n+1];
    for(int i=0; i<=n; i++)I[i] = 100007;
    I[0] *= -1;
    int ptr, lis = 0;
    for(int i=0; i<n; i++){
        ptr = lower_bound(I, I+n+1, A[i])-I;
        I[ptr] = A[i];
        lis = max(lis, ptr);
    }
    return lis;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int A[n], B[n], C[n];
        for(int i=0; i<n; i++)cin>>A[i];
        for(int i=0; i<n; i++)cin>>B[i];
        unordered_map<int, int> M;
        for(int i=0; i<n; i++){
            M[A[i]] = i;
        }
        for(int i=0; i<n; i++){
            C[i] = M[B[i]];
        }
        cout<<LIS(C, n)<<"\n";
    }
    return 0;
}