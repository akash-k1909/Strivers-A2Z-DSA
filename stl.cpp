#include<bits/stdc++.h>
//#include<math.h>//idi
//#include<string.h>//idi paidi annni stdc++.h lo untai

using namespace std;//if we dont include this we have to write std::for cin cout all those everytime

void print(){
    cout<<"akash"<<endl;//this function wont return anything
}
int sum(int a,int b){
    return a+b;//this functions should return something 
}

int main(){
    print();
    int c=sum(1,5);
    cout<<c;
    return 0;
}
//stl 
//algortithms 
//containers -> vectors,........
// functions
//iterators

void explainpair(){//in a pair can only store 2 variables
    pair<int ,int > p={1,3};
    cout<<p.first<<" "<<p.second;
    pair<int ,pair<int ,int >>a={1,{2,3}};
    cout<<p.first<<" "<<a.second.second<<" "<<a.second.first;
    //pair array
    pair<int,int>arr[]={{1,2},{2,3},{3,4}};
    cout<<arr[1].second;//pair can be printed as a datatype  

}
//vectors lo unna functions annni  manchiga nerchukunte migatavi list,queue,map,set
void explainvector(){
    //size can be changed unlike array
    //vector stores elements like array
    vector<int>v;//creates empty container{}
    v.push_back(1);
    v.emplace_back(2);//it dynamically incrceases size its size and pushes 2 at the back {1}-,{1,2}
    //mamuluga emplace faster than pushback
    vector<pair<int,int>>vec;
    vec.push_back({1,2});
    vec.emplace_back(3,4);//autpmatically assumes as a pair in this but not in push back
    vector<int>v(5,100);//{100,100,100,100,100}  5 instances of 100
    vector<int>v(5);//ikkada edoooka garbage value ichhidi compiler
    vector<int>v1(5,20);//{5 instances of 20}
    vector<int>v2(v1);//another container  ikkkada kuda 5 instances of 20 i mean copy avutai 


    cout<<v[0]<<" "<<v.at(0);//both same aa num ichiddi

    //iterator points to memory where the elemnt is 
    vector<int>:: iterator it=v.begin();
    it++;
    cout<<*(it)<<" ";//for suppose {20,10,15,6,7} output will be 10
    //*use chester i.e *(it) it gives value inside where it is pointed okavela just (it) run kodite afreeess idchid
    it=it +2;
    cout<<*(it)<<" ";// ikkada output will be 6


    vector<int>:: iterator it=v.end();//iterator will be pointing after 7(last element) but not 7 okavela 7 kavalante it--
    vector<int>:: iterator it=v.rend();//pointing to left of 20
    vector<int>:: iterator it=v.rbegin();//pointing to 7 if it++ it goes left think in reverse way,it++ will be 6
    cout<<v.back()<<" ";//back means here its 7 elelment at last

    //printing in vector 3 ways
    //1st
    for (vector<int>:: iterator it =v.begin(); it !=v.end();it++){
        cout<<*(it)<<" ";
    }
    //but stl vunnade simple way to write
    for (auto it=v.begin();it !=v.end();it++ ){
        cout<<*(it)<<" ";
    }// according to the data the datatype is automatically assigned i.e for example int v=5 ani iche badulu auto v=5 iste adhe ea datatype fit aitee adhi tiskuniddi okavaela em datatype toskovalo telinappudu idhi vadachu
    for (auto it: v){
        cout<<it<<" ";//here auto is datatype but not iterator
    }//this is for each loop
    //deleteion of a vector
    //{10,20,30,40}
    v.erase(v.begin()+1);//this removees 20 ,either you can give input as erase(iterator or the location or address)
    //{now it looks 10,30,40}

    //now for continous
    //{10,20,30,40,50} should remove 20,30
    v.erase(v.begin()+1,v.begin()+3);//parameters em ivvali ante start and end ki one add 
    //i.e [left include right not inluded see brackets)



    //insert function 
    vector<int>v(2,100);//{100,100}
    v.insert(v.begin(),300);//{300,100,100}
    v.insert(v.begin()+1,2,5);//{300,5,5,100,100}index ,number of elements ,numeber

    vector<int>copy(2,50);//{50,50} ikkada copy ani just manam icham name not inbuilt
    v.insert(v.begin(),copy.begin(),copy.end());//{50,50,300,5,5,100,100} ikkda okavela koddiga part of copy ivvalante start end part sarigga iste vachiddi


    //{10,20}
    cout<<v.size();//gives 2
    v.pop_back();//pop20 remaining {10}

    //v1->{10,20}
    //v2->{30,40}
    v1.swap(v2);//v1 to ve and v2 to v1

    v.clear();//erase the vector {}
    cout<<v.empty();//if vector is empty returns true else fasle
}
//insert in vector is costly(time complexity) than list (push front)
void explainList(){
    list<int> ls;//ikkkada front kuda undiddi compared to vector

    ls.push_back(1);//{1}
    ls.emplace_back(2);//{1,2}
    //for veector singly linked list is maintained but for list ,doubly linekd list is maintained

    ls.push_front(5);//{5,1,2}
    ls.emplace_front();
    //rest functions same as vector 
    //begin,end,rbegin,rend,clear,insert,size,swap,empty
}
void explainDeque(){
    deque<int>dq;
    dq.push_back(1);//{1}
    dq.emplace_back(2);//{1,2}
    dq.push_front(4);//{4,1,2}
    dq.emplace_front(3);//{3,4,1,2}

    dq.pop_back();//{3,4,1}
    dq.pop_front();//{4,1}

    dq.back();
    dq.front();
    //rest functions same as vector
}
void explainStack(){
    stack<int>st;//lifo last in first out
    st.push(1);//{1}
    //indexing vadalem stack lo st[2] is invalid
    st.push(2);//{2,1}
    st.push(3);//{3,2,1}
    st.push(4);//{4,3,2,1}
    st.emplace(5);//{5,4,3,2,1}

    cout<<st.top();//{5} is still in the stack
    st.pop();//now st looks {4,3,2,1}
    //in stack only 3 main functions push,pop,top
    cout<<st.top();//{4}

    cout<<st.size();//4
    cout<<st.empty();//false
    stack<int>st1,st2;
    st1.swap(st2);
    

}
