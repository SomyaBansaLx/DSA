/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedint.h"
//#include <iostream>

    
   static bool i_am_chota(string a, string str2)
{
    int n1 = a.size(), n2 = str2.size();
  
    if (n1 < n2){
        
        return true;

    }

    else if(n2 < n1){

        return false;

    }
  
    for (int i = 0; i < n1; i++){

        if (a[i] < str2[i]){

            return true;

        }

        else if (a[i] > str2[i]){

            return false;

        }

    }

    return false;
}

static void reverse(string &a){

    string b;
    for(int i=a.size()-1;i>=0;i--){
        b.push_back(a[i]);
    }
    a=b;

}
  
static string findDiff(string str1, string str2){

    if (i_am_chota(str1, str2)){

        swap(str1, str2);

    }
  
    string str = "";
  
    int n1 = str1.length(), n2 = str2.length();
  
    reverse(str1);

    reverse(str2);
  
    int carry = 0;
  
    for (int i = 0; i < n2; i++) {
  
        int use2  = ((str1[i] - '0') - (str2[i] - '0') - carry);
  
        if (use2 < 0) {
            use2 = use2 + 10;
            carry = 1;
        }

        else{

            carry = 0;
            
        }
  
        str.push_back(use2 + '0');

    }
  
    for (int i = n2; i < n1; i++) {

        int use = ((str1[i] - '0') - carry);
  
        if (use < 0) {
            use = use + 10;
            carry = 1;
        }

        else{

            carry = 0;

        }
  
        str.push_back(use + '0');
    }

    int idx=str.size()-1;

    while(str[idx--]=='0'){

       str.pop_back();
       if(str.size()==0){
        break;
       }

    }


    if(str==""){

        str="0";

    }
   
    reverse(str);
  
    return str;

}

