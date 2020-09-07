#include<bits/stdc++.h>
using namespace std;

const int INF = 1e7;
const int MAX = 101;

void FloydWarshal(int G[MAX][MAX], int Ans[MAX][MAX], int V){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            for(int k=0; k<V; k++){
                    Ans[j][k] = (Ans[j][i] + Ans[i][k]) < Ans[j][k] ? Ans[j][i] + Ans[i][k] : Ans[j][k];
            }
        }
    }
}

void printAns(int Ans[MAX][MAX], int V){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(Ans[i][j] == INF){
                cout<<"INF ";
            }
            else{
                cout<<Ans[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}

int main(){
    int G[MAX][MAX];
    int Ans[MAX][MAX];
    int V, x, y, w=1;
    cin>>V;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cin>>x;
            G[i][j] = x;
        }
    }
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(i == j){
                Ans[i][j] = 0;
            }
            else{
                if(G[i][j]==0){
                    Ans[i][j]=INF;
                    // cout<<G[i][j]<<Ans[i][j]<<"zero\n";
                }
                else{
                    // cout<<G[i][j]<<Ans[i][j]<<"not zero\n";
                    Ans[i][j]=G[i][j];
                }
            }
        }
    }
    FloydWarshal(G, Ans, V);
    printAns(Ans, V);
    cout<<"\n";
    return 0;
}




