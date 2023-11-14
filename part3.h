//
// Created by justi on 14/11/2023.
//

#ifndef UNTITLED8_PART3_H
#define UNTITLED8_PART3_H

typedef struct rdv{
    int date_rdv[3];
    int heure_debut [2];
    int  herre_duree [2];
    char * objet;
    struct rdv* rdv;
}rdv;
typedef struct contact{
    char* prenom;
    char* nom;
    rdv* rdv;
};
#endif //UNTITLED8_PART3_H
