#include<bits/stdc++.h>
using namespace std;

string longestPali(string str){
    int n = str.length();
    int DP[n][n];
    memset(DP, 0, sizeof(DP));
    int start = 0;
    int mxx = 1;
    for(int i=0; i<n; i++){
        DP[i][i] = 1;
        if(str[i] == str[i+1]){
            DP[i][i+1] = 1;
            if(2>mxx){
                start = i;
                mxx = 2;
            }
        }
    }
    int j;
    for(int k=3; k<=n; ++k){
        for(int i=0; i<n-k+1; ++i){
            j = i+k-1;
            // cout<<i<<j<<endl;
            // cout<<str.substr(i,j+1)<<" "<<str[i]<<str[j]<<j-i<<endl;
            if(str[i] == str[j] && DP[i+1][j-1]){
                DP[i][j] = 1;
                if((k)>mxx){
                    start = i;
                    mxx = k; 
                    // cout<<mxx<<" -- "<<str.substr(start, start+mxx)<<endl;
                }
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=i; j<n; j++){
    //         cout<<DP[i][j]<<" ";
    //     }
    //     cout<<endl;
    //     }
    string ans = "";
    for(int i=start; i<start+mxx; i++){
        ans+=str[i];
    }
    return ans;
    // return str.substr(start, start+mxx);
}

int main(){
    int t;cin>>t;
    string str;
    while(t--){
        cin>>str;
        cout<<longestPali(str)<<"\n";
    }
    return 0;
}