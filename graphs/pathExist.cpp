#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int G[21][21];
bool V[21][21];
int row[] = {-1, 0, 1, 0};
int col[] = {0, -1, 0, 1};
int N;

bool isValidPos(int x, int y){
    return (x>=0) && (y>=0) && (x<N) && (y<N);
}

bool isPath(int s_x, int s_y){
    cout<<s_x<<s_y<<endl;
    V[s_x][s_y]=true;
    bool ans = false;
    for(int i=0; i<4; i++){
        int x = s_x+row[i]; int y = s_y+col[i];
        if(isValidPos(x,y)){
            cout<<x<<y<<endl;
            if(G[x][y] == 2){
                return true;
            }
            if(G[x][y]==3 && !V[x][y]){
                ans = ans || isPath(x, y);
            }
        }
    }
    return ans;
}

int main(){
    SPEED;
    int t, s_x, s_y;
    cin>>t;
    while(t--){
        cin>>N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>G[i][j];
                if(G[i][j] == 1){
                    s_x = i;
                    s_y = j;
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<G[i][j];
            }
            cout<<"\n";
        }
        memset(V, 0, sizeof(V));
        if(isPath(s_x, s_y)){
            cout<<1<<"\n";
        }
        else{
            cout<<0<<"\n";
        }
    }
    return 0;
}