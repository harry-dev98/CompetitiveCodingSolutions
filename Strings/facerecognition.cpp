#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    string twobytwo;
    char P[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>P[i][j];
        }
    }
    int ans=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            twobytwo = "";
            twobytwo += P[i][j];
            twobytwo += P[i+1][j];
            twobytwo += P[i+1][j+1];
            twobytwo += P[i][j+1];
            sort(twobytwo.begin(), twobytwo.end());
            if(twobytwo=="acef"){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}