#include "CubicProbing.h"

CubicProbing::CubicProbing(){
    m=100003; size=0;Account b; b.id=""; b.balance=0;
    bankStorage1d.resize(m,b);
    power.resize(4,1);
    min_idx=m;
    for(int i=1;i<4;i++){
    power[i]=31*power[i-1];
}

p2.resize(10,1);
for(int i=1;i<10;i++){
    p2[i]=3*p2[i-1];
}
}

void CubicProbing::createAccount(std::string id, int count) {
 size++;
   Account a;   a.id=id; a.balance=count;
   
  int k=hash(id);
      long long i=1;
      int z=k;
    while(bankStorage1d[z].id!=""){
        z=(k+i*i*i)%m;
        i++;
    }
   bankStorage1d[z]=a;
   if(z<min_idx){
    min_idx=z;
 }
}

std::vector<int> CubicProbing::getTopK(int k) {
   if(k>size){
        k=size;
    }

    std::vector<int> ans(size);
    int idx=0;
    for(int i=min_idx;i<m;i++){

      if(bankStorage1d[i].id!=""){

        ans[idx++]=bankStorage1d[i].balance;

      }
      if(idx==size){
        break;
      }
    }

    MS(ans,0,size-1);
    std::vector<int> ans2(k);
    idx=0;
    for(int i=size-1;i>size-1-k;i--){
        
        ans2[idx++]=ans[i];
       
    }

    return ans2;
}

int CubicProbing::getBalance(std::string id) {
   
    int k=hash(id);
     long long i=1;
      int z=k;
    while(bankStorage1d[z].id!=id){
        z=(k+i*i*i)%m;
        i++;
       if(z==k){
        return -1;
       }
    }
    

    return bankStorage1d[z].balance;
 
}

void CubicProbing::addTransaction(std::string id, int count) {
    int k=hash(id);
    long long i=1;
    int z=k;  bool c=true;
    while(bankStorage1d[z].id!=id){
        z=(k+i*i*i)%m;
        i++;
        if(z==k){
            c=false;
            break;
        }
    }
  if(!c){
   createAccount(id,count);
   return;
  }
    else {
        bankStorage1d[z].balance+=count;
      } 
   
}

bool CubicProbing::doesExist(std::string id) {
              
int k=hash(id);
      long long i=1;
      int z=k;
    while(bankStorage1d[z].id!=id){
        z=(k+i*i*i)%m;
        i++;
        if(z==k){
            return false;
        }
    }
    return true;
   
}

bool CubicProbing::deleteAccount(std::string id) {

     int k=hash(id);
     long long i=1;
      int z=k; 
    while(bankStorage1d[z].id!=id ){
        z=(k+i*i*i)%m;
        i++;
        if(z==k){
            return false;
        }
    }

    bankStorage1d[z].id="";
    size--;
    bankStorage1d[z].balance=0;
    return true;
  
}
int CubicProbing::databaseSize() {


    // IMPLEMENT YOUR CODE HERE
    return size; // Placeholder return value
}

int CubicProbing::hash(std::string id) {
  
int hashval=0;
for(int i=0;i<4;i++){
    hashval=(hashval+(id[i]-'0')*power[i])%m;
}

for(int i=4;i<11;i++){
   hashval=(hashval+(id[i]-'0')*p2[i-4])%m ;
}

for (int i=12;i<22;i++){
     hashval=(hashval+((id[i]-'0')*p2[i-12])%m)%m ;
}
    // IMPLEMENT YOUR CODE HERE
    return hashval;
}
/*int main(){
    CubicProbing c;
    c.addTransaction("ABCD1234567_0123456789",90);
    c.createAccount("ABCY1234567_0123456789",95);
    c.addTransaction("ABCQ1234567_0123456789",900);
    c.createAccount("AHCY1234567_0123456789",980);
    c.deleteAccount("ABCD1234567_0123456789");
    std::cout<<c.databaseSize()<<std::endl;
    c.getTopK(5);
    std::cout<<c.databaseSize()<<std::endl;
    return 0;
}*/