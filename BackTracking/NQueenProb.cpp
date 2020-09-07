#include<bits/stdc++.h>
using namespace std;
#define N 11
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

bool isValid(int i, int j, unordered_map<int, int> row){
    bool val = true;
    for(auto itr = row.begin(); itr != row.end(); itr++){
        int c = itr->first;
        int r = itr->second;
        // cout<<"this -> ("<<i<<" "<<j<<")\n";
        // cout<<"old -> ("<<c<<" "<<r<<")\n";
        val = val && (r != j);
        // cout<<"val is "<<val<<endl;
        int m = 1, cnst;
        for(int a=0; a<2; a++){
            cnst = r - m*c;
            // cout<<"eq -> y = "<<m<<"*x + "<<cnst<<endl;
            val = val && (j != m*i + cnst);
            // cout<<"val is "<<val<<endl;
            m = -1;
        }
        // if(!val)return false;
    }
    // cout<<"done\n";
    return (row.find(i) == row.end()) && val;
}

void nQueen(int n, vector<string> &V, unordered_map<int, int> &row, string str=""){
    if(row.size() == n){
        V.push_back(str);
        return;
    }
    // cout<<"string "<<str<<endl;
    int col = row.size();
    for(int i=0; i<n; i++){
        // cout<<i<<" == i\n";
        if(isValid(col, i, row)){
            // cout<<"isval\n";
            row[col] = i;
            char ch = (i) + '0';
            nQueen(n, V, row, str+ch);
            row.erase(col);
        }
    }
    // cout<<endl;

}

int main(){
    SPEED;
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string> V;
        unordered_map<int, int> row;
        nQueen(n, V, row);
        if(V.size() == 0){
            cout<<-1<<"\n";
        }
        else{
            for(auto itr = V.begin(); itr!=V.end(); itr++){
                cout<<"[";
                string s = *itr;
                for(int i=0; i<s.length(); i++){
                    int ans = s[i]-'0';
                    cout<<++ans<<" ";
                }
                cout<<"] ";
            }
        cout<<"\n";
        }
    }
}