#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>k>>s;
        bool ans = true;
        int ones, zeros;
        string ans_str = "";
        for(int i=0; i<k; i++){
            ones = 0; zeros = 0;
            for(int j=i; j<n; j+=k){
                if(s[j] == '0'){
                    zeros++;
                }
                else if(s[j] == '1'){
                    ones++;
                }
            }
            if(ones!=0 && zeros!=0){
                ans = false;
                break;
            }
            
            if(s[i] == '?'){
                ans_str += (zeros>0?'0':(ones>0)?'1':'?');
            }
            else{
                ans_str += s[i];
            }
        }
        ones = 0; zeros = 0;
        for(char ch:ans_str){
            if(ch == '1'){
                ones++;
            }
            else if(ch == '0'){
                zeros++;
            }
            
        }
        if(max(ones, zeros) > k/2){
            ans = false;
        }
        cout<<(ans?"YES":"NO")<<"\n";
    }
    return 0;
}