/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"

//Write your code below this line

SymbolTable::SymbolTable(){

    root = NULL;

    size=0;

}

SymNode* insert_krdo (SymNode* root, string k,SymNode* parent){

     if(root==NULL){

        root=new SymNode(k);

        root->par= parent;

     }

     else if(root->key < k){

         root->right = insert_krdo (root->right,k,root);

     }

     else if(root->key > k){

         root->left = insert_krdo (root->left,k,root);

     }

     else {

       return root;

     }

      int lt = (root->left==NULL) ? 0 : root->left->height;

      int rt= (root->right==NULL) ? 0 : root->right->height;
      
      root->height = max(lt,rt) + 1;

      int height_ka_farak = lt - rt;

      // LL
    if (height_ka_farak > 1 && k < root->left->key){

        return root->RightRightRotation();

    }
 
    // RR
    if (height_ka_farak < -1 && k > root->right->key){

        return root->LeftLeftRotation();

    }
 
    // LR
    if (height_ka_farak > 1 && k > root->left->key){

        root->left = root->left->LeftLeftRotation();

        return root->RightRightRotation();
    }
 
    // RL
    if (height_ka_farak < -1 && k < root->right->key){
        
        root->right = root->right->RightRightRotation();

        return root->LeftLeftRotation();

    }
 
    return root;

}



void SymbolTable::insert(string k){

    if(size==0){

       root=new SymNode(k);

       size++;

       return;
         
    }

    root = insert_krdo( root , k , NULL );

    size++;

}

SymNode* merse_bada(SymNode* root){

     if(root->left==NULL){

       return root;

     }

     return merse_bada(root->left);

}

SymNode* del_krdo_koi_toh( SymNode* root , string k , SymNode* parent){

     if(root==NULL){

        return NULL;

     }

     else if(k < root->key){

         root->left = del_krdo_koi_toh(root->left,k,root);

     }

     else if(k > root->key){

         root->right = del_krdo_koi_toh(root->right,k,root);

     }

     else {

       if(root->left==NULL || root->right==NULL){

         if(root->left==NULL && root->right==NULL){

                root = NULL;

         }

         else {

              SymNode* temp= root->left ? root->left : root->right;

              root->key=temp->key;

              root->height=temp->height;

              root->par=parent;

              root->left=temp->left;

              root->right=temp->right;

              root->address=temp->address;

              free(temp);

         }

      }

      else {

        SymNode* temp=merse_bada(root->right);

        root->key=temp->key;

        root->address=temp->address;

        root->right=del_krdo_koi_toh(root->right,temp->key,root);

      }

     }

     if(root==NULL){

         return NULL;

     }
     

      int lt = (root->left==NULL) ? 0 : root->left->height;

      int rt= (root->right==NULL) ? 0 : root->right->height;
      
      root->height = max(lt,rt) + 1;

      int height_ka_farak = lt - rt;

      if(height_ka_farak>1){

           int ltlt = (root->left->left==NULL) ? 0 : root->left->left->height;

           int ltrt= (root->left->right==NULL) ? 0 : root->left->right->height;

           int left_height_ka_farak = ltlt-ltrt;

           // LL
           if(left_height_ka_farak>=0){

               return root->RightRightRotation();

           }

           // LR
           if(left_height_ka_farak<0 ){

                root->left = root->left->LeftLeftRotation();

                return root->RightRightRotation();

           }

      }

      if(height_ka_farak<-1){

      int rtrt = (root->right->right==NULL) ? 0 : root->right->right->height;

      int rtlt = (root->right->left==NULL) ? 0 : root->right->left->height;

      int right_height_ka_farak = rtlt-rtrt;

    // RR
    if ( right_height_ka_farak<=0){

        return root->LeftLeftRotation();

    }

    // RL
    if (right_height_ka_farak > 0 ){
        
        root->right = root->right->RightRightRotation();

        return root->LeftLeftRotation();

    }

    }
 
    return root;

}

void SymbolTable::remove(string k){

      size--;

      root = del_krdo_koi_toh(root,k,NULL);

      return;

}

int SymbolTable::search(string k){

     if (root == NULL){

        return -2;

     }

     SymNode* temp = root;

     while( temp-> key !=k){

        if(temp->key>k){

            temp=temp->left;

            
        if(temp==NULL){

              return -2;

        }

        }

        else {

            temp=temp->right;

            
         if(temp==NULL){

              return -2;

         }
             
        }

     }

     return temp->address;

}

void SymbolTable::assign_address(string k,int idx){

     if (root == NULL){

        return;

     }

     SymNode* temp = root;

     while( temp-> key !=k ){

        if(temp->key>k){

            temp=temp->left;

        }

        else {

            temp=temp->right;
             
        }

     }

     temp->address = idx;

}

int SymbolTable::get_size(){

    return size;

}

SymNode* SymbolTable::get_root(){

    return root;

}

void destroykrdoplz(SymNode* a){

    if(a==NULL){

        return;

    }

    destroykrdoplz(a->left);

    destroykrdoplz(a->right);

    a->~SymNode();

    a=NULL;

}

SymbolTable::~SymbolTable(){

    // if(root!=NULL){

    // root->~SymNode();

    // }

    // root=NULL;

}