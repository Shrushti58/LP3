#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	
	int n;
	cout<<"Enter n"<<endl;
	
	cin>>n;
	
	int k;
	cout<<"Enter k"<<endl;
	cin>>k;
	
	vector<pair<double,pair<int,int>>>arr;
	
	for(int i=0;i<n;i++){
		int w;
		int p;
		
		cin>>w;
		cin>>p;
		
		double ratio=(double)p/w;
		
		arr.push_back({ratio,{w,p}});
	}
	
	double ans=0;
	
	for(int i=0;i<n;i++){
		int w=arr[i].second.first;
		int p=arr[i].second.second;
		if(k==0){
			break;
		}
		
		if(w<=k){
			ans+=p;
			k-=w;
		}else{
			ans+=(arr[i].first)*k;
			k=0;
		}
	}
	cout<<ans;
}
