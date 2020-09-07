#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++)cin>>A[i];
        sort(A, A+n);
        bool ans = true;
        for(int i=1; i<n; i++){
            if(A[i] - A[i-1] > 1){
                ans = false;
                break;
            }
        }
        cout<<(ans?"YES":"NO")<<"\n";
    }
    return 0;
}