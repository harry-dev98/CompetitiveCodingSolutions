#include<iostream>
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
        int x, y, z;
        x = A[0];
        y = A[1];
        z = A[n-1];
        if(x+y<=z){
            cout<<1<<" "<<2<<" "<<n<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
    return 0;
}