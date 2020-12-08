#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, d;
    cin>>t;
    while(t--){
        cin>>n>>d;
        int arr[2];
        arr[0]=d-1;
        arr[1]=d-1;
        vector<int> Age(n);
        for(int& a: Age)cin>>a;
        for(int a: Age){
            if(a>=80 || a <= 9)arr[0]++;
            else arr[1]++;
        }
        cout<<(arr[0]/d+arr[1]/d)<<"\n";
    }
    return 0;
}