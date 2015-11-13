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
		//���� 
		Student* next;
		
		//�ӿ�
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
		//��ʼ�� 
		Student(){
			next = NULL;
			cin >> _stuID >> _stuName >> _stuGender >> _stuAge >> _stuSubject;
		}
		//��ӡ 
		void print(){
			cout << _stuID << "\t" << _stuName << "\t" << _stuGender << "\t" << _stuAge << "\t" << _stuSubject << endl;
		}
		
		//��ӡ����list 
		static void printList(Student* temp){
			cout << "\n����\t����\t�Ա�\t����\t�������\n"; 
			if(temp != NULL){
				temp->print();
				temp = temp->next;
				while(temp != NULL){
					temp->print();
					temp = temp->next;
				}
			}else{
				cerr << "��ӡ��Ч";
			}
		}
		
		//���� 
		static void insert(Student*& first, int& length){
			cout << "��������Ҫ����Ŀ�����λ�ã�";
			int num;
			cin >> num;
			
			if(num < 1 || num > length+1){
				cerr << "����λ�÷Ƿ�";
			}else{
				Student* ins;
				
				cout << "���������뿼���� ���ţ��������Ա����估�������" << endl;
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
			cout << "��������Ҫɾ���Ŀ����Ŀ��ţ�";
			string id;
			cin >> id;
			
			Student* temp = first;
			
			if(temp->getID() == id){
				Student* del = temp;
				cout << "��ɾ���Ŀ�����Ϣ�ǣ�" << endl;
				del->print();
				first = temp->next;
				delete(del);
			}else{
				for(;temp->next != NULL;temp=temp->next){
					if(temp->next->getID() == id)
						break;
				}
				if(temp->next == NULL){
					cerr << "����������" << endl;
				}else{
					Student* del = temp->next;
					cout << "��ɾ���Ŀ�����Ϣ�ǣ�" << endl;
					del->print();
					temp->next = del->next;
					delete(del);
				}
			}
			printList(first);
		}
		
		static void modify(Student*& first){
			cout << "��������Ҫ�޸ĵĿ����Ŀ��ţ�";
			string id;
			cin >> id;
			
			Student* temp = first;
			for(;temp!= NULL;temp=temp->next){
				if(temp->getID() == id)
					break;
			}
			
			if(temp == NULL){
				cerr << "����������" << endl;
			}else{
				cout << "��������Ҫ�޸ĵĿ�����Ϣ��1���ţ�2������3�Ա�4���䣬5������𣩣�";
				int i;
				cin >> i;
				string after;
				if(i==1){
					cout << "�������޸ĺ�Ŀ��ţ�";
					cin >> after;
					temp->setID(after);
				}else if(i==2){
					cout << "�������޸ĺ��������";
					cin >> after;
					temp->setName(after);
				}else if(i==3){
					cout << "�������޸ĺ���Ա�";
					cin >> after;
					temp->setGender(after);
				}else if(i==4){
					cout << "�������޸ĺ�����䣺";
					cin >> after;
					temp->setAge(after);
				}else if(i==5){
					cout << "�������޸ĺ�ı������";
					cin >> after;
					temp->setSubject(after);
				}else{
					cerr << "�����������������" << endl;
				}
			}
			printList(first);
		}
		
		static void find(Student* first){
			cout << "��������Ҫ���ҵĿ����Ŀ��ţ�";
			string id;
			cin >> id;
			
			Student* temp = first;
			for(;temp!= NULL;temp=temp->next){
				if(temp->getID() == id)
					break;
			}
			if(temp == NULL){
				cerr << "����������" << endl;
			}else{
				temp->print();
			}
		}
		
		static void gather(Student* first, int length){
			bool flag = true;
			while(flag == true){
				cout << "��ѡ����Ҫ���еĲ�����";
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
					cerr << "��������" << endl;
				}
			}
		}
		
		
};
