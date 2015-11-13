#include"ClassStudent.cpp"

int main(){
	cout << "首先请建立考生信息系统" << endl;
	cout << "请输入考生人数："; 
	int number;
	cin >> number;
	cout << "请依此输入考生的 考号，姓名，性别，年龄及报考类别！" << endl;
	
	Student* first = NULL;
	
	//初始输入 
	if(number < 1){
		cerr << "请输入至少一个考生" << endl;
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
	cout << "请选择您要进行的操作（1插入，2删除，3查找，4修改，0取消操作）" << endl;
	
	Student::gather(first,number);
	
	return 0;
}
