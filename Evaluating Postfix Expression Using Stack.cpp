#include<iostream>
using namespace std;
class Stack{
    public:
int data;
Stack * next;
Stack (int data){
this->data =data;
this->next=nullptr;
}
};
Stack* head=nullptr;
void push(int data){
if (head==nullptr){
    Stack* temp = new Stack(data);
    head=temp;

}
else {
    Stack* temp=new Stack(data);
    temp->next=head;
    head=temp;
}
}
int topdata(){
    if(head!=nullptr) return head->data;
    else return -1;
}
int pop(){
    if(head==nullptr) {cout<<"Stack Underflow";
    return -1;}
    else{
        Stack* temp;
        int data=head->data;;
        temp=head;
        head=head->next;
        delete temp;
        return data;
    }

}
int postfix(char arr[]){

    for(int i=0;arr[i]!='\0';i++){
       if (arr[i]==' ') continue;
       if(arr[i]>='0' && arr[i]<='9'){
        push(arr[i]-'0');
       }
       else{
        int a=pop();
        int b=pop();
        int result=0;
        char opt=arr[i];
        switch(opt){
        case '+':result=b+a;break;
        case '-':result=b-a;break;
        case '*':result=a*b;break;
        case '/':
            if(a==0){
                cout<<"Error! Can't divide by 0";
                break;
            }
              else result=b/a; break;
        default:
            cout<< "Invalid operands\n";
            return 404;
        }
        push(result);
       }

    }
return pop();
}

int main(){
char inputchar[100];
cout << "Enter your input :";
cin.getline(inputchar, 100);
int result=postfix(inputchar);
cout<<result<<endl;
}
