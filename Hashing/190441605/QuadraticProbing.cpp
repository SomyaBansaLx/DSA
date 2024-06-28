#include "QuadraticProbing.h"

QuadraticProbing::QuadraticProbing(){
    m3=100003; size3=0;
    Account b; b.id=""; b.balance=0;
    min_idx=m3;
    bankStorage1d.resize(m3,b);
    power.resize(4,1);
      
    for(int i=1;i<4;i++){
    power[i]=31*power[i-1];
}

p2.resize(10,1);
for(int i=1;i<10;i++){
    p2[i]=3*p2[i-1];
}

}

void QuadraticProbing::createAccount(std::string id, int count) {

 size3++;
 Account a;   a.id=id; a.balance=count;
 int k=hash(id);

 long long i=1;
 int z=k; int c=m3/2;
 while(bankStorage1d[z].id!="" && c>=0){
        z=(k+i*i)%m3;
        i++;
        c--;
    }

    if(c==-1){
        z=k;  i=1;
     while(bankStorage1d[z].id!=""){
        z=(k-i*i)%m3;
        if(z<0){
            z+=m3;
        }
        i++;
      
    }

   bankStorage1d[z]=a;
    if(z<min_idx){
    min_idx=z;
 }
  
    }
    else {

   bankStorage1d[z]=a;
    if(z<min_idx){
    min_idx=z;
 }
    }

}

std::vector<int> QuadraticProbing::getTopK(int k) {
   if(k>size3){
        k=size3;
    }
   
    std::vector<int> ans(size3);
    int idx=0;
    for(int i=min_idx;i<m3;i++){

      if(bankStorage1d[i].id!=""){

        ans[idx++]=bankStorage1d[i].balance;

      };
      if(idx==size3){
        break;
      }
    }

    MS(ans,0,size3-1);
    std::vector<int> ans2(k);
   idx=0;
    for(int i=size3-1;i>size3-1-k;i--){
        
        ans2[idx++]=ans[i];
    }
  

    // IMPLEMENT YOUR CODE HERE
    return ans2;
}

int QuadraticProbing::getBalance(std::string id) {
     int k=hash(id);
      long long i=1;
      int z=k; int c=m3/2;
    while(bankStorage1d[z].id!=id && c>=0){
        z=(k+i*i)%m3;
        i++;
        c--;
    }
    if(c==-1){
        z=k; c=m3/2; i=1;
     while(bankStorage1d[z].id!=id && c>=0){
        z=(k-i*i)%m3;
        if(z<0){
            z+=m3;
        }
        i++;
        c--;
    }

   if(c==-1){
     
     return -1;
     
   }
   else {
    return bankStorage1d[z].balance;
   }

    }
    else {

   return bankStorage1d[z].balance;
    }

    // IMPLEMENT YOUR CODE HERE
    return -1; // Placeholder return value
}

void QuadraticProbing::addTransaction(std::string id, int count) {
    
      int k=hash(id);
     long long i=1;
      int z=k; int c=m3/2;
    while(bankStorage1d[z].id!=id && c>=0){
        z=(k+i*i)%m3;
        i++;
        c--;
    }
    if(c==-1){
        z=k; c=m3/2; i=1;
     while(bankStorage1d[z].id!=id && c>=0){
        z=(k-i*i)%m3;
        if(z<0){
            z+=m3;
        }
        i++;
        c--;
    }

   if(c==-1){
    z=k;  i=1; c=m3/2;
      while(bankStorage1d[z].id!="" && c>=0){
          z=(k+i*i)%m3;
          i++;
          c--;
      } 

      if(c==-1){
    z=k;  i=1; 
      while(bankStorage1d[z].id!=""){
          z=(k-i*i)%m3;
          if(z<0){
            z+=m3;
        }
          i++;
        
      }
      
   bankStorage1d[z].id=id;
        bankStorage1d[z].balance=count;
   size3++;
      }
      else {
        bankStorage1d[z].id=id;
        bankStorage1d[z].balance=count;
        size3++;
      } 
   }
   else {
    bankStorage1d[z].balance+=count;
   }

    }
    else {

    bankStorage1d[z].balance+=count;
    }
     
}
    // IMPLEMENT YOUR CODE HERE


bool QuadraticProbing::doesExist(std::string id) {

    int k=hash(id);

    long long i=1;

    int z=k; int c=m3/2;

    while(bankStorage1d[z].id!=id && c>=0){

        z=(k+i*i)%m3;
        i++;
        c--;
    }

    if(c==-1){
    z=k; c=m3/2; i=1;
        while(bankStorage1d[z].id!=id && c>=0){
        z=(k-i*i)%m3;
        if(z<0){
            z+=m3;
        }
        i++;
        c--;
    }

   if(c==-1){
     
     return false;
     
   }
  
    return true;
   

   }
   

   return true;
  
}

bool QuadraticProbing::deleteAccount(std::string id) {
     
    int k=hash(id);
      int i=1;
      int z=k; int c=m3/2;
    while(bankStorage1d[z].id!=id && c>=0){
        z=(k+i*i)%m3;
        i++;
        c--;
    }
    if(c==-1){
        z=k; c=m3/2; i=1;
     while(bankStorage1d[z].id!=id && c>=0){
        z=(k-i*i)%m3;
        if(z<0){
            z+=m3;
        }
        i++;
        c--;
    }

   if(c==-1){
     
     return false;
     
   }
  else {
    bankStorage1d[z].id="";
    bankStorage1d[z].balance=0;
    size3--;
    return true;
    }

    }
   
    bankStorage1d[z].id="";
    bankStorage1d[z].balance=0;
    size3--;
   return true;
   
}

int QuadraticProbing::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    return size3; // Placeholder return value
}

int QuadraticProbing::hash(std::string id) {
   
  

int hashval=0;
for(int i=0;i<4;i++){
    hashval=(hashval+(id[i]-'0')*power[i])%m3;
}

for(int i=4;i<11;i++){
   hashval=(hashval+(id[i]-'0')*p2[i-4])%m3 ;
}

for (int i=12;i<22;i++){
     hashval=(hashval+((id[i]-'0')*p2[i-12])%m3)%m3 ;
}
    // IMPLEMENT YOUR CODE HERE
    return hashval;
}
