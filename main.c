#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <time.h>
#include "timer.h"
#include "part3.h"
int main(){
       /*
   FILE *log_file = fopen("log.txt","w");
   char format[] = "%d\t%s\t%s\n" ;
   char *time_lvl0;
   char *time_all_levels;
   int comp=0;
   srand(time(NULL));
   printf("donner une valeur a level");
   for(int level=7;level<=10;level++){
   t_d_list* li= create_list(level);
   int pi=1;
   for(int u=0;u<level;u++){
       pi*=2;
   }
   for(int i=1;i<pi;i++){
       p_d_cell cell= create_cell(level, i);
       insert_cell(li,cell);
   }
   srand(time(NULL));
       print_all_list(*li);
   int value=( rand() % pi) ;
   if (value==0)value=1;
       startTimer();
       print_all_list(*li);
       for(int te=0;te<1000;te++ ){
           int value=( rand() % pi) ;
           if (value==0)value=1;
           searclevel0(li,value);
       }
       stopTimer();
       time_lvl0 = getTimeAsString();
       displayTime();
       // fonction du module timer
       startTimer();
       for(int te=0;te<1000;te++ ){
           int value=( rand() % pi) ;
           if (value==0)value=1;
       int rest=serclevellast( li,value);
       time_all_levels = getTimeAsString();
       stopTimer();}
       displayTime();
   fprintf(log_file,format,level,time_lvl0, time_all_levels);
   comp+=1;
   }
    srand(time(NULL));
    int pi=1;
    t_d_list* li= create_list(10);
    int level=10;
    for(int u=0;u<level;u++){
        pi*=2;
    }
    for(int i=1;i<pi;i++){
        p_d_cell cell= create_cell(level, i);
        insert_cell(li,cell);
    }
    int value=( rand() % pi) ;
    printf("nombre de valeur %d conplexite recherche au niveau0:%d  conplexite recherche a partir du niveau le plut haut:%d",pi, searclevel0(li,value),serclevellast( li,value));


    fclose(log_file);*/
    c_list* con=create_list_contact();
    char*name =scanString();
    créer_contact(con,name);
    print_all_lista(*con);
    name =scanString();
    créer_contact(con,name);
    print_all_lista(*con);
    name =scanString();
    créer_contact(con,name);
    printf("te");
    print_all_lista(*con);
    name =scanString();
    créer_contact(con,name);
    print_all_lista(*con);
    createrdv(con);
    print_all_lista(*con);
    return 0;


}
