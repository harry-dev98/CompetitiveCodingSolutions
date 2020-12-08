#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int itr = 0;
        vector<int> Ans(n);
        int f = -1;
        for(int i=1; i<=n; i++){
            Ans[i-1] = f*i;
            f *= -1;
        }
        if(k == n/2){
            //do nothing
        } else if(k < n/2) {
            int k_ = 0;
            int s = 0;
            for(int a: Ans){
                s+=a;
                if(s > 0)k_++;
                if(k == k_)break;
            }
            for(int i=2*k; i<n; i++)Ans[i] = -1*abs(Ans[i]);
        } else {
            int k_ = 0;
            for(int i=n-1; i>=0; i--){
                if(Ans[i] < 0){
                    Ans[i] *= -1;
                    k_++;
                }
                if(n/2 + k_ == k)break;
            }
        }
        for(int a: Ans)cout<<a<<" ";
        cout<<"\n";
    }
    return 0;
}