#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;string str;
    cin>>t;
    while(t--){ 
        cin>>str;
        int n = str.length();
        vector<int> Arr(256, 0);
        for(int i=0; i<(n)/2; i++){
            Arr[str[i]]++;
        }
        for(int i=(n+1)/2; i<n; i++){
            Arr[str[i]]--;
        }
        bool isAns = true;
        for(int a:Arr)if(a!=0)isAns = false;
        cout<<(isAns?"YES":"NO")<<"\n";
    }   
    return 0;
}