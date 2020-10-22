#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, x, n;
    string str;
    cin>>t;
    while(t--){
        cin>>str>>x;
        n = str.length();
        vector<char> ans(n, '1');
        bool isAns = true, one, two;
        for(int i=0; i<n; i++){
            if(str[i] == '0'){
                if(i - x >= 0){
                    ans[i-x] = '0';
                }
                if(i + x < n){
                    ans[i+x] = '0';
                }
            }
        }
        for(int i=0; i<n; i++){
            one = false; two = false;
            if(str[i] == '1'){
                if(i-x>=0){
                    if(ans[i-x] == '1')one=true;
                }
                if(i+x<n){
                    if(ans[i+x] == '1')two=true;
                }
            }
            if(one || two){
                if(str[i] != '1'){
                    isAns = false;
                }
            } else {
                if(str[i] != '0'){
                    isAns = false;
                }
            }
        }
        if(isAns){
            for(char c: ans)cout<<c;
            cout<<"\n";
        } else{
            cout<<-1<<"\n";
        }
    }
    return 0;
}