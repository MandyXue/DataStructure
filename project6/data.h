#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include "heap.h"
using namespace std;

class datalist{
private:
	float sortTime;
	long exchangeTimes;
	int number;       //the number of numbers
	vector<int> randomNums;

	//exchange function
	void swap(int& x,int& y){
		int temp = x;
		x = y;
		y = temp;
	}
	//print function
	void print(int *a){
		for(int i=0;i<number;i++){
			cout << a[i] << ";";
		}
		cout << endl;
	}
	//sort type
	//bubble
	void bubbleSort(){
		int a[number];
		for(int i=0;i<number;++i){
			a[i] = randomNums[i];
		}
		clock_t t;
		t = clock();
		bool exchange;
		for(int i = 0; i < number; i++){
			exchange = false;
			for(int j = 0; j < number; j++){
				if(a[j-1]>a[j]){
					swap(a[j-1],a[j]);
					exchange = true;
					exchangeTimes++; //exchange time
				}
			}
		}
		t = clock() - t;
		sortTime = t/CLOCKS_PER_SEC;
		// print(a);
	}
	//select
	void selectSort(){
		int a[number];
		for(int i=0;i<number;++i){
			a[i] = randomNums[i];
		}
		clock_t t;
		t = clock();
		for(int i = 0; i < number; i++){
			int k = i;
			for(int j = i+1; j < number; j++){
				if(a[j] < a[k])
					k = j;
				if(k != i){
					swap(a[i],a[k]);
					exchangeTimes++;  //exchange time
				}
			}
		}
		t = clock() - t;
		sortTime = t/CLOCKS_PER_SEC;
		// print(a);
	}

	//insert sort
	void insertSort(){
		int a[number];
		for(int i=0;i<number;++i){
			a[i] = randomNums[i];
		}
		clock_t t;
		t = clock();
		for(int i = 0; i < number; i++){
			int temp = a[i];
			int j = i;
			while(j > 0 && a[i] < a[j-1]){
				a[j] = a[j-1];
				j--;
				exchangeTimes++; //exchange time
			}
			a[j] = temp;
		}
		t = clock() - t;
		sortTime = t/CLOCKS_PER_SEC;
		// print(a);
	}
	void shellSort(){
		int a[number];
		for(int i=0;i<number;++i){
			a[i] = randomNums[i];
		}
		clock_t t;
		t = clock();
		int len = 1 + rand()%number;
		for(int div = len/2;div>=1;div/=2){
			for(int i= div;i<len;i+=div){
				for(int j=i;(a[j]<a[j-div])&&j>=0;j-=div){
					swap(a[j],a[j-div]);
					exchangeTimes++;
				}
			}
		}
		t = clock() - t;
		sortTime = t/CLOCKS_PER_SEC;
		// print(a);
		// for(int i=0;i<number;++i){
		// 	cout << a[i] << ";";
		// }
	}

	//quick sort basic functions
	int Partition(int *a,const int low,const int high){
		int pivotpos = low;
		int pivot = a[low];
		for(int i = low + 1; i <= high; i++){
			if(a[i]<pivot && ++pivotpos != i){
				swap(a[pivotpos],a[i]);
				exchangeTimes++;  //exchange time
			}
			swap(a[low],a[pivotpos]);
			exchangeTimes++;  //exchange time
		}
		return pivotpos;
	}
	void quick(int *a,const int left,const int right){
		if(left < right){
			int pivotpos = Partition(a,left,right);
			quick(a,left,pivotpos-1);
			quick(a,pivotpos+1,right);
		}
	}
	//quick sort
	void quickSort(){
		int a[number];
		for(int i=0;i<number;++i){
			a[i] = randomNums[i];
		}
		clock_t t;
		t = clock();
		quick(a,1,number-1);
		t = clock() - t;
		sortTime = t/CLOCKS_PER_SEC;
		// print(a);
	}
	//heap sort
	void heapSort(){
		MinHeap<int> Myheap(number);
		for(int i=0;i<number;++i){
			Myheap.Insert(randomNums[i]);
		}
		clock_t t;
		t = clock();
		exchangeTimes = Myheap.HeapSort(number);
		t = clock() - t;
		sortTime = t/CLOCKS_PER_SEC;
	}
	void merge(int *a,int *b,const int l,const int m,const int n){
		int i=0,j=m+1,k=0;
		while(i<=m && j<=n){
			if(a[i]<=a[j]){
				b[k] = a[i];
				i++;k++;
				exchangeTimes ++;
			}else{
				b[k] = a[i];
				j++;k++;
				exchangeTimes ++;
			}
			if(i<=m)
				for(int n1=k,n2=i;n1<=n && n2<=m;n1++,n2++)
					b[n1]=a[n2];
			else
				for(int n1=k,n2=j;n1<=n && n2<=m;n1++,n2++)
					b[n1]=a[n2];
		}
		// print(a);
	}

