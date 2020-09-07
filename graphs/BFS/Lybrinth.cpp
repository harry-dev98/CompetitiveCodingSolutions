#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

#define pii pair<int, int>
#define pic pair<int, char>

int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };
char Dir[] = {'D', 'U', 'R', 'L'};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x = 0, y = 0;
    cin>>n>>m;
    char A[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
            if(A[i][j] == 'A'){
                x = i;
                y = j;
            }
        }
    }
    unordered_map<int, pic> M;
    queue<pii>Q;
    Q.push({x, y});
    A[x][y] = '#';
    int ans = -1;
    int a = x*m+y;
    while(!Q.empty()){
        pii front = Q.front();Q.pop();
        x = front.first;
        y = front.second;
        for(int i=0; i<4; i++){
            if(x+X[i]>=0 && x+X[i]<n && y+Y[i]>=0 && y+Y[i]<m){
                if(A[x+X[i]][y+Y[i]] == '.'){
                    Q.push({x+X[i], y+Y[i]});
                    M[(x+X[i])*m + (y+Y[i])] = {x*m+y, Dir[i]};
                    A[x+X[i]][y+Y[i]] = '#';
                }
                else if(A[x+X[i]][y+Y[i]] == 'B'){
                    ans = (x+X[i])*m + (y+Y[i]);
                    M[(x+X[i])*m + (y+Y[i])] = {x*m+y, Dir[i]};
                    Q = {};
                    break;
                }
            }
        }
    }
    if(ans != -1){
        cout<<"YES\n";
        string _ = "";
        while(ans != a){
            _ = M[ans].second + _;
            ans = M[ans].first;
        }
        cout<<_.size()<<"\n"<<_<<"\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}