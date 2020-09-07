#include<iostream>
#include<vector>
using namespace std;

void lcs(const string& s1, const string& s2, vector<string>& allLCS, string& LCS, int& maxLCS){
    int l1 = s1.size(), l2 = s2.size();
    int DP[l1+1][l2+1];

    for(int i=0; i<=l1; i++){
        for(int j=0; j<=l2; j++){
            if(i==0 || j==0)DP[i][j] = 0;
            else if(s1[i-1] == s2[j-1]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
    maxLCS = DP[l1][l2];
    for(int i=0; i<=l1; i++){
        for(int j=0; j<=l2; j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<"\n";
    }
    int i = l1, j = l2;
    LCS = "";
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            LCS = s1[i-1]+LCS;
            i--;j--;
            continue;
        }
        if(DP[i-1][j]>DP[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s1, s2;
    cin>>s1>>s2;
    string LCS;
    int maxLCS;
    vector<string>allS;
    lcs(s1, s2,allS, LCS, maxLCS);
    cout<<maxLCS<<" "<<LCS<<"\n";
    return 0;
}