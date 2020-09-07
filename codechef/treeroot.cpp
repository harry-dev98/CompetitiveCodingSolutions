#include<iostream>
#include<utility>
#include<set>
using namespace std;

#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second

int main(){
    speed;
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        pair<int,int> A[n+1];
        for(int i=1; i<=n; i++){
            cin>>A[i].first>>A[i].second;
        }
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum += A[i].first - A[i].second;
        }
        cout<<sum<<"\n";
    }
    return 0;
}