	void mergeSort(){
		int a[number];
		for(int i=0;i<number;++i){
			a[i] = randomNums[i];
		}
		int b[number];
		for(int i=0;i<number;++i){
			b[i] = randomNums[i];
		}
		clock_t t;
		t = clock();

		int i=0,len=1;
		while(i+2*len<=number-1){
			merge(a,b,i,i+len-1,i+2*len-1);
			i+=2*len;
		}
		if(i+len <= number-1)
			merge(a,b,i,i+len-1,number-1);
		else
			for(int j=i;j<=number-1;j++)
				b[j] = a[j];

		t = clock() - t;
		sortTime = t/CLOCKS_PER_SEC;
		// print(b);
	}
	int pre_process_data(int array[], int length, int weight)
	{
		int index ;
		int value = 1;

		for(index = 0; index < weight; index++)
			value *= 10;

		for(index = 0; index < length; index ++)
			array[index] = array[index] % value /(value /10);

		for(index = 0; index < length; index ++)
			if(0 != array[index])
				return 1;

		return 0;
	}
	void sort_for_basic_number(int array[], int length, int swap[])
	{
		int index;
		int basic;
		int total = 0;

		for(basic = -9; basic < 10; basic++){
			for(index = 0; index < length; index++){
				if(-10 != array[index] && basic == array[index] ){
					swap[total ++] = array[index];
					array[index] = -10;
					exchangeTimes++;
				}
			}
		}

		memmove(array, swap, sizeof(int) * length);
	}
	void sort_data_by_basic_number(int array[], int data[], int swap[], int length, int weight)
	{
		int index ;
		int outer;
		int inner;
		int value = 1;

		for(index = 0; index < weight; index++)
			value *= 10;

		for(outer = 0; outer < length; outer++){
			for(inner = 0; inner < length; inner++){
				if(-10 != array[inner] && data[outer]==(array[inner] % value /(value/10))){
					swap[outer] = array[inner];
					array[inner] = -10;
					exchangeTimes++;
					break;
				}
			}
		}

		memmove(array, swap, sizeof(int) * length);
		return;
	}
	void radixSort(){
		int a[number];
		for(int i=0;i<number;++i){
			a[i] = randomNums[i];
		}
		// int n = number;
		// int d = maxbit(a,n);
		// int *tmp = new int[n];
		// int *count = new int[10];
		// int i,j,k;
		// int radix = 1;
		clock_t t;
		t = clock();

		int *array=a;
		int length=number;

		int* pData;  
	    int weight = 1;  
	    int count;  
	    int* swap;  
	    if(NULL == array || 0 == length)  
	        return;  
	  
	    pData = (int*)malloc(sizeof(int) * length);  
	    assert(NULL != pData);  
	    memmove(pData, array, length * sizeof(int));  
	  
	    swap = (int*)malloc(sizeof(int) * length);  
	    assert(NULL != swap);  
	  
	    while(1){  
	        count = pre_process_data(pData, length, weight);  
	        if(!count)  
	            break;  
	        sort_for_basic_number(pData, length, swap);  
	        sort_data_by_basic_number(array, pData, swap, length, weight);  
	        memmove(pData, array, length * sizeof(int));  
	        weight ++;  
	    }  
	  
	    free(pData);  
	    free(swap);  

	    // print(a);
		t = clock() - t;
		sortTime = t/CLOCKS_PER_SEC;
	}
public:
	long getExcTime(){return exchangeTimes;}
	float getSortTime(){return sortTime;}
	datalist(int num){
		number = num;
		exchangeTimes = 0;
		sortTime = 0;
	}
	void init(){
		for(int i=0;i<number;i++){
			int temp = 1 + rand()%(number*10);
			randomNums.push_back(temp);
		}
	}
	void clear(){
		sortTime = 0;
		exchangeTimes = 0;
	}
	void print(){
		for(int i=0;i<number;i++){
			cout << randomNums[i] << ";";
		}
		cout << endl;
	}
	void getBubbleSort(){
		bubbleSort();
		cout << "Bubble sort needs:\t" << sortTime << " seconds." << endl;
		cout << "Bubble sort needs:\t" << exchangeTimes << " times." << endl;
	}
	void getInsertSort(){
		insertSort();
		cout << "Insert sort needs:\t" << sortTime << " seconds." << endl;
		cout << "Insert sort needs:\t" << exchangeTimes << " times." << endl;
	}
	void getQuickSort(){
		quickSort();
		cout << "Quick sort needs:\t" << sortTime << " seconds." << endl;
		cout << "Quick sort needs:\t" << exchangeTimes << " times." << endl;
	}
	void getSelectSort(){
		selectSort();
		cout << "Select sort needs:\t" << sortTime << " seconds." << endl;
		cout << "Select sort needs:\t" << exchangeTimes << " times." << endl;
	}
	void getHeapSort(){
		heapSort();
		cout << "Heap sort needs:\t" << sortTime << " seconds." << endl;
		cout << "Heap sort needs:\t" << exchangeTimes << " times." << endl;
	}
	void getMergeSort(){
		mergeSort();
		cout << "Merge sort needs:\t" << sortTime << " seconds." << endl;
		cout << "Merge sort needs:\t" << exchangeTimes << " times." << endl;
	}
	void getShellSort(){
		shellSort();
		cout << "Shell sort needs:\t" << sortTime << " seconds." << endl;
		cout << "Shell sort needs:\t" << exchangeTimes << " times." << endl;
	}
	void getRadixSort(){
		radixSort();
		cout << "Radix sort needs:\t" << sortTime << " seconds." << endl;
		cout << "Radix sort needs:\t" << exchangeTimes << " times." << endl;
	}
};
