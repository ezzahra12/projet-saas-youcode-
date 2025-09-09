#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxJoueurs 100
typedef struct 
{
    int id;
    char nom[100];
    char prenom[100];
    int numeroMaillot;
    char poste[100];
    int age;
    int buts;
    char dateInscription;
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
    j.id = id;
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
   printf("statut: (1=titulaire,0=remplacement): ");
   scanf("%d",  &s);
   switch(s){
    case 1:
    strcpy(j.statut,"titulaire");
    break;
    case 0:
    strcpy(j.statut,"remplacement");
    break;
    default:
      printf("Choix invalide \n");
      
   }
   printf("Buts: \n");
    scanf("%d", &j.buts);
nombreJoueurs++; 
}

void ajouterplusierjoueur(){
    int n;
    printf("entrer combien de joueur tu veux ajoute ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("-------jouer numero %d----------\n");
        ajouterJ();
    }
}
    
    
int main(){
     int choix;
    printf("\n------ Menu ------\n");
    printf("1. Ajouter un joueur\n");
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
          ajouterJ();
            break;

        case 2:
        modifierJ();
            break;

        case 3:
        supprimerJ();
            break;

        case 4:
        afficherJs();
            break;
        case 5:
        rechercherJ();
            break;

        case 6:
            break;

        case 7:
          
            break;
        
        default:
            break;
        }
    }



    

