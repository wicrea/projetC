
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
p_d_cell  create_cell(int level,int value){
    p_d_cell  new_cell =(p_d_cell)malloc (sizeof (t_d_cell));
    new_cell->level=level;
    new_cell->value=value;
    new_cell->next=(p_d_cell*)malloc (level*sizeof (p_d_cell));
    for(int i=0;i<level;i++){
        new_cell->next[i]=NULL;
    }
    return new_cell;
}
t_d_list* create_list(int level){
    t_d_list* l =(t_d_list*) malloc(sizeof (t_d_list));
    l->level=level;
    l->head=(p_d_cell*)malloc (level*sizeof (p_d_cell));
    for(int i=0;i<level;i++){
        l->head[i]=NULL;
    }
    return l;
}
void print_list(int level,t_d_list li){
    printf("list head_%d @-]-->",level);
if (li.head[level]!=NULL){
    p_d_cell temp= li.head[level];
    while (temp!= NULL){
        printf("[ %d|@-]-->",temp->value);
        temp=temp->next[level];
    }}
    printf("NULL");
}
void print_all_list(t_d_list li){
    for(int i=0;i<li.level;i++){
        print_list(i,li);
        printf("\n");
    }
}
void insert_cell(t_d_list* li,p_d_cell cell){
    int tplev=0;
    int test=1;
    while ((tplev!=li->level) &&((cell->value%(2*test))==0) ) {
        tplev++;
        test *= 2;
    }
    for(tplev;tplev>-1;tplev--){
        p_d_cell temp=li->head[tplev];
        if (li->head[tplev]!=NULL){
            while(temp->next[tplev]!=NULL && (temp->next[tplev]->value<=cell->value) ) {
                temp = temp->next[tplev];
            }

        cell->next[tplev]=temp->next[tplev];
        temp->next[tplev]=cell;
        }
        else{
            li->head[tplev]=cell;
        }
}}

int searclevel0( t_d_list* li,int sh){
    p_d_cell temp =li->head[0];
    while(temp!=NULL) {
        if(temp->value==sh){
            return 1;
        }
        temp=temp->next[0];
    }
    return 0;
}
int serclevellast(t_d_list* li,int sh){
    int tplev=(li->level)-1;
    p_d_cell temp=li->head[tplev];
    p_d_cell celt;
    while( (tplev>-1)&&(temp->value>sh)){
        tplev=tplev-1;
        temp=li->head[tplev];
    }
    while((temp!=NULL) &&( tplev>-1)){
        if(temp->value==sh){
            return 1;}
        celt=temp->next[tplev];
        if((celt!=NULL)&&(celt->value<=sh)){
            temp=temp->next[tplev];
        }
        else{
            tplev=tplev-1;
        }
    }
    return 0;
}