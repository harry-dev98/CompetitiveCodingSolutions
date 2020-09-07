#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> G[10001];

int MinDieRolls(){
    int cv = 1;
    int dist[31];
    int ans = 1;
    for(int i=1; i<31; i++){
        dist[i] = ans;
        if(ans%6==0)ans++;
    }
    for(int i=1; i<31; i++){
        if(G[i].size()!=0){
            for(auto itr=G[i].begin(); itr!=G[i].end(); itr++){
                if(dist[*itr] > dist[i] && *itr>i){
                    dist[*itr] = dist[i];
                    
                    for(int i = *itr+1; i<*itr+6; i++){
                        if(i>30)break;
                        dist[i] = dist[*itr]+1;
                    }
                }
                cout<<i<<" - "<<*itr<<" :: "<<dist[*itr]<<endl;
            }
        }
    }
    return dist[30];
}

int main(){
    SPEED;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x, y;
        for(int i=0; i<n; i++){
            cin>>x>>y;
            G[x].push_back(y);
        }
        cout<<MinDieRolls()<<"\n";
    }        
}