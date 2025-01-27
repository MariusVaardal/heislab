#include "Queue.h"

node createNode(){
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    return temp;
}

node addNode(node head, int value){
    node temp, p;
    temp = createNode();
    temp->data = value;
    if(head == NULL){
        head = temp;
    }
    else{
        p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    printf("%d", head->data);
    return head;
}

node clearVal(node head, int value){
    node temp, p;
    p = head;
    if (p == NULL){ // avbryter om køen er tom
        printf("komme viss head e NULL");
        return head;
    }
    if(p->next == NULL){ // om det ikke er flere elementer i køen sette head til NULL
        printf("Denne komme viss next e NULL");
        temp = p;
        p = NULL;
        free(temp);
        
        return p;
    }
    while (p->next != NULL){
        if (p->next->data == value){
            temp = p->next;
            p->next = p->next->next;
            free(temp);
        }
        else{
            p = p->next;
        }
    }
    // Legg inn til å fjerne bakerst også
    return head;
}

node printQueue(node head){
    node p;
    p = head;
    while (1)
    {
        if (p == NULL)
        {
            return head;
        }
        printf("%d ", p->data);
        p = p->next;
    }
}

node clearQueue(node head){
    node temp, p;
    p = head;
    if(head == NULL){
        return head;
    }
    while(p->next != NULL){
        temp = p->next;
        p->next = p->next->next;
        free(temp);
    };
    temp = p->next;
    free(temp);
    temp = p;
    p = NULL;
    free(temp);
    // Legg inn til å håndtere bakerst
    // og kanskje tilbake til NULL
    return p;
}

node addFloor(node head, int floor){
    head = addNode(head, floor);
    return head;
}