
#include<iostream>
#include <vector>
using namespace std;

class node{ 
    public:
      int data; 
      node* next;
      node(int val){
        data=val; next=NULL;}
        };
        

class SET{
   public:
    
     
   node* front; node* end; int size;
   SET(){ front=NULL;end=NULL; size=0;}
    };
    

void Insert(SET &a,int val){
    
   if (a.front==NULL){ a.front=new node(val); a.end=a.front; cout<<++a.size<<endl;
   return;
   }
   
   node * temp=a.front;
  if (temp->next==NULL){
      if(temp->data==val){cout<<a.size<<endl; return;}
      else if (temp->data <val){temp->next=new node(val); a.end=temp->next; cout<<++a.size<<endl; return;}
      else { node* temp1=new node(val);
      temp1->next=a.front; a.end=a.front;
     a.front=temp1; cout<<++a.size<<endl; return;
      }
      }
  else {
      if (temp->data==val){cout<<a.size<<endl; return;}
      else {
      if (a.end->data<val){a.end->next=new node(val); a.end=a.end->next; cout<<++a.size<<endl; return;}
      else{
    while(temp->next->data < val){
       temp=temp->next;
   }
   
   if (temp->next==NULL){
       temp->next=new node(val);
       a.end=temp->next;
       cout<<++a.size<<endl;
       return;
       }
   else{ 
       if (temp->next->data==val){
       cout<<a.size<<endl;
       return;}
       else {node* new_node=new node(val);
         new_node->next=temp->next;
       temp->next= new_node;
     cout<<++a.size<<endl; return;
       };   
  }   
      }
}
}
}

void Delete(SET &a,int val){
    if (a.size<2){
        if (a.front==NULL){ cout<<a.size<<endl; return;}
        else {if (a.front->data==val){a.front=NULL; a.end=NULL; cout<<--a.size<<endl; return;}
        else { cout<<1<<endl; return;
        }
        }
    }
    else {
        if (a.front->data==val){ a.front=a.front->next; cout<<--a.size<<endl; return;};
       
        if (a.end->data<val){ cout<<a.size<<endl; return;}
        else{
         node* temp=a.front;
  while(temp->next->data<val ){
    temp=temp->next;  
  }
  if (temp->next->data==val && temp->next==a.end){ 
      a.end=temp; temp->next=NULL; cout<<--a.size<<endl; return;
 };
 if (temp->next->data==val){  temp->next=temp->next->next;  cout<<--a.size<<endl; return;}
 else {cout<<a.size<<endl; return;}
}
}
}

bool belong(SET a,int val){
    if (a.front==NULL){ cout<<0<<endl; return 0;}
 if (a.end->data<val){ cout<<0<<endl; return 0;}
        node* temp=a.front;
        while(temp->data<val){
            temp=temp->next;
        }
        if (temp->data==val){ cout<<1<<endl; return 1;}
        else {cout<<0<<endl; return 0;}
    }

void print(SET a){
 node* temp=a.front;
if (temp==NULL){cout<<endl; return;}

while(temp->next!=NULL){
    cout<<temp->data<<",";
    temp=temp->next;
}
cout<<temp->data<<endl;
 return;
}

