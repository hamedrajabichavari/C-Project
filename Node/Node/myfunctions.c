//
//  myfunctions.c
//  Node
//
//  Created by Rajabi Chavari, Hamed on 2019-07-16.
//  Copyright © 2019 Rajabi Chavari, Hamed. All rights reserved.
//

#include "myFunctions.h"
#include <time.h>

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
//        printf("what's the data?");
//        scanf("%d",&currentNode->data);
        currentNode->data = printRandomNumber();
        currentNode->previous = NULL;
        currentNode->next = NULL;
        printTheNodes();
        
    } else{
//        printf("what's the new data?");
//        scanf("%d",&currentNode->data);
        currentNode->data = printRandomNumber();
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
        //printf("what is the data?");
        //scanf("%d",&currentNode->data);
        currentNode->data = printRandomNumber();
        currentNode->next = NULL;
        currentNode->previous = NULL;
        printTheNodes();
    }else {
        
       //get new data from user
        
        //puts("add one more node");
        //scanf("%d",&currentNode->data);
        
        currentNode->data = printRandomNumber();
        currentNode->next = NULL;
        currentNode->previous = endNode;
        endNode->next = currentNode;
        endNode = currentNode;
        printTheNodes();
        
    }
    
}

void addMiddleAfter() {
    
    if(start == NULL && endNode == NULL){
        puts("no code no print");
    }else {
    
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
//    puts("what is the data?");
//    scanf("%d",&currentNode->data);
    currentNode->data = printRandomNumber();
    Nodeptr * temp2Ptr;
    temp2Ptr = tempPtr->next;
    temp2Ptr->previous = currentNode;
    currentNode->next = temp2Ptr;
    tempPtr->next = currentNode;
    currentNode->previous = tempPtr;
    }
    printTheNodes();
    
    
}
}

void addMiddleBefore() {
    
    
    if(start == NULL && endNode == NULL){
        puts("no code no print");
    }else {
    
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
//        puts("what is the data?");
//        scanf("%d",&currentNode->data);
        currentNode->data = printRandomNumber();
        Nodeptr * temp2Ptr;
        temp2Ptr = tempPtr->previous;
        temp2Ptr->next = currentNode;
        currentNode->previous = temp2Ptr;
        tempPtr->previous = currentNode;
        currentNode->next = tempPtr;
    }
    printTheNodes();
    
    
}
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

void deleteNode() {
    
    if(start == NULL && endNode == NULL){
        puts("no code no print");
    }else {
        
        Nodeptr * MiddleNode = (Nodeptr *)malloc(sizeof(Nodeptr));
        puts("which node do you want to delete?");
        scanf("%d",&MiddleNode->data);
        Nodeptr * tempPtr;
        tempPtr = start;
        while(tempPtr->data != MiddleNode->data){
            
            tempPtr = tempPtr->next;
        }
        
        if(tempPtr == endNode){
           deleteNodeFromEnd();
            
       
        }else{
            if(tempPtr == start){
            deleteNodeFromStart();
            
            
        }
        else{
            
            Nodeptr * temp1Ptr;
            Nodeptr * temp2Ptr;
            temp1Ptr = tempPtr->previous;
            temp2Ptr = tempPtr->next;
            temp2Ptr->previous = temp1Ptr;
            temp1Ptr->next = temp2Ptr;
            free(tempPtr);
        }
        }
        printTheNodes();
        
        
    }
}


void deleteAllNodes() {
    
        
        while(start != NULL){
            
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
        }
    printTheNodes();
    }

void printNumbers(int oddOrEven){
    
    if( start == NULL){
        puts("list is empty");
        return;
    }
    Nodeptr * current = start;
    
    
    while(current != NULL){
        
        if(current->data % 2 == oddOrEven){
            printf("| %d |-->",current->data);
        }
        
        current = current->next;
    }
    
    puts("");
    
    
}

void replaceNode() {
    
    if(start == NULL && endNode == NULL){
        puts("no code no print");
    }else {
        
        int wrongdata;
        puts("which node do you want to replace?");
        scanf("%d",&wrongdata);
        Nodeptr * tempPtr;
        tempPtr = start;
        while(tempPtr->data != wrongdata){
            
            tempPtr = tempPtr->next;
        }
        int correctdata;
//        puts("what is the correct data?");
//        scanf("%d",&correctdata);
        correctdata = printRandomNumber();
        tempPtr->data = correctdata;
        
        printTheNodes();
        
        
    }
}

void sortTheNodes(){
    
    //there is no node
    if(start == NULL && endNode == NULL){
        puts("no code no print");
    }
    
    //there is at least 1 node
    else {
        printf("the size is %d\n",sizeoflist());
        Nodeptr * current;
        //comparing the nodes from start to end
        for(int i=0 ; i< sizeoflist() ; i+=1){
            //comparing from start to the node that already fixed
            for(int j =0 ; j<sizeoflist()-1-i ; j+=1){
                current = start;
                while(current->next != NULL){
                    swap (&current->data , &current->next->data);
                    current = current->next;
                }
            }
        }
            printTheNodes();
    }
        
        
        
}



