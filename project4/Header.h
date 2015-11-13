#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;
 
struct BSTNode{
    int data;
    BSTNode *left,*right;
    BSTNode():left(NULL),right(NULL){}
    BSTNode(const int d,BSTNode *L=NULL,BSTNode *R=NULL):data(d),left(L),right(R){}
    void setData(int d){data = d;}
    int getData(){return data;}
};
