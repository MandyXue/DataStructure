#include"ClassStudent.cpp"

int main(){
	cout << "�����뽨��������Ϣϵͳ" << endl;
	cout << "�����뿼��������"; 
	int number;
	cin >> number;
	cout << "���������뿼���� ���ţ��������Ա����估�������" << endl;
	
	Student* first = NULL;
	
	//��ʼ���� 
	if(number < 1){
		cerr << "����������һ������" << endl;
	}else{
		first = new(Student);
		Student* temp = NULL;
		temp = first;
		for(int i = 0; i < number-1; i++){
			temp->next = new(Student);
			temp = temp->next;
		}
	}
	Student::printList(first);
	cout << "��ѡ����Ҫ���еĲ�����1���룬2ɾ����3���ң�4�޸ģ�0ȡ��������" << endl;
	
	Student::gather(first,number);
	
	return 0;
}