void Union(SET &a,SET &b){
     node* temp1=a.front; node* temp2= b.front;
     if (temp2==NULL){
      cout<<a.size<<endl;
      return;   
     }
     SET c; node* temp3;
      node* temp4;
     
     while(temp1!=NULL && temp2!=NULL){
         if (c.size==0){
          if (temp1->data<temp2->data){
          c.front=new node(temp1->data); 
          temp3=c.front;
           temp1=temp1->next; c.size++;}
    
       else if (temp1->data==temp2->data){
           c.front=new node(temp1->data);  
            temp3=c.front;
             temp1=temp1->next; temp2=temp2->next; c.size++;
       }
       else {
          c.front=new node(temp2->data);
           temp2=temp2->next; c.size++;
           temp3=c.front;
       }
         }
         else{
      
       if (temp1->data<temp2->data){
           temp4=new node(temp1->data); temp3->next=temp4; 
           temp3=temp3->next;
           temp1=temp1->next; c.size++;}
    
       else if (temp1->data==temp2->data){
             temp4=new node(temp1->data);  temp3->next=temp4;
             temp3=temp3->next;
             temp1=temp1->next; temp2=temp2->next; c.size++;
       }
       else {
           temp4=new node(temp2->data);  temp3->next=temp4;
            temp3=temp3->next;
           temp2=temp2->next; c.size++;
           
       }
       }
     }
       
       if (temp1!=NULL)
       { while (temp1!=NULL)
       { 
           temp4=new node(temp1->data);
           temp3->next=temp4; 
           temp3=temp3->next;
           temp1=temp1->next; c.size++;}
       }
      
       else {
           while(temp2!=NULL) { if (c.size==0){
                c.front=new node(temp2->data);
           temp2=temp2->next; c.size++;
           temp3=c.front;
           }
           else {
           temp4=new node(temp2->data);  temp3->next=temp4;
            temp3=temp3->next;
           temp2=temp2->next; c.size++;
           }
           
           }
       }
    
       a.front=c.front;
       a.end=temp3;
       a.size=c.size;
       
       cout<<a.size<<endl; return;
     }


void Intersection(SET &a,SET &b){
    
    node* temp1=a.front; node*temp2= b.front;
    if (temp2==NULL || temp1==NULL){a.front=NULL; a.end=NULL; a.size=0; cout<<a.size<<endl;return;}
    if (a.end->data<b.front->data){a.front=NULL; a.end=NULL; a.size=0; cout<<a.size<<endl; return;}
    if (a.front->data>b.end->data){a.front=NULL; a.end=NULL; a.size=0; cout<<a.size<<endl; return;}
   SET c; node* temp3 ;  node* temp4;
   while(temp1 !=NULL && temp2 !=NULL){
       if (temp1->data<temp2->data){ temp1=temp1->next;}
       else if (temp1->data==temp2->data){
           if (c.size==0){c.front=new node(temp1->data); c.size++; 
           temp1=temp1->next; temp2=temp2->next; temp3=c.front;}
           else {
          temp4=new node(temp1->data); temp3->next=temp4;
          temp3=temp3->next;temp1=temp1->next; temp2=temp2->next; c.size++;
           }   
           }
       else {temp2=temp2->next;}
       }
      
    a.front=c.front; a.end=temp3; a.size=c.size;
    cout<<a.size<<endl; return;
    }


void Diff(SET &a,SET &b){
    
     node* temp1=a.front; node*temp2= b.front;
      if (temp2==NULL || temp1==NULL){ cout<<a.size<<endl; return;}
    if (a.end->data<b.front->data){ cout<<a.size<<endl; return;}
    if (a.front->data>b.end->data){cout<<a.size<<endl; return;};
   SET c; node* temp3;  node* temp4;
   while(temp1 !=NULL && temp2 !=NULL){
        if (c.size==0){
          if (temp1->data<temp2->data){
          c.front=new node(temp1->data); 
          temp3=c.front;
           temp1=temp1->next; c.size++;}
    
       else if (temp1->data==temp2->data){
         
             temp1=temp1->next; temp2=temp2->next; 
       }
       else {
         
           temp2=temp2->next; 
       }
       }
       else {
       if (temp1->data<temp2->data){temp4=new node(temp1->data);
       temp3->next=temp4; temp3=temp3->next;temp1=temp1->next; c.size++; }
       
       else if (temp1->data==temp2->data)
       {temp1=temp1->next; temp2=temp2->next;}
       
       else { temp2=temp2->next;}
       }
   }
       while(temp1 != NULL){
           if (c.size==0){
                c.front=new node(temp1->data); 
          temp3=c.front;
           temp1=temp1->next; c.size++;
           }
           else {
          temp4=new node(temp1->data); temp3->next=temp4; temp3=temp3->next;temp1=temp1->next; c.size++;
       }
       }

    a.front=c.front; a.end=temp3;; a.size=c.size;
    cout<<a.size<<endl; return;
}

