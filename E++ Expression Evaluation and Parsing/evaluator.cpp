/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */

#include "evaluator.h"

//#include "exprtreenode.cpp"

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
      
        ExprTreeNode* lt = create_my_tree(expression, index); // LT SUBT

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


        ExprTreeNode* rt = create_my_tree(expression, index); // rt sbt

        index++;

        ExprTreeNode* root=new ExprTreeNode();

        root->type=op;

        root->left = lt;

        root->right = rt;

        return root;

    } 
    
    else {

        // Handle variables
        
        if ((curr[0]-'0'<=9 && curr[0]-'0'>= 0) || curr[0]=='-'){

        UnlimitedInt* a=new UnlimitedInt(curr);

        return new ExprTreeNode("VAL", a);

        }
         
        // Handle constants

        else {

            ExprTreeNode* a= new ExprTreeNode();

            a->type="VAR";

            a->id=curr;

            return a;

        }
    }

   return NULL;

}


UnlimitedRational* eval_me_please(ExprTreeNode* root,SymbolTable* symtable) {

    if (!is_op(root->type)) {

        if(root->type == "VAR"){
             
             UnlimitedRational* a = symtable->search(root->id);

             return a;

        }
        else {

         return root->val;

        }
    }

    UnlimitedRational* lv = eval_me_please(root->left,symtable);
    UnlimitedRational* rv = eval_me_please(root->right,symtable);

   string z=root->type;

        if(z=="ADD"){

           root->evaluated_value= lv->add(lv,rv);
           return lv->add(lv,rv);

        }

        else if(z=="SUB"){

             root->evaluated_value= lv->sub(lv,rv);
             return lv->sub(lv,rv);

        }

        else if(z=="MUL"){

            root->evaluated_value= lv->mul(lv,rv);
            return lv->mul(lv,rv);

        }
        root->evaluated_value= lv->div(lv,rv);
        return lv->div(lv,rv);

        
}

Evaluator::Evaluator(){

    symtable=new SymbolTable();

};

void del_me(ExprTreeNode* a){

    if(a==NULL){

        return ;

    }

    del_me(a->left);

    del_me(a->right);

    a->~ExprTreeNode();

    a=NULL;

}

Evaluator:: ~Evaluator(){

    if(symtable!=NULL){

    symtable->~SymbolTable();

    }

    for(int i=0;i<expr_trees.size();i++){

         del_me(expr_trees[i]);

     }
     
     symtable=NULL;

};

// void printexp(ExprTreeNode* head){
//     if(head==NULL){
//         return;
//     }
//     if(head->left==NULL){
//         if(head->val){
//             cout<<head->val->get_frac_str()<<" ";
//         }
//         else{
//             cout<<head->type<<" ";
//         }
//         return;
//     }
//     cout<<"( ";
//     printexp(head->left);
//     cout<<head->type<<" ";
//     printexp(head->right);
//     cout<<")";
// }

    // Read an input vector of tokens (strings)
    // Parse it and convert it to a parse tree
    // Push the root of the tree in the expr_trees
void Evaluator::parse(vector<string> code){
     
    string sym=code[0];
    string root=code[1];

    ExprTreeNode* top=new ExprTreeNode("ROOT",new UnlimitedInt(0));

    top->left=new ExprTreeNode();

    top->left->type="VAR";

    top->left->id=sym;

    int idx=2;

    top->right=create_my_tree(code, idx);

    expr_trees.push_back(top);

   // printexp(top->right);
    
};

    // Evaluate the last element of the expr_trees
    // This function is guaranteed to be called immediately 
    // after a call to parse, and will be only called ONCE
    // for a tree
    // Also populate the symbol tables
void Evaluator:: eval(){
 
   ExprTreeNode* back=expr_trees.back();

   UnlimitedRational* a=eval_me_please(back->right,symtable);

   back->left->val=a;

   back->left->evaluated_value=a;

   //cout<<a->get_frac_str()<<endl;

   symtable->insert(back->left->id,a);
   
};


