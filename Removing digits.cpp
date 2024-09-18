#include<bits/stdc++.h>
using namespace std;

int main(){
	

	int n;
	cin>>n;
	vector<int>dp(n+1,1e6+1);

	dp[0]=0;
	for(int i=1;i<=n;i++){
		int m=i;
		while(m!=0){
			int r= m%10;
			dp[i] = min(dp[i] , dp[i-r]); 
			m = m/10;
		}
		dp[i] +=1;
	}
	cout<<dp[n];
	return 0;
}