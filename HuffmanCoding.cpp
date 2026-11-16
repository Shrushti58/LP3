#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
	public:
		char ch;
		int freq;
		Node* left;
		Node* right;
		
		Node(char c,int f){
			ch=c;
			freq=f;
			left=NULL;
			right=NULL;
		}
};

void printcode(Node* root,string code){
	if(root==NULL){
		return;
	}
	if(root->left==NULL && root->right==NULL){
		cout<<root->ch<<" -> "<<code<<endl;
		return;
	}
	
	printcode(root->left,code+"0");
	printcode(root->right,code+"1");
}

void huffman(vector<pair<char,int>>chars){
	
	priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
	
	for(int i=0;i<chars.size();i++){
		
		char c=chars[i].first;
		int f=chars[i].second;
		
		pq.push({f,new Node(c,f)});
	}
	
	while(pq.size()>1){
		
		Node* left=pq.top().second;
		pq.pop();
		
		Node* right=pq.top().second;
		pq.pop();
		
		Node* parent=new Node('$',left->freq+right->freq);
		parent->left=left;
		parent->right=right;
		pq.push({left->freq+right->freq,parent});
	}
	
	cout<<"Codes :"<<endl;
	printcode(pq.top().second,"");
}
int main(){
	
	int n;
	cout<<"Enter No. of Characters : "<<endl;
	cin>>n;
	
	vector<pair<char,int>>chars;
	
	cout<<"Enter Characters and their Freq : "<<endl;
	for(int i=0;i<n;i++){
		char c;
		int f;
		cout<<"Enter Char :"<<endl;
		cin>>c;
		cout<<"Enter Freq :"<<endl;
		cin>>f;
		chars.push_back({c,f});
	}
	
	huffman(chars);
}
