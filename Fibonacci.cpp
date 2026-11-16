#include<iostream>
using namespace std;
int recfib(int n){
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	
	return recfib(n-1)+recfib(n-2);
}
void iter(int n){
	int a=0;
	int b=1;
	
	for(int i=0;i<n;i++){
		cout<<a<<" ";
		int c=a+b;
		a=b;
		b=c;
	
	}
}
int main(){
	int n;
	cout<<"Enter n:"<<endl;
	cin>>n;
	int ch;
	cout<<"Enter 1.Recursive 2.Iterative"<<endl;
	cin>>ch;
	
	if(ch==1){
		for(int i=0;i<n;i++){
		cout<<recfib(i)<<" ";
	}
	}else if(ch==2){
		iter(n);
	}else{
		cout<<"Enter valid choice"<<endl;
	}
	
}
