#include<bits/stdc++.h>
using namespace std;
int main(){
    int i;
    for (i=1 ;i<=10;i+=1){//int 1 ni lopala decalre chesam kabbatti scope only inside
        cout<<"hi  "<<i<<'\n';
    }
    cout<<i<<endl;
    return 0;

    // while lloop 
    int i;
    while(i<=5){
        cout<<"hi"<<i<<endl;
        i=i+1;
    }
    //do while
    int i=2;
    do{
        cout<<"hi";
        i+=1;
    }
    while(i<=1);
    cout<<i;
    return 0;// okasari aiite pakka run aipoddi
}