#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Edge{
	int Destination_ID;
	int weight;
	friend class Vertex;
	friend class Graph;
	public:
		
		Edge(){}
		Edge(int id,int w):Destination_ID(id),weight(w){}
};
class Vertex{
	public:
	int state_id;
	string state_name;
	
	list<Edge> edgeList;
	public:
		Vertex():state_id(0),state_name(""){}
		Vertex(int id,string name):state_id(),state_name(){}
		friend class Graph;
};
class Graph{
	vector<Vertex> vertices;
	public:
		
		void addVertex(Vertex newVertex){
			bool check  = checkIFVertexExistByID(newVertex.state_id);
			
		}
		void addedge(int id1,int id2,int w){
			bool check1 = checkIFVertexExistByID(id1);
			bool check2 = checkIFVertexExistByID(id2);
			bool check3;
			if (check1 && check2 == true){
				check3 = checkIfEdgeExistByID(id1,id2);
				if(check3 == true){
					cout<<"Edge already exist";
				} 
				else{
					for(int i = 0;i<vertices.size();i++){
						if(vertices.at(i).state_id==id1){
							Edge e(id2,w);
							vertices.at(i).edgeList.push_back(e);
						}
						else if(vertices.at(i).state_id==id2){
							Edge e(id1,w);
							vertices.at(i).edgeList.push_back(e);
						}
					}
					cout<<"Edge added successfully";
				}
			}	 
		}
		Vertex getVertexByID(int vid){
			Vertex temp;
			for(int i=0;i<vertices.size();i++){
				temp = vertices.at(i);
				if(temp.state_id==vid){
					return temp;
				}
			}
			return temp;
		}
		bool checkIfEdgeExistByID(int fromVertex,int toVertex){
			Vertex v = getVertexByID(fromVertex);
			list<Edge> e;
			e = v.edgeList;
			
			for(auto it = e.begin();it!=e.end();it++){
				if(it->Destination_ID==toVertex){
					
					return true;
					break;
				}
			}
			return false;
		}
		bool checkIFVertexExistByID(int vid){
			for(int i=0;i<vertices.size();i++){
				if(vertices.at(i).state_id==vid){
					return true;
				}
			}
		}
};
int main(){
	Graph g;
	Vertex v1;
	v1.state_id =1;
	v1.state_name = "Khi";
	
	g.addVertex(v1);
	v1.state_id = 1;
	v1.state_id = "khi";
	g.addvertex()
	g.addedge(1,2,300)
	return 0;
}
