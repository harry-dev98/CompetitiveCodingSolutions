#include<bits/stdc++.h>
using namespace std;

void updateBIT(int BIT[], int n, int i, int key){
    // BIT has index from 1 so.. 
    n++;i++;
    while(i<=n){
        // cout<<i<<" ";
        BIT[i] += key;
        i += (i & -i); 
    }
    // cout<<endl;
}

int getSumBIT(int BIT[], int n, int i){
    // BIT has index from 1 so..
    // n++; i++;
    int ans=0;
    while(i>0){
        // cout<<i<<" ";
        ans += BIT[i];
        i -= i & (-i);
    }
    // cout<<"ans is "<<ans<<endl;
    return ans;
}


int main(){
    int t;cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        int A[n], BIT[n+1];
        memset(BIT, 0, sizeof(BIT));
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        // build BIT
        for(int i=0; i<n; i++){
            updateBIT(BIT, n, i, A[i]);
        }
        for(int i=0; i<n+1; i++)
            cout<<BIT[i]<<", ";
        cout<<endl;
        int l, r;
        for(int i=0; i<q; i++){
            cin>>l>>r;
            cout<<getSumBIT(BIT, n, r) - getSumBIT(BIT, n, l)<<" ";
        }
        cout<<"\n";
    }
}