#include<iostream>
using namespace std;

#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){
    SPEED;
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        n--;
        while(n>0 && A[n] <= A[n-1])n--;
        while(n>0 && A[n] >= A[n-1])n--;
        
        cout<<n<<"\n";
    }
}