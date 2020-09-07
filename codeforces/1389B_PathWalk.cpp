#include<iostream>
using namespace std;

#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){
    int64_t t;
    cin>>t;
    while(t--){
        int64_t n, k, z, p, mxp=0;
        cin>>n>>k>>z;
        int64_t A[n];
        for(int i=0; i<n; i++)cin>>A[i];
        int64_t tmp, ans=0, mx = 0, sum = 0;

        for(int i=0; i<k+1; i++){
            sum += A[i];
            if(i<n-1){
                mx = max(mx, A[i] + A[i+1]);
            }
            if((k-i)%2==0){
                tmp = (k-i)/2;
                if(tmp<=z){
                    ans = max(ans, sum + tmp * mx);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}