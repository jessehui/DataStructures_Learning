//
//  main.cpp
//  datastucture_test
//
//  Created by Jesse. on 9/10/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <iostream>

/*
typedef struct Node{
    int payload;
    struct Node * next;

}node;
*/


struct node{
    int payload;
    node * next;
};              //c++中struct可以省略

int main()
{
    node *head = nullptr;
    //insert 10 nodes
    for(int i = 0; i<10; i++)
    {
        node * new_node = new node; //新建一个node
        new_node->payload = i*10;
        new_node->next = head;
        head = new_node;
    }
    
    node *iterator = head;
    while(iterator)
    {
        std::cout << iterator->payload << std::endl;
        iterator = iterator->next;
        
    }
}



