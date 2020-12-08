#include<bits/stdc++.h>
using namespace std;

int main(){
    int d1, v1, d2, v2, p;
    cin>>d1>>v1>>d2>>v2>>p;
    int days = 0;
    int vacc = 0;
    while(vacc < p){
        days++;
        if(days>=d1)vacc+=v1;
        if(days>=d2)vacc+=v2;
    }
    cout<<days<<"\n";
    return 0;
}