#include <bits/stdc++.h>
using namespace std;
class Graph{
	private:
		int row,col;
		int** adjmat;
	public:
		Graph(int s):row(s),col(s){
			adjmat= new int*[row];
			for(int i=0;i<row;i++){
				*(adjmat+i)= new int[col];
				for(int j=0;j<col;j++){
					*(*(adjmat+i)+j) = 0;
				}
			}
		}
		void addedge(int a,int b){
			adjmat[a][b] = 1;
			adjmat[b][a] = 1;
		}
		void display(){
			cout<<endl<<"   ";
			for(int k=0;k<row;k++){
				cout<<k<<" ";
			}
			cout<<endl;
			for(int i=0;i<row;i++){
				cout<<i<<" ";
				cout<<"[";
				for(int j=0;j<col;j++){
					cout<<adjmat[i][j]<<" ";
				}
				
				cout<<"]"<<endl;
			}
		}
		void bfs(int r){
			cout<<endl<<"BFS: ";
			bool visited[row]= {false};
			queue<int> q;
			q.push(r);
			while(!q.empty()){
				int i = q.front();
				q.pop();
				cout<<i<<" ";
				
				for(int j=0;j<row;j++){
					if(adjmat[i][j]==1 && !visited[i] && !visited[j]){
						q.push(j);
					}
				}
				visited[i] = true;
			}
		}
		void dfs(int r){
			cout<<endl<<"DFS: ";
			bool visited[row]= {false};
			stack<int> s;
			s.push(r);
			while(!s.empty()){
				int i = s.top();
				s.pop();
				cout<<i<<" ";
				
				for(int j=0;j<row;j++){
					if(adjmat[i][j]==1 && !visited[i] && !visited[j]){
						s.push(j);
					}
				}
				visited[i] = true;
			}
		}
		
};
int main(){
	Graph g(5);
	g.addedge(1,4);
	g.addedge(4,2);
	g.addedge(0,1);
	g.addedge(2,1);
	g.addedge(1,3);
	g.display();
	g.bfs(1);
	g.dfs(1);
}
