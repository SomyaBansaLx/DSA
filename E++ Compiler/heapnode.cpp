/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "heapnode.h"

//Write your code below this line

HeapNode::HeapNode(){

}

HeapNode::HeapNode(int _val){

    val=_val;

    par = nullptr;

    left = nullptr;

    right = nullptr;

}

HeapNode::~HeapNode(){

//     if(par!=nullptr){

//     par->~HeapNode();

//     }

//     if(left!=nullptr){

//     left->~HeapNode();

//     }

//     if(right!=nullptr){

//     right->~HeapNode();

//    }

//     par=nullptr;

//     left=nullptr;
    
//     right=nullptr;
  
}