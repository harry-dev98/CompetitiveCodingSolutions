#include<iostream>
#include<queue>
#include<cstring>
#include<utility>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pii pair<long long, long long>

long long t=0;
void dfs(long long cv, bool vis[], long long A[], long long B[], priority_queue<pii>& pq, int deptT[]){
    vis[cv] = 1;
    t++;
    if(B[cv] != -1){
        if(vis[B[cv]]==0){
            dfs(B[cv], vis, A, B, pq, deptT);
        }
    }
    t++;
    deptT[cv] = A[cv]>0?t:-t;
    pq.push({(deptT[cv]), cv});
}

int main(){
    long long n;
    cin>>n;
    long long A[n+1], B[n+1];
    for(long long i=0; i<n; i++){
        cin>>A[i+1];
    }
    for(long long i=0; i<n; i++){
        cin>>B[i+1];
    }
    bool vis[n+1];
    int deptT[n+1];
    memset(vis, 0, sizeof(vis));
    priority_queue<pii>pq;
    for(long long i=1; i<=n; i++){
        if(vis[i] == 0){
            dfs(i, vis, A, B, pq, deptT);
        }    
    }
    pii top;
    long long ans = 0;
    vector<long long>Ans; 
    memset(vis, 0, sizeof(vis));
    while(!pq.empty()){
        top = pq.top();
        pq.pop();
        if(vis[top.second]==0){
            ans += A[top.second];
            Ans.push_back(top.second);
            if(B[top.second] != -1){
                A[B[top.second]] += A[top.second];
                if(A[B[top.second]] > 0 && deptT[B[top.second]]<0){
                    pq.push({-deptT[B[top.second]], B[top.second]});
                }
            }
            vis[top.second] = 1;
        }
        // cout<<top.second<<"\n";
    }
    cout<<ans<<"\n";
    for(auto a:Ans){
        cout<<a<<" ";
    }
    cout<<"\n";
    return 0;
}