#include <bits/stdc++.h>
using namespace std;
class Graph{
	private:
		int size;
		list<int> *table;
	public:
		Graph(int s):size(s),table(new list<int>[s]){}	
		void addedge(int a,int b){
			table[a].push_back(b);
			table[b].push_back(a);
		}
		void display(){
			for(int i=0;i<size;i++){
				cout<<endl<<i<<"|";
				list<int>::iterator it;
				for(it=table[i].begin();it!=table[i].end();it++){
					cout<<"-->"<<*it;
				}
			}
		}
		void bfs(int r){
			bool visited[size]={false};
			queue<int> q;
			q.push(r);
			while(!q.empty()){
				int i = q.front();
				q.pop();
				cout<<i<<" ";
			
				list<int>::iterator it;
				for(it=table[i].begin();it!=table[i].end();it++){
					if(!visited[i] && !visited[*it]){
						q.push(*it);
					}	
				}
				visited[i]=true;
				
			}
				
		}
		void dfs(int r){
			bool visited[size]={false};
			stack<int> s;
			s.push(r);
			while(!s.empty()){
				int i = s.top();
				s.pop();
				cout<<i<<" ";
			
				list<int>::iterator it;
				for(it=table[i].begin();it!=table[i].end();it++){
					if(!visited[i] && !visited[*it]){
						s.push(*it);
					}	
				}
				visited[i]=true;
				
			}
				
		}
};
int main(){
	Graph g(5);
	g.addedge(3,4);
	g.addedge(1,2);
	g.addedge(0,4);
	g.addedge(0,1);
	g.display();
	cout<<endl;
	g.bfs(0);
	cout<<endl;
	g.dfs(0);
	return 0;
}
