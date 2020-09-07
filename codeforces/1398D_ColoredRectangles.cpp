#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool comp(int a, int b){
    return a>b;
}

int main(){
    int r, g, b;
    cin>>r>>g>>b;
    int R[r], G[g], B[b];
    int DP[r+1][g+1][b+1];
    for(int i=0; i<r; i++){
        cin>>R[i];
    }
    for(int i=0; i<g; i++){
        cin>>G[i];
    }
    for(int i=0; i<b; i++){
        cin>>B[i];
    }
    sort(R, R+r, comp);
    sort(G, G+g, comp);
    sort(B, B+b, comp);
    int ans = 0;
    memset(DP, 0, sizeof(DP));
    for(int i=0; i<=r; i++){
        for(int j=0; j<=g; j++){
            for(int k=0; k<=b; k++){
                if(i<r && j<g){
                    DP[i+1][j+1][k] = max(DP[i+1][j+1][k], DP[i][j][k]+R[i]*G[j]);
                }
                if(i<r && k<b){
                    DP[i+1][j][k+1] = max(DP[i+1][j][k+1], DP[i][j][k]+R[i]*B[k]);
                }
                if(j<g && k<b){
                    DP[i][j+1][k+1] = max(DP[i][j+1][k+1], DP[i][j][k]+B[k]*G[j]);
                }
                ans = max(ans, DP[i][j][k]);
            }
        }
    }
       cout<<ans<<'\n';
    return 0;
}