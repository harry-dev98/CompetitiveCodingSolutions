#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, sx, sy, dx, dy;
    cin>>t>>sx>>sy>>dx>>dy;
    string dir;
    cin>>dir;
    unordered_map<char, pair<int,int>> M={{'S',{0, -1}}, {'N', {0, 1}}, {'W', {-1, 0}}, {'E', {1, 0}}};
    int t_ = 0;
    bool ans = false;
    for(char ch: dir){
        if(sx == dx && sy == dy){
            ans = true;
            break;
        }
        int _x = M[ch].first;
        int _y = M[ch].second;
        if(abs(dx - (sx + _x)) < abs(dx - sx) || abs(dy - (sy + _y)) < abs(dy - sy)){
            // cout<<ch<<" "<<t_<<"\n";
            sx += _x;
            sy += _y;
        }
        t_++;
    }
    if(sx == dx && sy == dy){
        ans = true;
    }
    cout<<(ans?t_:-1)<<"\n";
    return 0;
}