string mod_nikaldo(string a,string b){

    int n=b.length();

    int s=a.length();

     string op=a.substr(0,n);

       int idx=n;
       
       while(idx!=s){
           
           while(!i_am_chota(op,b)){
   
               op=findDiff(op,b);
           
           }

           if(op=="0"){

               op="";

           }
           
           op.push_back(a[idx++]);
          
           
       }

       while(!i_am_chota(op,b)){

               op=findDiff(op,b);
        
      }

      return op;


}


    UnlimitedInt:: UnlimitedInt(string s){

         if(s[0]=='-'){

            s.erase(s.begin());

            size=s.size();
         
            int* a=new int[size];

            for(int i=0;i<size;i++){
                a[i]=s[i]-'0';
            }

            sign=-1;
          
            unlimited_int=a;

         }

         else {

          size=s.size();

          sign=1;
         
          int* a=new int[size];

          for(int i=0;i<size;i++){
            a[i]=s[i]-'0';
          }
          
          unlimited_int=a;

         }

    }; // Create from string 

    UnlimitedInt:: UnlimitedInt(int i){

         size=1;
         unlimited_int=new int[1];
         unlimited_int[0]=i; 
         sign=1;

    }; // Create from int

    UnlimitedInt:: UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz){
        capacity = cap;
        size=sz;
        unlimited_int=ulimited_int;
        sign=sgn;
    }; // Complete constructor

    UnlimitedInt:: ~UnlimitedInt(){

         if(unlimited_int!=NULL){

         delete[] unlimited_int;
         unlimited_int=NULL;

         }
    };

    // Return the size of the unlimited int
    int UnlimitedInt:: get_size(){
       return size;
    };

    // Return the unlimited_int array
    int* UnlimitedInt:: get_array(){
        return unlimited_int ;
    }; 

    // Get sign
    int UnlimitedInt:: get_sign(){
       return sign;
    };

    // Get capacity 
    int UnlimitedInt:: get_capacity(){
        return capacity;
    };

    // Implement these integer operations as they are defined for integers in mathematics
    // (Since there are no size restrictions)
    UnlimitedInt* UnlimitedInt:: add(UnlimitedInt* i1, UnlimitedInt* i2){

          int sgn1=i1->get_sign();
          int sgn2=i2->get_sign();
          
     if(sgn1==sgn2){

          string str1=i1->to_string();
          string str2=i2->to_string();

          if (str1.length() > str2.length()){

                swap(str1, str2);

          }
  
    string str = "";

    int n1 = str1.length(), n2 = str2.length();
  
    reverse(str1);
    reverse(str2);
  
    int carry = 0;
    for (int i=0; i<n1; i++) {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);

        str.push_back(sum%10 + '0');
  
        carry = sum/10;

    }
  
    for (int i=n1; i<n2; i++) {

        int sum = ((str2[i]-'0')+carry);

        str.push_back(sum%10 + '0');

        carry = sum/10;

    }
  
    if (carry){

        str.push_back(carry+'0');

    }
  
    reverse(str);
 
  UnlimitedInt* ab=new UnlimitedInt(str);

  ab->sign=sgn1;

  return ab;

   }        
      else {
       
        string str1=i1->to_string();

        string str2=i2->to_string();
        
        string res=findDiff(str1,str2);

        UnlimitedInt* ans=new UnlimitedInt(res);

        if(i_am_chota(str1,str2) && i1->get_sign()==1){

             ans->sign=-1;

        }
        else if(!i_am_chota(str1,str2) && i1->get_sign()==-1){

            ans->sign=-1;

        }

        else {

            ans->sign=1;

        }

        return ans;

    };

    }

    UnlimitedInt* UnlimitedInt:: sub(UnlimitedInt* i1, UnlimitedInt* i2){
         
            i2->sign = 0 - i2->sign;

            UnlimitedInt* use_me= add(i1,i2);

            i2->sign = 0 - i2->sign;

            return use_me;
          
    };

    UnlimitedInt* UnlimitedInt:: mul(UnlimitedInt* i1, UnlimitedInt* i2){

        string a=i1->to_string();

        string b=i2->to_string();

        int aa=a.size(); int bb=b.size();
        
        int *vec1=new int[aa];

    for (int i = 0; i < aa ; i++) {

        vec1[i] = a[aa - i - 1] - '0';

    }

    int* vec2=new int[bb];

    for (int i = 0; i < bb ; i++) {

        vec2[i] = b[bb - i - 1] - '0';

    }
 
    int* res=new int[aa+bb];

    for(int i=0;i<aa+bb;i++){

        res[i]=0;

    }
 
    for (int i = 0; i < bb; i++) {
        
        int carry = 0;

        for (int j = 0; j < aa; j++) {
            
            int i_am_prod = vec1[j] * vec2[i] + carry + res[i + j];

            carry = i_am_prod / 10;

            res[i + j] = i_am_prod % 10;

        }

        res[i + aa] = carry;

    }

    int pos=aa+bb;
    
    string i_am_the_answer(pos, '0');

    for (int i = 0; i < pos; i++) {

        i_am_the_answer[pos - i - 1] = res[i] + '0';

    }

    int idx=0;

    while(i_am_the_answer[idx]=='0'){

        idx++;

        if(idx==i_am_the_answer.size()){

            break;

        }

    }

    if(idx==i_am_the_answer.size()){
      
        return  new UnlimitedInt(0);

    }

    else {

        string me;

        for(int i=idx;i<i_am_the_answer.size();i++){

            me.push_back(i_am_the_answer[i]);

        }

        UnlimitedInt* ans_here = new UnlimitedInt(me);

        if(i1->get_sign() != i2->get_sign()){

            ans_here->sign=-1;

        }

        return ans_here;

    }

    
    UnlimitedInt* ans=new UnlimitedInt(i_am_the_answer);

    if(i1->get_sign() != i2->get_sign()){

        ans->sign=-1;

    }

    return ans;

    };

    UnlimitedInt* UnlimitedInt:: div(UnlimitedInt* i1, UnlimitedInt* i2){

       string a=i1->to_string();

       string b=i2->to_string();

       int s=a.size();

       int n=b.size(); 

       if(i_am_chota(a,b)){

         if(i1->get_sign() != i2->get_sign()){

             UnlimitedInt* hehe= new UnlimitedInt(1);

             hehe->sign=-1;

             return hehe;

         }

         else {
        
             return new UnlimitedInt(0);

         }
        
       }

       else {

       string op=a.substr(0,n);

       string ans;
       
       int idx=n;
       
       while(idx!=s){
           
           int count=0;

           while(!i_am_chota(op,b)){
   
               op=findDiff(op,b);
               
               count++;

           }

           ans.push_back(count+'0');

           if(op=="0"){

               op="";

           }
           
           op.push_back(a[idx++]);
          
           
       }

       int count=0;

       while(!i_am_chota(op,b)){

               op=findDiff(op,b);

               count++;

           }

         ans.push_back(count+'0');
         
         if(ans[0]=='0'){

             ans.erase(ans.begin());

         }
         
         UnlimitedInt* my2=new UnlimitedInt(ans);

         if(i1->get_sign()!=i2->get_sign()){

            if(op!="0"){

                my2=my2->add(my2,new UnlimitedInt("1"));

            }
      
            my2->sign=-1;

         }
         
         return my2;

       }

    };

    UnlimitedInt* UnlimitedInt:: mod(UnlimitedInt* i1, UnlimitedInt* i2){
       
         string str1=i1->to_string();

         string str2=i2->to_string();

        int n1 = str1.length(), n2 = str2.length();
        bool c;
    if (n1 < n2){
       c = true;
    }
    else if (n2 < n1){
        c= false;
    }
  
    else {
        for (int i = 0; i < n1; i++){

        if (str1[i] < str2[i]){

            c= true;
            break;

        }

        else if (str1[i] > str2[i]){

            c=false;
            break;

        }

        else {

            c=false;

        }

        }

    }

     if(c){

       UnlimitedInt* a=new UnlimitedInt(str1);
       a->sign=i1->get_sign();
       return a;

     }

     else {
       
       string bekar=i1->to_string();
       string aur_bekar=i2->to_string();

       string hadd_bekar=mod_nikaldo(bekar,aur_bekar);

       UnlimitedInt* a=new UnlimitedInt(hadd_bekar);

       if(i1->get_sign()==-1){

          a->sign=-1;         
 
       }

       return a;

     }

    };

    string UnlimitedInt:: to_string(){
        
        string b;

        for(int i=0;i<size;i++){

            b.push_back(unlimited_int[i]+'0');
            
        }
    
        return b;

    };
    