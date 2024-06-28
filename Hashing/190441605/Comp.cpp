#include "Comp.h"
Comp::Comp(){
    m4=100003;
    size4=0; Account b; b.id=""; b.balance=0;
    bankStorage1d.resize(m4,b);
    power.resize(4,1);
      min_idx=m4;
    for(int i=1;i<4;i++){
    power[i]=31*power[i-1];
}

p2.resize(10,1);
for(int i=1;i<10;i++){
    p2[i]=3*p2[i-1];
}
}
void Comp::createAccount(std::string id, int count) {

  
 size4++;


   Account a;   a.id=id; a.balance=count;
   
  int k=hash(id);
      int i=hash2(id); int idash=i;
      int z=k; 
    while(bankStorage1d[z].id!=""){
        z=(k+i)%m4;
        i+=idash; 
    }
    
   bankStorage1d[z]=a;
    if(z<min_idx){
    min_idx=z;
 }

}

std::vector<int> Comp::getTopK(int k) {
    if(k>size4){
        k=size4;
    }

    std::vector<int> ans(size4);
    int idx=0;
    for(int i=min_idx;i<m4;i++){

      if(bankStorage1d[i].id!=""){

        ans[idx++]=bankStorage1d[i].balance;

      }
      if(idx==size4){
        break;
      }
    }

    MS(ans,0,size4-1);
    std::vector<int> ans2(k);
idx=0;
    for(int i=size4-1;i>size4-1-k;i--){
        
        ans2[idx++]=ans[i];
    }
  

    // IMPLEMENT YOUR CODE HERE
    return ans2;
}

int Comp::getBalance(std::string id) {
int k=hash(id);
    int i=hash2(id);
int idash=i;
      int z=k;
    while(bankStorage1d[z].id!=id){
        z=(k+i)%m4;
        i+=idash;
        if(z==k){
            return -1;
        }
    }
   
    return bankStorage1d[z].balance;
   }

void Comp::addTransaction(std::string id, int count) {
   int k=hash(id);
     int i=hash2(id); int idash=i;
      int z=k; 
    while(bankStorage1d[z].id!=id){
        z=(k+i)%m4;
        i+=idash;
        if(z==k){
            createAccount(id,count);
        }
    }
   
    bankStorage1d[z].balance+=count;
 
}

bool Comp::doesExist(std::string id) {

    int k=hash(id);
     int i=hash2(id); int idash=i;
      int z=k;
    while(bankStorage1d[z].id!=id){
        z=(k+i)%m4;
        i+=idash;
        if(z==k){
            return false;
        }
    }
   return true;
}

bool Comp::deleteAccount(std::string id) {
       int k=hash(id);
      int i=hash2(id); int idash=i;
      int z=k;
    while(bankStorage1d[z].id!=id){
        z=(k+i)%m4;
        i+=idash;
        if(z==k){
            return false;
        }
    }
    
    bankStorage1d[z].id="";
    bankStorage1d[z].balance=0;
    size4--;
    return true;
  
}
int Comp::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    return size4; // Placeholder return value
}

int Comp::hash(std::string id) {
  
int hashval=0;
for(int i=0;i<4;i++){
    hashval=(hashval+(id[i]-'0')*power[i])%m4;
}

for(int i=4;i<11;i++){
   hashval=(hashval+(id[i]-'0')*p2[i-4])%m4 ;
}

for (int i=12;i<22;i++){
     hashval=(hashval+((id[i]-'0')*p2[i-12])%m4)%m4 ;
}
    // IMPLEMENT YOUR CODE HERE
    return hashval;
}


int Comp:: hash2(std::string id){
   return 59;
}


// Feel free to add any other helper functions you need
// Good Luck!