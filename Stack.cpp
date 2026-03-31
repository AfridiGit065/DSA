#include<iostream>
using namespace std;
class Stack{
int *arr;
int last,N;
public :
    Stack(int capacity){
        N=capacity;
    arr= new int [capacity];
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
        coout<<"Stack is empty"<<endl;
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
int main(){
    int c,choice,val;
cout<<"Enter stack capacity :";
cin>> c;
Stack s(c);

while(true){
        cout<<"1)Push"<<endl;
cout<<"2)Pop"<<endl;
cout<<"3)Peek element"<<endl;

cout <<"Enter your choice "<<endl;
cin>>choice;
    switch(choice){
case 1:
        cout<<"Enter the value :"<<endl;
        cin>>val;
        s.push(val);
        break;
case 2: s.pop();break;
case 3: cout<< "peek element is "<<s.peek()<<endl;break;
case 4: return 0;break;
   default : cout<<"Invalid input";
}
}



}
