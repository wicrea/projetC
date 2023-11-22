#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <time.h>
#include "timer.h"
int main() {
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
    for(int te=0;te<100;te++ ){
    int value=( rand() % pi) ;
    if (value==0)value=1;
        startTimer();
        searclevel0(li,value);
        stopTimer();

        time_lvl0 = getTimeAsString(); // fonction du module timer
        startTimer();
    int rest=serclevellast( li,value);
    stopTimer();
    time_all_levels = getTimeAsString();
    fprintf(log_file,format,level,time_lvl0, time_all_levels);
    comp+=1;
    }  }
    fclose(log_file);
    return 0;

}
