#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, P;
    cin>>N>>P;
    vector<int> Cost(N+1), Pages(N+1);
    Cost[0]=0;
    Pages[0]=0;
    for(int c=1; c<=N; c++)cin>>Cost[c];
    for(int p=1; p<=N; p++)cin>>Pages[p];
    vector<vector<int>> MaxPages(N+1, vector<int>(P+1, 0));
    for(int i=1; i<=N; i++){
        for(int j=0; j<=P; j++){
            MaxPages[i][j] = (j>=Cost[i])?max(MaxPages[i-1][j], MaxPages[i-1][j-Cost[i]]+Pages[i]): MaxPages[i-1][j];
        }
    }
    cout<<MaxPages[N][P]<<"\n";
    return 0;
}