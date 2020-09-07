#include<iostream>
#include<cstring>
#include<math.h>
#include<vector>
#include<unordered_set>
using namespace std;

#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){
    int t, n;
    speed;
    cin>>t;
    bool A[200001];
    memset(A, 1, sizeof(A));
    for(int i=2; i<sqrt(200001); i++){
        if(A[i] == true){
            for(int j=i*i; j<200001; j+=i){
                A[j] = false;
            }
        }
    }
    while(t--){
        cin>>n;
        int sum = 0;
        vector<int>S;
        for(int i=2; i<=n; i++){
            if(A[i]==false){
                for(int x=2; x<=sqrt(i); x++){
                    if(i%x == 0 && A[x] && A[i/x] && x*x != i){
                        S.push_back(i);
                    }
                }
            }
            if(S.size()>6)break;
        }
        if(S.size()<3){
            cout<<"NO\n";
        }
        else{
            unordered_set<int>set;
            int rem;
            for(int c=0; c<S.size(); c++){
                set = {S[0], S[1], S[c+2]};
                sum = S[0] + S[1] + S[c+2];
                rem = n-sum;
                if(rem <= 0){
                    cout<<"NO\n";
                    break;
                }
                set.insert(rem);
                if(set.size() == 4){
                    cout<<"Yes\n";
                    for(auto z:set){
                        cout<<z<<" ";
                    }
                    cout<<"\n";
                    break;
                }           
                set.erase(S[c+2]);
            }
        }
    }
    return 0;
}