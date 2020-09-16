#include<bits/stdc++.h>
using namespace std;
char G[101][101];
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

void fill(int a, int b, int n, int m, char filler){
    G[a][b] = filler;
    for(int i=0; i<4; i++){
        int x = a + X[i];
        int y = b + Y[i]; 
        if(x>=0 && x<n && y>=0 && y<m){
            if(G[x][y] == '.'){
                fill(x, y, n, m, (filler=='B'?'W':'B'));
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>G[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(G[i][j] == '.'){
                fill(i, j, n, m, 'B');
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<G[i][j];
        }
        cout<<"\n";
    }
    return 0;
}