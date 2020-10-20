#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, temp;
	cin>>t;
	while(t--){
		cin>>n;
		temp = n;
		int noDig = -1, ans = 0;
		while(n){
			noDig++;
			n /= 10;
		}
		while(temp){
			ans += (temp%10) * pow(10, noDig);
            temp /= 10;
            noDig--;
        }
        cout<<ans<<"\n";
    }
    return 0;
}