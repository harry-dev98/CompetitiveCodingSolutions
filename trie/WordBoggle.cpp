#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define w(x) while(x--)

typedef struct node{
    unordered_map<char, node*>data;
    bool isEOW = false;
}* ptr;

void insert(ptr t, string s){
    int n = s.length();
    for(int i=0; i<n; i++){
        auto itr = t->data.find(s[i]);
        if(itr == t->data.end()){
            t->data[s[i]] = new node;
        }
        t = t->data[s[i]];
    }
    t->isEOW = true;
}

int X[] = {1, 1, 1, -1, -1, -1, 0, 0};
int Y[] = {1, -1, 0, 1, -1, 0, 1, -1};

void dfs(ptr t, vector<vector<char>>A, vector<vector<bool>>vis, int x, int y, int n, int m, vector<string>&S, string s){
    if(t->isEOW){
        S.pb(s);
    }
    vis[x][y] = 1;
    for(int i=0; i<8; i++){
        int x_ = x+X[i];
        int y_ = y+Y[i];
        if(x_>=0 && x_<n && y_>=0 && y_<m){
            if(vis[x_][y_] == 0){
                char c = A[x_][y_];
                if(t->data.find(c) != t->data.end()){
                    if(s[0] == 's')cout<<s<<" + "<<c<<" === ("<<x_<<" "<<y_<<")\n";
                    dfs(t->data[c], A, vis, x_, y_, n, m, S, s+c);
                }
            }
        }
    }
    // vis[x][y] = 0;
    if(s[0] == 's')cout<<s<<" ends\n";
}

void dfs(ptr t, string s=""){
    if(t->isEOW){
        cout<<s<<"\n";
    }
    for(auto itr:t->data){
        dfs(itr.second, s+itr.first);
    }
}

int main(){
    SPEED;
    int t;
    cin>>t;
    w(t){
        ptr t = new node;
        int x;
        cin>>x;
        string s;
        for(int i=0; i<x; i++){
            cin>>s;
            insert(t, s);
        }
        int n, m;
        cin>>n>>m;
        vector<vector<char>>A(n, vector<char>(m));
        for(int i=0; i<n; i++)for(int j=0; j<m; j++)cin>>A[i][j];
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++)for(int j=0; j<m; j++){
            auto itr = t->data.find(A[i][j]);
            if(itr != t->data.end()){
                v.push_back({i, j});
            }
        }

        vector<string> ans;
        // dfs(t);
        for(auto itr:v){
            vector<vector<bool>> vis(n, vector<bool>(m, 0));
            int x_=itr.fi, y_=itr.se;
            // cout<<A[x_][y_]<<endl;
            s="";
            dfs(t->data[A[x_][y_]], A, vis, x_, y_, n, m, ans, s+A[x_][y_]);
        }
        sort(ans.begin(), ans.end());
        for(auto a:ans){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}