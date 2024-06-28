/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"
//#include "entry.cpp"
bool ismall(string str1, string str2)

{
    int a = str1.length(), b = str2.length();
  
    if (a < b){

        return true;

    }

    else if (b < a){

        return false;

    }

    for (int i = 0; i < a; i++){

        if (str1[i] < str2[i]){

            return true;

        }

        else if (str1[i] > str2[i]){

            return false;

        }
        
        else {

           continue;

        }

    }
  
    return false;
}

SymbolTable::SymbolTable(){
   root=NULL;
   size=0;
};

void del_krdo(SymEntry* root){

  if(root==NULL){
    return ;
  }
  del_krdo(root->left);
  del_krdo(root->right);

  root->~SymEntry();

  root=NULL;

}

SymbolTable::~SymbolTable(){
    del_krdo(root);
};

SymEntry* insertt(SymEntry* n,SymEntry* in){

    if(n==NULL){

        return in;

    }

    if(n->key<in->key){

        n->right=insertt(n->right,in);

    }
    else if(n->key> in->key){

        n->left=insertt(n->left,in);

    }

    return n;

}
void SymbolTable::insert(string k, UnlimitedRational* v){

        SymEntry* temp=new SymEntry(k,v);

        root = insertt(root,temp);

        size++;

};

SymEntry* del(SymEntry* r,string k){

   if (r == NULL){

        return NULL;

   }
  
    if (!ismall(r->key,k)) {

        r->left = del(r->left, k);

        return r;

    }

    else if (ismall(r->key,k)) {

        r->right = del(r->right, k);

        return r;

    };
 
    if (r->left == NULL) {

        SymEntry* temp = r->right;

        delete r;

        return temp;

    }

    else if (r->right == NULL) {

        SymEntry* temp = r->left;

        delete r;

        return temp;

    }

    else {
 
        SymEntry* previous = r;
 
        SymEntry* traverse_using_me = r->right;
        while (traverse_using_me->left != NULL) {
            previous = traverse_using_me;
            traverse_using_me = traverse_using_me->left;
        }
 
        if (previous != r){

            previous->left = traverse_using_me->right;

        }

        else{

            previous->right = traverse_using_me->right;

        }
 
        r->key = traverse_using_me->key;

        r->val=traverse_using_me->val;
 
        delete traverse_using_me;

        return r;
    }

    return NULL;

}
    // Remove a key (and value) in the symbol table
void SymbolTable::remove(string k){

    root=del(root,k);

    size--;

    return;
    
};
 
    // Find the val corresponding to the key in the symbol table
UnlimitedRational* SymbolTable::search(string k){

        SymEntry* temp=root;

        while(temp->key!=k){

          if(ismall(root->key,k)){

            temp=temp->right;

          }

          else {

            temp=temp->left;

          }

        }

        return temp->val;

};

    // Get size
int SymbolTable::get_size(){

   return size;

};

    // Get root 
SymEntry* SymbolTable::get_root(){

   return root;
   
};
