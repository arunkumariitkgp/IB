//
//  main.c
//  Lists
//
//  Created by Arun Kumar on 10/02/17.
//  Copyright © 2017 Pervacio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* reverseIterative(struct Node* head);
struct Node* removeDuplicatesFromSortedList(struct Node *head);
int formNumber(struct Node *head);

void insertAtAnyPosition(struct Node **head, int data, int position){
    struct Node *temp = *head;
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    if (position == 1) {
        new->next = *head;
        *head = new;
        return;
    }
    for (int i = 0; i < position - 2; i ++) {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
}

void printList(struct Node *head){
    while (head != NULL) {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void implementList(){
    struct Node *head = NULL;
//    for (int i = 0; i < 20; i ++) {
//        insertAtAnyPosition(&head, 1, i);
//    }
    insertAtAnyPosition(&head, 1, 1);
    insertAtAnyPosition(&head, 2, 2);
    insertAtAnyPosition(&head, 3, 3);
    insertAtAnyPosition(&head, 4, 4);
    insertAtAnyPosition(&head, 5, 5);
    printList(head);
    printf("NUM is : %d\n",formNumber(head));
    printList(head);
}

int getCount(struct Node *head){
    int c = 0;
    while(head != NULL) {
        c ++;
        head = head->next;
    }
    return c;
}

struct Node* getIntersectionNode(struct Node* A, struct Node* B) {
    int lenA = getCount(A);
    int lenB = getCount(B);
    int d,i;
    if(lenA > lenB) {
        d = lenA - lenB;
        for(i = 0; i < d; i ++)
            A = A->next;
    }
    else{
        d = lenB - lenA;
        for(i = 0; i < d; i ++)
            B = B->next;
    }
    while(A != NULL && B != NULL) {
        if(A == B)
            return A;
        A = A->next;
        B = B->next;
    }
    return NULL;
}

struct Node* reverseIterative(struct Node* head){
    struct Node *prev = NULL, *current, *next;
    current = head;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

//HEAD IS A GLOBAL VAR IN THIS CASE
struct Node *head;
void reverseRecursive(struct Node* P){
    if(P->next == NULL){
        head = P;
        return;
    }
    reverseRecursive(P->next);
    P->next->next = P;
    P->next = NULL;
}

/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 */

struct Node* removeDuplicatesFromSortedList(struct Node *head){
    struct Node *temp = head, *prev;
    prev = NULL;
    int data = INT_MAX;
    while(temp != NULL) {
        if(temp->data == data) {
            prev->next = temp->next;
            temp = temp->next;
        }
        else {
            data = temp->data;
            prev = temp;
            temp = temp->next;
        }
    }    return head;
}

/*
 Swap nodes in a linked list without swapping data
 Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. Swapping data of nodes may be expensive in many situations when data contains many fields.
 
 It may be assumed that all keys in linked list are distinct.
 
 Examples:
 
 Input:  10->15->12->13->20->14,  x = 12, y = 20
 Output: 10->15->20->13->12->14
 
 Input:  10->15->12->13->20->14,  x = 10, y = 20
 Output: 20->15->12->13->10->14
 
 Input:  10->15->12->13->20->14,  x = 12, y = 13
 Output: 10->15->13->12->20->14
 This may look a simple problem, but is interesting question as it has following cases to be handled.
 1) x and y may or may not be adjacent.
 2) Either x or y may be a head node.
 3) Either x or y may be last node.
 4) x and/or y may not be present in linked list.
 
 How to write a clean working code that handles all of the above possibilities.
 
 We strongly recommend to minimize your browser and try this yourself first.
 
****The idea it to first search x and y in given linked list. If any of them is not present, then return. While searching for x and y, keep track of current and previous pointers. First change next of previous pointers, then change next of current pointers. Following are C and Java implementations of this approach.
 */
void swapNodes(struct Node **head_ref, int x, int y)
{
    // Nothing to do if x and y are same
    if (x == y) return;
    
    // Search for x (keep track of prevX and CurrX
    struct Node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x)
        {
        prevX = currX;
        currX = currX->next;
        }
    
    // Search for y (keep track of prevY and CurrY
    struct Node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y)
        {
        prevY = currY;
        currY = currY->next;
        }
    
    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;
    
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        *head_ref = currY;
    
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else  // Else make x as new head
        *head_ref = currX;
    
    // Swap next pointers
    struct Node *temp = currY->next;
    currY->next = currX->next;
    currX->next  = temp;
}

/*
 Pairwise swap elements of a given linked list by changing links
 Given a singly linked list, write a function to swap elements pairwise. For example, if the linked list is 1->2->3->4->5->6->7 then the function should change it to 2->1->4->3->6->5->7, and if the linked list is 1->2->3->4->5->6 then the function should change it to 2->1->4->3->6->5
 
 This problem has been discussed here. The solution provided there swaps data of nodes. If data contains many fields, there will be many swap operations. So changing links is a better idea in general. Following is a C implementation that changes links instead of swapping data.
 */
struct Node* swapPairs(struct Node* A) {
    if(A == NULL || A->next == NULL)
        return A;
    struct Node *curr = A->next, *prev = A;
    A = curr;
    while(curr != NULL) {
        struct Node *next = curr->next;
        curr->next = prev;
        if(next == NULL || next->next == NULL) {
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }
    return A;
}

//FORM LIST AS A NUMBER i.e 1->2->3->4->5->6->7 becomes an integer 7654321
int formNumber(struct Node *head) {
    int num = 0;
    if(head == NULL)
        return 0;
    num = formNumber(head->next);
    num = num * 10 + head->data;
    return num;
}

void insertAtEnd(int x, struct Node **head) {
    
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = x;
    new->next = NULL;
    if (*head == NULL) {
        new->next = *head;
        *head = new;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}
void insertAtBegining(int x, struct Node **head) {
    
    struct Node *nw = (struct Node *)malloc(sizeof(struct Node));
    nw->data = x;
    nw->next = *head;
    *head = nw;
}

/*
 Add Two Numbers as Lists
 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 
 342 + 465 = 807
 Make sure there are no trailing zeros in the output list
 So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
 */
struct Node* addLists(struct Node *h1, struct Node *h2) {
    struct Node *h3 = NULL;
    int carry = 0;
    while (h1 != NULL && h2 != NULL) {
        if (h1->data + h2->data + carry > 9) {
            insertAtBegining((h1->data + h2->data + carry) % 10, &h3);
            carry = 1;
        }
        else {
            insertAtBegining(h1->data + h2->data + carry, &h3);
            carry = 0;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    while (h1 != NULL) {
//        if (h1->data + carry) {
            if (h1->data + carry > 9) {
                insertAtBegining((h1->data + carry) % 10, &h3);
                carry = 1;
            }
            else {
                insertAtBegining(h1->data + carry, &h3);
                carry = 0;
            }
//        }
        h1 = h1->next;
    }
    while (h2 != NULL) {
//        if (h2->data + carry) {
            if (h2->data + carry > 9) {
                insertAtBegining((h2->data + carry) % 10, &h3);
                carry = 1;
            }
            else {
                insertAtBegining(h2->data + carry, &h3);
                carry = 0;
            }
//        }
        h2 = h2->next;
    }
    
    return reverseIterative(h3);
}

/*
 List Cycle
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 
 Try solving it using constant additional space.
 
 Example :
 
 Input :
 
 ______
 |     |
 \/    |
 1 -> 2 -> 3 -> 4
 
 Return the node corresponding to node 3.
 http://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
 */
struct Node* detectCycle(struct Node* A) {
    if(A == NULL)
        return NULL;
    struct Node *slow = A, *fast = A->next;
    while(fast && fast->next) {
        if(slow == fast){
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
     if (slow == fast)
     {
         slow = A;
         while (slow != fast)
         {
             slow = slow->next;
             fast = fast->next;
         }
    
         return fast;
     }
     else
    return NULL;
}

int main(int argc, const char * argv[]) {
    implementList();
    return 0;
}
