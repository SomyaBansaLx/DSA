/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedrational.h"
//#include "ulimitedint.cpp"

bool i_am_zero(UnlimitedRational* a){
  
if(a->get_q()->get_size()==1){

    if(a->get_q()->to_string()=="0"){

        return true;

    }

  }

  return false;

}

bool small_hun(string a, string str2)
{
    
    int n1 = a.length(), n2 = str2.length();
  
    if (n1 < n2){

        return true;

    }

    if (n2 < n1){

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

void rev_krdo(string &a){

    string b;

    for(int i=a.size()-1;i>=0;i--){

        b.push_back(a[i]);

    }

    a=b;

}
  

string diff_nikaldo (string a, string b){

    if (small_hun(a, b)){

        swap(a, b);

    }
  
   
    string str = "";
  
    int n1 = a.length(), n2 = b.length();
  
    rev_krdo(a);

    rev_krdo(b);
  
    int carry_lelo  = 0;
  
    for (int i = 0; i < n2; i++) {
  
        int gg = ((a[i] - '0') - (b[i] - '0') - carry_lelo );
  
        if (gg < 0) {

            gg = gg + 10;
            carry_lelo = 1;

        }
        else{
            
            carry_lelo = 0;

        }
  
        str.push_back(gg + '0');

    }

    for (int i = n2; i < n1; i++) {

        int gg = ((a[i] - '0') - carry_lelo );
  
        if (gg < 0) {

            gg = gg + 10;
            carry_lelo = 1;

        }

        else{

            carry_lelo = 0;

        }
  
        str.push_back(gg + '0');
        
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
 
    rev_krdo(str);
  
    return str;

}

string mod_nikaldoo(string a,string b){

    int n=b.length();

     int s=a.length();

      string op=a.substr(0,n);

       int idx=n;
       
        while(idx!=s){
           
           while(!small_hun(op,b)){
   
               op=diff_nikaldo (op,b);
             
           }

           if(op=="0"){

               op="";

           }
           
           op.push_back(a[idx++]);
              
       }

       while(!small_hun(op,b)){

               op=diff_nikaldo (op,b);

      }

      return op;

}

std::string find_gcd(string a,string b){
    
    string o1=a;
    string o2=b;

    if (o1 == "0")
        return o2;
    if (o2 == "0")
        return o1;
 
    if (o1 == o2)
        return o1;
 
    if (small_hun(o2,o1)){

        return find_gcd(mod_nikaldoo(o1,o2),o2);

    }

    else {

        return find_gcd(o1,mod_nikaldoo(o2,o1));

    }

}

UnlimitedRational::UnlimitedRational(){



};
    
UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den){

        p=num;
        q=den;
        
};

UnlimitedRational::~UnlimitedRational(){
    
    if(p!=NULL){

      p->~UnlimitedInt();

    }
    
    if(q!=NULL){

      q->~UnlimitedInt();

    }

    p=NULL;
    q=NULL;

};

UnlimitedInt* UnlimitedRational::get_p(){
      return p;
};

UnlimitedInt* UnlimitedRational::get_q(){
    return q;
};

string UnlimitedRational::get_p_str(){
     return p->to_string();
}; // Return the numerator as a string

string UnlimitedRational::get_q_str(){
   return q->to_string();
}; 
    
string UnlimitedRational::get_frac_str(){
   string a=get_p_str();
   string b=get_q_str();
   string c= a + "/" + b ;

   if(p->get_sign() != q->get_sign()){
    c="-"+c;
   }

   return c;

}; // Return the rational as "p/q"

    // Rational arithmetic operations
UnlimitedRational* UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2){

    if(i_am_zero(i2)){

       UnlimitedInt* b=new UnlimitedInt(0);

       return new UnlimitedRational(b,b);

    }

    if(i_am_zero(i1)){

       UnlimitedInt* b=new UnlimitedInt(0);
       return new UnlimitedRational(b,b);

    }

     UnlimitedInt* num1=i1->get_p();
     UnlimitedInt* dem1=i1->get_q();
     UnlimitedInt* num2=i2->get_p();
     UnlimitedInt* dem2=i2->get_q();

     UnlimitedInt* mul1=num1->mul(num1,dem2);
     UnlimitedInt* mul2=num1->mul(num2,dem1);
     UnlimitedInt* mul3=num1->mul(dem1,dem2);

     UnlimitedInt* ad=num1->add(mul1,mul2);

string a=ad->to_string();
string b=mul3->to_string();
string c=find_gcd(a,b);
UnlimitedInt* opr=new UnlimitedInt(c);
UnlimitedInt* num=num1->div(ad,opr);
UnlimitedInt* dem=num1->div(mul3,opr);

   return new UnlimitedRational(num,dem);
};
UnlimitedRational* UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2){

    if(i_am_zero(i2)){

       UnlimitedInt* b=new UnlimitedInt(0);
       return new UnlimitedRational(b,b);

    }

    if(i_am_zero(i1)){

       UnlimitedInt* b=new UnlimitedInt(0);
       return new UnlimitedRational(b,b);

    }
    
     UnlimitedInt* num1=i1->get_p();
     UnlimitedInt* dem1=i1->get_q();
     UnlimitedInt* num2=i2->get_p();
     UnlimitedInt* dem2=i2->get_q();

     UnlimitedInt* mul1=num1->mul(num1,dem2);
     UnlimitedInt* mul2=num1->mul(num2,dem1);
     UnlimitedInt* mul3=num1->mul(dem1,dem2);

     UnlimitedInt* ad=num1->sub(mul1,mul2);

string a=ad->to_string();
string b=mul3->to_string();
string c=find_gcd(a,b);
UnlimitedInt* opr=new UnlimitedInt(c);
UnlimitedInt* num=num1->div(ad,opr);
UnlimitedInt* dem=num1->div(mul3,opr);

  return new UnlimitedRational(num,dem);
  
};


