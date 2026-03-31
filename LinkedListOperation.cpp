#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node node;

node* createNode()
{
    node* nn=new node();
    printf("Enter data:");
    scanf("%d",&nn->data);
    nn->next = NULL;
    return nn;
}

void printList(node* head)
{
    node* temp = head;
    printf("Data in Linked List:\n\n");
    if(temp==NULL)
    {
        printf("No Data Found!\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n\n");
}

node* insert_head(node* head, node* nn)
{
    node* temp = head;
    if(head!=NULL)
    {
        nn->next=head;
    }
    head=nn;
    printf("Node inserted in Head!\n\n");
    return head;
}

node* insert_tail(node* head, node* nn)
{
    node* temp = head;
    if(temp==NULL)
    {
        head = insert_head(head,nn);
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    printf("Node inserted in Tail!\n\n");
    return head;
}

node* insertAtNthPosition(node* head, node* nn, int len, int pos)
{
    node* temp = head;
    if(pos==1)
    {
        head=insert_head(head,nn);
    }
    else if(pos==len+1)
    {
        head=insert_tail(head,nn);
    }
    else
    {
        for(int i=1; i<=pos-2; i++)
        {
            temp=temp->next;
        }
        nn->next=temp->next;
        temp->next=nn;
    }
    printf("Data inserted at nth position!\n\n");
    return head;
}

int ListSize(node* head)
{
    node* temp= head;
    int counter=0;
    while(temp != NULL)
    {
        counter++;
        temp=temp->next;
    }
    return counter;
}

void menu()
{
    printf("1) Print List\n");
    printf("2) Insert Data at Head\n");
    printf("3) Insert Data at Tail\n");
    printf("4) Size of Linked List\n");
    printf("5) Insert Data at Nth Position\n");
    printf("0) Exit\n");
    printf("Enter your choice:");
}

int main()
{
    node* head = NULL, *nn;
    int choice;
    menu();
    scanf("%d",&choice);

    while(choice!=0)
    {
        if(choice==1)
        {
            printList(head);
        }
        else if(choice==2)
        {
            nn= createNode();
            head = insert_head(head,nn);
        }
        else if(choice==3)
        {
            nn=createNode();
            head=insert_tail(head, nn);
        }
        else if(choice==4)
        {
            int len = ListSize(head);
            printf("List Size: %d\n\n",len);
        }
        else if(choice==5)
        {
            nn=createNode();
            int lsize = ListSize(head);
            printf("Enter position:");
            int pos;
            scanf("%d",&pos);
            if(pos>=1 && pos<=lsize+1)
            {
                head=insertAtNthPosition(head,nn,lsize, pos);
            }
            else
            {
                printf("Invalid Position!\n\n");
            }

        }
        else
        {
            printf("Invalid Choice!\n");
        }
        menu();
        scanf("%d",&choice);
    }

    printf("\nYour pressed the Exit button!\nbye...\n");
}
