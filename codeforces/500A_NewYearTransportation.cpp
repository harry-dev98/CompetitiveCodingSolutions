#include<iostream>
using namespace std;

#define ___ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){
    ___;
    int n, t;
    cin>>n>>t;
    int A[n-1];
    bool ans = false;
    t--;
    for(int i=0; i<n-1; i++)cin>>A[i];
    for(int i=0; i<n; i++){
        if(i==t){
            ans = true;
        }
        i = i + A[i]-1;
    }
    cout<<(ans?"YES":"NO")<<"\n";
    return 0;
}