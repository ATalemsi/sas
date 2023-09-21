#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("entrer le statut  de la tache : ecrit a realiser ||  en cours de realisation || finalisee : ");
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

void tri_alpha(tache taches[]){
    int i;
    int j;
    tache tmp;
    int min;
     if(tai==0){
        printf("la table vide");
        return;
     }else{
       for(i=0;i<=tai-2;i++){
            min=i;
       for(j=0;j<tai-i-1;j++)
            taches[j].titre[0]=toupper(taches[j].titre[0]);
            if(strcmp(taches[j].titre,taches[j+1].titre)>0){
                tmp=taches[i];
                taches[i]=taches[j];
                taches[j]=tmp;
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
/*
void  comp_date2(date d1, date d2){
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
*/
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
void modifier_status(tache taches[], int identi){
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

void supp_tache(tache taches[],int identi){
    int i ,j;
    int t=0;
    for(i=0;i<tai;i++){
        if(taches[i].id=identi){
                t=1;
            for(j=i;j<identi-1;j++){
                taches[j]=taches[j+1];
            }
        }
        tai--;
        return;
    }
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
    tache taches[100];
    int nbr=2;
   ajouter_nouveaux_tache(taches);
   //ajouter_plusieur(taches,nbr);
   //tri_alpha( taches);
   // tri_date(taches);
   afficher_tache(taches);
   modifier_desc(taches,1);
   afficher_tache(taches);





    return 0;
}
