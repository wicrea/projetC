#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main() {

    printf("donner une valeur a level");
    int level;
    scanf("%d",&level);
    t_d_list* li= create_list(level);
    int pi=1;
    for(int u=0;u<level;u++){
        pi*=2;
    }
    for(int i=1;i<pi;i++){
        p_d_cell cell= create_cell(level, i);
        insert_cell(li,cell);
    }
    print_all_list(*li);
    int rest=serclevellast( li,151);
    printf("%d",rest);
    return 0;

}
