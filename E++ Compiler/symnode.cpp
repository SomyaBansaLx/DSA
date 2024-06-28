/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symnode.h"

//Write your code below this line

SymNode::SymNode(){

}

SymNode::SymNode(string k){

    key=k;

    left=NULL;

    right=NULL;

    par=NULL;

    height=0;

}

SymNode* SymNode::LeftLeftRotation(){

    SymNode *y = this->right;

    SymNode *x = y->left;
 
    y->left = this;

    this->right = x;

   int thisleftheight=  (this->left==NULL) ? 0 : this->left->height ;

   int thisrightheight=  (this->right==NULL) ? 0 : this->right->height ;

   int yrightheight =  (y->right==NULL) ? 0 : y->right->height ;
 
    this->height = max(thisleftheight,thisrightheight) + 1;

    y->height = max(y->left->height,yrightheight) + 1;

    y->par=this->par;

    this->par=y;

    if(x != NULL){

    x->par= this;

    }
 
    return y;

}

SymNode* SymNode::RightRightRotation(){

    SymNode * x = this -> left;

    SymNode * y = x -> right;
 
    x->right = this ;

    this->left = y;

    int thisleftheight=  (this->left==NULL) ? 0 : this->left->height ;

    int thisrightheight=  (this->right==NULL) ? 0 : this->right->height ;

    int xleftheight =  (x->left==NULL) ? 0 : x->left->height ;
 
    this->height = max(thisleftheight,thisrightheight) + 1;

    x->height = max(xleftheight,x->right->height) + 1;

    x->par=this->par;

    this->par=x;

    if(y != NULL){

    y->par= this;

    }

    return x;

}

SymNode* SymNode::LeftRightRotation(){

    left = left->LeftLeftRotation();

    return RightRightRotation();

}

SymNode* SymNode::RightLeftRotation(){

    right = right -> RightRightRotation();

    return LeftLeftRotation();

}

SymNode::~SymNode(){

//     if(par!=NULL){

//     par->~SymNode();

//     }

//     if(left!=NULL){

//     left->~SymNode();

//     }

//     if(right!=NULL){

//     right->~SymNode();

//    }

//     par=nullptr;

//     left=nullptr;
    
//     right=nullptr;

}