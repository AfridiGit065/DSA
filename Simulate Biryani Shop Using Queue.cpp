#include <iostream>
using namespace std;
class Queue{
public :
string name;
Queue * next;
Queue (string data){

this->name=data;
this->next=nullptr;
}
};
Queue *head =nullptr;
Queue *tail =nullptr;
void enqueue(string data){
    Queue *temp=new Queue(data);
if (head==NULL){
    head=temp;
    tail=head;
}
else {
    tail->next=temp;
    tail=temp;
}
}
void dequeue(){
if(head==nullptr){
    cout<<"No customer in the line"<<endl;
}
else {
    Queue* temp=nullptr;
    temp=head;
    head=head->next;
    cout<<"Give Biriyani to "<<temp->name<<endl;
    delete temp;
}
}
int length(){
Queue* temp=head;
int count=0;
while(temp!=NULL){
  count++;
  temp=temp->next;
}
return count;
}
int main (){
string name;
int option,c;

while(1){
    cout<<endl;
    cout<<"/ Welcome to Shariar's Biriyani Dine /"<< endl;
    cout<< "1. Add New Customer"<<endl;
    cout<<"2. Give Biryani to Customer"<<endl;
    cout<<"3. Total Customers in Line"<<endl;
    cout<<"4. Close Shop"<<endl;
    cout<<"Enter your choice : ";
    cin>>option;
    cin.ignore();
    switch(option){
        case 1:
        cout<<"Enter customer name : ";
        getline(cin,name);
        enqueue(name);
        cout<<name<<" is added in the list!"<<endl;
        break;
        case 2:
        dequeue();
        break;
        case 3:
         c=length();
        cout<<"Total "<< c <<" customer in the line "<<endl;
        break;
        case 4:
        return 0;
        break;
        default:
    cout << "Invalid option. Please select a valid option." << endl;
    }
}
return 0;
}
