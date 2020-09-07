#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n+1];
        for(int i=1; i<=n; i++){
            cin>>A[i];
        }
        unordered_map<int, long long int> M;
        int j;
        for(int i=1; i<=n; i++){
            A[i] = (A[i]==1)?1:-1;
        }
        long long ans = 0;
        for(int i=2; i<=n; i++){
            A[i] += A[i-1];
            if(A[i] == 0){
                ans++;
            }
        }
        for(int i=1; i<=n; i++){
            if(M.find(A[i]) != M.end()){
                ans += M[A[i]];
            }
            M[A[i]]++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
