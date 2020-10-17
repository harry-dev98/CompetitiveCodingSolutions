#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, l;
    cin>>t;
    while(t--){
        cin>>n>>l;
        vector<double> Flags(n);
        vector<double> Time1(n), Time2(n);
        for(auto& f: Flags)cin>>f;
        Time1[0] = Flags[0];
        double speed = 1.0;
        for(int itr=1; itr<n; itr++){
            speed += 1.0;
            Time1[itr] = Time1[itr-1] + (Flags[itr]-Flags[itr-1])/speed;
        }
        Time2[n-1] = (l-Flags[n-1]);
        speed = 1.0;
        for(int itr=n-2; itr>=0; itr--){
            speed += 1.0;
            Time2[itr] = Time2[itr+1] + (Flags[itr+1]-Flags[itr])/speed;
        }
        int afterMeetFlag = -1;
        for(int itr=0; itr<n; itr++){
            if(Time1[itr] >= Time2[itr]){
                afterMeetFlag = itr;
                break;
            }
        }
        if(afterMeetFlag == -1){
            double diffTime = Time1[n-1];
            double extraDisTraveled = diffTime;
            cout<<fixed<<setprecision(6)<<Time1[n-1] + (((l - Flags[n-1]) - extraDisTraveled)/(n+2))<<"\n";

        } else if(Time1[afterMeetFlag] == Time2[afterMeetFlag])cout<<fixed<<setprecision(15)<<Time1[afterMeetFlag]<<"\n";
        else {
            double diffTime = Time2[afterMeetFlag] - Time1[afterMeetFlag-1];
            double extraDisTraveled = (afterMeetFlag+1) * diffTime;
            cout<<fixed<<setprecision(6)<<Time2[afterMeetFlag] + ((Flags[afterMeetFlag] - (Flags[afterMeetFlag-1] + extraDisTraveled))/(n+2))<<"\n"; 
        }
    }
    return 0;
}