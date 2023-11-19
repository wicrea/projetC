//
// Created by justi on 23/10/2023.
//

#ifndef UNTITLED8_LIST_H
#define UNTITLED8_LIST_H
#include <math.h>
typedef struct s_d_cell
{ int value;
    int level;
    struct s_d_cell** next;

} t_d_cell;
typedef struct s_d_list
{
    int level;
    struct s_d_cell** head;
} t_d_list;
typedef struct s_d_cell t_d_cell, *p_d_cell;
p_d_cell  create_cell(int level,int value);
t_d_list* create_list(int level);
void print_list(int level,t_d_list li);
void print_all_list(t_d_list li);
void insert_cell(t_d_list* li,p_d_cell cell);
int searclevel0( t_d_list* li,int sh);
int serclevellast(t_d_list* li,int sh);
#endif //UNTITLED8_LIST_H
