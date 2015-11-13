#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

class Student{
	private:
		string _stuID;
		string _stuName;
		string _stuGender;
		string _stuAge;
		string _stuSubject;
		
	public:
		//链表 
		Student* next;
		
		//接口
		void setID(string str){
			_stuID = str;
		}
		void setName(string str){
			_stuName = str;
		}
		void setGender(string str){
			_stuGender = str;
		}
		void setAge(string str){
			_stuAge = str;
		}
		void setSubject(string str){
			_stuSubject = str;
		}
		
		string getID(){
			return _stuID;
		}
		string getName(){
			return _stuName;
		}
		string getGender(){
			return _stuGender;
		}
		string getAge(){
			return _stuAge;
		}
		string getSubject(){
			return _stuSubject;
		}
		//初始化 
		Student(){
			next = NULL;
			cin >> _stuID >> _stuName >> _stuGender >> _stuAge >> _stuSubject;
		}
		//打印 
		void print(){
			cout << _stuID << "\t" << _stuName << "\t" << _stuGender << "\t" << _stuAge << "\t" << _stuSubject << endl;
		}
		
		//打印整个list 
		static void printList(Student* temp){
			cout << "\n考号\t姓名\t性别\t年龄\t报考类别\n"; 
			if(temp != NULL){
				temp->print();
				temp = temp->next;
				while(temp != NULL){
					temp->print();
					temp = temp->next;
				}
			}else{
				cerr << "打印无效";
			}
		}
		
		//插入 
		static void insert(Student*& first, int& length){
			cout << "请输入你要插入的考生的位置：";
			int num;
			cin >> num;
			
			if(num < 1 || num > length+1){
				cerr << "插入位置非法";
			}else{
				Student* ins;
				
				cout << "请依此输入考生的 考号，姓名，性别，年龄及报考类别！" << endl;
				ins = new(Student);
				
				if(num == 1){
					ins->next = first;
					first = ins;
				}else{
					Student* temp = first;
					for(int i = 0; i < num - 2;i++){
						temp = temp->next;
					}
					ins->next = temp->next;
					temp->next = ins;
				}
				length ++;
			}
			printList(first);
		}
		
		static void deleteStu(Student*& first){
			cout << "请输入你要删除的考生的考号：";
			string id;
			cin >> id;
			
			Student* temp = first;
			
			if(temp->getID() == id){
				Student* del = temp;
				cout << "你删除的考生信息是：" << endl;
				del->print();
				first = temp->next;
				delete(del);
			}else{
				for(;temp->next != NULL;temp=temp->next){
					if(temp->next->getID() == id)
						break;
				}
				if(temp->next == NULL){
					cerr << "考生不存在" << endl;
				}else{
					Student* del = temp->next;
					cout << "你删除的考生信息是：" << endl;
					del->print();
					temp->next = del->next;
					delete(del);
				}
			}
			printList(first);
		}
		
		static void modify(Student*& first){
			cout << "请输入你要修改的考生的考号：";
			string id;
			cin >> id;
			
			Student* temp = first;
			for(;temp!= NULL;temp=temp->next){
				if(temp->getID() == id)
					break;
			}
			
			if(temp == NULL){
				cerr << "考生不存在" << endl;
			}else{
				cout << "请输入你要修改的考生信息（1考号，2姓名，3性别，4年龄，5报考类别）：";
				int i;
				cin >> i;
				string after;
				if(i==1){
					cout << "请输入修改后的考号：";
					cin >> after;
					temp->setID(after);
				}else if(i==2){
					cout << "请输入修改后的姓名：";
					cin >> after;
					temp->setName(after);
				}else if(i==3){
					cout << "请输入修改后的性别：";
					cin >> after;
					temp->setGender(after);
				}else if(i==4){
					cout << "请输入修改后的年龄：";
					cin >> after;
					temp->setAge(after);
				}else if(i==5){
					cout << "请输入修改后的报考类别：";
					cin >> after;
					temp->setSubject(after);
				}else{
					cerr << "输入错误，请重新输入" << endl;
				}
			}
			printList(first);
		}
		
		static void find(Student* first){
			cout << "请输入你要查找的考生的考号：";
			string id;
			cin >> id;
			
			Student* temp = first;
			for(;temp!= NULL;temp=temp->next){
				if(temp->getID() == id)
					break;
			}
			if(temp == NULL){
				cerr << "考生不存在" << endl;
			}else{
				temp->print();
			}
		}
		
		static void gather(Student* first, int length){
			bool flag = true;
			while(flag == true){
				cout << "请选择您要进行的操作：";
				int i;
				cin >> i;
				if(i==1){
					insert(first,length);
				}else if(i==2){
					deleteStu(first);
				}else if(i==3){
					find(first);
				}else if(i==4){
					modify(first);
				}else if(i==0){
					flag = false;
				}else{
					cerr << "输入有误" << endl;
				}
			}
		}
		
		
};
