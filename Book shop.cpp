#include<bits/stdc++.h>
using namespace std;

int main(){
	

	int n;
	int sum;
	cin>>n>>sum;
	vector<int>price;
	vector<int>pages;
	for(int i=0;i<n;i++){
		int ele;
		cin>>ele;
		price.push_back(ele);
	}
	for(int i=0;i<n;i++){
		int ele;
		cin>>ele;
		pages.push_back(ele);
	}
	vector<vector<int>>dp(n,vector<int>(sum+1,0));
	for(int i=0;i<=sum;i++){
		if(i>=price[0]) dp[0][i] = pages[0];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=sum;j++){
			int not_pick= dp[i-1][j];
			int pick= -1;
			if(j>=price[i]){
				pick = dp[i-1][j-price[i]]+pages[i];
			}
			dp[i][j] = max(pick,not_pick);
		}
	}
	cout<<dp[n-1][sum];
	return 0;
}