/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include <iostream>
#include "minheap.h"

//Write your code below this line

HeapNode* last_vala(HeapNode* a,int size){

    int count=size;
    
    int c=1;

    while(size!=0){
        
        size/=2;

        c++;

    }

    int aa[c];
    
    HeapNode* temp=a;
    
    int idx=c-1;

    while(count!=0){

        if(count%2==0){

          aa[idx--]=0;

        }

        else {

           aa[idx--]=1;

        }

        count/=2;

    }
    if(idx+2<c){
    for(int i=idx+2;i<c;i++){
        
        if(aa[i]==0){

            temp=temp->left;

        }

        else {

            temp=temp->right;

        }
        
    }

    }
    
    return temp;

}
void heapifydownkrdovai(HeapNode* &a){

   
        if (a == nullptr){
            
            return;

        }

        HeapNode* i_am_small = a;
        
        if (a->left != nullptr && a->left->val < i_am_small->val) {

            i_am_small = a->left;

        }

        if (a->right != nullptr && a->right->val < i_am_small->val) {

            i_am_small = a->right;

        }

        if (i_am_small != a) {

           int temp=a->val;

           a->val=i_am_small->val;

           i_am_small->val=temp;

           heapifydownkrdovai(i_am_small);

        }

}

void Heapify_up_plzz(HeapNode* a){

    if(a==nullptr){

      return;

    }

    if(a->par==nullptr){

       return;

    }

    if(a->val<a->par->val){

       int temp=a->val;

       a->val=a->par->val;

       a->par->val=temp;

       Heapify_up_plzz(a->par);

    }

}

MinHeap::MinHeap(){

    size=0;

    root=nullptr;

}

void MinHeap::push_heap(int num){

     if(root==nullptr){

        root=new HeapNode(num);

        size++;

        return;

    }

    size++;

    int count=size;
    
    int cc=size;

    HeapNode* temp=root;
    
    HeapNode* curr=nullptr;

    int c=1;

    while(cc!=0){
        
        cc/=2;

        c++;

    }

    int aa[c];

    int idx=c-1;

    while(count!=0){

        if(count%2==0){

          aa[idx--]=0;

        }

        else {

           aa[idx--]=1;

        }

        count/=2;

    }
    
    if(idx+2<c){

    for(int i=idx+2;i<c;i++){
        
        if(aa[i]==0){
            
            curr=temp;

            temp=temp->left;
            
        }
        
        else {
            
            curr=temp;

            temp=temp->right;
            
        }
        
    }

    }
      
     if(temp==root){

         if(root->left==nullptr){

           root->left=new HeapNode(num);

           root->left->par=root;

           Heapify_up_plzz(root->left);

           return;

         }
         
         else {

           root->right=new HeapNode(num);

           root->right->par=root;

           Heapify_up_plzz(root->right);

           return;

         }

     }

     if(curr->left==temp){

          curr->left=new HeapNode(num);

          curr->left->par=curr;

          Heapify_up_plzz(curr->left);

          return;

     }

     else {

          curr->right=new HeapNode(num);

          curr->right->par=curr;

          Heapify_up_plzz(curr->right);

          return;

     }

}


int MinHeap::get_min(){

    return root->val;

}

void MinHeap::pop(){

    if(root->left==nullptr && root->right==nullptr){

        root=nullptr;

        size--;

        return;

    }
    
    HeapNode* temp=last_vala(root,size);

    root->val=temp->val;

    if(temp->par->right==temp){

       temp->par->right = nullptr;

    }

    else {

        temp->par->left=nullptr;

    }

    heapifydownkrdovai(root);

    size--;

}

void destroykrd(HeapNode* a){

    if(a==NULL){

        return;

    }

    destroykrd(a->left);

    destroykrd(a->right);

    a->~HeapNode();

    a=NULL;

}

MinHeap::~MinHeap(){

    // if(root!=nullptr){

    //       root->~HeapNode();

    // }

    // root=nullptr;

}

