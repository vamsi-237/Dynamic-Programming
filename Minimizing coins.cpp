#include<bits/stdc++.h>
using namespace std;
 
int coins(int n ,int sum , vector<int>vec){
	if(n==0) {
		if(sum%vec[0]==0) return sum/vec[0];
		else return 1e8;
	}
	int  not_pick = coins(n-1,sum,vec);
	int pick=  1e8;
	if(sum >= vec[n]){
		pick = 1 + coins(n,sum-vec[n], vec);
	}
	return min(pick,not_pick);
}

int main(){
	
	int n;
	int sum;
	cin>>n>>sum;
	vector<int>vec;
	for(int i=0;i<n;i++){
		int ele;
		cin>>ele;
		vec.push_back(ele);
	}
	vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
	for(int i =0;i<=sum;i++){
            if(i%vec[0]==0) dp[0][i] = i/vec[0];
            else dp[0][i] =1e7;
    }
    for(int i=1;i<n;i++){
        for(int  j=0;j<=sum;j++){
            int not_take = dp[i-1][j];
            int take=1e7;
            if(vec[i]<= j) take= 1 + dp[i][j-vec[i]];
            dp[i][j] = min(take,not_take);
        }
    }
    int x=dp[n-1][sum];
    if(x>=1e7) cout <<-1;
    else cout<<x;
	return 0;
}