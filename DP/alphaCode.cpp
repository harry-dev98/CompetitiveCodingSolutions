#include<bits/stdc++.h>
using namespace std;

string s;
long long int DP[10000];
int n, x, y, z;
int main(){
    while(true){
        memset(DP, 0, sizeof(DP));
        cin>>s;
        if(s=="0"){
            break;
        }
        n = s.length();
        x = s[0]-'0';
        y = s[1]-'0';
        if(x==0 || (x>2&&y==0)){
            cout<<0<<"\n";
            continue;
        }
        DP[0] = 1;
        DP[1] = (y==0)?1:(x*10+y > 26)?1:2;
        for(int i=2; i<n; i++){
            x = s[i-1]-'0';
            y = s[i] - '0';
            z = 10*x+y;
            if(z==0 || (x>2&&y==0)){
                break;
            }
            // cout<<z<<" ";
            if(x<=2 && y==0){
                DP[i] = DP[i-2];
                continue;
            }
            DP[i] = (x==0)?DP[i-1]:(z>26)?DP[i-1]:DP[i-1]+DP[i-2];
            // cout<<s[i]<<" -> "<<DP[i]<<endl;
        }
        cout<<DP[n-1]<<"\n";
    }
    return 0;
}