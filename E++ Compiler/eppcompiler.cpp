/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */

#include "eppcompiler.h"

//Write your code below this line

EPPCompiler::EPPCompiler(){

      

}

EPPCompiler::EPPCompiler(string out_file,int mem_limit){

     output_file = out_file;

     memory_size = mem_limit;

    //  mem_loc.resize(mem_limit);

    //  for(int i=0;i<memory_size;i++){

    //     mem_loc[i]=0;

    //  }

     for(int i=0;i<memory_size;i++){

         least_mem_loc.push_heap(i);

     }

}

void EPPCompiler::compile(vector<vector<string> > code){

      for(int i=0;i<code.size();i++){

         targ.parse(code[i]);

         if(code[i][0]!="ret" && code[i][0]!="del"){

            if(targ.symtable->search(code[i][0])==-2){

            targ.symtable->insert(code[i][0]);

            int x=least_mem_loc.get_min();

            least_mem_loc.pop();
            
            // int idx=0;

            // while(mem_loc[idx]!=0){

            //     idx++;

            // }

            // mem_loc[idx]=1;

            targ.symtable->assign_address(code[i][0],x);

            }

         };

         vector<string> ans=generate_targ_commands();

         write_to_file(ans);

      }

}

void postfix(ExprTreeNode* a,vector<string> &me,Parser targ){

    if(a==NULL){

         return;

    }

    postfix(a->right,me,targ);

    postfix(a->left,me,targ);

    if(a->type == "VAL"){
       
       string c=to_string(a->num);

       c=" "+c;

       me.push_back("PUSH" + c);

    }

    else if(a->type=="VAR"){

        string c=to_string(targ.symtable->search(a->id));

        string f="PUSH mem";

        string g="["+c+"]";

        me.push_back(f+g);

    }
    
    else {

        me.push_back(a->type);

    }



}

vector<string> EPPCompiler::generate_targ_commands(){

     ExprTreeNode* a = targ.expr_trees.back();

     vector<string> res;

     if(a->left->type=="DEL"){

          int k=targ.symtable->search(a->right->id);

              targ.symtable->remove(a->right->id);

              //mem_loc[k]=0;

              least_mem_loc.push_heap(k);      

          res.push_back("DEL = mem[" + to_string(k) + "]");

          return res;

     }

     else if(a->left->type=="RET"){

        vector<string> res;

        postfix(a->right,res,targ);

        string k="RET = POP";

        res.push_back(k);

        return res;
  
     }

     else {
         
        vector<string> res;

        postfix(a->right,res,targ);

        string k="["+to_string(targ.symtable->search(a->left->id)) + "]" +" = POP";

        res.push_back("mem"+k);

        return res;

     }

}

void EPPCompiler::write_to_file(vector<string> commands){

      ofstream out;

      out.open(output_file,ios::app);

      for(auto u:commands){

          out<<u<<endl;

      }

      out.close();

}

EPPCompiler::~EPPCompiler(){


  
}

