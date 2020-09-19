#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        vector<int> V(101, 0);
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++)cin>>A[i];
        for(int i=0; i<n; i++){
            V[A[i]]++;
        }
        int ans = -1;
        for(int i=0; i<=100; i++){
            if(V[i] == 0){
                if(ans == -1){
                    ans = i;
                }

                ans += i;
                break;    
            } else if(V[i] == 1){
                if(ans == -1){
                    ans = i;
                }
            } 
        }
        cout<<ans<<"\n";
    }
    return 0;
}