// int main(){
//         Evaluator ev;
//         vector<string> vecy;
//     vecy.push_back("ap1");
//     vecy.push_back(":=");
//     vecy.push_back("4");
//     ev.parse(vecy);
//     cout<<endl;
//     ev.eval();
    


//         vector<string> vec;
//     vec.push_back("ap2");
//     vec.push_back(":=");
//      vec.push_back("(");
//    //  vec.push_back("(");
//     vec.push_back("ap1");
//     vec.push_back("-");
//     vec.push_back("(");
//     vec.push_back("4");
//     vec.push_back("/");
//      vec.push_back("3");
//     vec.push_back(")");
//     vec.push_back(")");
//     // vec.push_back("pow0");
//     // vec.push_back(")");
//     // vec.push_back(")");
//     ev.parse(vec);
//      cout<<endl;
//      ev.eval();
// // //     //  inorder(ev.symtable->get_root());
// // //     //  cout<<endl;
// // //     //  getvals(ev.expr_trees);
// // //   //  vec.clear();

//   vector<string> vecc;
//     vecc.push_back("ap3");
//     vecc.push_back(":=");
//      vecc.push_back("(");
//    //  vecc.push_back("(");
//     vecc.push_back("ap2");
//     vecc.push_back("+");
//     vecc.push_back("(");
//     vecc.push_back("4");
//     vecc.push_back("/");
//      vecc.push_back("5");
//     vecc.push_back(")");
//     vecc.push_back(")");
//     ev.parse(vecc);
//      cout<<endl;
//       ev.eval();
// // //     //  inorder(ev.symtable->get_root());
// // //     //  cout<<endl;
// // //     //  getvals(ev.expr_trees);
// // //      

//      vector<string> ve;
//    ve.push_back("ap4");
//     ve.push_back(":=");
//      ve.push_back("(");
//    //  ve.push_back("(");
//     ve.push_back("ap3");
//     ve.push_back("-");
//     ve.push_back("(");
//     ve.push_back("4");
//     ve.push_back("/");
//      ve.push_back("7");
//     ve.push_back(")");
//     ve.push_back(")");
//     ev.parse(ve);
//     cout<<endl;
//     ev.eval();
// // //     // inorder(ev.symtable->get_root());
// // //      cout<<endl;
// // //     // getvals(ev.expr_trees);
//     vector<string> v;
//      v.push_back("ap5");
//     v.push_back(":=");
//      v.push_back("(");
//    //  v.push_back("(");
//     v.push_back("ap4");
//     v.push_back("+");
//     v.push_back("(");
//     v.push_back("4");
//     v.push_back("/");
//      v.push_back("9");
//     v.push_back(")");
//     v.push_back(")");
//     ev.parse(v);
//     cout<<endl;
//     ev.eval();


//     vector<string> vy;
//      vy.push_back("ap6");
//     vy.push_back(":=");
//      vy.push_back("(");
//    //  vy.push_back("(");
//     vy.push_back("ap5");
//     vy.push_back("-");
//     vy.push_back("(");
//     vy.push_back("4");
//     vy.push_back("/");
//      vy.push_back("11");
//     vy.push_back(")");
//     vy.push_back(")");
//     ev.parse(vy);
//     cout<<endl;
//     ev.eval();

//     vector<string> vyy;
//      vyy.push_back("ap7");
//     vyy.push_back(":=");
//      vyy.push_back("(");
//    //  vyy.push_back("(");
//     vyy.push_back("ap6");
//     vyy.push_back("+");
//     vyy.push_back("(");
//     vyy.push_back("4");
//     vyy.push_back("/");
//      vyy.push_back("13");
//     vyy.push_back(")");
//     vyy.push_back(")");
//     ev.parse(vyy);
//     cout<<endl;
//     ev.eval();
// // //     // inorder(ev.symtable->get_root());
// // //     // cout<<endl;
// // //     // getvals(ev.expr_trees);
//    return 0;
//  }