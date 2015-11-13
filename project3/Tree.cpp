#include"iostream"
#include"string"
using namespace std;

struct TreeNode{
	string name;
	int childNum;
	
	TreeNode *firstChild;   //��Ůָ�� 
	TreeNode *nextSibling;  //�ֵ�ָ�� 
	
	TreeNode(string dt = "", TreeNode *fc = NULL, TreeNode *ns = NULL){
		name = dt;
		firstChild = fc;
		nextSibling = ns;
		childNum = 0;
	}
};

class Tree{
	private:
		TreeNode *root, *current;                   //��ָ�뼰��ǰָ��
	public:
		Tree(){root = current = NULL;}              //���캯�� 
		
		Tree(string name){                          //���캯�� 
			root = new TreeNode();
			current = new TreeNode();
			root->name = name;
			current = root;
		}
		
		string getRoot(){return root->name;}        //�������� 
		string getCurrent(){return current->name;}  //�������ڵ�ָ�� 
		
		bool Root();                                //Ѱ�Ҹ���ʹ֮��Ϊ��ǰ��� 
		bool IsEmpty(){return root == NULL;}        //�ж����Ƿ�Ϊ�� 
		bool FirstChild();                          //Ѱ�ҵ�ǰ���ĵ�һ����Ů��ʹ֮��Ϊ��ǰ��� 
		bool NextSibling();                         //Ѱ����һ���ֵܣ�ʹ֮��Ϊ��ǰ��� 
		bool Parent();                              //Ѱ�Ҹ��ڵ㣬ʹ֮��Ϊ��ǰ��� 
		bool Find(string target);                   //��������������target�Ľ�㣬ʹ֮��Ϊ��ǰ��� 
		
		bool Find(TreeNode *p, string value);       //����PΪ������������value
		bool FindParent(TreeNode *t, TreeNode *p);  //��tΪ��������Ѱ��p�ĸ��ڵ㣬��ʹ֮��Ϊ��ǰ�ڵ�
		
		void printChild(TreeNode *p);               //��ӡ��Ů 
		void startFamily(string name);              //������ͥ 
		void addChild(string name);                 //��Ӷ�Ů 
		void dissmissFamily(string name);           //��ɢ���ּ�ͥ 
		void changeName(string name);               //�������� 
};



bool Tree::Find(TreeNode *p, string value){       //����PΪ������������value
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

//��������������target�Ľ�㣬ʹ֮��Ϊ��ǰ��� 
bool Tree::Find(string target){
	if(IsEmpty()){
		return false;
	}
	return Find(root,target);
};

bool Tree::FindParent(TreeNode *t, TreeNode *p){  //��tΪ��������Ѱ��p�ĸ��ڵ㣬��ʹ֮��Ϊ��ǰ�ڵ�
	TreeNode *q = t->firstChild;
	bool succ;
	while(q != NULL && q != p){     //ѭ���ĳ��ӵ��ֵ��������� 
		if((succ = FindParent(q,p)) == true)  //�ҵ� 
			return succ;
		q = q->nextSibling;
	}
	if(q != NULL && q == p){
		current = t;
		return true;
	}else{                     //δ�ҵ����ڵ� 
		current = NULL;
		return false;
	}
}
		

//Ѱ�Ҹ���ʹ֮��Ϊ��ǰ��� 
bool Tree::Root(){  
	if(root == NULL){
		current = NULL;
		return false;
	}else{
		current = root;
		return true;
	}
};

//Ѱ�Ҹ��ڵ㣬ʹ֮��Ϊ��ǰ��� 
bool Tree::Parent(){
	TreeNode *p = current;
	if(current == NULL || current == root){
		current = NULL;
		return false;
	}
	return FindParent(root,p);
};

//Ѱ�ҵ�ǰ���ĵ�һ����Ů��ʹ֮��Ϊ��ǰ��� 
bool Tree::FirstChild(){
	if(current != NULL && current -> firstChild != NULL){
		current = current -> firstChild;
		return true;
	}
	current = NULL;
	return false;
};

//Ѱ����һ���ֵܣ�ʹ֮��Ϊ��ǰ��� 
bool Tree::NextSibling(){
	if(current != NULL && current -> nextSibling != NULL){
		current = current -> nextSibling;
		return true;
	}
	current = NULL;
	return false;
};

void Tree::printChild(TreeNode *p){
	cout << p->name << "�ĵ�һ�������ǣ�";
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
		cout << "������" << current->name << "�Ķ�Ů������";
		int num;
		cin >> num;
		current->childNum = num;
		
		cout << "����������" << current->name << "�Ķ�Ů��������";
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
		cout << "�����������������" << endl;
	}
}

void Tree::addChild(string name){
	if(Find(name)){
		cout << "������" << current->name << "����ӵĶ��ӣ���Ů������������";
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
		cout << "�����������������" << endl;
	}
}

void Tree::dissmissFamily(string name){
	if(Find(name)){
		cout << "Ҫ��ɢ��ͥ�����ǣ�" << current->name << endl;
		printChild(current);
		TreeNode *del = current->firstChild;
		current->firstChild = NULL;
		delete(del);
	}else{
		cout << "�����������������" << endl;
	}
}

void Tree::changeName(string name){
	if(Find(name)){
		cout << "��������ĺ��������";
		string change;
		cin >> change;
		string before = current->name;
		current->name = change;
		cout << before << "�Ѹ���Ϊ" << current->name << endl; 
	}else{
		cout << "�����������������" << endl;
	}
}
