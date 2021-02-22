#include<bits/stdc++.h>
using namespace std;
int MEX(set<int>s)
{
	set<int>::iterator it;
	int x=*(s.begin());
	//cout<<x<<" ";
	if(x>0)
	return 0;
	for(it=s.begin();it!=s.end();it++)
	{
		if(x==*(it))
		x++;
		else
		return x;
		//cout<<x<<" ";
	}
	//cout<<endl;
	return x;
}
vector<int> process(vector<vector<int> >&lis,vector<int>&v)
{
	
	vector<int>a(v.size(),-1);
//	for(int i=0;i<=v.size();i++)
//	cout<<a[i]<<" ";
//	cout<<endl;
	for(int i=0;i<v.size();i++)
	{
		int x=v[i];
		set<int>s;
		for(int j=0;j<lis[x-1].size();j++)
		{
			s.insert(a[lis[x-1][j]-1]);
	    }
//	    set<int>::iterator it;
//	    for(it=s.begin();it!=s.end();it++)
//		{
//		   cout<<*it<<" ";
//		}
	//	cout<<endl;
	    x=MEX(s);
	  //  cout<<x<<endl;
	    a[v[i]-1]=x;
	}
	return a;
}
int main()
{
   int t;
   cin>>t;
   for(int k=0;k<t;k++)
   {
		int n;
		cin>>n;
		vector<vector<int > >lis(n);
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			lis[x-1].push_back(y-1);
			lis[y-1].push_back(x-1);
		}
	//	cout<<"p1";
		vector<int>v;
		for(int i=1;i<=n;i++)
			{
				v.push_back(i);
			}
	    vector<vector<int > >ans;
		ans.push_back(process(lis,v));
	
		while(next_permutation (v.begin(), v.end()))
			{
				vector<int>a=process(lis,v);
				int f=0;
				for(int i=0;i<ans.size();i++)
				{
					if(a==ans[i])
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					ans.push_back(a);
				}
				
			}
		cout<<ans.size()<<endl;
  
  }
	return 0;
}