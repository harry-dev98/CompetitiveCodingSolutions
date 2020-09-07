#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
long long int INF = 10e9 + 7;

long int S[100007]={};
long int I=2;
long int A, B, N, Q, l, r, tmp;

long int CalS(long int n){
    if(n <= I){
        return S[n];
    }
    S[n] = ((B%INF)*(CalS(n-1)%INF))%INF+((A%INF)*(CalS(n-2)%INF))%INF;
    return S[n];
}


int main(){
    SPEED;
    cin>>N>>Q;
    cin>>S[1]>>S[2];
    cin>>A>>B;
    long int arr[N+2]={}, arr_[N+2]={}, arr__[N+2]={}, arr_1[N+2]={};
    for(long int i=1; i<=N; i++){
        cin>>arr[i];
    }
    for(long int i=0; i<Q; i++){
        cin>>l>>r;
        arr_[l] += S[1];
        tmp = r-l+1;
        if(I<tmp){
            arr__[r] += -1 * CalS(tmp);
            I = tmp;
        }
        else{
            arr__[r] += -1 * S[tmp];
        }
        arr_1[r-1] += -1 * S[tmp-1];
    }
    // for(long int i=1; i<=N+1; i+x) cout<<arr_[i]<<" "<<arr__[i]<<") ";
    // cout<<endl;
    for(long int i=1; i<=N; i++){
        if(i==1){
            arr_[i]=arr_[i];
        }
        else if(i==2){
            arr_[i] += ((B%INF)*(arr_[i-1]%INF)%INF); 
        }
        else{
            arr_[i] += ((A%INF)*(arr_[i-2]%INF)%INF)+((B%INF)*(arr_[i-1]%INF))%INF;
        }
        arr[i] += arr_[i];
        arr_[i] += arr__[i];
        arr_[i-1] += arr_1[i-1];
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}