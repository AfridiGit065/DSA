#include<iostream>
using namespace std;
class Stack{
char *arr;
int last,N;
public :
    Stack(int capacity){
        N=capacity;
    arr= new char [capacity];
    last=-1;
    }
void push(int val){

if(last==N-1){
    cout<<"Stack Overflow ";
}
else {
        last++;
    arr[last]=val;

    cout<<"pushed "<<arr[last]<<endl;

}

}
int pop(){
    int temp;
    if (last==-1){
        cout<<"Stack underflow"<<endl;
    }
    else {

        temp=arr[last];

        last--;
    }
    return temp;
}
int peek (){
    if (last==-1){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
else return arr[last];
}
bool isEmpty(){
if(last<0){
    return true;
}
else return false;
}
};
void delete_middle ( ){


}
int main(){
    int c,choice,val;
cout<<"Enter stack capacity :";
cin>> c;
Stack s(c);
string st;
cout<< "Enter your String "<<endl;
cin>> st;

for (char ch : st){
    s.push(ch);
}
string result="";
 while (!s.isEmpty()){
    result+=s.pop();
}
cout<<"Output : "<<result<<endl;
}

