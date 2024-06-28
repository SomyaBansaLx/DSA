#include "Chaining.h"
using namespace std;
Chaining::Chaining(){
    m=100003;
    bankStorage2d.resize(m);
    s=0;
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

void Chaining::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
   int k=hash(id);
   Account a;   a.id=id; a.balance=count;
   bankStorage2d[k].push_back(a);
   s++;
   if(k<min_idx){
    min_idx=k;
 }
}

std::vector<int> Chaining::getTopK(int k) {
   if(k>s){
        k=s;
    }

    std::vector<int> ans(s);
    int idx=0;
    for(int i=min_idx;i<m;i++){
        if(bankStorage2d[i].size()>0){
            for(int j=0;j<bankStorage2d[i].size();j++){
      
        ans[idx++]=bankStorage2d[i][j].balance;

      }
    }
    if(idx==s){
        break;
    }
    }
    idx=0;
    MS(ans,0,s-1);
    std::vector<int> ans2(k);

    for(int i=s-1;i>s-1-k;i--){
        ans2[idx++]=ans[i];
        
    }
 
  

    // IMPLEMENT YOUR CODE HERE
    return ans2;
}

int Chaining::getBalance(std::string id) {

int k=hash(id);
if (bankStorage2d[k].size()==0){
 return -1;
}

for (int i=0;i<bankStorage2d[k].size();i++){
    if (bankStorage2d[k][i].id==id){
      return  bankStorage2d[k][i].balance;
    }
}
    // IMPLEMENT YOUR CODE HERE
    return -1; // Placeholder return value
}

void Chaining::addTransaction(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE

int k=hash(id);

bool c=false;
for (int i=0;i<bankStorage2d[k].size();i++){
    if (bankStorage2d[k][i].id==id){
        bankStorage2d[k][i].balance+=count;
        c=true; break;
    }
}
if (!c){
     createAccount(id,count);
}

}

bool Chaining::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int k=hash(id);
if (bankStorage2d[k].size()==0){
 return false;
}

for (int i=0;i<bankStorage2d[k].size();i++){
    if (bankStorage2d[k][i].id==id){
      return true;
    }
}
    // IMPLEMENT YOUR CODE HERE
   
    return false; // Placeholder return value
}

bool Chaining::deleteAccount(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    
        int k=hash(id);
        for (int i=0;i<bankStorage2d[k].size();i++){
            if (bankStorage2d[k][i].id==id){
                bankStorage2d[k].erase(bankStorage2d[k].begin()+i);
                s--;
            return true;
            }
        }
    

    return false; 
}
int Chaining::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    
    return s; // Placeholder return value
}

int Chaining::hash(std::string id) {
  
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

