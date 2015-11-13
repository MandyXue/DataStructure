#include"Tree.cpp"

void title();
void circle(Tree *);

int main(){
	title();
	cout << "�����뽨��һ�����ף�" << endl;
	string name;
	cout << "���������ȵ�������";
	cin >> name;
	Tree *family = new Tree(name);
	cout << "�˼��׵������ǣ�" << family->getRoot() << endl; 
	
	circle(family);
//	return 0;
}

void title(){
	cout << "    ***************** ���׹���ϵͳ *****************" << endl;
	cout << "    ================================================" << endl;
	cout << "    ==            ��ѡ��Ҫִ�еĲ�����            ==" << endl;
	cout << "    ==            A -- ���Ƽ���                   ==" << endl;
	cout << "    ==            B -- ��Ӽ�ͥ��Ա               ==" << endl;
	cout << "    ==            C -- ��ɢ�ֲ���ͥ               ==" << endl;
	cout << "    ==            D -- ���ļ�ͥ��Ա����           ==" << endl;
	cout << "    ==            E -- �˳�����                   ==" << endl;
	cout << "    ================================================" << endl;
}

void circle(Tree *family){
	bool flag = true;
	while(flag == true){
		cout << "\n��ѡ��Ҫִ�еĲ�����";
		char type;
		cin >> type;
		if(type == 'A' || type == 'a'){
			cout << "������Ҫ������ͥ���˵�������";
			string name;
			cin >> name;
			family->startFamily(name);
		}else if(type == 'B' || type == 'b'){
			cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�������";
			string name;
			cin >> name;
			family->addChild(name);
		}else if(type == 'C' || type == 'c'){
			cout << "������Ҫ��ɢ��ͥ���˵�������";
			string name;
			cin >> name;
			family->dissmissFamily(name);
		}else if(type == 'D' || type == 'd'){
			cout << "������Ҫ�����������˵�Ŀǰ������";
			string name;
			cin >> name;
			family->changeName(name);
		}else if(type == 'E' || type == 'e'){
			flag = false;
		}else{
			cout << "�������û������ָ����������롣" << endl; 
		}
	}
}
