#include<bits/stdc++.h>
using namespace std;
int count(int n){
    /*
    int count=0;
    while(n>0){//dry run for example 523 checks >0 in secong loop 52>0 check chestadi
        //method 1
        int lastdigit=n%10;//lastdigit lo 3 pettukuniddi 
        count+=1;//0+1
        n=n/10;//52 
        //ikkada numbers reverse order lo extract avutai
        //time complexity is log10(n) as number of times its running is n/10
    }

    */
   //method 2
    int count=(int)(log10(n)+1);//okavela bitstdc++ add cheyyakapote math.h add cheyyali
    cout<<count;
    //return 0;//ikkada 0 ni return cheyalsinavasarledu
    //The function promises to return an integer value to the caller.
    



    /*all abouut return 0
    unction returns int but always returns 0 (meaningless).
explain 
what wil happen if i keep
make me understand clearly what happens with some cases


Good question — this is a very important C/C++ concept, and many students get confused here.
Let’s go slow and very clear, with cases + examples.

1️⃣ What does int check_armstrong(int n) mean?

When you write:

int check_armstrong(int n)


you are promising the compiler:

“This function will return an int value to whoever calls it.”

So the caller expects a meaningful integer back.

2️⃣ What does your function actually return?

Your function ends with:

return 0;


So no matter what number you pass, the function always returns 0.

⚠️ That means:

The result of calculation (armstrong / not armstrong)

is NOT returned

It is only printed inside the function

3️⃣ What happens if you call your function?
📌 Case 1: Simple call
check_armstrong(153);

What happens:

Output on screen → armstrong

Return value → 0

But return value is ignored

This works only because you print inside the function.

4️⃣ Case 2: Store return value
int x = check_armstrong(153);
cout << x;

Output:
armstrong0

Why?

Function prints "armstrong"

Function returns 0

x = 0

cout << x prints 0

⚠️ x does NOT tell you whether number is Armstrong.

5️⃣ Case 3: Use in if condition ❌ (IMPORTANT)
if(check_armstrong(153))
    cout << "Yes";
else
    cout << "No";

What happens?

check_armstrong(153) returns 0

if(0) → FALSE

Output:

armstrongNo


💥 WRONG LOGIC

Even though 153 is Armstrong, condition fails because:

0 means false

Your function always returns 0

6️⃣ Why returning 0 is meaningless here
Situation	Expected	Actual
Armstrong number	true / 1	0 ❌
Non-Armstrong number	false / 0	0 ❌

👉 Return value gives no information

So the function is lying about its purpose.

7️⃣ Correct ways to design the function
✅ Option 1: Return bool (BEST PRACTICE)
bool check_armstrong(int n){
    int dup = n, sum = 0;

    while(n){
        int d = n % 10;
        sum += d * d * d;
        n /= 10;
    }
    return sum == dup;
}


Usage:

if(check_armstrong(153))
    cout << "Armstrong";
else
    cout << "Not Armstrong";


✔ Logical
✔ Reusable
✔ Clean

✅ Option 2: Return int meaningfully
int check_armstrong(int n){
    int dup = n, sum = 0;

    while(n){
        int d = n % 10;
        sum += d * d * d;
        n /= 10;
    }

    if(sum == dup) return 1;
    else return 0;
}


Usage:

if(check_armstrong(370))
    cout << "Armstrong";

❌ Bad Practice (Your Original)
int check_armstrong(int n){
    ...
    cout<<"armstrong";
    return 0;
}


✔ Works only for printing
❌ Fails in logic usage
❌ Not reusable
❌ Misleading return type

8️⃣ Key Rule to Remember (EXAM GOLD ⭐)

If a function returns int or bool, the return value must represent the result of the computation — not just 0.

🔑 Final Intuition (One-line)

cout → shows output

return → sends result back

Your function shows the result but sends nothing useful back

If you want, I can also explain:

return vs cout using memory diagram

What happens if you don’t return anything at all

Why C allows this but it’s dangerous

Just say 👍

if we define func as int 
should we really have to return an int or no need

Short answer: YES. If a function is declared as int, you MUST return an int.
Long answer below — this is where most confusion comes from.

1️⃣ What the language rule says (very important)

In C++:

If a function has a non-void return type (int, float, bool, etc.),
it must return a value of that type on every possible execution path.

So for:

int func() {
    ...
}


✔ Returning an int is required
❌ Not optional

2️⃣ Then why does code sometimes “work” without returning?

This is the dangerous part.

Example:
int func() {
    cout << "Hello";
}

What happens?

Compiler may only give a warning

Program still runs

BUT → Undefined Behavior

⚠️ Undefined Behavior =

Program may work, crash, or give random values depending on compiler, OS, optimization.

3️⃣ What value is returned if you don’t return anything?

👉 Garbage value

Because:

Return value is taken from a CPU register (usually EAX / RAX)

That register contains whatever was there before

Example:
int x = func();
cout << x;


Possible outputs:

4198976
-858993460
0
123456


💥 Completely unpredictable.

4️⃣ Let’s see this with cases
📌 Case 1: Correct usage
int add(int a, int b){
    return a + b;
}


✔ Valid
✔ Predictable

📌 Case 2: Returning nothing ❌
int add(int a, int b){
    int c = a + b;
}


❌ No return statement
❌ Undefined behavior

Compiler warning:

control reaches end of non-void function

📌 Case 3: Conditional return (partially wrong)
int func(int x){
    if(x > 0)
        return 1;
}


❌ What if x <= 0?
❌ No return → undefined behavior

✔ Must be:

int func(int x){
    if(x > 0)
        return 1;
    return 0;
}

5️⃣ When is it OK to NOT return anything?

👉 ONLY when return type is void

void print_armstrong(int n){
    ...
    cout << "armstrong";
}


✔ Correct
✔ No return needed

6️⃣ So why do beginners use int main() and return 0?

Because:

int main(){
    ...
    return 0;
}


0 → program executed successfully

Non-zero → error code to OS

⚠️ In C++ only, if you omit return 0; in main(), compiler automatically inserts it.
❗ This is a special exception only for main(), not for other functions.

7️⃣ Summary Table (MEMORIZE THIS)
Function Type	Must Return?	What to Return
int	✅ Yes	integer value
bool	✅ Yes	true / false
float	✅ Yes	float value
void	❌ No	nothing
int main()	Optional	compiler adds return 0
    */
    
}
int reversal(int n){
    //input 123 output 321 
    //if ending with zeroes 4200 output should be 24
    int rev=0;
    while(n>0){
        int lastdigit=n%10;
        rev=(rev*10)+lastdigit;
        n=n/10;
    }
    cout<<rev;
}
int palindrome(int n){
    int dup=n;//endukante n=n/10 chesinappudu last iteration lo 0 ayiddi appudu n lo 0 srore ayiddi but if lo compare chesetappudu n ni manaki vachina reversal tho compare cheyyadam avvadu so duplicate creeate and store to compare
    int rev=0;
    while(n>0){
        int lastdigit=n%10;
        rev=(rev*10)+lastdigit;
        n=n/10;
    }
    if (dup==rev) cout<<"palindrome";
    else cout<<"not palindrome";
}
int check_armstrong(int n){
    //if 3 digit the power 3 add if n then power n for every digit
    //method 1
    int dup=n;
    int sum=0;
    while(n>0){
        int lastdigit=n%10;
        sum=sum+(lastdigit*lastdigit*lastdigit);//this only works for 3 digit
        n=n/10;
    }
    if (sum==dup) cout<<"armstrong";//ikkada okavela n tho compare cheste wrong vastadi endukante n will be 0 if it comes out of loop coz o kante takuva aitene vastadi
    else cout<<"not armstrong";//so we should check withh duplicate
}

