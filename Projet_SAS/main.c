#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
typedef struct date{
    int annee;
    int mois;
    int jour;
  }date;

typedef struct tache{
    int id;
    char *titre;
    char *desc;
    date  deadline;
    int statut;
}tache;

int tai=0;

void ajouter_nouveaux_tache(tache taches[]){
    int ch;
    if(tai==0){
        taches[tai].id=1;
    }else{
       taches[tai].id=tai+1;
    }
    printf("-----entrer les informations de la taches %d -----  \n",taches[tai].id);
    taches[tai].titre=(char*)malloc(sizeof(char*));
    printf("entrer le titre de la tache : ");
    scanf(" %[^\n]",taches[tai].titre);
    taches[tai].desc = (char*)malloc(sizeof(char*));
    printf("entrer la description de la tache :");
    scanf(" %[^\n]", taches[tai].desc);
    printf("--- le deadline de la tache------\n ");
    printf(" entrer le jour de   deadline de la tache : ");
    scanf("%d",&taches[tai].deadline.jour);
    while(taches[tai].deadline.jour>32 || taches[tai].deadline.jour<0){
         printf("veuiller entre une valeur entre 0 et 31 :");
         scanf("%d",&taches[tai].deadline.jour);
    }
    printf(" entrer le mois de deadline de la tache : ");
    scanf("%d",&taches[tai].deadline.mois);
    while(taches[tai].deadline.mois>13 || taches[tai].deadline.mois<0){
         printf("veuiller entre une valeur entre 0 et 12 :");
         scanf("%d",&taches[tai].deadline.mois);
    }
    printf(" entrer le annee de deadline de la tache : ");
    scanf("%d",&taches[tai].deadline.annee);
    while( taches[tai].deadline.annee<2022 || taches[tai].deadline.annee<0){
         printf("veuiller entre une valeur entre superieur a 2023 :");
         scanf("%d",&taches[tai].deadline.annee);
    }
    do {
    printf("--entre le nombre de  status :--- \n ");
    printf("1-TO DO \n");
    printf("2-DOING \n");
    printf("3-DONE \n");
    scanf("%d",&ch);
    }while(ch<0 && ch>3);
     taches[tai].statut=ch;
    tai++;
}
 void ajouter_plusieur( tache taches[], int nbr){
      int i;
      for(i=0;i<nbr;i++){
        printf("ajouter la tache num %d : \n",i+1);
        ajouter_nouveaux_tache(taches);
        }

        }

void tri_alphabetique(tache taches[]){
    tache temp;
    for (int i = 0; i<tai; i++)
    {
        for (int j = i+1; j < tai; j++)
        {
             if (strcmp(taches[i].titre,taches[j].titre)>0)
        {
            temp=taches[i];
            taches[i]=taches[j];
            taches[j]=temp;
        }
        }
    }
}
int  comp_date(date d1, date d2){
   if(d1.annee!=d2.annee){
    return d1.annee - d2.annee;
   }
    if(d1.mois!=d2.mois){
    return d1.mois - d2.mois;
    }
    if(d1.jour!=d2.jour){
    return d1.jour - d2.jour;
   }
}
void tri_date(tache taches[]){
     int i;
     int j;
     tache tmp;
     for(i=0;i<=tai-2;i++){
        for(j=0;j<tai-i-1;j++){
            if(comp_date(taches[j].deadline,taches[j+1].deadline)>0){
               tmp=taches[j];
               taches[j]=taches[j+1];
               taches[j+1]=tmp;
            }
        }
     }
}

