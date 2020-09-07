
#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++
char MOV[] = {'D', 'U', 'R', 'L'};
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

bool isValid(int x, int y, int n, int m[MAX][MAX]){
    return x>=0 && y>=0 && x<n && y<n && m[x][y]==1;
}

bool _util(int m[MAX][MAX], int n, vector<string> &V, int x, int y, string str=""){
    if(x == n-1 && y == n-1){
        V.push_back(str);
        return true;
    }
    int newX, newY;
    bool ret;
    m[x][y] *= -1;
    for(int i=0; i<4; i++){
        newX = x + X[i];
        newY = y + Y[i];
        if(isValid(newX, newY, n, m)){
            cout<<newX<<newY<<endl;
            ret |= _util(m, n, V, newX, newY, str+MOV[i]);
        }
    }
    m[x][y] *= -1;
    return ret;
    
}

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> V;
    if(isValid(0, 0, n, m)){
        _util(m, n, V, 0, 0, "");
    }
    return V;
}
