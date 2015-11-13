#include"iostream"
#include"string"
using namespace std;

struct TreeNode{
	string name;
	int childNum;
	
	TreeNode *firstChild;   //子女指针 
	TreeNode *nextSibling;  //兄弟指针 
	
	TreeNode(string dt = "", TreeNode *fc = NULL, TreeNode *ns = NULL){
		name = dt;
		firstChild = fc;
		nextSibling = ns;
		childNum = 0;
	}
};

class Tree{
	private:
		TreeNode *root, *current;                   //根指针及当前指针
	public:
		Tree(){root = current = NULL;}              //构造函数 
		
		Tree(string name){                          //构造函数 
			root = new TreeNode();
			current = new TreeNode();
			root->name = name;
			current = root;
		}
		
		string getRoot(){return root->name;}        //返回祖先 
		string getCurrent(){return current->name;}  //返回现在的指针 
		
		bool Root();                                //寻找根，使之成为当前结点 
		bool IsEmpty(){return root == NULL;}        //判断树是否为空 
		bool FirstChild();                          //寻找当前结点的第一个子女，使之成为当前结点 
		bool NextSibling();                         //寻找下一个兄弟，使之成为当前结点 
		bool Parent();                              //寻找父节点，使之成为当前结点 
		bool Find(string target);                   //在树中搜索含有target的结点，使之成为当前结点 
		
		bool Find(TreeNode *p, string value);       //在以P为根的树中搜索value
		bool FindParent(TreeNode *t, TreeNode *p);  //在t为根的树中寻找p的父节点，并使之成为当前节点
		
		void printChild(TreeNode *p);               //打印儿女 
		void startFamily(string name);              //建立家庭 
		void addChild(string name);                 //添加儿女 
		void dissmissFamily(string name);           //解散部分家庭 
		void changeName(string name);               //更改姓名 
};



bool Tree::Find(TreeNode *p, string value){       //在以P为根的树中搜索value
	bool result = false;
	if(p->name == value){
		result = true;
		current = p;
	}else{
		TreeNode *q = p->firstChild;
		while(q != NULL && ! (result = Find(q,value)))
			q = q->nextSibling;
	}
	return result;
}

//在树中搜索含有target的结点，使之成为当前结点 
bool Tree::Find(string target){
	if(IsEmpty()){
		return false;
	}
	return Find(root,target);
};

bool Tree::FindParent(TreeNode *t, TreeNode *p){  //在t为根的树中寻找p的父节点，并使之成为当前节点
	TreeNode *q = t->firstChild;
	bool succ;
	while(q != NULL && q != p){     //循根的长子的兄弟链，搜索 
		if((succ = FindParent(q,p)) == true)  //找到 
			return succ;
		q = q->nextSibling;
	}
	if(q != NULL && q == p){
		current = t;
		return true;
	}else{                     //未找到父节点 
		current = NULL;
		return false;
	}
}
		

//寻找根，使之成为当前结点 
bool Tree::Root(){  
	if(root == NULL){
		current = NULL;
		return false;
	}else{
		current = root;
		return true;
	}
};

//寻找父节点，使之成为当前结点 
bool Tree::Parent(){
	TreeNode *p = current;
	if(current == NULL || current == root){
		current = NULL;
		return false;
	}
	return FindParent(root,p);
};

//寻找当前结点的第一个子女，使之成为当前结点 
bool Tree::FirstChild(){
	if(current != NULL && current -> firstChild != NULL){
		current = current -> firstChild;
		return true;
	}
	current = NULL;
	return false;
};

//寻找下一个兄弟，使之成为当前结点 
bool Tree::NextSibling(){
	if(current != NULL && current -> nextSibling != NULL){
		current = current -> nextSibling;
		return true;
	}
	current = NULL;
	return false;
};

void Tree::printChild(TreeNode *p){
	cout << p->name << "的第一代子孙是：";
	p = p->firstChild;
	cout << p->name;
	while(p->nextSibling != NULL){
		p = p->nextSibling;
		cout << " " << p->name;
	}
	cout << endl;
}

void Tree::startFamily(string name){
	if(Find(name)){
		cout << "请输入" << current->name << "的儿女人数：";
		int num;
		cin >> num;
		current->childNum = num;
		
		cout << "请依此输入" << current->name << "的儿女的姓名：";
		string child[num];
		for(int i=0; i<num;i++){
			cin >> child[i];
		}
		current->firstChild = new TreeNode(child[0]);
		current = current->firstChild;
		
		for(int i=1;i<num;i++){
			current->nextSibling = new TreeNode(child[i]);
			current = current->nextSibling;
		}
		Find(name);
		printChild(current);
		
	}else{
		cout << "您输入的姓名不存在" << endl;
	}
}

void Tree::addChild(string name){
	if(Find(name)){
		cout << "请输入" << current->name << "新添加的儿子（或女儿）的姓名：";
		string childName;
		cin >> childName;
		int childNum = current->childNum;
		current->childNum++;
		if(current->firstChild != NULL){
			current = current->firstChild;
			for(int i=0;i<childNum-1;i++){
				current = current->nextSibling;
			}
			current->nextSibling = new TreeNode(childName);
		}else{
			current->firstChild = new TreeNode(childName);
		}
		
		Find(name);
		printChild(current);
	}else{
		cout << "您输入的姓名不存在" << endl;
	}
}

void Tree::dissmissFamily(string name){
	if(Find(name)){
		cout << "要解散家庭的人是：" << current->name << endl;
		printChild(current);
		TreeNode *del = current->firstChild;
		current->firstChild = NULL;
		delete(del);
	}else{
		cout << "您输入的姓名不存在" << endl;
	}
}

void Tree::changeName(string name){
	if(Find(name)){
		cout << "请输入更改后的姓名：";
		string change;
		cin >> change;
		string before = current->name;
		current->name = change;
		cout << before << "已更名为" << current->name << endl; 
	}else{
		cout << "您输入的姓名不存在" << endl;
	}
}