void dead_line(tache taches[]){
int i;
int t=0;
int delai_jour;
int jours;
    int tab[tai];
    time_t seconds=time(NULL);
    struct tm *current_time=localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth =(current_time->tm_mon + 1);
    int currentDay =current_time->tm_mday;

    for (i = 0; i < tai; i++){
        jours = taches[i].deadline.annee*365+taches[i].deadline.mois*30+taches[i].deadline.jour;
        delai_jour = jours-(currentYear*365+currentMonth*30+currentDay);
        tab[i]= delai_jour;
    }
    for (int i = 0; i < tai; i++)
    {
        if(tab[i]==0){
           printf("id : %d | Titre : %s | Deadline en : Aujourdui\n",taches[i].id,taches[i].titre);
           t=1;
        }else if ( tab[i]>0&&tab[i]<=3)
        {
           t=1;
           printf("id : %d | Titre : %s | Deadline en : %d jours\n",taches[i].id,taches[i].titre,tab[i]);
        }
        if(t==0){

            printf(" aucun jour a mois de 3 jour restent pour le deadline");
        }

    }
}
void modifier_desc(tache taches[], int identi){
    int i;
    int t=0;
    for(i=0;i<tai;i++){
        if(taches[i].id==identi){
               printf("modifier votre description : ");
               scanf(" %[^\n]",taches[i].desc);
               t=1;
        }
    }
    if(t==0){
      printf("Aucune tache avec identifiant %d na ete trouvee.\n",identi);
    }

}
void modifier_status(tache taches[], int identi){
    int i;
    int c;
    int t=0;
    for(i=0;i<tai;i++){
        if(taches[i].id==identi){
        printf("modifier votre status : \n");
                  do {
                        printf("--entre le nombre de  status :--- \n ");
                        printf("1-TO DO \n");
                        printf("2-DOING \n");
                        printf("3-DONE \n");
                        scanf("%d",&c);
                     }while(c<0 && c>3);
                      taches[i].statut=c;
                       t=1;
        }
    }
    if(t==0){
      printf("Aucune tache avec identifiant %d na ete trouvee.\n",identi);
    }

}
void modifier_deadline(tache taches[], int identi){
    int i;
    int t=0;
    for(i=0;i<tai;i++){
        if(taches[i].id==identi){
               printf("modifier date de deadline : \n");
               printf(" entrer le nouveaux jour  : ");
               scanf("%d",&taches[i].deadline.jour);
               while(taches[i].deadline.jour>32 || taches[i].deadline.jour<0){
               printf("veuiller entre une valeur entre 0 et 31 :");
                scanf("%d",&taches[i].deadline.jour);
                  }
               printf(" entrer le noveaux mois  : ");
               scanf("%d",&taches[i].deadline.mois);
               while(taches[i].deadline.mois>13 || taches[i].deadline.mois<0){
               printf("veuiller entre une valeur entre 0 et 12 :");
               scanf("%d",&taches[i].deadline.mois);
            }
                printf(" entrer le nouveaux annee  : ");
                scanf("%d",&taches[i].deadline.annee);
                while( taches[i].deadline.annee<2022 || taches[i].deadline.annee<0){
                printf("veuiller entre une valeur entre superieur a 2023 :");
                scanf("%d",&taches[i].deadline.annee);
            }
               t=1;
        }
    }
    if(t==0){
      printf("Aucune tache avec identifiant %d na ete trouvee.\n",identi);
    }

}

void recherche_par_id(tache taches[],int identi){
     int i;
      int t=0;
     for(i=0;i<tai;i++){
        if(taches[i].id==identi){
        taches[i];
        printf("------tache %d---- \n",taches[i].id);
        printf("titre : %s \n",taches[i].titre);
        printf("--------------------------------\n");
        printf("description : %s \n",taches[i].desc);
         printf("--------------------------------\n");
        if(taches[i].statut==1){
        printf("|  statut     | : TO DO \n");

        }else if(taches[i].statut==2){
        printf("|  statut     | : DOING \n");
        }else {
        printf("|  statut     |: DONE \n");
        }
         printf("--------------------------------\n");
        printf("| la date jj/mm/aaaa  | : %d/%d/%d \n",taches[i].deadline.jour,taches[i].deadline.mois,taches[i].deadline.annee);
        }
         printf("--------------------------------\n");
     }
    if(t==0){
      printf("Aucune tache avec identifiant %d na ete trouvee.\n",identi);
       printf("--------------------------------\n");
    }
}
void recherche_par_titre(tache taches[]){
      int i;
      char *tit;
      tache ta;
      int t=0;
      tit = (char*)malloc(sizeof(char*));
      printf("donner le titre de la tache que tu veux rechercher : ");
      scanf(" %[^\n]",tit);
     for(i=0;i<tai;i++){
        if(strcmp(taches[i].titre,tit)==0){
             ta=taches[i];
             printf("------tache %d---- \n",ta.id);
             printf("titre : %s \n",ta.titre);
             printf("description : %s \n",ta.desc);
             printf("statut : %s \n",ta.statut);
             printf("la date jj/mm/aaaa : %d/%d/%d \n",ta.deadline.jour,ta.deadline.mois,ta.deadline.annee);
             t=1;
        }
     }
     if(t==0){
        printf(" aucun id trouve");
     }
    }


