#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
int DP[100007];

int MinMoves(string s, int i){
    if(i >= s.length()){
        return 0;
    }
    if(DP[i] != 1000007)return DP[i];
    string s1 = s.substr(0, 2*i);
    string s2 = s.substr(0, i) + s.substr(0, i);
    // cout<<s1<<" "<<s2<<" "<<s1.compare(s2)<<endl;
    return DP[i] = 1 + min(MinMoves(s, i+1),(s1.compare(s2)==0)?MinMoves(s, 2*i):10000007);
}

int main(){
    SPEED;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        DP[0]=1;
        for(int i=0; i<=s.length(); i++)DP[i]=1000007;
        cout<<1+MinMoves(s, 1)<<"\n";
    }
    return 0;
}