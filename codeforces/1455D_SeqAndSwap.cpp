#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<int> A(n);
        for(int i=0; i<n; i++)cin>>A[i];
        vector<int> A_Dash(A);
        bool f = true;
        int ans = 0;
        if(is_sorted(A.begin(), A.end())){
            cout<<0<<"\n";
        } else {
            for(int i=0; i<n; i++){
                if(A[i] > x){
                    swap(A[i], x);
                    ans++;
                }
                if(is_sorted(A.begin()+i, A.end())){break;}
            }
            if(is_sorted(A.begin(), A.end()))cout<<ans<<"\n";
            else cout<<-1<<"\n";
        }
    }
    return 0;
}