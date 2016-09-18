//
//  joseph_circle.cpp
//  datastucture_test
//
//  Created by Jesse. on 9/17/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <stdio.h>
#include <iostream>

struct node{
    int payload;
    node *next;
    node(int payload) {this->payload = payload;};   //传初值 ???
}

class joseph_circle()
{
    node *tail;
    node *eliminate_ptr;
    
}