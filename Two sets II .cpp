#include<bits/stdc++.h>
using namespace std;


int sets( int n,int sum){
	if(sum%2!=0) return 0;
	sum  = sum /2;
	
	vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
	const unsigned int mod=1e9+7;
	for(int i=0;i<=n;i++) dp[i][0] = 1;
	dp[0][1] = 1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=sum;j++){
			int take = dp[i-1][j];
			int not_take=0;
			if(j>=i ){
				not_take= dp[i-1][j-i];
			}
			dp[i][j] = (take+not_take)%mod;
		}
	}
	return dp[n][sum];

}
int main(){
	

	int n;
	cin>>n;
	int sum= n*(n+1)/2;
	int x=sets(n,sum);
	cout<<x;

	return 0;
}