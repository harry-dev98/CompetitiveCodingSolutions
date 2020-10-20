#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, rank, bug, ladus;
    string str, origin;
    cin>>t;
    while(t--){
        ladus = 0;
        cin>>n>>origin;
        while(n--){
            cin>>str;
            if(str == "CONTEST_WON"){
                cin>>rank;
                ladus += 300 + max(0, 20-rank);
            } else if (str == "TOP_CONTRIBUTOR"){
                ladus += 300;
            } else if (str == "BUG_FOUND"){
                cin>>bug;
                ladus += bug;
            } else {
                ladus += 50;
            }
        }
        cout<<ladus/(origin=="INDIAN"?200:400)<<"\n";
    }
    return 0;
}