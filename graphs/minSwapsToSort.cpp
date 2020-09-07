// { Driver Code Starts
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends


/* You are required to complete this method */

// return the minimum number of swaps required to sort the arra
int minSwaps(int arr[], int N){
    pair<int, int> sortedA[N];
    for(int i=0; i<N; i++){
        sortedA[i] = {arr[i], i};
    }
    sort(sortedA, sortedA+N);
    unordered_set<int> vis((arr), (arr+N));
    int cycle=0, ans=0;
    int cv = 0;
    while(cv!=-1){
        // cout<<cv<<endl;
        auto itr = vis.find(arr[cv]);
        if(itr != vis.end()){
            vis.erase(itr);
            cv = sortedA[cv].second;
            cycle++;
            
        }
        else{
            ans += cycle-1;
            cycle = 0;
            cv = -1;
            for(int i=0; i<N; i++){
                if(vis.find(arr[i]) != vis.end()){
                    cv = i;
                    break;
                }
            }

        }
    }
    return ans;
}
