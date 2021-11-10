#include <iostream>
#include <cstring>
using namespace std;
class Node{
	private:
		string p_id;
		int no_p;
		int quota;
		Node* next;
	public:
		Node():p_id(" "),no_p(0),quota(0),next(0){}
		Node(string p,int n,int q):p_id(p),no_p(n),quota(q),next(0){}
		friend class CSLL;
};
class CSLL{
	private:
		Node* head;
	public:
		CSLL():head(0){}
		void addNode(string p,int n,int q){
			Node* newnode = new Node(p,n,q);
			Node* temp = head;
			if(head==NULL){
				head = newnode;
				newnode->next = head;
				return;
			}
			do{
				temp = temp->next;
			}while(temp->next!=head);
			temp->next=newnode;
			newnode->next = head;
		}
		void display(){
			Node* temp = head;
			do{
				cout<<temp->p_id<<" "<<temp->no_p<<" "<<temp->quota<<endl;
				temp = temp->next;
			}while(temp!=head);
		}
		void TinyOS(){
			Node * temp = head;
			//check the greatest no_p/quota;
			int max = 0;
			do{
				int n = temp->no_p / temp->quota;
				if(n>max){
					max = n;
				}
			}while(temp!=head);
			temp = head;
			for(int i=0;i<max;i++){
				do{
					if(temp->no_p>0){
						cout<<endl<<temp->p_id;
						temp->no_p -= temp->quota;
					}
					temp = temp->next;
				}while(temp!=head);
			}
		}
};
int main(){
	CSLL L1;
	string p;
	int n,q;
	int no;
	cin>>no;
	for(int i=0;i<no;i++){
		cin>>p;
		cin>>n;
		cin>>q;
		L1.addNode(p,n,q);
	}
//	L1.display();
	L1.TinyOS();
	return 0;
}
