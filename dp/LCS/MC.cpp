#include<iostream>
using namespace std;


int lcs(const string& s1, const string& s2){
    int l1 = s1.size(), l2 = s2.size();
    int DP[2][l2+1];
    int ii = 1;
    for(int i=0; i<=l2; i++){
        DP[0][i] = 0;
    }
    DP[1][0] = 0;
    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            if(s1[i-1] == s2[j-1]){
                DP[ii][j] = 1 + DP[1-ii][j-1];
            }
            else{
                DP[ii][j] = max(DP[1-ii][j], DP[ii][j-1]);
            }
        }
        ii = 1 - ii;
    }
    return DP[1-ii][l2];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    while(1){
        cin>>s1;
        if(s1=="#")break;
        cin>>s2;
        int l = lcs(s1, s2);
        cout<<(s1.size()-l)*15+(s2.size()-l)*30<<"\n";
    }
    return 0;
}