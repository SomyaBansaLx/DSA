/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"
//#include "symtable.cpp"

ExprTreeNode::ExprTreeNode(){

};

ExprTreeNode::ExprTreeNode(string t, UnlimitedInt* v){
   type=t;
   UnlimitedInt* a=new UnlimitedInt(1);
   val=new UnlimitedRational(v,a);
   evaluated_value=new UnlimitedRational(v,a);
};

ExprTreeNode::ExprTreeNode(string t, UnlimitedRational* v){

  type=t;

  evaluated_value=v;

  if(t=="VAL" || t=="VAR"){

    val=v;
    evaluated_value=v;
    
  }

};

ExprTreeNode::~ExprTreeNode(){

  if(val!=NULL){

   val->~UnlimitedRational();

  }

  val=NULL;

};
