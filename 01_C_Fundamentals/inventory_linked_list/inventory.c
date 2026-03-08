#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct box{
    char name[50];
    float price;
    struct box* next;
} Box;

typedef struct {
    Box* head;
    Box* tail; 
    int box_count;
} inventory;


void add_box_front(inventory* inv, char* name){
    Box* newbox=malloc(sizeof(Box));
    strcpy(newbox->name, name);
    newbox->next=inv->head;
    inv->head=newbox;
    if(inv->tail==NULL){inv->tail=newbox;}
    inv->box_count++;
    free(newbox);
}

void add_box_back(inventory* inv, char* name){
    Box* newbox=malloc(sizeof(Box));
    strcpy(newbox->name, name);
    newbox->next=inv->tail;
    inv->head=newbox;
    if(inv->head==NULL){inv->head=newbox;}
    inv->box_count++;
    free(newbox);
}

int main(){
    Box* box1=malloc(sizeof(Box));
    inventory* inv;
    strcpy(box1->name,"box1");
    printf("Box name: %s",box1->name);

    add_box_back(inv,"Boxxxx");
    
    printf("Box name: %s",box1->next->name);

    free(box1);
    return 0;
    
}

