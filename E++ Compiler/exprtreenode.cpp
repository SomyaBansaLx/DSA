/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"

//Write your code below this line

ExprTreeNode::ExprTreeNode(){

}

ExprTreeNode::ExprTreeNode(string t,int v){

    type=t;

    num=v;

    left=NULL;

    right=NULL;
  
}

ExprTreeNode::~ExprTreeNode(){

    // left=nullptr;
    
    // right=nullptr;

}

