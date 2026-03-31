#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;
     void Insert(int data){
    if (head== NULL){
        head= new Node(data);
        tail=head;
}
        else {
        Node* temp= new Node(data);
        tail->next=temp;
        tail=temp;
        }
}
    void PrintList(){
    cout<<"Printing linklist : ";
    for (Node* i=head;i!=NULL;i=i->next){
        cout<< i->data<<endl;
    }
    }

    void ListLength(){
    int count=0;
    for (Node* i=head;i!=NULL;i=i->next){
       count++;
    }
    cout<<"length "<< count<<endl;
}

 void InsertSorted(int data){
    if (head==NULL){
    head= new Node(data);
    tail=head;
}
    else if (head->next == NULL){
    Node* temp= new Node(data);

        if(temp->data > head->data){
        tail->next=temp;
        tail=temp;
    }
        else {
            temp->next=head;
            tail=head;
            head=temp;
        }
}
    else {
    Node* temp= new Node(data);
    Node* front= head->next;
    Node* back= head;

        if (back->data > temp->data){
            temp->next=head;
            head=temp;
            front= head->next;
            back= head;
            tail=tail->next;
        }
   while (front!= NULL ){
        if(front->data > temp->data) {
                if(back->data < temp->data){
                    temp->next=front;
                    back->next =temp;

                }
                            }
            front=front->next;
            back=back->next;
    }
        tail=back;

        if (temp->data > tail->data){
            tail->next =temp;
            tail=temp;
        }
    }

}

void DeleteMin(){
    if (head==NULL) cout<<"Empty List";

    else{
    int min=head->data;
    Node* i=head;
   while(i !=NULL){//finding min
    if (min > i->data){
        min=i->data;
    }
    i=i->next;
}
 if(min ==head->data){
    Node* temp = head;
    head = head->next;
    delete temp;
 }

    Node* front=head;
    Node* back=nullptr;
  while(front != NULL){
    if(front->data == min){
            Node* temp = front;
          back->next=front->next;
        front= back->next;
            delete temp;
            }
     back=front;
    front=front->next;
}


}

}
int main (){
    int option,data;
  while (true) {
        cout<< endl;
        cout << "Main Menu"<<endl;
        cout << "1. Insert \n";
        cout << "2. InsertSort\n";
        cout << "3. Print the list\n";
        cout << "4. ListLength \n";
        cout << "5. DeleteMin\n";
        cout << "6. Exit. Good Programming\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                Insert(data);
                break;
            case 2:
                cout << "Enter data to insertSorted: ";
                cin >> data;
                InsertSorted(data);
                break;
            case 3:
                PrintList();
                break;
            case 4:
                ListLength();
                break;
            case 5:
                DeleteMin();
                break;
            case 6:
                return 0;

            default:
                cout << "Invalid option. Please select a valid option." << endl;
        }
    }

    return 0;

}
