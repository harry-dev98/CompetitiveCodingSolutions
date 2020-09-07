// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <deque>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
void reorderList(Node* head) {
    deque<Node*> DQ;
    Node *tmp = head->next;
    while(tmp != NULL){
        DQ.push_back(tmp);
        tmp = tmp->next;
    }
    int i=0;
    while(!DQ.empty()){
        if(i == 0){
            head->next = DQ.back();DQ.pop_back();
            i = 1;
        }
        else{
            head->next = DQ.front(); DQ.pop_front();
            i = 0;
        }
        head = head->next;
    }
    head->next = NULL;
}


void _reorderList(Node* head) {
    deque<Node*>DQ[2];
    int i=0;
    while(head != NULL){
        DQ[i].push_back(head);
        head = head->next;
        i = (i==0)?1:0;
    }
    i = 0;head = NULL;
    while(!DQ[0].empty() || !DQ[1].empty()){
        if(!DQ[i].empty()){
            if(head == NULL){
                head = DQ[i].front();DQ[i].pop_front();
            }
            else{
                head->next = DQ[i].front();DQ[i].pop_front();
                head = head->next;
            }
            
            if(DQ[i].empty()){
                continue;
            }
            head->next = DQ[i].back();DQ[i].pop_back();
            head = head->next;
        }
        i = (i==0)?1:0;
    }
    head->next = NULL;
    return;
}