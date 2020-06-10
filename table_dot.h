//
//  table_dot.h
//  Genome Alignment
//
//  Created by Hanyu on 5/29/20.
//  Copyright © 2020 Hanyu. All rights reserved.
//

#ifndef table_dot_h
#define table_dot_h
#include <string>

using namespace std;


class table_dot {
    
public:
    table_dot();
    table_dot(string base);
    table_dot(float num);
    
    table_dot * prev;
    string value;
    float score;
    bool letter;
    string n1;
    string n2;
    bool diagonal;
    
};




#endif /* table_dot_h */
