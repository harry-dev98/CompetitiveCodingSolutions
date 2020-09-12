#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        vector<int> V(100, 0);
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++)cin>>A[i];
        for(int i=0; i<n; i++){
            V[A[i]]++;
        }
        int ans = 0;
        for(int i=0; i<100; i++){
            if(V[i]==1){
                if(ans == 0){
                    ans+=i;
                }
                else{
                    ans += i;
                    break;
                }
            }
            else if(V[i] == 0){
                if(ans == 0){
                    ans += 2*i;
                }
                else{
                    ans += i;
                }
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}