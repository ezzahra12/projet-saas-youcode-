#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxJoueurs 100

typedef struct 
{
    char id[10];
    char nom[100];
    char prenom[100];
    int numeroMaillot;
    char poste[100];
    int age;
    int buts;
    char dateInscription[11];
    char statut[50];

}joueur;


joueur joueurs[maxJoueurs];
joueur j;

int id=0;
int nombreJoueurs=0;
void ajouterJ(){
    if (nombreJoueurs >= maxJoueurs) {
        printf(" Nombre maximum de joueurs atteint\n");
        return;
    }
   
    id++;
    char codei[10];
    sprintf(codei,"K%05d",id);
    strcpy(j.id,codei);
    getchar();
    printf("Nom: \n");
   fgets(j.nom,sizeof(j.nom),stdin);
   j.nom[strcspn(j.nom,"\n")]='\0';
    
    printf("Prenom: \n");
    fgets(j.prenom,sizeof(j.prenom),stdin);
   j.prenom[strcspn(j.prenom,"\n")]='\0';
 
    printf("Numero de maillot: \n ");
    scanf("%d", &j.numeroMaillot);
    getchar();
    
    printf("Poste: \n");
    fgets(j.poste,sizeof(j.poste),stdin);
   j.poste[strcspn(j.poste,"\n")]='\0';

   int s;
    do {
        printf("Statut (1=titulaire,0=remplacement): ");
        scanf("%d",&s);
        getchar();
        if(s!=0 && s!=1)
            printf("Choix invalide, réessayez.\n");
    } while(s!=0 && s!=1);
    strcpy(j.statut, s==1 ? "titulaire" : "remplacement");
   printf("Buts: \n");
    scanf("%d", &j.buts);
    getchar();
nombreJoueurs++; 
joueurs[nombreJoueurs] = j;
printf("Ajout avec succès %s (%s) \n", j.nom,j.id);
}

void ajouterplusierjoueur(){
    int n;
    printf("entrer combien de joueur tu veux ajoute ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("-------jouer numero %d----------\n",nombreJoueurs+1);
        ajouterJ();
    }
}
void triNormale(){
    printf("-------la liste des joueurs-------");
    for(int i=0;i<nombreJoueurs;i++){
        printf("joueurNumero %d : id: %s - Nom: %s - Prenom: %s  - numeroMaillot: %d Poste: %s  - Age: %d  - Buts: %d - dateInscription: %s - Statut: %s",
        joueurs[i].id,
        joueurs[i].nom,
        joueurs[i].prenom,
        joueurs[i].numeroMaillot,
        joueurs[i].poste,
        joueurs[i].age,
        joueurs[i].buts,
        joueurs[i].dateInscription,
        joueurs[i].statut
    );

}
}

void afficherj(){
   int choix;
printf("\n--- Menu Affichage ---\n");
printf("1. Liste normale\n");
printf("2. Trier par nom (alphabetique)\n");
printf("3. Trier par age\n");
printf("4. Afficher par poste\n");
printf("saisir votre choix : ");
scanf("%d",&choix);
getchar(); 
 switch(choix){
    case  1:
      triNormale();
    case  2:
    case  3:
    case  4:
 }
}
    
    
int main(){
     int choix;
    printf("\n------ Menu ------\n");
    printf("1. Ajouter des joueurs \n");
    printf("2. Modifier un joueur\n");
    printf("3. Supprimer un joueur\n");
    printf("4. Afficher tous les joueurs\n");
    printf("5. Rechercher un joueur\n");
    printf("6. Statistiques\n");
    printf("7. Quitter\n");
    printf("------------------\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

        switch (choix){
        case 1:
          ajouterplusierjoueur();
            break;

        case 2:
        // modifierJ(){};
            break;

        case 3:
        //supprimerJ(){}
            break;

        case 4:
        //afficherJs(){}
            break;
        case 5:
        //rechercherJ(){
            break;

        case 6:
            break;

        case 7:
          
            break;
        
        default:
            break;
        }
    }



    