void nombre_total_tache(tache taches[]){
     int i;
     int N_tache=0;
     for(i=0;i<tai;i++){
        if(taches[i].id!=0){
            N_tache++;
        }
     }
      if(N_tache==0){
        printf("On a aucun tache a cree \n");
      }else{
          printf(" le nombre des tache cree est : %d \n",N_tache);
      }
}

void status_tache(tache taches[]){
     int i;
     int complet=0;
     int incomplet=0;
     for(i=0;i<tai;i++){
          if(taches[i].statut==3){
            complet++;
          }else{
              incomplet++;
          }

     }
     printf(" les nombres des tache incomplet :  %d \n",incomplet);
        printf(" les nombres des tache complet :  %d \n",complet);

}

void jours_restant(tache taches[]){
int i;
int delai_jour;
int jours;
    int tab[tai];
    time_t seconds=time(NULL);
    struct tm *current_time=localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth =(current_time->tm_mon + 1);
    int currentDay =current_time->tm_mday;

    for (i = 0; i < tai; i++){
        jours = taches[i].deadline.annee*365+taches[i].deadline.mois*30+taches[i].deadline.jour;
        delai_jour = jours-(currentYear*365+currentMonth*30+currentDay);
        tab[i]= delai_jour;
    }
    for (int i = 0; i < tai; i++)
    {
    printf("id : %d | Titre : %s | le nombre des jour rester : %d \n",taches[i].id,taches[i].titre,tab[i]);
    }
}
void supp_tache(tache taches[],int identi){
    int i ,j;
    int t=0;
    for(i=0;i<tai;i++){
        if(taches[i].id==identi){
                t=1;
            for(j=i;j<tai-1;j++){
                taches[j]=taches[j+1];

            }
        }
    }
    tai--;

      if(t==0){
      printf("Aucune tache avec identifiant %d na ete trouvee.\n",identi);
    }



}
void afficher_tache(tache *taches){
    int i;
    if(tai==0){
        printf("table est vide");
       return;
    }else {
        for( i=0;i<tai;i++){
        printf("-------votre taches--------\n");
        printf("|  ID         | %d  \n",taches[i].id);
        printf("| titre       | : %s \n",taches[i].titre);
        printf("| description | : %s \n",taches[i].desc);
        if(taches[i].statut==1){
        printf("|  statut     | : TO DO \n");

        }else if(taches[i].statut==2){
        printf("|  statut     | : DOING \n");
        }else {
        printf("|  statut     |: DONE \n");
        }

        printf("| la date jj/mm/aaaa : %d/%d/%d |\n",taches[i].deadline.jour,taches[i].deadline.mois,taches[i].deadline.annee);
        printf("----------------------------------------------------------\n");

        }
    }
    }


