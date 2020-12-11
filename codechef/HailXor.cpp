#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, n, x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<vector<long long>>arr(n, vector<long long>(32, -1));
        vector<long long> A(n), hlpr(32, -1);
        for(long long& a: A)cin>>a;
        for(long long i=n-1; i>=0; i--){
            for(long long shift=31; shift>=0; shift--){
                arr[i][shift] = hlpr[shift];
                if(A[i] & (1<<shift)){
                    hlpr[shift] = i;
                }
            }
        }

        for(long long i=0; i<n-1; i++){
            for(long long bitpos=31; bitpos>=0; bitpos--){
                if(A[i] & (1<<bitpos)){
                    x--;
                    A[i] ^= (1<<bitpos);
                    if(arr[i][bitpos] != -1){
                        A[arr[i][bitpos]] ^= (1<<bitpos);
                    } else {
                        A[n-1] ^= (1<<bitpos);
                    }
                }
                if(x==0)break;
            }
            if(x==0)break;
        }
        if(n == 2 && x%2 == 1){
            A[n-1] ^= 1;
            A[n-2] ^= 1;
        }
        for(long long a: A)cout<<a<<" ";
        cout<<"\n";
    }
    return 0;
}