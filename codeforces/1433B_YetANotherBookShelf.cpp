#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>Books(n);
        for(int& b:Books)cin>>b;
        int ans = 0;
        int zeros = 0;
        for(int b: Books){
            if(b == 0){
                zeros++;
            }
        }
        for(int i=0; i<n; i++){
            if(Books[i] == 1)break;
            ans--;
        }

        for(int i=n-1; i>=0; i--){
            if(Books[i] == 1)break;
            ans--;
        }
        cout<<ans+zeros<<"\n";
    }
    return 0;
}