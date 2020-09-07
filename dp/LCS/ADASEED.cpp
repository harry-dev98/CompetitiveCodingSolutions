#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int lis(int A[], int n){
    int I[n+1];
    for(int i=0; i<n+1; i++)I[i] = 200009;
    I[0] *= -1;
    int lis=0, ptr;
    for(int i=0; i<n; i++){
        ptr = lower_bound(I, I+n+1, A[i]) - I;
        I[ptr] = A[i];
        lis = max(ptr, lis);
    }
    return lis;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int A[n], B[n], C[n];
        for(int i=0; i<n; i++)cin>>A[i];
        for(int i=0; i<n; i++)cin>>B[i];
        queue<int> Q[m];
        for(int i=0; i<n; i++){
            Q[A[i]].push(i);
        }
        for(int i=0; i<n; i++){
            C[i] = Q[B[i]].front();
            Q[B[i]].pop();
        }
        cout<<2*(n-lis(C, n))<<"\n";
    }
    return 0;
}