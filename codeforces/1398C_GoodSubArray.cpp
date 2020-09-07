#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        int A[n+1];
        A[0] = 0;
        for(int i=1; i<=n; i++){
            A[i] = A[i-1] + (s[i-1] - '0');
        }
        int ans = 0, k;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=n; j++){
                k = j-i-1;
                if(i + 1 == A[j] - A[k]){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}