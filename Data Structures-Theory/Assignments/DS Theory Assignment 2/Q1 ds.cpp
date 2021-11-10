#include <iostream>
using namespace std;
class Node{
	private:
		Node* next;
		char var;
		int coff;
		int power;
	public:
		Node():next(0),var(' '),coff(0),power(0){}
		Node(int c,char v,int p):next(0),var(v),power(p),coff(c){}
		friend class SLL;
};
class SLL{
	private:
		Node* head;
		Node* tail;
	public:
		SLL():head(NULL),tail(NULL){}
		void addNode(int c,char v,int p){
			Node* newnode = new Node(c,v,p);
			Node* temp = tail;
			if(head==NULL){
				head=newnode;
				tail = newnode;
				return;
			}
			temp->next = newnode;
			tail = newnode;
		}
		void input(){
			
		}
		SLL& operator+(SLL &rhs){
			Node* temp = head;
			Node* temp2 ;
			int flag = 0;
			while(temp!=NULL){
				flag = 0;
				temp2 = rhs.head;
				while(temp2!=NULL && flag==0){
					if(temp->var == temp2->var && temp->power == temp2->power){
						temp2->coff=temp2->coff+temp->coff;
						flag =1;
					}
					temp2 = temp2->next;	
				}
				if(flag==0){
					rhs.addNode(temp->coff,temp->var,temp->power);
					
				}
				temp = temp->next;
			}
			return rhs;
		}
		void sort(){
			Node* temp = head;
			Node* temp2 = head;
			int d,c;
			char v;
			while(temp->next!=NULL){
				while(temp2->next!=NULL){
					if(temp2->power>temp2->next->power){
						d = temp2->power;
						temp2->power = temp2->next->power;
						temp2->next->power = d;
						
						c = temp2->coff;
						temp2->coff = temp2->next->coff;
						temp2->next->coff = c;
						
						v = temp2->var;
						temp2->var = temp2->next->var;
						temp2->next->var = v;
					}
					temp2 = temp2->next;
				}
				temp = temp->next;
			}
		}
		int count(){
			Node* temp = head;
			int count = 1;
			while(temp->next!=NULL){
				count++;
				temp=temp->next;
				
			}
			return count;
		}
		void display(){
			sort();
			Node* temp = head;
			do{
				cout<<temp->coff<<" "<<temp->var<<" "<<temp->power<<" "<<endl;
				temp =temp->next;
			}while(temp!=NULL);
			
		}	
};

int main(){
 int n,c,p;
	char v;
	SLL L1,L2,L3;		
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c;
		cin>>v;
		cin>>p;
		L1.addNode(c,v,p);
	}	
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c;
		cin>>v;
		cin>>p;
		L2.addNode(c,v,p);
	}		
	L3 = L1+L2;	//zindagi sey koi shikwa tou nahi hai 
	
	cout<<L3.count()<<endl;
	L3.sort();
	L3.display();

}
