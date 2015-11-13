#include "data.h"

void title(){
	cout << "**      contray on sort algorithm      **" << endl;
	cout << "=========================================" << endl;
	cout << "**        1 --- bubble sort            **" << endl;
	cout << "**        2 --- select sort            **" << endl;
	cout << "**        3 --- insert sort            **" << endl;
	cout << "**        4 --- shell sort             **" << endl;
	cout << "**        5 --- quick sort             **" << endl;
	cout << "**        6 --- heap sort              **" << endl;
	cout << "**        7 --- merge sort             **" << endl;
	cout << "**        8 --- radix sort             **" << endl;
	cout << "**        9 --- quit                   **" << endl;
	cout << "=========================================" << endl;
}

int main(){
	title();
	
	//while
	bool flag = true;
	//random number
	cout << "Please input how many random number you need: ";
	int randomNum;
	cin >> randomNum;
	cout << endl;
	datalist data(randomNum);
	data.init();

	while(flag){
		int selectNum;
		cout << "Please select the algorithm you need: ";
		cin >> selectNum;
		if(selectNum == 1){
			data.getBubbleSort();
			data.clear();
		}else if(selectNum == 2){
			data.getSelectSort();
			data.clear();
		}else if(selectNum == 3){
			data.getInsertSort();
			data.clear();
		}else if(selectNum == 4){
			data.getShellSort();
			data.clear();
		}else if(selectNum == 5){
			data.getQuickSort();
			data.clear();
		}else if(selectNum == 6){
			data.getHeapSort();
			data.clear();
		}else if(selectNum == 7){
			data.getMergeSort();
			data.clear();
		}else if(selectNum == 8){
			data.getRadixSort();
			data.clear();
		}else if(selectNum == 9){
			cout << "Bye." << endl;flag = false;
		}else{
			cout << "Invalid input, try again." << endl;
		}
		cout << endl;
	}

	system("pause");
}
