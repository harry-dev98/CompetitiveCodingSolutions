#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int LIS(vector<int> A){
    int n = A.size();
    int I[n+1];
    for(int i=0; i<n+1; i++)I[i] = 200009;
    I[0] *= -1;
    int lis=0, ptr;
    for(int i=0; i<n; i++){
        ptr = lower_bound(I, I+n+1, A[i]) - I;
        I[ptr] = A[i];
        lis = max(ptr, lis);
    }
    return lis;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s1, s2;
    cin>>s1>>s2;
    queue<int> Q[26];
    vector<int> C;
    for(int i=0; i<s1.length(); i++){
        Q[s1[i]-'a'].push(i);
    }
    for(int i=0; i<s2.length(); i++){
        if(!Q[s2[i]-'a'].empty()){
            C.push_back(Q[s2[i]-'a'].front());
            Q[s2[i]-'a'].pop();
        }
    }
    cout<<LIS(C)<<"\n";
}