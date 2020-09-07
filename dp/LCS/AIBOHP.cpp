#include<iostream>
#include<algorithm>
using namespace std;
int lis(int A[], int n){
    int I[n+1];
    for(int i=0; i<n+1; i++)I[i] = 200009;
    I[0] *= -1;
    int lis=0, ptr;
    for(int i=0; i<n; i++){
        ptr = lower_bound(I, I+n+1, A[i]) - I;
        I[ptr] = A[i];
        lis = max(ptr, lis);
    }
    return lis;
}
int lcs(string s, string l){
    int len = s.length();
    int DP[2][len+1];
    for(int i=0; i<=len; i++){
        DP[0][i] = 0;
    }
    DP[1][0] = 0;
    int _ = 1;
    for(int i=1; i<=len; i++){
        for(int j=1; j<=len; j++){
            if(s[i-1] == l[j-1]){
                DP[_][j] = DP[1-_][j-1]+1;
            }
            else{
                DP[_][j] = max(DP[1-_][j], DP[_][j-1]);
            }
        }
        _ = 1 - _;
    }
    return DP[1-_][len];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string s, s_;
    cin>>t;
    while(t--){
        cin>>s;
        s_ = s;
        reverse(s_.begin(), s_.end());
        cout<<s.length()-lcs(s, s_)<<"\n";
    }
}