void check_armstrong_method2(int n){
    int dup = n, sum = 0;
    int digits = 0, temp = n;
    while(temp){//number of digits kosam
        digits++;
        temp /= 10;
    }

    while(n){
        int d = n % 10;
        sum += pow(d, digits);
        n /= 10;
    }
    if(sum==dup) cout<<"its armstrong";
    else cout<<"its not armstrong";
}
void print_all_divisors(int n){
    /* method  1 brute force
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";//time complexity O(log(n));
        }}
    */
   //method 2 
   vector<int>lst;

   for(int i=1;i*i<=n;i++){//here instead of using sqrt func which take some more time we can use i*i<n
    if (n%i==0){
        lst.push_back(i);
        //time complexity O(sqrt(n));
    
    if((n/i)!=i){
        lst.push_back(n/i);
        //to avoid printing square root twice in case of perfect square
    }
   }
   //below ones time complexity is O(nlogn) as we are sorting the list of divisors which can be at max n in case of n is even and prime number
   //as here n is number of factors 
}sort(lst.begin(),lst.end());
for (auto it :lst) cout<<it<<" ";
//for printing this o(n)
    //as we dont know the size of output can use vector in cpp or list in java
}//so total time complexity is O(sqrt(n)+nlogn) which is better than O(n) of method 1

void check_prime(int n){
    /*brute force approach entante counter okati pettukuntav 
    only it should have 2 divisors 1 and itself so if counter equals 2 it is prime 
    count=0
    for(int i=1;i<=n;i++){
    if(n%i==0){
    counter+=1;}}
    if (count==2){
    cout <<its prime}
    */
   //method 2
   int count=0;
   for(int i=1;i*i<=n;i++){
    if (n%i==0){
        count++;
        if((n/i)!=i) count++;
    }}
    if(count==2) cout<<"its prime";
    else cout<<"its not prime";
}
void gcd_of_two_num(int a,int b){
    //method 1 can start with start
    /*int gcd=1;
    for (int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0){
            gcd=i;
        }
    }*/
   //method 2 starting from end
   /*
   for(int i=min(a,b);i>=1;i--){
      if(a%i==0 && b%i==0){
        gcd=i;
        break;//as we are starting from end we can break as soon as we find the first common divisor}}
   */
  //method 3
  while (a>0 && b>0){
    if(a>b) a=a%b;
    else b=b%a;
  }
  if (a==0) cout<<"gcd is"<<b;
  else cout<<"gcd is"<<a;//or else this line can directly write return a
  //time complexity of method 3 is O(log(min(a,b))) which is better than O(min(a,b)) of method 1 and 2


}

int main(){
    int n;
    cin>>n;
    //count(n);
    //reversal(n);
    //palindrome(n);
    //check_armstrong(n);
    //check_armstrong_method2(n);
    //print_all_divisors(n);
    //check_prime(n);
    //int a,b; cin>>a>>b;
    //gcd_of_two_num(a,b);
}

