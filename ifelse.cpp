#include<bits/stdc++.h>
using namespace std;
///takes input age and tells if adult or not
/*
int main(){
    int age;//two lines continuation lo ila rayadaniki three lines documentaion ki at the start of ,code normal practice lo itla chestaru  
    cin>>age;
    if(age>=18){
        cout<<"pedda puku";}
    else{
        cout<<"chinna puku";}
    return 0;
    
int main(){
    int marks;
    cin>>marks;
    if(marks < 25){
        cout<<"F";
    }
    if(marks>=25 && marks<=44){
        cout<<"E"; 
    }
    if(marks>=45 && marks<=50){
        cout<<"D"; 
    }

    // ikkada 24 input ichina anni if execute avutay coz just if kabatti

    
}
    */
int main(){
    int marks;
    cin>>marks;
    if(marks < 25){
        cout<<"F";
    }
    else if(marks <45){
        cout<<"E";
        if (marks >40){
            cout<<"just pass ";//nested if idi
        }

    }
    //ikkada input 26 aite 2nd dantloki vastadi okavela 45 kanna ekkuva iste next dantloki veltadi 
}   