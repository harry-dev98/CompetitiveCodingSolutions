#include<iostream>
using namespace std;

#define fst ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){
    fst;
    int n, m;
    cin>>n>>m;
    int A[m];
    for(int i=0; i<m; i++)cin>>A[i];
    long long ans = 0;
    int ptr = 1;
    for(int i=0; i<m; i++){
        ans += (ptr<=A[i])?A[i] - ptr: n - (ptr-A[i]);
        ptr = A[i];
    }
    cout<<ans<<"\n";
    return 0;
}