void SymDiff(SET &a,SET &b){
     node* temp1=a.front; 
     node* temp2= b.front;
     
     if (temp2==NULL){
      cout<<a.size<<endl; return;   
     }
     SET c; node* temp3; node* temp4;
     while(temp1!=NULL && temp2!=NULL){
         
         if (c.size==0){
          if (temp1->data<temp2->data){
          c.front=new node(temp1->data); 
          temp3=c.front;
           temp1=temp1->next; c.size++;}
    
       else if (temp1->data==temp2->data){
          
             temp1=temp1->next; temp2=temp2->next;
       }
       else {
          c.front=new node(temp2->data);
           temp2=temp2->next; c.size++;
           temp3=c.front;
       }
         }
         else {
       if (temp1->data<temp2->data){
           temp4=new node(temp1->data); temp3->next=temp4; temp3=temp3->next; temp1=temp1->next; c.size++;}
    
       else if (temp1->data==temp2->data){
          temp1=temp1->next; temp2=temp2->next;
       }
       else {
           temp4=new node(temp2->data); temp3->next=temp4; temp3=temp3->next; 
           temp2=temp2->next; c.size++;}
       }
     }
     
     while(temp1!=NULL){ temp4=new node(temp1->data); temp3->next=temp4;
     temp3=temp3->next; temp1=temp1->next; c.size++;}
     while(temp2!=NULL){ 
         if (c.size==0){ c.front=new node(temp2->data); c.size++; temp2=temp2->next; temp3=c.front;}
         else {
    temp4=new node(temp2->data); temp3->next=temp4;
     temp3=temp3->next; 
     temp2=temp2->next; c.size++;};
     }

       a.front=c.front; a.end=temp3; a.size=c.size;
       cout<<a.size<<endl; return;
}



    

   
 
int main() {
vector<SET*> container(1e5+3);
int com_num;
while(cin>>com_num){
    int set_num; cin>>set_num;
    if (com_num==1){
       int val; cin>>val;
         if (container[set_num]==NULL){container[set_num]=new SET();}
        
        Insert(*(container[set_num]),val);}  
    
    else if (com_num==2){
         int val; cin>>val;
         if (container[set_num]==NULL){cout<<-1<<endl;}
        else {
        Delete(*(container[set_num]),val);}
    }
     else if (com_num==3){
         int val; cin>>val;
         if (container[set_num]==NULL){cout<<-1<<endl;}
        else {
        belong(*(container[set_num]),val);}
    }
     else if (com_num==4){
         int set_num1; cin>>set_num1;
        if (container[set_num]==NULL){container[set_num]=new SET();}
        if (container[set_num1]==NULL){container[set_num1]=new SET();}
        Union(*(container[set_num]),*(container[set_num1]));
    }
     else if (com_num==5){
         int set_num1; cin>>set_num1;
        if (container[set_num]==NULL){container[set_num]=new SET();}
        if (container[set_num1]==NULL){container[set_num1]=new SET();}
        Intersection(*(container[set_num]),*(container[set_num1]));
    }
     else if (com_num==6){
         if (container[set_num]==NULL){ container[set_num]=new SET(); cout<<0<<endl;}
         else{
        cout<<container[set_num]->size<<endl;}
    }
     else if (com_num==7){
         int set_num1; cin>>set_num1;
        if (container[set_num]==NULL){container[set_num]=new SET();}
        if (container[set_num1]==NULL){container[set_num1]=new SET();}
        Diff(*(container[set_num]),*(container[set_num1]));
    }
     else if (com_num==8){
        int set_num1; cin>>set_num1;
        if (container[set_num]==NULL){container[set_num]=new SET();}
        if (container[set_num1]==NULL){container[set_num1]=new SET();}
        SymDiff(*(container[set_num]),*(container[set_num1]));
    }
     else {
        if (container[set_num]==NULL){cout<<endl;}
        else{
        print(*(container[set_num]));}
    }
    
}
return 0;
}
