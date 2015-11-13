#include"Header.h"
class BST
{
public:
	// BST():root(NULL);
	BST(){
		root = NULL;
	}
	BST(int value){
		int x;
		root = NULL;
		RefValue = value;
		cin >> x;
		while(x != RefValue){
			Insert(x,root);
			cin >> x;
		}
	}
	// ~BST();
	bool Search(const int x)
		{return (Search(x,root) != NULL)? true:false;}
	// BST& operator = (const BST &R);
	void makeEmpty(){makeEmpty(root);root=NULL;}
	void PrintTree(){PrintTree(root);}
	bool Insert(const int& el){return Insert(el,root);}
	bool Remove(const int x){return Remove(x,root);}
private:
	BSTNode *root;
	int RefValue;
	BSTNode *Search(const int x,BSTNode *ptr){
		if(ptr==NULL)return NULL;
		else if(x<ptr->data)return Search(x,ptr->left);
		else if(x>ptr->data)return Search(x,ptr->right);
		else return ptr;
	}
	void makeEmpty(BSTNode *&ptr){
	    if (ptr->left != NULL)
	        makeEmpty(ptr->left);
	    if (ptr->right != NULL)
	        makeEmpty(ptr->right);
	    delete ptr;
	    ptr=NULL;
	}
	void PrintTree(BSTNode *ptr){
		if(ptr != NULL){
			PrintTree(ptr->left);
			cout << ptr->data << "->";
			PrintTree(ptr->right);
		}
	}
	bool Insert(const int& el,BSTNode *&ptr){
		if(ptr==NULL){
			ptr = new BSTNode(el);
			if(ptr == NULL){cerr << "out of space" << endl; exit(1);}
			return true;
		}else if(el < ptr->data){
			Insert(el,ptr->left);
		}else if(el > ptr->data){
			Insert(el,ptr->right);
		}else{
			cout << "The input key<" << el << ">is have in!" << endl;
			return false;
		}
	}
	bool Remove(const int x,BSTNode *ptr){
		BSTNode *temp;
		if(ptr != NULL){
			if(x < ptr->data){
				Remove(x,ptr->left);
			}else if(x > ptr->data){
				Remove(x,ptr->right);
			}else if(ptr->left != NULL && ptr->right != NULL){
				temp = ptr->right;
				while(temp->left != NULL)temp = temp->left;
				ptr->data = temp->data;
				Remove(ptr->data,ptr->right);
			}else{
				temp = ptr;
				if(ptr->left == NULL)ptr = ptr->right;
				else ptr = ptr->left;
				delete temp;
				return true;
			}
		}
		return false;
	}
};
