#include<iostream>
#include<vector>
using namespace std;
int main(){
	
	int n;
	cout<<"Enter n"<<endl;
	cin>>n;
	
	vector<int>weight;
	vector<int>profit;
	cout<<"Enter weights and profit"<<endl;
	
	for(int i=0;i<n;i++){
		int w;
		int p;
		cout<<"Enter weight"<<endl;
		cin>>w;
		weight.push_back(w);
		
		cout<<"Enter profit"<<endl;
		cin>>p;
		profit.push_back(p);
	}
	
	int k;
	cout<<"Enter Knapsack "<<endl;
	cin>>k;
	
	vector<vector<int>>dp(n+1,vector<int>(k+1,0));
	
	for(int i=1;i<n+1;i++){
		int take=0;
		int skip=0;
		
		for(int j=1;j<k+1;j++){
			
			if(weight[i-1]<=j){
				take=profit[i-1]+dp[i-1][j-weight[i-1]];
			}
			skip=dp[i-1][j];
			
			dp[i][j]=max(take,skip);
		}
	}
	
	cout<<dp[n][k];

}
