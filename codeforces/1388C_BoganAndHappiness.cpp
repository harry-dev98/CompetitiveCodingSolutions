#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5+7;
vector<int>G[N];
int P[N], H[N];

bool dfs(int cv, int p=-1){
    int gdMoodChildern = 0;
    bool ans = true;
    for(auto v:G[cv]){
        if(v == p)continue;
        ans = ans && dfs(v, cv);
        P[cv] += P[v];
        gdMoodChildern += (P[v]+H[v])/2;
    }
    int _ = (P[cv] + H[cv]);
    if(_%2==1 || _<0 || (_/2)<gdMoodChildern || _/2 > P[cv]){
        return false;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        bool ans = true;
        int n, m, x, y;
        cin>>n>>m;
        for(int i=0; i<n; i++)cin>>P[i];
        for(int i=0; i<n; i++)cin>>H[i];
        for(int i=0; i<n-1; i++){
            cin>>x>>y;
            x--; y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        ans = ans && dfs(0);
        cout<<(ans?"YES":"NO")<<"\n";
        for(int i=0; i<n; i++)G[i].clear();
    }
    return 0;
}