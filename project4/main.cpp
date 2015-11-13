#include"BinaryTree.cpp"

void title();

int main(){
	title();
	bool flag = true;
	BST bst;
	while(flag == true){
		cout << "Please select: ";
		int number;
		cin >> number;
		if(number == 1){
			cout << "Please input key to create Bsort_tree:" << endl;
			BST binarySearchTree(0);
			bst = binarySearchTree;
			cout << "Bsort_tree is:" << endl;
			bst.PrintTree();
			cout << endl;
		}else if(number == 2){
			int insert;
			cout << "Please input key which inserted: ";
			cin >> insert;
			bst.Insert(insert);
			cout << "New Bsort_tree is:" << endl;
			bst.PrintTree();
			cout << endl;
		}else if(number == 3){
			int search;
			cout << "Please input key which searched: ";
			cin >> search;
			if(bst.Search(search)){
				cout << "search success!" << endl;
			}else{
				cout << search << " doesn't exist!" << endl;
			}
		// }else if(number == 4){
		// 	int deleteNum;
		// 	cout << "Please input key which deleted: ";
		// 	cin >> deleteNum;
		// 	bst.Remove(deleteNum);
		// 	cout << "new Bsort_tree is:" << endl;
		// 	bst.PrintTree();
		// 	cout << endl;
		}else if(number == 4){
			flag = false;
		}else{
			cout << "Wrong Input. Please try again." << endl; 
		}
		cout << endl;
	}
	
	system("pause");
	
	return 0;
}

void title(){
	cout << "**            BinaryTree           **" << endl;
	cout << "=====================================" << endl;
	cout << "**    1 -- create a binary tree    **" << endl;
	cout << "**    2 -- insert a number         **" << endl;
	cout << "**    3 -- search a number         **" << endl;
	cout << "**    4 -- quit                    **" << endl;
	cout << "=====================================" << endl;
}
