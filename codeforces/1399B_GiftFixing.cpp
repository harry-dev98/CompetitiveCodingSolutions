#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int C[n], O[n];
        for(int i=0; i<n; i++)cin>>C[i];
        for(int i=0; i<n; i++)cin>>O[i];
        int minC = *min_element(C, C+n);
        int minO = *min_element(O, O+n);
        int t1, t2;
        long long moves = 0;
        for(int i=0; i<n; i++){
            t1 = max(0, C[i]-minC);
            t2 = max(0, O[i]-minO);
            moves += max(t1, t2);
        }
        cout<<moves<<"\n";
    }
    return 0;
}