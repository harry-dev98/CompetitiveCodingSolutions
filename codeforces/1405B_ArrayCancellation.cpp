#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        long long A[n];
        for(int i=0; i<n; i++)cin>>A[i];
        long long _neg=0, _pos=0;
        for(int i=n-1; i>=0; i--){
            if(A[i]<0){
                _neg += A[i];
            }
            else{
                _neg += A[i];
                _pos += max((long long)0, _neg);
                _neg = min((long long)0, _neg);
            }
        }
        cout<<_pos<<"\n";
    }
    return 0;
}