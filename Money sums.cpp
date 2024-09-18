#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	vector<int>vec;
	for(int i=0;i<n;i++){
		int ele;
		cin>>ele;
		vec.push_back(ele);
	}
	int sum=0;
	for(int i=0;i<n;i++) sum += vec[i];

	vector<int>prev(sum+1,0) , curr(sum+1,0) ;
	
	prev[vec[0]] += 1;
	
	for(int i=1;i<n;i++){
		for(int j=0;j<=sum;j++){
			if(j==vec[i] or prev[j]) curr[j] = 1;
			else if (j>=vec[i]){
				if(prev[j-vec[i]]){
					curr[j]  =1;
				}
			}
		}
		prev=curr;
	}
	int count=0;
	for(int i=0;i<=sum;i++) if(prev[i]) count += 1;
	cout<<count<<endl;
	for(int i=0;i<=sum;i++) if(prev[i]) cout<<i<<" ";
	return 0;
}