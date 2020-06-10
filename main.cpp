//
//  main.cpp
//  Genome Alignment
//
//  Created by Hanyu on 5/29/20.
//  Copyright © 2020 Hanyu. All rights reserved.
//

#include <iostream>
#include "table_dot.h"
#include "table.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // take in 2 sequences
    string fir_seq;
    string sec_seq;
    cout << "Enter first sequence: " << endl;
    cin >> fir_seq;
    cout << "Enter second sequence: " << endl;
    cin >> sec_seq;
    
    /*
    if (fir_seq.size() != sec_seq.size()){
        cout << "ERROR: Sequence with different length!" << endl;
        return 1;
    }
     */
    
    //create a table
    unsigned long num1 = fir_seq.length() + 2;
    unsigned long num2 = sec_seq.length() + 2;
    table_dot * table [num2][num1];
    table[0][0] = new table_dot();
    table[0][0]->letter = true;
    table[1][1] = new table_dot();
    table[0][1] = new table_dot();
    table[0][1]->letter = true;
    table[1][0] = new table_dot();
    table[1][0]->letter = true;
    
    //place sequences on borders of the table
    for (int i = 0; i < fir_seq.size(); i++){
        table[0][i+2] = new table_dot();
        table[0][i+2]-> value = fir_seq[i];
        table[0][i+2]-> letter = true;
       //cout << "[" << table[0][i+2]->value << "] ";
    }
    for (int j = 0; j < sec_seq.size(); j++){
        table[j+2][0] = new table_dot();
        table[j+2][0]-> value = sec_seq[j];
        table[j+2][0]-> letter = true;
       //cout <<  "[" << table[j+2][0]->value << "] ";
    }
    

    
    for (int j = 1; j < fir_seq.size() +2; j++ ){
        for (int i = 1; i < sec_seq.size() +2; i++){
            
            if (i == 1 && j == 1 ){
                continue;
            } else {
                table[i][j] = new table_dot();
                table[i][j]->n1 = table[0][j]->value;
                table[i][j]->n2 = table[i][0]->value;
                if (i == 1){
                    table[i][j]->score = table[i][j-1]->score - 2;
                    table[i][j]->prev = table[i][j-1];
                }
                else if (j == 1){
                    table[i][j]->score = table[i-1][j]->score - 2;
                    table[i][j]->prev = table[i-1][j];
                }
                else {
                    float score1 = table[i-1][j]->score - 2;
                    float score2 = table[i][j-1]->score - 2;
                    float score3 = table[i-1][j-1]->score;
                    if (table[0][j]->value == table[i][0]->value){
                        score3++;
                    } else {
                        score3--;
                    }
                    
                    if ((score1 >= score2) & (score1 >= score3)){
                        table[i][j]->score = score1;
                        table[i][j]->prev = table[i-1][j];
                        table[i][j]->diagonal = false;
                    }
                    else if ((score2 >= score1) & (score2 >= score3)){
                        table[i][j]->score = score2;
                        table[i][j]->prev = table[i][j-1];
                        table[i][j]->diagonal = false;
                    }
                    else {
                        table[i][j]->score = score3;
                        table[i][j]->prev = table[i-1][j-1];
                        table[i][j]->diagonal = true;
                    }
                }
            }
            //cout << table[i][j]->score << endl;
        }
        
    }
    
    for (int i = 0; i < num2; i++){
        for (int j = 0; j < num1; j++){
            if (table[i][j]->letter){
                cout << "[" << table[i][j]->value << "] ";
            } else {
                cout << "[" << table[i][j]->score << "] ";
            }
            
            if (j == fir_seq.size()+1){
                cout << endl;
            }
            
        }
    }
    cout << endl;
    
    //_________________________________________________
    //second part --> TraceBack
    //_________________________________________________
    string record;
    table_dot * end = table[sec_seq.size()+1][fir_seq.size()+1];
    while(end->prev != NULL){
        cout << end->score  << endl;
        if (end->n1 == end->n2){
            record = "[" + end->n1 + "] " + record;
        } else {
            if(end->diagonal){
                record = "[Mismatch] " + record;
            } else{
                record = "[Gap] " + record;
            }
        }
        end = end->prev;
        
        
    }
    
    cout << "Shared Sequence: " << record << endl;
    return 0;
}


