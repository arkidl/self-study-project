#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

struct Number
{
    int num;
    struct Number *next;
};

typedef struct Number node;
typedef struct Number *ndPtr;

void builtRandList(ndPtr *First,int n);
void addNodeEnd(ndPtr *First, node n);
void addNodeFront(ndPtr *First, node n);

void printList(ndPtr First);
int getSize(ndPtr First);

void deleteEndNode(ndPtr *First);
void deleteFrontNode(ndPtr *First);
void deleteNodeVal(ndPtr *First,node nd);
void deleteNodeAtPos(ndPtr *First,int pos);
void deleteAll(ndPtr *First);

void insertSorted(ndPtr *First, node n);

void fullscreen();
void displyMenu();



int main()
{

    ndPtr First;
    First=NULL;
    node nd;
    int i;
    int n;
    while(1)
    {
        displyMenu();

        printList(First);
        printf("\nEnter your choice: ");
        scanf("%d",&i);

        switch(i)
        {

        case 1:


            printf("Enter the number of nodes: ");

            scanf("%d",&n);
            builtRandList(&First,n);
            break;

        case 2:

            printf("Enter the number: ");
            scanf("%d",&nd.num);
            addNodeEnd(&First,nd);
            break;

        case 3:

            printf("Enter the number: ");
            scanf("%d",&nd.num);
            addNodeFront(&First,nd);
            break;

        case 4:

            printf("Enter the number: ");
            scanf("%d",&nd.num);
            insertSorted(&First,nd);
            break;

        case 5:
            deleteEndNode(&First);
            break;

        case 6:
            deleteFrontNode(&First);
            printList(First);
            break;

        case 7:

            printf("Enter the number to be deleted : ");
            scanf("%d",&nd.num);
            deleteNodeVal(&First,nd);
            break;

        case 8:

            printf("Enter the position of the number to be deleted (0 - n-1): ");
            int pos;
            scanf("%d",&pos);
            deleteNodeAtPos(&First,pos);
            break;

        case 9:
            deleteAll(&First);
            system("pause");
            break;

        case 10:
            printList(First);
            system("pause");
            break;

        case 11:

            printf("Size of the list is: %d\n",getSize(First));
            system("pause");
            break;

        case 12:
            return 0;

        default:

            printf(" Invalid option!\n");
            system("pause");
        }

    }
    return 0;
}

void displyMenu()
{
    fullscreen();
    system("cls");
    printf("*********************************\n");
    printf("*       List Of Operations      *\n");
    printf("*  ---------------------------  *\n");
    printf("*   1. Built random list.       *\n");
    printf("*   2. Insert to the END        *\n");
    printf("*   3. Insert to the FRONT      *\n");
    printf("*   4. Insert Sorted            *\n");
    printf("*   5. deleteEndNode            *\n");
    printf("*   6. deleteFrontNode          *\n");
    printf("*   7. deleteNodeVal            *\n");
    printf("*   8. deleteNodeAtPos          *\n");
    printf("*   9. deleteAllNodes           *\n");
    printf("*  10. DisplayList              *\n");
    printf("*  11. Size                     *\n");
    printf("*  12. Exit                     *\n");
    printf("*********************************\n");
    return;
}


void builtRandList(ndPtr *First,int n)
{
    if(n<1)
        return;

    srand(time(0));
    *First = (ndPtr) malloc(sizeof(node));
    ndPtr temp;
    temp = *First;
    temp->num = rand();
    temp->next = NULL;

    for(int i=1; i<n; i++)
    {
        temp->next = (ndPtr) malloc(sizeof(node));
        temp = temp->next;
        temp->num = rand();
        temp->next = NULL;
    }
    return;
}

void addNodeEnd(ndPtr *First, node n)
{
    if(First==NULL)
    {
        addNodeFront(First, n);
        return;
    }
    ndPtr newNode = (ndPtr) malloc(sizeof(node));
    ndPtr temp=*First;
    while(temp->next!=0)
    {
        temp= temp->next;
    }
    temp->next = newNode;
    *newNode = n;
    newNode->next = NULL;
    return;
}

void addNodeFront(ndPtr *First, node n)
{
    ndPtr newNode = (ndPtr) malloc(sizeof(node));
    *newNode = n;
    newNode->next = *First;
    *First = newNode;
    return;
}

void printList(ndPtr First)
{
    printf("\nThe list: ");
    ndPtr oneNode = First;
    while(oneNode != NULL)
    {
        printf("%d ", oneNode->num);
        oneNode = oneNode->next;
    }
    return;
}

int getSize(ndPtr First)
{
    ndPtr oneNode = First;
    int i=0;
    while(oneNode != NULL)
    {
        i++;
        oneNode = oneNode->next;
    }
    return i;
}

void deleteEndNode(ndPtr *First)
{
    if(First==NULL)
        return;
    ndPtr temp=*First, doubleNext=temp->next;
    while(doubleNext->next!=0)
    {
        temp= temp->next;
        doubleNext=temp->next;
    }
    free(doubleNext);
    temp->next = NULL;
    return;
}

void deleteFrontNode(ndPtr *First)
{
    if(First==NULL)
        return;

    ndPtr temp=*First;
    temp = temp->next;
    free(*First);
    *First = temp;
    return;
}

void deleteNodeVal(ndPtr *First, node nd)
{
    if(First==NULL)
        return;
    ndPtr temp=*First, doubleNext;
    doubleNext = temp->next;
    while(doubleNext->num!=nd.num&&doubleNext!=NULL)
    {
        temp=temp->next;
        doubleNext = temp->next;
    }
    temp->next = doubleNext->next;
    free(doubleNext);
    return;
}

void deleteNodeAtPos(ndPtr *First,int pos)
{
    if(First==NULL)
        return;
    ndPtr tmp = *First, theOtherNode;
    int i=1;
    while(i<pos-1)
    {
        i++;
        tmp = tmp->next;
    }
    theOtherNode= tmp->next;
    tmp->next=theOtherNode->next;
    free(theOtherNode);
    return;
}
void deleteAll(ndPtr *First)
{
    while(*First!=NULL)
    {
        deleteFrontNode(First);
    }
    return;
}


void insertSorted(ndPtr *First, node n)
{
    if(First==NULL)
    {
        addNodeFront(First, n);
        return;
    }
    ndPtr newNode = (ndPtr) malloc(sizeof(node));
    *newNode = n;
    ndPtr temp1= *First, temp2=temp1->next;
    while(temp2!=NULL)
    {
        if(temp1->num < newNode->num && temp2->num > newNode->num)
        {
            newNode->next = temp2;
            temp1->next = newNode;
            break;
        }
        temp1= temp2;
        temp2 = temp2->next;
    }

    return;
}

void fullscreen()
{
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN,0x1c, 0, 0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
