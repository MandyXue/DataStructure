#include"heap.h"

template <class T>
struct Edge
{
	int dest;
	int cost;
	Edge<T> *link;
	Edge(){}
	Edge(int num,int weight):dest(num),cost(weight),link(NULL){}
	bool operator != (Edge<T>& R)const{
		return (dest != R.dest)?true:false;
	}
};

template <class T>
struct Vertex
{
	T data;
	Edge<T> *adj;
};

template <class T>
class GraphInk
{
public:
	GraphInk(int sz = 30){
		maxVertices = sz; numVertices = 0; numEdges = 0;
		NodeTable = new Vertex<T>[maxVertices];
		if(NodeTable == NULL){cerr << "Wrong in allocating memory." << endl; exit(1);}
		for(int i=0; i<maxVertices; i++)NodeTable[i].adj = NULL;
	}

	T getValue(int i){return (i>=0 && i<numVertices)?NodeTable[i].data:0;}
	int getWeight(int v1,int v2){
		if(v1!=-1&&v2!=-1){
			Edge<T> *p = NodeTable[v1].adj;
			while(p!=NULL && p->dest != v2)
				p = p->link;
			if(p!=NULL)return p->cost;
		}
		return 0;
	}
	bool insertVertex(const T& vertex){
		if(numVertices == maxVertices)return false;
		NodeTable[numVertices].data = vertex;
		numVertices++;
		return true;
	}
	bool insertEdge(int v1,int v2,int weight){
		if(v1>=0 && v1<numVertices && v2>=0 && v2<numVertices){
			Edge<T> *q, *p = NodeTable[v1].adj;
			while(p!=NULL && p->dest != v2)
				p = p->link;
			if(p!=NULL) return false;
			p = new Edge<T>;
			q = new Edge<T>;
			p->dest = v2; p->cost = weight;
			p->link = NodeTable[v1].adj;
			NodeTable[v1].adj = p;
			q->dest = v1; q->cost = weight;
			q->link = NodeTable[v2].adj;
			NodeTable[v2].adj = q;
			numEdges++;
			return true;
		}
		return 0;
	}
	// bool removeVertex(int v);
	// bool removeEdge(int v1,int v2);
	int getFirstNeighbor(int v){
		if(v!=-1){
			Edge<T> *p = NodeTable[v].adj;
			if(p!=NULL)return p->dest;
		}
		return -1;
	}
	int getNextNeighbor(int v,int w){
		if(v != -1){
			Edge<T> *p = NodeTable[v].adj;
			while(p!=NULL && p->dest != w)
				p = p->link;
			if(p!=NULL && p->link != NULL)
				return p->link->dest;
		}
		return -1;
	}

	bool findVerInsertEdge(T v1,T v2,int vcost){
		for(int i = 0; i < numVertices; i++){
			// cout << getValue(i);
			for(int j = 0; j < numVertices; j++){
				if(v1 == getValue(i) && v2 == getValue(j)){
					if(insertEdge(i,j,vcost)){
						return true;
					}
				}
			}
		}
		return false;
	}

	int NumberOfVertices(){return numVertices;}
	int NumberOfEdges(){return numEdges;}

	void DFS(GraphInk<T>& G,int v,bool visited[]){
		// cout << G.getValue(v);
		visited[v] = true;
		int w = G.getFirstNeighbor(v);
		while(w!=-1){
			cout << G.getValue(v) << "-<" << G.getWeight(v,w) << ">-" <<G.getValue(w)<< endl;
			if(visited[w]==false)
				DFS(G,w,visited);
			w = G.getNextNeighbor(v,w);
		}
	}

	void DFS(GraphInk<T>& G,const T& v){
		int i,loc,n = G.NumberOfVertices();
		bool *visited = new bool[n];
		for(i=0;i<n;i++) visited[i]=false;
		loc = G.getVertexPos(v);
		DFS(G,loc,visited);
		delete[] visited;
	}
	
	int getVertexPos(const T vertex){
		for(int i = 0; i < numVertices;i++)
			if(NodeTable[i].data == vertex)return i;
		return -1;
	}

private:
	int maxVertices;
	int numEdges;
	int numVertices;	
	Vertex<T> *NodeTable;
	
};
