/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "parser.h"

//Write your code below this line

Parser::Parser(){

    symtable=new SymbolTable();

}


bool is_op(string c) {
    return
    c == "ADD" || 
    c == "SUB" || 
    c == "MUL" || 
    c == "DIV" || 
    c=="MOD" ;
  }

    ExprTreeNode* create_my_tree(vector<string> expression, int& index) {

    if (index >= expression.size()) {
        return NULL;
    }

    string curr = expression[index++];
    
    if (curr == "(") {
      
        ExprTreeNode* left = create_my_tree(expression, index); // LT SUBT

        string op = expression[index++]; 

        if(op=="+"){
            op="ADD";
        }
        else if(op=="-"){
            op="SUB";
        }
        else if(op=="*"){
            op="MUL";
        }
        else if(op=="/"){
            op="DIV";
        }
        else {
            op="MOD";
        }


        ExprTreeNode* right = create_my_tree(expression, index); // rt sbt

        index++;

        ExprTreeNode* root=new ExprTreeNode();

        root->type=op;

        root->left = left;

        root->right = right;

        return root;

    } 
    
    else {

        // Handle variables
        
        if (curr[0]-'0'>9 || curr[0]-'0'<0){

            ExprTreeNode* a= new ExprTreeNode();

            a->type="VAR";

            a->id=curr;

            return a;

        }
         
        // Handle constants

        else {

        if(curr[0]=='-'){

           curr.erase(curr.begin());

           int x=stoi(curr);

           x = 0 - x;

           return new ExprTreeNode("VAL", x);

        }  

        else {

        int x= stoi(curr);

        return new ExprTreeNode("VAL", x);

        }

        }
    }
}





void Parser::parse(vector<string> expression){

    if(expression[0]=="del"){

        ExprTreeNode* top=new ExprTreeNode("ROOT", 0);

        top->left=new ExprTreeNode();

        top->left->type="DEL";

        top->right=new ExprTreeNode();

        top->right->id=expression[2];

        expr_trees.push_back(top);

    }

    else if(expression[0]=="ret"){

    ExprTreeNode* top=new ExprTreeNode("ROOT", 0);

    top->left=new ExprTreeNode();

    top->left->type="RET";

    int idx=2;

    top->right=create_my_tree(expression, idx);

    expr_trees.push_back(top); 

    }

    else {

    string sym=expression[0];

    string root=expression[1];

    ExprTreeNode* top=new ExprTreeNode("ROOT", 0);

    top->left=new ExprTreeNode();

    top->left->type="VAR";

    top->left->id=sym;

    int idx=2;

    top->right=create_my_tree(expression, idx);

    expr_trees.push_back(top);

    }

}

void destroykrdovai(ExprTreeNode* a){

    if(a==NULL){

        return;

    }

    destroykrdovai(a->left);

    destroykrdovai(a->right);

    a=NULL;

}

Parser::~Parser(){

    // if(expr_trees.size()>0){

    // for(int i=0;i<expr_trees.size();i++){

    //       if(expr_trees[i]!=nullptr){

    //        destroykrdovai(expr_trees[i]);
            
    //       }

    // }

    // }

    // if(symtable!=NULL){

    //     symtable->~SymbolTable();

    // }

    // symtable=NULL;
  
}