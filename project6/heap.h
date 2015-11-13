#include"PQueue.h"
#define DefaultSize 10
#include<iostream>
using namespace std;


// enum bool {false,true}
template <class E>
class MinHeap: public PQueue<E>{
public:
	MinHeap(int sz = DefaultSize){
		maxHeapSize = (DefaultSize < sz) ? sz:DefaultSize;
		heap = new E[maxHeapSize];
		if(heap == NULL){cerr << "Failed to allocate memory for heap." << endl; exit(1);}
		currentSize = 0;
	}
	MinHeap(E arr[], int n){
		maxHeapSize = (DefaultSize < n) ? n:DefaultSize;
		heap = new E[maxHeapSize];
		if(heap == NULL){cerr << "Failed to allocate memory for heap." << endl; exit(1);}
		for(int i = 0;i < n;i++) heap[i] = arr[i];
		currentSize = n;
		int currentPos = (currentSize - 2)/2;
		while(currentPos >= 0){
			siftDown(currentPos,currentSize-1);
			currentPos --;
		}
	}
	// ~MinHeap(){delete []heap;};
	bool Insert(const E& x){
		if(currentSize == maxHeapSize)
			{cerr << "Heap Full" << endl; return false;}
		heap[currentSize] = x;
		siftUp(currentSize);
		currentSize++;
		return true;
	}
	bool RemoveMin(E& x){
		if(!currentSize){cout << "Heap empty" << endl; return false;}
		x = heap[0];heap[0] = heap[currentSize - 1];
		currentSize--;
		siftDown(0,currentSize-1);
		return true;
	}
	bool IsEmpty()const{return (currentSize == 0) ? true:false;}
	bool IsFull()const{return (currentSize == maxHeapSize) ? true:false;}
	void MakeEmpty(){currentSize = 0;}

	int HeapSort(int number){
		int exTime = 0;
		for(int i = (number-2)/2; i>=0;i--){
			siftDown(i,number-1);
		}
		for(int i = number-1; i>=1; i--){
			swap(heap[0],heap[i]);
			exTime++;
			siftDown(0,i-1);
		}
		return exTime;
	}

private:
	E *heap;
	int currentSize;
	int maxHeapSize;

	void swap(int& x,int& y){
		int temp = x;
		x = y;
		y = temp;
	}
	void siftDown(int start,int m){	
		int i = start,j = 2*i+1;
		E temp = heap[i];
		while(j <= m){
			if(j < m && heap[j]>heap[j+1])j++;
			if(temp <= heap[j])break;
			else{heap[i] = heap[j];i=j;j=2*j+1;}
		}
		heap[i] = temp;
	}
	void siftUp(int start){
		int j = start,i = (j-1)/2;E temp = heap[j];
		while(j>0){
			if(heap[i] <= temp)break;
			else{heap[j] = heap[i]; j=i; i=(i-1)/2;}
		}
		heap[j] = temp;
	}
};
