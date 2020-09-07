#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int A[n], B[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        stack<int>S;
        S.push(n-1);
        B[n-1] = -1;
        for(int i=n-2; i>=0; i--){
            while(!S.empty()){
                if(A[S.top()] >= A[i]){
                    break;
                }
                else{
                    S.pop();
                }
            }
            if(!S.empty()){
                 B[i] = S.top();
            }
            else{
                B[i] = -1;
            }
            S.push(i);
        }
        int ans = 0;
        int _;
        for(int i=0; i<n;){
            if(B[i] == -1){
                _ = *min_element(A+i, A+n);
                ans += A[i] - _;
                break;
            }
            else{
                if(B[i+1] != -1){
                    _ = *min_element(A+i, A+B[i]);
                    ans += A[i] - _;
                }
                i = B[i]; 
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}