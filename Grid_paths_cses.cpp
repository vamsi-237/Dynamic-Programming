#include<bits/stdc++.h>
using namespace std;


int main(){
	
	int n;
	cin>>n;
	vector<vector<char>>vec;
	vector<char>v;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char ele;
			cin>>ele;
			// cout<<ele<<" ";
			v.push_back(ele);
		}
		vec.push_back(v);
		v.clear();
		
	}
	if(vec[0][0]=='*' or vec[n-1][n-1]=='*'){
		cout<<0<<" ";
		return 0;
	}

	const unsigned int mod=1e9+7;

	vector<vector<int>>dp(n,vector<int>(n,0));

	for(int i=0;i<n;i++){
		if(vec[i][0]=='.') dp[i][0]=1;
		else{
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(vec[0][i]=='.') dp[0][i]=1;
		else {
			break;
		}

	}

	
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(vec[i][j]=='*') dp[i][j] = 0;
			else {
				int top=0,left=0;
				if(j>0) left  = dp[i][j-1];
				if(i>0) top=dp[i-1][j];
				dp[i][j] = (top+left)%mod;

			}
		}	
	}   


	cout<<dp[n-1][n-1];
	return 0;
}




