//
//  myfunctions.c
//  Node
//
//  Created by Rajabi Chavari, Hamed on 2019-07-16.
//  Copyright © 2019 Rajabi Chavari, Hamed. All rights reserved.
//

#include "myFunctions.h"

typedef struct Node Nodeptr;

typedef struct Node
{
    int data;
    Nodeptr* next;
    Nodeptr* previous;
} Nodeptr;

Nodeptr * start;
Nodeptr * endNode;

void printTheNodes() {
    if(start == NULL && endNode == NULL){
        puts("no code no print");
    }else {
        puts("print Nodes forward");
        Nodeptr * currentPtr = start;
        
        while(currentPtr != NULL){
            printf("%d",currentPtr->data);
            printf("-->");
            currentPtr = currentPtr->next;
        }
        printf("NULL\n");
        puts("-------------------");
        
        puts("");
    }
}

void printTheNodesBackwards() {
    
    if(start == NULL && endNode == NULL){
        puts("no code no print");
    }else {
         puts("print Nodes backward");
        Nodeptr * currentPtr = endNode;
        
        while(currentPtr != NULL){
            printf("%d",currentPtr->data);
            printf("-->");
            currentPtr = currentPtr->previous;
        }
        printf("NULL\n");
        puts("------------------");
        
        puts("");
    }
}

void addToLeft() {

    Nodeptr * currentNode= (Nodeptr *)malloc(sizeof(Nodeptr));
    
    if(start==NULL && endNode == NULL){
         //this is a first node
        start = currentNode;
        endNode = currentNode;
        printf("what's the data?");
        scanf("%d",&currentNode->data);
        currentNode->previous = NULL;
        currentNode->next = NULL;
        
    } else{
        printf("what's the new data?");
        scanf("%d",&currentNode->data);
        currentNode->previous = NULL;
        currentNode->next = start;
        start->previous = currentNode;
        start = currentNode;
        printTheNodes();
    }
}

void addToRight(){
    
    Nodeptr * currentNode = (Nodeptr *)malloc(sizeof(Nodeptr));
    
    if(start == NULL && endNode == NULL){
        //this is a first node
        start = currentNode;
        endNode = currentNode;
        printf("what is the data?");
        scanf("%d",&currentNode->data);
        currentNode->next = NULL;
        currentNode->previous = NULL;
    }else {
        
       //get new data from user
        
        puts("add one more node");
        scanf("%d",&currentNode->data);
        currentNode->next = NULL;
        currentNode->previous = endNode;
        endNode->next = currentNode;
        endNode = currentNode;
        printTheNodes();
        
    }
    
}

void addMiddleAfter() {
    
   Nodeptr * MiddleNode = (Nodeptr *)malloc(sizeof(Nodeptr));
    puts("after which node?");
    scanf("%d",&MiddleNode->data);
    Nodeptr * tempPtr;
    tempPtr = start;
    while(tempPtr->data != MiddleNode->data){
        
        tempPtr = tempPtr->next;
    }
    
    if(tempPtr == endNode){
        addToRight();
        
    }else{
    
    Nodeptr * currentNode = (Nodeptr *)malloc(sizeof(Nodeptr));
    puts("what is the data?");
    scanf("%d",&currentNode->data);
    Nodeptr * temppPtr;
    temppPtr = tempPtr->next;
    temppPtr->previous = currentNode;
    currentNode->next = temppPtr;
    tempPtr->next = currentNode;
    currentNode->previous = tempPtr;
    }
    printTheNodes();
    
}


void addMiddleBefore() {
    
    Nodeptr * MiddleNode = (Nodeptr *)malloc(sizeof(Nodeptr));
    puts("before which node?");
    scanf("%d",&MiddleNode->data);
    Nodeptr * tempPtr;
    tempPtr = endNode;
    while(tempPtr->data != MiddleNode->data){
        
        tempPtr = tempPtr->previous;
    }
    
    if(tempPtr == start){
        addToLeft();
        
    }else{
        
        Nodeptr * currentNode = (Nodeptr *)malloc(sizeof(Nodeptr));
        puts("what is the data?");
        scanf("%d",&currentNode->data);
        Nodeptr * temppPtr;
        temppPtr = tempPtr->previous;
        temppPtr->next = currentNode;
        currentNode->previous = temppPtr;
        tempPtr->previous = currentNode;
        currentNode->next = tempPtr;
    }
    printTheNodes();
    
    
}


void deleteNodeFromStart(){
    
     if(start == endNode ){
         //there is only 1 node
         free(start);
         start = NULL;
         endNode = NULL;
     }else{
         //there are more than 1 node
         Nodeptr * tempPtr;
         tempPtr = start->next;
         tempPtr->previous = NULL;
         free(start);
         start = tempPtr;
     }
    printTheNodes();
}


void deleteNodeFromEnd(){
    
    if(start == endNode ){
         //there is only 1 node
        free(endNode);
        start = NULL;
        endNode = NULL;
    }else{
    //there are more than 1 node
    Nodeptr * tempPtr;
    tempPtr = endNode->previous;
    tempPtr->next = NULL;
    free(endNode);
    endNode = tempPtr;
    }
    printTheNodes();
}

void menu() {
    puts("");
    printf("\t\twelcome, please select one\n");
    printf("\t\t1- add a node to left\n");
    printf("\t\t2- add a node to right\n");
    printf("\t\t3- add a node to middle after a node\n");
    printf("\t\t4- add a node to middle before a node\n");
    printf("\t\t5- printf the list forward\n");
    printf("\t\t6- printf the list backward\n");
    printf("\t\t7- delete a node (start)\n");
    printf("\t\t8- delete a node (end)\n");
    printf("\t\t0- exit\n");
    printf("? :  ");
}
