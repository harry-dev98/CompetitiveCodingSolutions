#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    string str;
    cin>>t;
    while(t--){
        cin>>n>>str;
        int nC = 0, nAC = 0, nB = 0;
        for(char ch: str){
            if(ch == '-')nB++;
            else if(ch == '>')nC++;
            else nAC++;
        }
        if(nC == 0 || nAC == 0){
            cout<<n<<"\n";
        } else {
            nB = 0;
            str += str[0];
			for(int i = 0;i < n;i++){
				if(str[i] == '-' || str[i+1] == '-') nB++;
			}
            cout<<nB<<"\n";
        }
    }
    return 0;
}