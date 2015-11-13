#include"Tree.cpp"

void title();
void circle(Tree *);

int main(){
	title();
	cout << "首先请建立一个家谱！" << endl;
	string name;
	cout << "请输入祖先的姓名：";
	cin >> name;
	Tree *family = new Tree(name);
	cout << "此家谱的祖先是：" << family->getRoot() << endl; 
	
	circle(family);
//	return 0;
}

void title(){
	cout << "    ***************** 家谱管理系统 *****************" << endl;
	cout << "    ================================================" << endl;
	cout << "    ==            请选择要执行的操作：            ==" << endl;
	cout << "    ==            A -- 完善家谱                   ==" << endl;
	cout << "    ==            B -- 添加家庭成员               ==" << endl;
	cout << "    ==            C -- 解散局部家庭               ==" << endl;
	cout << "    ==            D -- 更改家庭成员姓名           ==" << endl;
	cout << "    ==            E -- 退出程序                   ==" << endl;
	cout << "    ================================================" << endl;
}

void circle(Tree *family){
	bool flag = true;
	while(flag == true){
		cout << "\n请选择要执行的操作：";
		char type;
		cin >> type;
		if(type == 'A' || type == 'a'){
			cout << "请输入要建立家庭的人的姓名：";
			string name;
			cin >> name;
			family->startFamily(name);
		}else if(type == 'B' || type == 'b'){
			cout << "请输入要添加儿子（或女儿）的人的姓名：";
			string name;
			cin >> name;
			family->addChild(name);
		}else if(type == 'C' || type == 'c'){
			cout << "请输入要解散家庭的人的姓名：";
			string name;
			cin >> name;
			family->dissmissFamily(name);
		}else if(type == 'D' || type == 'd'){
			cout << "请输入要更改姓名的人的目前姓名：";
			string name;
			cin >> name;
			family->changeName(name);
		}else if(type == 'E' || type == 'e'){
			flag = false;
		}else{
			cout << "输入错误，没有这条指令，请重新输入。" << endl; 
		}
	}
}
