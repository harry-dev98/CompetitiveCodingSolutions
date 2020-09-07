#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long long t, n, k, _;
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        _ = *max_element(A, A+n);
        for(int i=0; i<n; i++){
            A[i] = (long long)(_ - A[i]);
        }
        k--;
        if(k%2==0){
            for(long long i=0; i<n; i++){
                cout<<A[i]<<" ";
            }
        }
        else{
            _ = *max_element(A, A+n);
            for(long long i=0; i<n; i++){
                cout<<(long long)(_-A[i])<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}