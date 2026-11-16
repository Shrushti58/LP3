#include<iostream>
#include<vector>
using namespace std;

void printboard(vector<vector<string>>& board,int n){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool issafe(vector<vector<string>>& board,int row,int col,int n){
	
	for(int i=0;i<n;i++){
		if(board[i][col]=="Q"){
			return false;
		}
	}
	
	for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
	if(board[i][j]=="Q"){
			return false;
		}	
		}
		
		for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
				if(board[i][j]=="Q"){
			return false;
		}
		}
		
		return true;
}

bool solve(vector<vector<string>>& board,int row,int n){
	
	if(row>=n){
		return true;
	}
	
	for(int col=0;col<n;col++){
		
		if(issafe(board,row,col,n)){
			board[row][col]="Q";
			if(solve(board,row+1,n)){
				return true;
			}
			board[row][col]=".";
		}
	}
	
	return false;
}

int main(){
	
	int n;
	
	cout<<"Enter n";
	cin>>n;
	vector<vector<string>>board(n,vector<string>(n,"."));
	
	cout<<"Enter first Queens position"<<endl;
	int row;
	int col;
	cin>>row>>col;
	
	if(row>=n || row<0 || col>=n || col<0){
		cout<<"Invaild row and col"<<endl;
		return 0;
	}
	board[row][col]="Q";
	
	if(solve(board,row+1,n)){
		printboard(board,n);
	}else{
		cout<<"Soln doesnt exits"<<endl;
	}
}
