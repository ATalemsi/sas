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
    taches[tai].titre=(char*)malloc(sizeof(char*)*101);
    printf("entrer le titre de la tache : ");
    scanf("%s",taches[tai].titre);
    printf("%s \n",taches[tai].titre);
    taches[tai].desc = (char*)malloc(256 * sizeof(char));
    printf("entrer la description de la tache :");
    fgets(taches[tai].desc, 255, stdin);

    taches[tai].desc[strcspn(taches[tai].desc, "\n")] = 0;
    printf("--- le deadline de la tache------\n ");
    printf(" entrer le jour de   deadline de la tache : ");
    scanf("%d",&taches[tai].deadline.jour);
    printf(" entrer le mois de deadline de la tache : ");
    scanf("%d",&taches[tai].deadline.mois);
    printf(" entrer le annee de deadline de la tache : ");
    scanf("%d",&taches[tai].deadline.annee);
    taches[tai].statut=(char*)malloc(sizeof(char*)*100);
    printf("entrer le statut  de la tache : ecrit à realiser ||  en cours de realisation || finalisee : ");
    scanf("%s",taches[tai].statut);
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
   //ajouter_nouveaux_tache(taches);
   ajouter_plusieur(taches,nbr);
   tri_alpha( taches);
   afficher_tache(taches);





    return 0;
}