int main()
{
    tache taches[150];
    int nbr;
    int delete_id;
    int up_id;
    int se_id;
    int scan;
    int choice;
    int choix,choix1,choix2,choix3,choix4;
    do{
       printf("\t -----saisir votre choix----- : \n");
       printf("\t1-Ajouter nouveaux tache : \n");
       printf("\t2-Ajouter plusieur tache : \n");
       printf("\t3-Affichage : \n");
       printf("\t4-Supprimer une tache : \n");
       printf("\t5-Modification : \n");
       printf("\t6-Rechercher :\n ");
       printf("\t7-Statistique : \n");
       printf("\t8-Quitter : \n ");
       scanf("%d",&choix);
          switch(choix){
             case 1: ajouter_nouveaux_tache(taches);
                   break;
             case 2: printf(" nombre des taches que tu veux ajouter : ");
                     scanf("%d",&nbr);
                     ajouter_plusieur(taches,nbr);
             break;
             case 3:
                  printf("\t ----- saisir votre choix pour affichage ----- :  \n");
                  printf("\t1-affichage simple :\n");
                  printf("\t2-affichage par tri alphabetique : \n");
                  printf("\t3-Affichage par tri deadline : \n");
                  printf("\t4-Afficher les taches dans le deadline est dans 3 jours au moins : \n ");
                  scanf("%d",&choix1);
                      switch(choix1){

                         case 1:
                             printf("Affichage simple: \n");
                             afficher_tache(taches);
                         break;
                         case 2 :tri_alphabetique(taches);
                                 afficher_tache(taches);
                         break;
                         case 3: tri_date(taches);
                                afficher_tache(taches);
                         break;
                         case 4:dead_line(taches);
                         break;
                         default :
                                printf(" merci ");
                      }
                  break;
             case 4 : printf(" donner id de tache que tu veux supprimer : ");
                      scanf("%d",&delete_id);
                      supp_tache(taches,delete_id);
             break;
             case 5 :printf("\t ----- saisir votre choix pour modifier ----- : \n ");
                     printf("\t1-modification de la description :\n");
                     printf("\t2-modification de status: \n");
                     printf("\t3-modification de la deadline : \n");
                     scanf("%d",&choix2);
                       switch(choix2){
                            case 1: printf("donner ID de tache pour  modidfier leur description : ");
                                  scanf("%d",&up_id);
                                  modifier_desc(taches,up_id);
                            break;
                            case 2:printf("donner ID de tache pour  modidfier leur status : ");
                                   scanf("%d",&up_id);
                                   modifier_status(taches,up_id);
                            break;
                            case 3: printf("donner ID de tache pour  modidfier leur deadline : ");
                                    scanf("%d",&up_id);
                                    modifier_deadline(taches,up_id);
                            break;
                            default :
                                 printf("aucun choix valid \n");
                                 printf("merci \n");
                                 break;
                       }
                       break;
                  case 6 : printf("--- sisair votre choix pour recherche----- \n ");
                           printf("\t1-recherche tache par ID:\n");
                           printf("\t2-recherche un tache pour titre: \n");
                           scanf("%d",&choix3);
                              switch(choix3){
                                  case 1:printf("donner le ID pour le recherche :");
                                  scanf("%d",&se_id);
                                  recherche_par_id(taches,se_id);
                                  break;
                                  case 2:recherche_par_titre(taches);
                                   break;
                                  default :
                                      printf("aucun choix valid \n");
                                      printf("merci \n");
                                    break;
                              }
                              break;
                    case 7 :printf("---- les statistique------ \n ");
                            printf("\t1-Afficher les nombre des taches : \n");
                            printf("\t2-Afficher les nombres des tache complet et incomplet : \n");
                            printf("\t3-Afficherles nombre des jours rester pour chaque tache : \n ");
                            scanf("%d",&choix4);
                            switch(choix4){
                               case 1: nombre_total_tache(taches);
                                 break;
                               case 2 :status_tache(taches);
                                  break;
                               case 3: jours_restant(taches);
                                break;
                               default :
                                   printf("aucun choix valid \n");
                                   printf("merci \n");
                                   break;
                            }
                            break;
                     case 8 : printf("");
                       break;
                     default :printf("choix invalid \n");
                              printf(" Merci");
                              break;
             }


       }while(choix!=8  );


     printf(" Merci de test notre programe");


     return 0;
           }
