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
        string s;
        vector<int>A(26, 0);
        for(int i=0; i<n; i++){
            cin>>s;
            for(char ch:s){
                int ind = ch - 'a';
                A[ind]++;
            }
        }
        bool ans = true;
        for(int _: A){
            if(_%n!=0){
                ans = false;
                break;
            }
        }
        cout<<(ans?"YES":"NO")<<"\n";
    }
    return 0;
}