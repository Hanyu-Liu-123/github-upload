//
//  table_dot.cpp
//  Genome Alignment
//
//  Created by Hanyu on 5/29/20.
//  Copyright © 2020 Hanyu. All rights reserved.
//

#include "table_dot.h"
#include <string>

using namespace std;

table_dot:: table_dot(){
    score = 0;
    value = "X";
    prev = NULL;
    letter = false;
    n1 = "N1";
    n2 = "N2";
    diagonal = false;
    
}

table_dot:: table_dot(string base){
    score = 0;
    value = base;
    prev = NULL;
}

table_dot:: table_dot(float num){
    score = num;
    value = "X";
    prev = NULL;
}


