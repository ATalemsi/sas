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
    char *statut;
}tache;

int tai=0;

void ajouter_nouveaux_tache(tache *taches){

    printf("-----entrer les informations de la taches----- \n");
    if(tai==0){
        taches[tai].id=1;
    }else{
       taches[tai].id=tai+1;
    }
    printf("%d \n",taches[tai].id);
    taches[tai].titre=(char*)malloc(sizeof(char*));
    printf("entrer le titre de la tache : ");
    scanf(" %[^\n]",taches[tai].titre);
    printf("%s \n",taches[tai].titre);
    taches[tai].desc = (char*)malloc(sizeof(char*));
    printf("entrer la description de la tache :");
    scanf(" %[^\n]", taches[tai].desc);
    printf("--- le deadline de la tache------\n ");
    printf(" entrer le jour de   deadline de la tache : ");
    scanf("%d",&taches[tai].deadline.jour);
    printf(" entrer le mois de deadline de la tache : ");
    scanf("%d",&taches[tai].deadline.mois);
    printf(" entrer le annee de deadline de la tache : ");
    scanf("%d",&taches[tai].deadline.annee);
    taches[tai].statut=(char*)malloc(sizeof(char*));
    printf("entrer le statut  de la tache : ecrit TO DO ||  DOING  || DONE : ");
    scanf(" %[^\n]", taches[tai].statut);
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
        }else if (tab[i]<=3)
        {
           printf("id : %d | Titre : %s | Deadline en : %d jours\n",taches[i].id,taches[i].titre,tab[i]);
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
    int t=0;
    for(i=0;i<tai;i++){
        if(taches[i].id==identi){
                printf("modifier votre status : ");
               scanf(" %[^\n]",taches[i].statut);
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
               printf("entre le nouveaux jour : ");
               scanf(" %d",taches[i].deadline.jour);
               printf("entre le nouveaux mois : ");
               scanf(" %d",taches[i].deadline.mois);
               printf("entre le nouveaux annee : ");
               scanf(" %d",taches[i].deadline.annee);
               t=1;
        }
    }
    if(t==0){
      printf("Aucune tache avec identifiant %d na ete trouvee.\n",identi);
    }

}

void recherche_par_id(tache taches[],int identi){
     int i;
      tache ta;
      int t=0;
     for(i=0;i<tai;i++){
        if(taches[i].id==identi){
        ta=taches[i];
        printf("------tache %d---- \n",ta.id);
        printf("titre : %s \n",ta.titre);
        printf("description : %s \n",ta.desc);
        printf("statut : %s \n",ta.statut);
        printf("la date jj/mm/aaaa : %d/%d/%d \n",ta.deadline.jour,ta.deadline.mois,ta.deadline.annee);
        }
     }
    if(t==0){
      printf("Aucune tache avec identifiant %d na ete trouvee.\n",identi);
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
        printf("On a aucun tache a cree");
      }else{
          printf(" le nombre des tache cree est : %d",N_tache);
      }
}

void status_tache(tache taches[]){
     int i;
     int complet=0;
     int incomplet=0;
     char sta1[]="DONE";
     char sta2[]="DOING";
     char sta3[]="TO DO";
     for(i=0;i<tai;i++){
          if(strcmp(taches[i].statut,sta1)==0){
            complet++;
          }
          if(strcmp(taches[i].statut,sta2)==0){
            incomplet++;
          }
             if(strcmp(taches[i].statut,sta3)==0){
            incomplet++;
          }
     }
     printf(" les nombres des tache incomplet :  %d",incomplet);
        printf(" les nombres des tache complet :  %d",complet);

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
        printf("----votre taches-----\n");
        printf("------tache %d---- \n",taches[i].id);
        printf("titre : %s \n",taches[i].titre);
        printf("description : %s \n",taches[i].desc);
        printf("statut : %s \n",taches[i].statut);
        printf("la date jj/mm/aaaa : %d/%d/%d \n",taches[i].deadline.jour,taches[i].deadline.mois,taches[i].deadline.annee);
        printf("----------------------------------------------------------\n");

        }
    }
    }


int main()
{
    tache taches[150];
    int nbr;
    char choice;
    int choix,choix1,choix2,choix3,choix4;
    do{
       printf("\t -----saisir votre choix----- : ");

       printf("\t1-Ajouter nouveaux tache :\n");
       printf("\t2-Ajouter plusieur tache : \n");
       printf("\t3-Affichage : \n");
       printf("\t4-Supprimer une tache : \n");
       printf("\t5-Modification : \n");
       printf("\t6-Rechercher : \n");
       printf("\t7-Statistique : \n");
       scanf("%d",&choix);
       if(choix>0 && choix<8){
          switch(choix){
             case 1: ajouter_nouveaux_tache(taches);
             break;
             case 2: printf


            getchar();
            printf(" do you want to  continue (y/n)\n") ;
            scanf("%c",&choice);
             }
          }


       }while(choice=='Y');





    }


   //ajouter_nouveaux_tache(taches);
    ajouter_plusieur(taches,nbr);
    supp_tache(taches,2);
    //afficher_tache(taches);
    //tri_alphabetique(taches);
    //tri_date(taches);
    //dead_line(taches);
    //jours_restant(taches);
    //recherche_par_id(taches,2);
    //recherche_par_titre(taches);
    //afficher_tache(taches);
   // modifier_desc(taches,1);
    afficher_tache(taches);
    return 0;
}
