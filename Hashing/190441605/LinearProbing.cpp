#include "LinearProbing.h"

LinearProbing::LinearProbing(){
    m2=100003; Account b; b.id=""; b.balance=0;
    bankStorage1d.resize(m2,b);
    size2=0;
    power.resize(4,1);
    min_idx=m2-1;
    for(int i=1;i<4;i++){
    power[i]=31*power[i-1];
}

p2.resize(10,1);
for(int i=1;i<10;i++){
    p2[i]=3*p2[i-1];
}
}

void LinearProbing::createAccount(std::string id, int count) {

 int k=hash(id);

 
    Account a; 
    a.id=id; 
    a.balance=count;
    while(bankStorage1d[k].id!=""){
        k=(k+1)%m2;
    }
    bankStorage1d[k]=a;
    size2++;
    if(k<min_idx){
    min_idx=k;
 }
}


std::vector<int> LinearProbing::getTopK(int k) {
    
    if(k>size2){
        k=size2;
    }
    std::vector<int> ans(size2);

    int idx=0;

    for(int i=min_idx;i<m2;i++){

        if(bankStorage1d[i].id!=""){

        ans[idx++]=bankStorage1d[i].balance;

        }
        if(idx>=size2){
            break;
        }
    }

    idx=size2-1;

 MS(ans,0,size2-1);

    std::vector<int> ans2(k);
   
    for(int i=0;i<k;i++){

        ans2[i]=ans[idx];
        idx--;
    }
    
    return ans2;

}


int LinearProbing::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int k=hash(id);
    int t=k;
    while(bankStorage1d[k].id!=id){
        k=(k+1)%m2;
        if(k==t){
            return -1;
        }
    }
    return bankStorage1d[k].balance;
}

void LinearProbing::addTransaction(std::string id, int count) {

    int k=hash(id);
    int t=k;
    while(bankStorage1d[k].id!=id){
        k=(k+1)%m2;
        if(k==t){
            createAccount(id,count);
            return;
        }
    }

    bankStorage1d[k].balance+=count;
    // IMPLEMENT YOUR CODE HERE
}

bool LinearProbing::doesExist(std::string id) {
    int k=hash(id);
    int t=k;
    while(bankStorage1d[k].id!=id){
        k=(k+1)%m2;
        if(k==t){
            return false;
        }
    }
    return true;
}

bool LinearProbing::deleteAccount(std::string id) {
    int k=hash(id);
    int t=k;
    while(bankStorage1d[k].id!=id){
        k=(k+1)%m2;
        if(k==t){
            return false;
        }
    }
    bankStorage1d[k].id="";
    bankStorage1d[k].balance=0;
    size2--;
    return true;
}

int LinearProbing::databaseSize() {
    return size2;
}

int LinearProbing::hash(std::string id) {
   
int hashval=0;
for(int i=0;i<4;i++){
    hashval=(hashval+(id[i]-'0')*power[i])%m2;
}

for(int i=4;i<11;i++){
   hashval=(hashval+(id[i]-'0')*p2[i-4])%m2 ;
}

for (int i=12;i<22;i++){
     hashval=(hashval+((id[i]-'0')*p2[i-12])%m2)%m2 ;
}
    return hashval; 
}

