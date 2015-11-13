#include"float.h"
#include"GraphInk.h"

struct MSTEdgeNode
{
	int tail,head;
	int key;
	MSTEdgeNode():tail(-1),head(-1),key(0){}
	bool operator <= (MSTEdgeNode& R){return key <= R.key;}
	bool operator > (MSTEdgeNode& R){return key > R.key;}
};

template <class T>
class MinSpanTree
{
public:
	MinSpanTree(int sz = 30):MaxSize(sz),n(0){
		edgevalue = new MSTEdgeNode[sz];
	}
	int Insert(MSTEdgeNode& item){
		edgevalue[n].head = item.head;
		edgevalue[n].key = item.key;
		edgevalue[n].tail = item.tail;
		n++;
	}
	void print(GraphInk<T>& G){
		// cout << "n: " << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << G.getValue(edgevalue[i].tail) << "-<" 
				 << edgevalue[i].key << ">->" 
				 << G.getValue(edgevalue[i].head) << "         ";
		}
		cout << endl;
	}
protected:
	MSTEdgeNode *edgevalue;
	int MaxSize,n;
};

template <class T>
void Prim(GraphInk<T>& G,const T u0,MinSpanTree<T>& MST){
	MSTEdgeNode ed;int v,count;
	int n = G.NumberOfVertices();
	int m = G.NumberOfEdges();
	int u = G.getVertexPos(u0);
	MinHeap<MSTEdgeNode> H(m);
	bool Vmst[n];
	for(int i=0;i<n;i++)
		Vmst[i] = false;
	Vmst[u] = true;
	count = 1;
	do{
		v = G.getFirstNeighbor(u);
		while(v!=-1){
			if(Vmst[v]==false){
				ed.tail = u;
				ed.head = v;
				ed.key = G.getWeight(u,v);
				H.Insert(ed);
			}
			v = G.getNextNeighbor(u,v);
		}
		while(H.IsEmpty() == false && count < n){
			H.RemoveMin(ed);
			if(Vmst[ed.head] == false){
				MST.Insert(ed);
				u = ed.head;
				Vmst[u] = true;
				count ++;
				break;
			}
		}
	} while(count < n);
}
