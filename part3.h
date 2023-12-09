//
// Created by justi on 14/11/2023.
//

#ifndef UNTITLED8_PART3_H
#define UNTITLED8_PART3_H
#include <string.h>
typedef struct rdv{
    int date_rdv[3];
    int heure_debut [2];
    int  herre_duree [2];
    char * objet;
    struct rdv* rdv;
}rdv;
typedef struct contact{
    char* name;
    rdv* rdv;
}contact;
void printString(char);

void afficher_contact(contact* x );
void supprimer_rdv(contact* x);


typedef struct s_cell{
    contact value;
    struct s_cell** next;
}s_cell;

typedef struct c_list{
    int level;
    s_cell ** head;
}c_list;
void print_lista(int level,c_list li);
void print_all_lista(c_list li);
c_list* create_list_contact();
s_cell* create_s_cell();
void créer_contact();
char *scanString(void);
int searclevel0part3(c_list * li, char * name);
#endif //UNTITLED8_PART3_H
