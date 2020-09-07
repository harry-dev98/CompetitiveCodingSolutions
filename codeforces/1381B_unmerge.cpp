#include<iostream>
#include<stack>

using namespace std;

int main(){
    int t, n, N;
    cin>>t;
    while(t--){
        cin>>n;
        N = 2*n;
        int A[N], PreP[N];
        for(int i=0; i<N; i++)cin>>A[i];
        stack<int> S;
        PreP[N-1] = N;
        S.push(N-1);    
        for(int i=N-2; i>=0; i--){
            while(!S.empty()){
                if(A[i] > A[S.top()]){
                    S.pop();
                }
                else{break;}
            }
            PreP[i] = S.empty()?N:S.top();
            S.push(i);
        }   
        // for(int i=0; i<N; i++)cout<<PreP[i]<<" ";
        // cout<<endl;
        int tmp, itr = 0, n1 = n, n2 = n;
        while(itr<N){
            tmp = PreP[itr];
            while(n1-PreP[tmp]+itr>=0 && tmp<N){
                tmp = PreP[tmp];
                // cout<<tmp<<endl;
            }
            n1 -= tmp-itr;
            // cout<<itr<<" "<<tmp<<" "<<n1<<" "<<n2<<endl;
            swap(n1, n2);
            itr = tmp;
        }
        if(n1==0 && n2 == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}