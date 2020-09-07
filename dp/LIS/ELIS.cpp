#include<iostream>
#include<algorithm>
using namespace std;

int LIS(int A[], int n){
    int I[n+1];
    for(int i=0; i<=n; i++)I[i] = INT32_MAX;
    I[0] = INT32_MIN;
    int ptr, lis = 1;
    for(int i=0; i<n; i++){
        ptr = lower_bound(I, I+n+1, A[i])-I;
        I[ptr] = A[i];
        lis = max(ptr, lis);
    }
    return lis;
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)cin>>A[i];
    cout<<LIS(A, n)<<"\n";
    return 0;
}