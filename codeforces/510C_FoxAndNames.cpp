#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<char> Ans;
vector<int>Alpha[26];
bool vis[26];
bool inStack[26];
bool ans = true;

void dfs(int cv){
    vis[cv] = 1;
    inStack[cv] = 1;
    for(auto v:Alpha[cv]){
        if(vis[v] == 0){
            dfs(v);
        }
        else{
            if(inStack[v] == 1){
                ans = false;
            }
        }
    }
    inStack[cv] = 0;
    Ans.push_back('a'+cv);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    string S[t];
    for(int i=0; i<t; i++){
        cin>>S[i];
    }
    int prev = S[0][0]-'a';
    int ch;
    for(int i=1; i<t; i++){
        
        ch = S[i][0]-'a';
        if(prev == ch){
            string s1 = S[i-1], s2=S[i];
            int j=0;
            while(j<min(s1.size(), s2.size())){
                if(s1[j] != s2[j]){
                    break;
                }
                j++;
            }
            if(j<min(s1.size(), s2.size())){
                Alpha[s1[j]-'a'].push_back(s2[j]-'a');
            }
            else{
                if(s1.size() > s2.size()){
                    ans = false;
                    break;
                }
            }
        }
        else{
            Alpha[prev].push_back(ch);
        }
        prev = ch;
    }
    memset(vis, 0, sizeof(vis));
    memset(inStack, 0, sizeof(inStack));
    for(int i=0; i<26; i++)if(vis[i] == 0){
        dfs(i);
    }
    if(ans){
        for(int i=Ans.size()-1; i>=0; i--){
            cout<<Ans[i];
        }
        cout<<"\n";
    }
    else{
        cout<<"Impossible\n";
    }
    return 0;
}