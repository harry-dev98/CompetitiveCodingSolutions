#include<bits/stdc++.h>
using namespace std;

int G[101][101];
int N, M;

bool isValid(int x, int y){
    return (x>=0) && (y>=0) && (x<N) && (y<M);
}

//cp->current place..
void getIslands(int cp_x, int cp_y, bool vis[][101]){
    vis[cp_x][cp_y] = true;
    static int row[] = {-1, 0, 1};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(cp_x+row[i] == 0 && cp_y+row[j]==0){
                continue;
            }
            if(isValid(cp_x+row[i], cp_y+row[j])){
                if(G[cp_x+row[i]][cp_y+row[j]]==1 && !vis[cp_x+row[i]][cp_y+row[j]]){
                    getIslands(cp_x+row[i], cp_y+row[j], vis);
                }
            }
        }
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>N>>M;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>G[i][j];
            }
        }
        bool vis[101][101];
        int islands = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(!vis[i][j] && G[i][j]){
                    getIslands(i, j, vis);
                    islands++;
                }
            }
        }
        cout<<islands<<"\n";
    }
    return 0;
}
