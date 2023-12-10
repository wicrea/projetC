//
// Created by justi on 14/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "part3.h"


char *scanString(void){
    char mystr[100] ;
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


void créer_contact(c_list* l,char* name) {
    contact x; //cree le nouveau contact
    x.name=name;
    s_cell *s;
    s = create_s_cell(x);
    if (l->head[0] == NULL) { //pour la liste vide
        for (int i = 0; i < 4; i++) {
            l->head[i] = s;
        }
    } else {
        s_cell *temp, *prev;
        temp = l->head[0];
        prev=temp;
        while ((temp!=NULL)&&(strcmp(temp->value.name,s->value.name)<0)) { //lit la liste jusqu'à l'endroit où il faut ajouter
            prev=temp;
            temp=temp->next[0];

        }
        if(strcmp(s->value.name,prev->value.name)>0){ //verifie qu'on ajoute pas a l'en téte (au head)
            s->next[0]=temp;
            prev->next[0]=s;
            if(prev->value.name[0]!=s->value.name[0]){ //si
                s_cell * tempniv3=l->head[3];
                while ((tempniv3->next[3]!=NULL)&&(tempniv3->next[3]->value.name[0]<s->value.name[0])){ //trouve le prev au niveau3
                    tempniv3=tempniv3->next[3];}
                s->next[3]=tempniv3->next[3];
                tempniv3->next[3]=s;
                if((tempniv3->next[3]!=NULL)&&(tempniv3->next[3]->value.name[0]==s->value.name[0])){ // éviter une boucle infinie
                    s->next[3]=NULL;
                }
                while (((tempniv3->next[2]!=NULL)&&(strcmp(temp->value.name,tempniv3->value.name)<0))&&(tempniv3->next[2]->value.name[1]<s->value.name[1])){
                    tempniv3=tempniv3->next[2]; //trouve le prev au niveau2
                }
                s->next[2]=tempniv3->next[2];
                tempniv3->next[2]=s;
                if((tempniv3->next[2]!=NULL)&&(tempniv3->next[2]->value.name[1]==s->value.name[1])){ //eviter une boucle infinie
                    s->next[2]=NULL;
                }
                while (((tempniv3->next[1]!=NULL)&&(tempniv3!=prev))&&(tempniv3->next[1]->value.name[2]<s->value.name[2])){ // trouver le prev au niveau 1
                    tempniv3=tempniv3->next[1];
                }
                s->next[1]=tempniv3->next[1];
                tempniv3->next[1]=s;
                if((tempniv3->next[1]!=NULL)&&(tempniv3->next[1]->value.name[2]==s->value.name[2])){ //eviter boucle infinie
                    s->next[2]=NULL;
                }
                if((temp!=NULL)&&(temp->value.name[0]==s->value.name[0])){ //change les pointeurs de temp
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
                    tempniv3->next[2]=s; //si la première lettre est pareille et celle d'apres est differente

                    while (((tempniv3->next[1]!=NULL)&&(tempniv3!=prev))&&(tempniv3->next[1]->value.name[2]<s->value.name[2])){
                        tempniv3=tempniv3->next[1]; //cherche le temp au niveau 1
                    }
                    s->next[1]=tempniv3->next[1];
                    tempniv3->next[1]=s;}
                else{ if(prev->value.name[2]!=s->value.name[2]){ //si les deux premières lettres sont pareilles et les autres sont differentes
                        s_cell * tempniv3=l->head[1];
                        s->next[1]=tempniv3->next[1];
                        tempniv3->next[1]=s;}
                }}

        }else{  //si on doit changer la première valeur
            if(temp==l->head[0]){
                s->next[0]=temp;
                for (int i=0;i<4;i++){
                    l->head[i]=s;
                    s->next[i]=temp;
                }

                if(temp->value.name[0]==s->value.name[0]){ //changer les pointeurs de temp
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
        if(strcmp(temp->value.name,name)==0){
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
void createrdv( c_list* li){
    rdv* dr=(rdv*) malloc(sizeof(rdv));
    printf("Donner la date : L'annee ");
    scanf("%d",&(dr->date_rdv[0]));
    printf("Mois : ");
    scanf("%d",&(dr->date_rdv[1]));
    printf("Jour : ");
    scanf("%d",&(dr->date_rdv[2]));
    printf("Donner l'heure du debut : Heure : ");
    scanf("%d",&(dr->heure_debut[0]));
    printf("\nMin: ");
    scanf("%d",&(dr->heure_debut[1]));
    printf("\nDonner la duree : en Heure : ");
    scanf("%d",&(dr->herre_duree[0]));
    printf("\nMin : ");
    scanf("%d",&(dr->herre_duree[1]));
    printf("\nDonner l'objet : ");
    dr->objet=scanString();
    printf("\nDonner contact a qui ajouter le rendez-vous : ");
    char * name=scanString();
    s_cell* temp =li->head[0];
    s_cell * prev=temp;
    while((temp!=NULL)&&(strcmp(temp->value.name,name)==0)){
        temp=temp->next[0];
    }
    if(temp==NULL){
        créer_contact( li, name);
        while((temp!=NULL)&&(strcmp(temp->value.name,name)==0)){
            temp=temp->next[0];
        }
        if(temp->value.rdv!=NULL){
            temp->value.rdv=dr;
        }else{
            rdv* trmprdv=temp->value.rdv;
            while (trmprdv->next!=NULL){
                trmprdv=trmprdv->next;
            }
            trmprdv->next=dr;
        }
    }
}
void printtotrdv(char *name, c_list* li){ // ne fonctionne pas comme prévu
    s_cell * temp=li->head[0];
    while((temp!=NULL)&&(strcmp(temp->value.name,name)==0)){
        temp=temp->next[0];
    }
    if(temp==NULL){
        printf("Ce contact n'existe pas !"); /
    }
    else{
        rdv* rdv=temp->value.rdv;
        if(rdv==NULL){
            printf("Aucun rendez-vous !");
        }
        else{
            while (rdv!=NULL){
                printf("Date : %d/%d/%d\n",rdv->date_rdv[2],rdv->date_rdv[1],rdv->date_rdv[0]);
                printf("Debut : %dh:%d\n",rdv->heure_debut[0],rdv->heure_debut[1]);
                printf("Duree : %dh:%d\n",rdv->herre_duree[0],rdv->herre_duree[1]);
                printf("Objet : %s\n",rdv->objet);
            }
        }
    }
}
