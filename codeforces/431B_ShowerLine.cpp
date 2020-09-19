#include<bits/stdc++.h>
using namespace std;
int A[6][6];

int solve(){
    int num[] = {1, 2, 3, 4, 5};
    int ans = 0;
    do{
        // int _ = (A[num[0]][num[1]] + A[num[1]][num[0]]+ A[num[1]][num[2]] + A[num[2]][num[1]]);
        // _ += 2*(A[num[2]][num[3]] + A[num[3]][num[2]] + A[num[3]][num[4]] + A[num[4]][num[3]]);
        int tmp = A[num[0]][num[1]] + A[num[1]][num[0]];
        tmp += A[num[2]][num[3]] + A[num[3]][num[2]];
        
        //1234
        tmp += A[num[1]][num[2]] + A[num[2]][num[1]];
        tmp += A[num[3]][num[4]] + A[num[4]][num[3]];
        
        //234
        tmp += A[num[2]][num[3]] + A[num[3]][num[2]];
        
        //34
        tmp += A[num[3]][num[4]] + A[num[4]][num[3]];
        ans = max(ans, tmp);
    } while(next_permutation(num, num+5));
    return ans;
}
int main(){
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            cin>>A[i][j];
        }
    }

    int ans = solve();
    cout<<ans<<"\n";
    return 0;
}