//sizeoflist function

int sizeoflist(){
    
    int count = 0 ;
    Nodeptr * current = start;
    while ( current != NULL){
        count +=1;
        current = current->next;
    }
    return count;
}

//swap function

void swap ( int * a , int * b){
    
    int c;
    
    if(*a > *b){
        c = *a;
        *a = *b;
        *b = c;
    }
}

int printRandomNumber(){
   
    //unique number
    srand((unsigned int)time(NULL));
    
 //randomly creat 1 -10
    //for(int i = 0 ; i < 1 ; i+= 1){
     return rand()%100;
    
    //}
}

int isPrime(long number){
    
    if(number<2)
        //not a prime number return 0
        return 0;
    
    if(number==2)
        //prime number return 1
        return 1;
    
 
    for( int i = 2 ; i<= (int)sqrt(number); i+=1){
        if ( number % i == 0)
            return 0;
        
    }
            return 1;
    
}
    
void test(){
    for( int i = 0 , counter = 0; counter < 10002 ; i+= 1){
        if (isPrime(i) == 1){
            counter += 1;
            if (counter == 10001){
                printf("the 10001st prime number is : %d\n", i);
                break;
            }
            
        }
    }
    
}
    
void howmanytimes(){
    if(start == NULL && endNode == NULL){
        puts("no code no print");
    }else {
        int data;
        puts("which node do you want to know how many times repeat?");
        scanf("%d",&data);
        Nodeptr * tempPtr;
        tempPtr = start;
        int count = 0;
        while(tempPtr != endNode){
            
            while(tempPtr->data != data && tempPtr != endNode){
                tempPtr = tempPtr->next;

            }

            if(tempPtr == endNode){
                break;
                
            }
            
            
            count +=1;
            tempPtr = tempPtr->next;
       
        }
        if(endNode->data == data){
         printf("the times of %d is : %d\n",data,count+1);
        }else{
        printf("the times of %d is : %d\n",data,count);
        }
    }
}

void keepjustone(){
    
    if(start == NULL && endNode == NULL){
        puts("no code no print");
    }else {
        int data;
        puts("which node do you want to keep just one?");
        scanf("%d",&data);
        Nodeptr * tempPtr;
        tempPtr = start;
        int count = 0;
        while(tempPtr != endNode){
            
            while(tempPtr->data != data && tempPtr != endNode){
                tempPtr = tempPtr->next;
            }
            if(tempPtr == endNode){
                break;
                
            }
            
            count +=1;
            if(count == 1){
            tempPtr = tempPtr->next;
            }
            if(count == 2){
                Nodeptr * temp1Ptr;
                Nodeptr * temp2Ptr;
                temp1Ptr = tempPtr->previous;
                temp2Ptr = tempPtr->next;
                temp2Ptr->previous = temp1Ptr;
                temp1Ptr->next = temp2Ptr;
                free(tempPtr);
                tempPtr = temp2Ptr;
                count = 1;
            }
            
            
        }
        if(endNode->data == data){
            tempPtr = endNode->previous;
            tempPtr->next = NULL;
            free(endNode);
            endNode = tempPtr;
        }

         printTheNodes();
    }
}


void set(){
    
    if(start == NULL && endNode == NULL){
        puts("no code no print");
    }else {
        
//        puts("which node do you want to keep just one?");
//        scanf("%d",&data);
        Nodeptr * tempPtr;
        Nodeptr * current;
        tempPtr = start;
        current = tempPtr;
        for(int i=0 ; i< sizeoflist() ; i+=1){
            tempPtr = current;
            int data = tempPtr->data;
            int count = 0;
            while(tempPtr != endNode){
                
                while(tempPtr->data != data && tempPtr != endNode){
                    tempPtr = tempPtr->next;
                }
                if(tempPtr == endNode){
                    break;
                    
                }
                
                count +=1;
                if(count == 1){
                    tempPtr = tempPtr->next;
                }
                if(count == 2){
                    Nodeptr * temp1Ptr;
                    Nodeptr * temp2Ptr;
                    temp1Ptr = tempPtr->previous;
                    temp2Ptr = tempPtr->next;
                    temp2Ptr->previous = temp1Ptr;
                    temp1Ptr->next = temp2Ptr;
                    free(tempPtr);
                    tempPtr = temp2Ptr;
                    count = 1;
                }
                
            }
            if(endNode->data == data){
                tempPtr = endNode->previous;
                tempPtr->next = NULL;
                free(endNode);
                endNode = tempPtr;
            }
           
            current = current->next;
            
        }
        
        printTheNodes();
    }
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
    printf("\t\t9- delete a node\n");
    printf("\t\t10- delete all nodes\n");
    printf("\t\t11- print odd numbers\n");
    printf("\t\t12- print even numbers\n");
    printf("\t\t13- replace node\n");
    printf("\t\t14- sort the nodes\n");
    printf("\t\t14- print prime numbers\n");
    printf("\t\t0- exit\n");
    printf("? :  ");
}
