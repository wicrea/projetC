
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// j'ai tout enlevé pour rajoutee les commentaires faits sur clion

p_d_cell  create_cell(int level,int value){
    //Allocation dynamique pour une cellule de la taille t_d_cell
    p_d_cell  new_cell =(p_d_cell)malloc (sizeof (t_d_cell));
    //Donner un nombre de niveaux pour le tableau de pointeurs
    new_cell->level=level;
    //Donner une valeur à la cellule, ici le nom enregistré dans le contact
    new_cell->value=value;
    //Allocation dynamique tableau de pointeurs de pointeur
    new_cell->next=(p_d_cell*)malloc (level*sizeof (p_d_cell));
    //Le pointeur à chaque niveau ne pointe vers rien pour l'instant
    for(int i=0;i<level;i++){
        new_cell->next[i]=NULL;
    }
    return new_cell;
}

// Fonction pour créer une nouvelle liste doublement chaînée avec un niveau spécifié
t_d_list* create_list(int level){

    // Allocation de mémoire pour la structure de la liste
    t_d_list* l =(t_d_list*) malloc(sizeof (t_d_list));

    //Atribution d'un nombre de niveaux
    l->level=level;

    // Allocation de mémoire pour le tableau de pointeurs vers les têtes des niveaux
    l->head=(p_d_cell*)malloc (level*sizeof (p_d_cell));

    // Initialisation de chaque tête de niveau à NULL
    for(int i=0;i<level;i++){
        l->head[i]=NULL;
    }
    return l;
}
void print_list(int level,t_d_list li){
    // Affiche le niveau de la liste et le début de la liste
    printf("list head_%d @-]-->",level);

    // Vérifie si la tête de la liste au niveau donné n'est pas NULL.
    if (li.head[level]!=NULL){
        // Initialise un pointeur temporaire au début de la liste.
        p_d_cell temp= li.head[level];
        // Parcourt la liste et affiche chaque élément.
        while (temp!= NULL){
            printf("[ %d|@-]-->",temp->value);
            temp=temp->next[level];
        }}
    // Affiche NULL pour indiquer la fin de la liste.
    printf("NULL");
}
void print_all_list(t_d_list li) {
    // Parcourt tous les niveaux de la structure de données.
    for (int i = 0; i < li.level; i++) {
        // Appelle la fonction print_list pour afficher la liste au niveau actuel.
        print_list(i, li);

        // Ajoute un saut de ligne pour séparer les niveaux.
        printf("\n");
    }
}
void insert_cell(t_d_list* li, p_d_cell cell) {
    int tplev = 0;  // Initialise le niveau à 0.
    int test = 1;   // Initialise la variable de test à 1.

    // Parcourt les niveaux jusqu'à atteindre le niveau maximum ou trouver un niveau approprié.
    while ((tplev != li->level) && ((cell->value % (2 * test)) == 0)) {
        tplev++;
        test *= 2;
    }

    // Parcourt tous les niveaux depuis le niveau trouvé jusqu'au niveau le plus bas.
    for (tplev; tplev > -1; tplev--) {
        p_d_cell temp = li->head[tplev];

        // Vérifie si la tête de la liste au niveau donné n'est pas NULL.
        if (li->head[tplev] != NULL) {
            // Parcourt la liste jusqu'à trouver l'emplacement approprié pour la nouvelle cellule.
            while (temp->next[tplev] != NULL && (temp->next[tplev]->value <= cell->value)) {
                temp = temp->next[tplev];
            }

            // Insère la cellule dans la liste au niveau actuel.
            cell->next[tplev] = temp->next[tplev];
            temp->next[tplev] = cell;
        } else {
            // Si la tête de la liste au niveau donné est NULL, la nouvelle cellule devient la tête.
            li->head[tplev] = cell;
        }
    }
}

int searclevel0(t_d_list* li, int sh) {
    // Initialise un pointeur temporaire au début de la liste au niveau 0.
    p_d_cell temp = li->head[0];

    int ch = 0; // Initialise le compteur de position à 0.

    // Parcourt la liste jusqu'à la fin ou jusqu'à trouver l'élément recherché.
    while (temp != NULL) {
        // Vérifie si la valeur actuelle de la cellule correspond à la valeur recherchée.
        if (temp->value == sh) {
            // Retourne la position (indice) de l'élément recherché.
            return ch;
        }

        // Passe à la cellule suivante dans le niveau 0.
        temp = temp->next[0];

        // Incrémente le compteur de position.
        ch += 1;
    }

    // Retourne 0 si l'élément n'est pas trouvé.
    return 0;
}


int serclevellast(t_d_list* li,int sh){ // chercher la position d'une valeur à ajouter 
    int tplev=log2(sh); // on effectue le log2 de la valeur recherchée pour savoir le niveau où on commence la recherche
    p_d_cell temp=li->head[tplev]; // on initialise un pointeur en tête de liste
    p_d_cell celt;
    int ch=0; // varibale qui stocke le nombre d'itérations
    while((temp!=NULL) &&( tplev>-1)){ // tant que le pointeur n'est pas nul et que le niveau calculé existe
        if(temp->value==sh){ // si on se trouve sur la bonne valeur alors on retourne le nombre d'itérations effectuées
            return ch+1;} 
        celt=temp->next[tplev]; // on continue de parcourir la liste
        if ((celt!=NULL)&&(celt->value<=sh)){ // si celts (val suivante) inf ou = on reste sur le niveau 
            temp=temp->next[tplev]; // on continue de parcourir ce niveau
            ch+=1; // incremente cpt nbr itération
        }
        if((celt==NULL)||(celt->value>sh)){ // si celt (val suivant) > la val n'est pas sur ce niveai donc on descend de niveau
            tplev= log2(sh-temp->value); // on calcule le niveau où on va 

        }}
    return 0;
}
