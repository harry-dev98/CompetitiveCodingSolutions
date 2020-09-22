#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
vector<bool> IsPrime(N, 1);
int main(){
    IsPrime[0] = 0;
    IsPrime[1] = 0;
    for(int i=2; i*i<=N; i++){
        if(IsPrime[i]){
            for(int j=i*i; j<=N; j+=i){
                IsPrime[j] = 0;
            }
        }
    }
    int t;
    long long n;
    cin>>t;
    while(t--){
        cin>>n;
        string ans;
        if(sqrt(n) - (int)sqrt(n) == 0){
            int _ = (int)sqrt(n);
            if(IsPrime[_]){
                ans = "YES";
            }
            else{
                ans = "NO";
            }
        }
        else{
            ans = "NO";
        }
        cout<<ans<<"\n";
    }
    return 0;
}