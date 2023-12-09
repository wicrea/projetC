//
// Created by justi on 14/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "part3.h"
void afficher_contact(contact* x){
    if (x->rdv->objet){
        printf("%s",x->rdv->objet);
    }
}

void supprimer_rdv(contact* x){
    free (x->rdv);
}

char *scanString(void){
    char mystr[100] ;
    printf("name:");
    scanf("%s",mystr);
    char * name=malloc((strlen(mystr)+1)*sizeof(char));
    strcpy(name,mystr);
    return name ;
}


c_list* create_list_contact(){
    c_list* l = (c_list*) malloc(sizeof (c_list));
    l->level = 4;
    l->head=(s_cell**)malloc (4*(sizeof (s_cell)));
    for(int i=0;i<4;i++){
        l->head[i]=NULL;
    }
    return l;
}

s_cell* create_s_cell(contact c){
s_cell* x= (s_cell*)malloc ((sizeof (s_cell)));
x->value = c;
x->next = (s_cell**)malloc (4*(sizeof (s_cell*)));

for(int i=0;i<4;i++){
    x->next[i]=NULL;
}
return x;
}


void créer_contact(c_list* l) {
    contact x;
    char* name=scanString();
    x.name=name;
    s_cell *s;
    s = create_s_cell(x);
    if (l->head[0] == NULL) {
        for (int i = 0; i < 4; i++) {
            l->head[i] = s;
        }
    } else {
        s_cell *temp, *prev;
        temp = l->head[0];
        prev=temp;
        while ((temp!=NULL)&&(strcmp(temp->value.name,s->value.name)<0)) {
            prev=temp;
         temp=temp->next[0];

         ;}
                if(strcmp(s->value.name,prev->value.name)>0){
                    s->next[0]=temp;
                    prev->next[0]=s;
              if(prev->value.name[0]!=s->value.name[0]){
                  s_cell * tempniv3=l->head[3];
                  while ((tempniv3->next[3]!=NULL)&&(tempniv3->next[3]->value.name[0]<s->value.name[0])){
                    tempniv3=tempniv3->next[3];}
                    s->next[3]=tempniv3->next[3];
                    tempniv3->next[3]=s;
                    if((tempniv3->next[3]!=NULL)&&(tempniv3->next[3]->value.name[0]==s->value.name[0])){
                        s->next[3]=NULL;
                    }
                  while (((tempniv3->next[2]!=NULL)&&(strcmp(temp->value.name,tempniv3->value.name)<0))&&(tempniv3->next[2]->value.name[1]<s->value.name[1])){
                      tempniv3=tempniv3->next[2];
                  }
                  s->next[2]=tempniv3->next[2];
                  tempniv3->next[2]=s;
                  if((tempniv3->next[2]!=NULL)&&(tempniv3->next[2]->value.name[1]==s->value.name[1])){
                      s->next[2]=NULL;
                  }
                  while (((tempniv3->next[1]!=NULL)&&(tempniv3!=prev))&&(tempniv3->next[1]->value.name[2]<s->value.name[2])){
                      tempniv3=tempniv3->next[1];
                  }
                  s->next[1]=tempniv3->next[1];
                  tempniv3->next[1]=s;
                  if((tempniv3->next[1]!=NULL)&&(tempniv3->next[1]->value.name[2]==s->value.name[2])){
                      s->next[2]=NULL;
                  }
                  if((temp!=NULL)&&(temp->value.name[0]==s->value.name[0])){
                      temp->next[3]=NULL;
                      if((temp!=NULL)&&(temp->value.name[1]==s->value.name[1])){
                          temp->next[2]=NULL;
                          if((temp!=NULL)&&(temp->value.name[2]==s->value.name[2])){
                              temp->next[1]=NULL;
                      } }

                  }}
              else{ if(prev->value.name[1]!=s->value.name[1]){
                      s_cell * tempniv3=l->head[2];
                      s->next[2]=tempniv3->next[2];
                      tempniv3->next[2]=s;
                      while (((tempniv3->next[1]!=NULL)&&(tempniv3!=prev))&&(tempniv3->next[1]->value.name[2]<s->value.name[2])){
                          tempniv3=tempniv3->next[1];
                      }
                      s->next[1]=tempniv3->next[1];
                      tempniv3->next[1]=s;}
                  else{ if(prev->value.name[2]!=s->value.name[2]){
                              s_cell * tempniv3=l->head[1];
                          s->next[1]=tempniv3->next[1];
                              tempniv3->next[1]=s;}
                  }}

                }else{
                    if(temp==l->head[0]){
                        s->next[0]=temp;
                        for (int i=0;i<4;i++){
                            l->head[i]=s;
                            s->next[i]=temp;
                        }

                        if(temp->value.name[0]==s->value.name[0]){
                            s->next[3]=temp->next[3];
                            temp->next[3]=NULL;
                        if(temp->value.name[1]==s->value.name[1]){
                            s->next[2]=temp->next[2];
                            temp->next[2]=NULL;
                        if(temp->value.name[2]==s->value.name[2]){
                            s->next[1]=temp->next[1];
                            temp->next[1]=NULL;
                        }}}}


                    } }}
int searclevel0part3(c_list * li, char * name){
    s_cell* temp =li->head[0];
    int ch=0;
    while(temp!=NULL) {
        if(temp->value.name==name){
            return ch;
        }
        temp=temp->next[0];
        ch+=1;
    }
    return 0;
}
void print_lista(int level,c_list li){
    printf("list head_%d @-]-->",level);
    if (li.head[level]!=NULL){
        s_cell* temp= li.head[level];
        while (temp!= NULL){
            printf("[ %s|@-]-->",temp->value.name);
            temp=temp->next[level];
        }}
    printf("NULL");
}

void print_all_lista(c_list li){
    for(int i=0;i<4;i++){
        print_lista(i,li);
        printf("\n");
    }
}
