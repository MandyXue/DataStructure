#include"MST.h"

void title(){
	cout << "**        the Simulation System of the Cost of Power Grid      **" << endl; 
	cout << "=================================================================" << endl;
	cout << "**        A --- Create vertices of Power Grid                  **" << endl; 
	cout << "**        B --- Add edge to the Power Grid                     **" << endl; 
	cout << "**        C --- Create minimum spanning tree                   **" << endl; 
	cout << "**        D --- Show minimum spanning tree                     **" << endl; 
	cout << "**        E --- Exit this program                              **" << endl; 
	cout << "=================================================================" << endl;
}

int main(){
	title();
	char input;
	
	GraphInk <string>graph(0);
	MinSpanTree<string> tempMST;


bool flag = true;
	while(flag == true){
		cout << "Please select: ";
		cin >> input;
		if(input == 'A'||input == 'a'){
			cout << "Please input the number of vertices: ";
			int numberOfVertex;
			cin >> numberOfVertex;
			GraphInk<string> temp(numberOfVertex);
			graph = temp;
			cout << "Please input names of the vertices: ";
			string tempStr;
			for(int i=0;i<numberOfVertex;i++){
				cin >> tempStr;
				graph.insertVertex(tempStr);
			}
		}else if(input == 'B'||input == 'b'){
			string tempVer1,tempVer2;
			int tempEdge;
			cout << "(Input '0 0 0' to end)" << endl;
			cout << "Please input two vertices and their edge: ";
			cin >> tempVer1 >> tempVer2 >> tempEdge;
			if(!graph.findVerInsertEdge(tempVer1,tempVer2,tempEdge)){
				cerr << "Failed to insert edge of " << tempVer1 << " and " << tempVer2 << " of cost of " << tempEdge << endl;
			}
			cout << "Please input two vertices and their edge: ";
			bool edgeFlag = true;
			while(edgeFlag == true){
				cin >> tempVer1 >> tempVer2 >> tempEdge;
				// cout << tempVer1 << tempVer2 << tempEdge;
				if(tempVer2== "0" && tempVer1== "0" && tempEdge == 0){
					edgeFlag = false;
					break;
				}
				if(!graph.findVerInsertEdge(tempVer1,tempVer2,tempEdge)){
					cerr << "Failed to insert edge of " << tempVer1 << " and " << tempVer2 << " of cost of " << tempEdge << endl;
				}
				cout << "Please input two vertices and their edge: ";
			}
			// cout << graph;
			// graph.DFS(graph,"a");
		}else if(input == 'C'||input == 'c'){
			cout << "Please input the start vertex: ";
			string stVer;
			cin >> stVer;
			Prim(graph,stVer,tempMST);
			cout << "Create minimum spanning tree!" << endl;
		}else if(input == 'D'||input == 'd'){
			cout << "The vertices and edges of the minimum spanning tree are:" << endl;
			tempMST.print(graph);
		}else if(input == 'E'||input == 'e'){
			flag = false;
		}
		cout << endl;
	}

	system("pause");

}

// int main(){
// 	GraphInk <string>graph(4);
// 	MinSpanTree<string> tempMST;

// 	graph.insertVertex("a");
// 	graph.insertVertex("b");
// 	graph.insertVertex("c");
// 	graph.insertVertex("d");

// 	graph.findVerInsertEdge("a","b",8);
// 	graph.findVerInsertEdge("b","c",7);
// 	graph.findVerInsertEdge("c","d",5);
// 	graph.findVerInsertEdge("d","a",11);
// 	graph.findVerInsertEdge("a","c",18);
// 	graph.findVerInsertEdge("b","d",12);

// 	graph.DFS(graph,"a");
	
// 	cout << "Create minimum spanning tree!" << endl;
// 	Prim<string>(graph,"a",tempMST);
	

// 	// cout << "The vertices and edges of the minimum spanning tree are:" << endl;
// 	// // tempMST.print(graph);

// 	system("pause");

// }
