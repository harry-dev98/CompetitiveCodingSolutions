#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n;
    cin>>n;
    long long A[n][n];
    for(long long i=0; i<n; i++){
        for(long long j=0; j<n; j++){
            cin>>A[i][j];
        }
    }
    long long B[n], C[n];
    for(long long i=0; i<n; i++){
        cin>>B[i];
        B[i]--;
    }
    reverse(B, B+n);
    long long revitr = n, ans, _k, _i, _j;
    for(long long k=0; k<n; k++){
        _k = B[k];
        ans = 0;
        for(long long i=0; i<n; i++){
            _i = i;
            for(long long j=0; j<n; j++){
                _j = j;
                A[_i][_j] = min(A[_i][_j], A[_i][_k]+A[_k][_j]);
            }
        }
        for(long long i=0; i<=k; i++){
            _i = B[i];
            for(long long j=0; j<=k; j++){
                _j = B[j];
                ans += A[_i][_j];
            }
        }
        C[--revitr] = ans;
    }
    for(long long i=0; i<n; i++){
        cout<<C[i]<<" ";
    }
    cout<<"\n";
    return 0;
}