UnlimitedRational* UnlimitedRational::mul(UnlimitedRational* i1, UnlimitedRational* i2){

    if(i_am_zero(i2)){

       UnlimitedInt* b=new UnlimitedInt(0);
       return new UnlimitedRational(b,b);

    }
    if(i_am_zero(i1)){

       UnlimitedInt* b=new UnlimitedInt(0);
       return new UnlimitedRational(b,b);

    }

     UnlimitedInt* num1=i1->get_p();
     UnlimitedInt* dem1=i1->get_q();
     UnlimitedInt* num2=i2->get_p();
     UnlimitedInt* dem2=i2->get_q();

     UnlimitedInt* mul1=num1->mul(num1,num2);
     UnlimitedInt* mul3=num1->mul(dem1,dem2);

     string a=mul1->to_string();
     string b=mul3->to_string();
     string c=find_gcd(a,b);
     UnlimitedInt* opr=new UnlimitedInt(c);
     mul1=num1->div(mul1,opr);
      mul3=num1->div(mul3,opr);
     
     
     return new UnlimitedRational(mul1,mul3);
};
UnlimitedRational* UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2){

    if(i2->get_p()->get_size()==1){

        if(i2->get_p()->to_string()=="0"){

       UnlimitedInt* b=new UnlimitedInt(0);
       return new UnlimitedRational(b,b);

    }

    }

    if(i_am_zero(i1)){

       UnlimitedInt* b=new UnlimitedInt(0);
       return new UnlimitedRational(b,b);

    }

    if(i_am_zero(i2)){

       UnlimitedInt* b=new UnlimitedInt(0);
       return new UnlimitedRational(b,b);

    }

     UnlimitedInt* num1=i1->get_p();
     UnlimitedInt* dem1=i1->get_q();
     UnlimitedInt* num2=i2->get_p();
     UnlimitedInt* dem2=i2->get_q();

     UnlimitedInt* mul1=num1->mul(num1,dem2);
     UnlimitedInt* mul3=num1->mul(dem1,num2);

     string a=mul1->to_string();
     string b=mul3->to_string();
     string c=find_gcd(a,b);
     UnlimitedInt* opr=new UnlimitedInt(c);
     mul1=num1->div(mul1,opr);
     mul3=num1->div(mul3,opr);
     
     
     return new UnlimitedRational(mul1,mul3);
};

//   int main(){

//      UnlimitedInt obj1("0");

//  //   cout<<obj1.to_string()<<"  "<<obj1.get_size()<<endl;

//      UnlimitedInt obj2("-5023");
//  //    cout<<obj2.to_string()<<"  "<<obj2.get_size()<<endl;
//      UnlimitedInt obj3("-1");
//   //  cout<<obj3.to_string()<<"  "<<obj3.get_size()<<endl;
//      UnlimitedInt obj4("1");
// //     cout<<obj4.to_string()<<"  "<<obj4.get_size()<<endl;
//      UnlimitedRational obj5(&obj1,&obj2);
//      UnlimitedRational obj6(&obj3,&obj4);
//      cout<<obj5.get_frac_str()<<endl;
//      cout<<obj6.get_frac_str()<<endl;
//  //    UnlimitedRational* obj11=obj5.mul(&obj5,&obj6);
//      UnlimitedRational* obj11=obj5.add(&obj5,&obj6);
//      UnlimitedRational* obj7=obj11->sub(&obj6,&obj5);
//  //    UnlimitedInt* obj8=obj2.mul(&obj2,&obj4);
//     // UnlimitedInt* obj9=obj7->add(obj7,obj8);
//     // UnlimitedInt* obj10=obj2.mul(&obj2,&obj4);
//     cout<<obj7->get_frac_str()<<endl;
//   //   cout<<obj8->to_string()<<endl;
//  //    UnlimitedRational* obj11=obj5.div(&obj5,&obj6);
//     //   cout<<obj7->to_string()<<endl;
//     //  cout<<obj8->to_string()<<endl;
// //      cout<<obj9->to_string()<<endl;
// //      cout<<obj10->to_string()<<endl;
//        cout<<obj11->get_frac_str()<<endl;
//      return 0;
//  }