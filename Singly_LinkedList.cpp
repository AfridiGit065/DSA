#include<iostream>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node(int data){
    this->data=data;
    this->next=nullptr;
}
};
Node* head=nullptr;
Node* tail=nullptr;
 void PrintList(){
    cout<<"Printing List "<<endl;
       for(Node* i=head;i!= NULL;i=i->next){
        cout<<i->data<<" ";
    }
}
    void Insert(int data){
    if(head==nullptr){
        head=new Node(data);
        tail=head;
    }
    else {
        Node* temp=new Node(data);
        tail->next=temp;
        tail=temp;
    }
    }
int ListLength() {
       int count=0;
    for(Node* i=head;i!= NULL;i=i->next){
        count++;
    }
    cout<<endl<<"List Length : "<<count<<endl;
    return count;
   }
void FindSearch(int data){
   Node*  temp=head;
   int position=0;
   int flag=0;
   while (temp!=NULL){
    if (temp->data == data){
        flag = position;
    }
    temp=temp->next;
    position++;
   }
   if (flag==0)cout<< "Provided value not found"<<endl;
   else cout<<"Provided value found at "<<flag<<endl;
   }
   FindMidValue(){
       int count=0;
       int mid;
    for(Node* i=head;i!= NULL;i=i->next){
        count++;
    }

    mid= count/2;

   Node*  temp=head;
   int position=0;
   while (temp!=NULL){
    if (position == mid){
        cout<<"Mid value found at Node "<<mid<<" & the middle element is "<<temp->data;
    }
    temp=temp->next;
    position++;
   }
   }
void Update(int data){
int key;
int flag=0;
cout<<"Enter value to update: ";
cin>>key;
Node* temp=head;
while (temp!=NULL){
    if (temp->data == data){
        temp->data = key;
        flag=1;
    }
    temp=temp->next;}
    if(flag==0)cout<<"Wrong input given";
}
  void MinMaxSum(){
    int n=ListLength();
int arr[n];
Node* temp=head;
int i=0;
while(temp!=NULL){
    arr[i]=temp->data;
    i++;
    temp=temp->next;
}
for (int i=1;i<n;i++){
    int t=arr[i];
    int j=i;
    while (j>=1 && arr[j-1] > t){
        arr[j] = arr[j-1];
        j--;
    }

    arr[j]=t;
}

int k;
cout<<"Enter value of k : ";
cin>>k;
int sum = arr[k-1] + arr[n-k];
cout<<"Sum is : "<<sum<<endl;
}
void DeleteDuplicate(){
if (head==NULL )  {
    cout<<"nothing to delete";
}
else {
    Node* i=head;
    Node*j=nullptr;

    Node* OuterBack=nullptr;
    while (i!=NULL){
            int flag=0;
        j=i->next;
       Node* InnerBack=i;
        while(j!=NULL){
                if(i->data == j->data){

                    Node* temp=j;
                    InnerBack->next=j->next;

                    if(j==tail){//duplicate in tail
                            tail=InnerBack;
                            }
                    j=j->next;
                    delete temp;

                    flag=1;
                }

         else   {InnerBack=j;
             j=j->next;
             }
        }
        if (flag!=0){
                Node* temp=i;
                if(i==head){//removing head

                   head=i->next;
                   i=head;
                   delete temp;
                }
           else {
            OuterBack->next=i->next;
            i=i->next;
            delete temp;
            }
        }
      else  {OuterBack=i;
           i=i->next;}
    }
}
}
int main(){
 int option,data;
  while (true) {
        cout<< endl;
        cout << "Main Menu"<<endl;
        cout << "1. Insert \n";
        cout << "2. FindSearch\n";
        cout << "3. Print the list\n";
        cout << "4. ListLength \n";
        cout << "5. FindMidValue\n";
        cout << "6. MinMaxSum\n";
        cout << "7. Update\n";
        cout << "8. DeleteDuplicate\n";
        cout << "9. Exit. Good Programming\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                Insert(data);
                break;
            case 2:
                cout << "Enter data to search: ";
                cin >> data;
                FindSearch(data);
                break;
            case 3:
                PrintList();
                break;
            case 4:
                ListLength();
                break;
            case 5:
                FindMidValue();
                break;
            case 6:
                MinMaxSum();
                break;
            case 7:
                 cout << "Enter data which you want to update : ";
                cin >> data;
                Update(data);
                break;
            case 8:
                DeleteDuplicate();
                break;
            case 9:
                return 0;

            default:
                cout << "Invalid option. Please select a valid option." << endl;
        }
    }

    return 0;

}


