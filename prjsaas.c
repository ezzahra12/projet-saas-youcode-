
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
    char statut[50];

} joueur;
//-----------------------------------------------------------------------------------------------------------------
joueur joueurs[maxJoueurs] = {
    {"K00001", "Mahrez", "Riyad", 26, "milieu", 32, 10, "titulaire"},
    {"K00002", "Hakimi", "Achraf", 2, "defenseur", 25, 3, "titulaire"},
    {"K00003", "Ziyech", "Hakim", 22, "attaquant", 30, 8, "titulaire"},
    {"K00004", "Bounou", "Yassine", 1, "gardien", 31, 0, "titulaire"},
    {"K00005", "Mazraoui", "Noussair", 12, "defenseur", 26, 2, "remplacement"},
    {"K00006", "Boufal", "Sofiane", 14, "milieu", 28, 4, "remplacement"},
    {"K00007", "Boutaib", "Hakim", 9, "attaquant", 34, 6, "titulaire"}};

int nombreJoueurs = 7;
int id = 7;
joueur j;

//------------------------------------------------------------------------------------------------------------------

void ajouterJ()
{
    if (nombreJoueurs >= maxJoueurs)
    {
        printf(" Nombre maximum de joueurs atteint\n");
        return;
    }

    id++;
    char codei[10];
    sprintf(codei, "K%05d", id);
    strcpy(j.id, codei);
    printf("Nom: \n");
    getchar();
    fgets(j.nom, sizeof(j.nom), stdin);
    j.nom[strcspn(j.nom, "\n")] = '\0';

    printf("Prenom: \n");
    fgets(j.prenom, sizeof(j.prenom), stdin);
    j.prenom[strcspn(j.prenom, "\n")] = '\0';

    printf("Numero de maillot: \n ");
    scanf("%d", &j.numeroMaillot);
    getchar();

    printf("Poste: (gardien,defenseur,milieu,attaquant) \n");
    fgets(j.poste, sizeof(j.poste), stdin);
    j.poste[strcspn(j.poste, "\n")] = '\0';

    printf("age: \n");
    scanf("%d", &j.age);

    int s;
    do
    {
        printf("Statut (1=titulaire,0=remplacement): ");
        scanf("%d", &s);
        getchar();
        if (s != 0 && s != 1)
            printf("Choix invalide, réessayez.\n");
    } while (s != 0 && s != 1);
    strcpy(j.statut, s == 1 ? "titulaire" : "remplacement");

    printf("Buts: \n");
    scanf("%d", &j.buts);
    getchar();
    joueurs[nombreJoueurs] = j;
    nombreJoueurs++;
    printf("Ajout avec succès %s (%s) \n", j.nom, j.id);
}
//-----------------------------------------------------------------------

void ajouterplusierjoueur()
{
    int n;
    printf("entrer combien de joueur tu veux ajoute ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("-------jouer numero %d----------\n", nombreJoueurs + 1);
        ajouterJ();
    }
}
//-----------------------------------------------------------------------

void triNormale()
{
    printf("-------la liste des joueurs-------\n");
    for (int i = 0; i < nombreJoueurs; i++)
    {
        printf("-------joueurNumero %d-------- : \n id: %s \n- Nom: %s \n- Prenom: %s  \n- numeroMaillot: %d \n -Poste: %s  \n- Age: %d  \n- Buts: %d \n- \n- Statut: %s \n",
               i + 1,
               joueurs[i].id,
               joueurs[i].nom,
               joueurs[i].prenom,
               joueurs[i].numeroMaillot,
               joueurs[i].poste,
               joueurs[i].age,
               joueurs[i].buts,
               joueurs[i].statut);
    }
}
//-----------------------------------------------------------------------
void triParNom()
{
    printf("--------liste Trier par nom (alphabetique)--------- \n");
    for (int i = 0; i < nombreJoueurs - 1; i++)
    {
        for (int j = 0; j < nombreJoueurs - i - 1; j++)
        {
            joueur temp;
            if (strcasecmp(joueurs[j].nom, joueurs[j + 1].nom) > 0)
            {
                temp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < nombreJoueurs; i++)
    {
        printf("-------joueurNumero %d-------- : \n id: %s \n- Nom: %s \n- Prenom: %s  \n- numeroMaillot: %d \n -Poste: %s  \n- Age: %d  \n- Buts: %d \n-- Statut: %s \n",
               i + 1,
               joueurs[i].id,
               joueurs[i].nom,
               joueurs[i].prenom,
               joueurs[i].numeroMaillot,
               joueurs[i].poste,
               joueurs[i].age,
               joueurs[i].buts,
               joueurs[i].statut);
    }
}
//-----------------------------------------------------------------------

void triParAge()
{
    for (int i = 0; i < nombreJoueurs - 1; i++)
    {
        for (int j = 0; j < nombreJoueurs - i - 1; j++)
        {
            if (joueurs[j].age > joueurs[j + 1].age)
            {
                joueur temp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = temp;
            }
        }
    }

    printf("--------liste Trier par age--------- \n");
    for (int i = 0; i < nombreJoueurs; i++)
    {
        printf("-------joueurNumero %d-------- : \n id: %s \n- Nom: %s \n- Prenom: %s  \n- numeroMaillot: %d \n- Poste: %s  \n- Age: %d  \n- Buts: %d \n- Statut: %s \n",
               i + 1,
               joueurs[i].id,
               joueurs[i].nom,
               joueurs[i].prenom,
               joueurs[i].numeroMaillot,
               joueurs[i].poste,
               joueurs[i].age,
               joueurs[i].buts,
               joueurs[i].statut);
    }
}

//-----------------------------------------------------------------------

void triParPoste()
{
    printf("---- Joueurs au poste: gardien ----\n");
    int count = 1;
    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (strcmp(joueurs[i].poste, "gardien") == 0)
        {

            printf(" ---------Gardien %d ------ \n -id: %s - Nom: %s - Prenom: %s - Numero: %d - Age: %d - Buts: %d - Statut: %s\n",
                   count++,
                   joueurs[i].id,
                   joueurs[i].nom,
                   joueurs[i].prenom,
                   joueurs[i].numeroMaillot,
                   joueurs[i].age,
                   joueurs[i].buts,
                   joueurs[i].statut);
        }
    }
    printf("\n");
    printf("---- Joueurs au poste: Defenseur ----\n");
    count = 1;
    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (strcmp(joueurs[i].poste, "defenseur") == 0)
        {

            printf("   ---------Defenseur %d ------ \n id: %s \n- Nom: %s \n- Prenom: %s \n- Numero: %d \n- Age: %d \n- Buts: %d \n- Statut: %s\n",
                   count++,
                   joueurs[i].id,
                   joueurs[i].nom,
                   joueurs[i].prenom,
                   joueurs[i].numeroMaillot,
                   joueurs[i].age,
                   joueurs[i].buts,
                   joueurs[i].statut);
        }
    }
    printf("\n");
    printf("---- Joueurs au poste: milieu ----\n");

    count = 1;

    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (strcasecmp(joueurs[i].poste, "milieu") == 0)
        {
            printf("   ---------Milieu %d ------ \n id: %s - Nom: %s - Prenom: %s - Numero: %d - Age: %d - Buts: %d - Statut: %s\n",
                   count++,
                   joueurs[i].id,
                   joueurs[i].nom,
                   joueurs[i].prenom,
                   joueurs[i].numeroMaillot,
                   joueurs[i].age,
                   joueurs[i].buts,
                   joueurs[i].statut);
        }
    }
    printf("\n");
    printf("---- Joueurs au poste: attaquant ----\n");
    count = 1;
    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (strcasecmp(joueurs[i].poste, "attaquant") == 0)
        {
            printf("   --------Attaquant %d ------ \n id: %s - Nom: %s - Prenom: %s - Numero: %d - Age: %d - Buts: %d - Statut: %s\n",
                   count++,
                   joueurs[i].id,
                   joueurs[i].nom,
                   joueurs[i].prenom,
                   joueurs[i].numeroMaillot,
                   joueurs[i].age,
                   joueurs[i].buts,
                   joueurs[i].statut);
        }
    }
    printf("\n");
}


//---------------------------------------------------------------------------------------------------------------------------------------
void supprimerJ()
{
    char idj[10];
    int trouve = 0;
    printf("saisir id \n");
    scanf("%s", idj);
    for (int i = 0; i < nombreJoueurs; i++){
        if (strcasecmp(joueurs[i].id, idj) == 0)
        {
            for (int j = i; j < nombreJoueurs - 1; j++){
                joueurs[j] = joueurs[j + 1];
            }
            nombreJoueurs--;
            trouve = 1;
            printf("le joueur avec l ID %s a ete supprime. \n", idj);
            break;
        }
    }
    if (!trouve)
    {
        printf("aucun joueur trouve avec l ID %s \n", idj);
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
void modifierPoste()
{
    char idj[10];
    int trouve = 0;
    printf("saisir id \n");
    scanf("%s", idj);
    getchar();
    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (strcasecmp(joueurs[i].id, idj) == 0)
        {
            printf("l ancien poste :%s \n", joueurs[i].poste);
            printf("saisir le nouveau poste : (gardien,defenseur,milieu,attaquant) \n");
            fgets(joueurs[i].poste, sizeof(joueurs[i].poste), stdin);
            joueurs[i].poste[strcspn(joueurs[i].poste, "\n")] = '\0';
            trouve = 1;
            printf("Le poste du joueur %s (%s) a ete modifie avec succes.\n", joueurs[i].nom, joueurs[i].id);
        }
    }
    if (!trouve)
    {
        printf("Aucun joueur trouve avec l ID %s \n", idj);
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
void modifierAge()
{
    char idj[10];
    int trouve = 0;
    printf("saisir id \n");
    scanf("%s", idj);
    getchar();
    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (strcasecmp(joueurs[i].id, idj) == 0)
        {
            printf("l ancien Age %d \n", joueurs[i].age);
            printf("saisir le nouveau Age: \n");
            scanf("%d", &joueurs[i].age);
            trouve = 1;
            printf("L'age du joueur %s (%s) a ete modifie avec succes.\n", joueurs[i].nom, joueurs[i].id);
        }
    }
    if (!trouve)
    {
        printf("Aucun joueur trouve avec l ID %s \n", idj);
    }
}
//----------------------------------------------------------------------------------------------------------------------
void modifierNombreButs()
{
    char idj[10];
    int trouve = 0;
    int star = 0;
    printf("saisir id \n");
    scanf("%s", idj);
    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (strcasecmp(joueurs[i].id, idj) == 0)
        {
            printf("l ancien nombre de Buts %d \n", joueurs[i].buts);
            printf("saisir le nouveau nombre de buts: \n");
            scanf("%d", &joueurs[i].buts);
            trouve = 1;
            printf("Les Buts du joueur %s (%s) a ete modifie avec succes.\n", joueurs[i].nom, joueurs[i].id);
        }
        if (joueurs[i].buts >= 10)
        {
            printf("Félicitations  C'est la star de l'équipe ! \n");
        }
    }

if (!trouve)
{
    printf("Aucun joueur trouve avec l ID %s \n", idj);
}
}


//-----------------------------------------------------------------------

void modifierJoueur()
{
    int choix;
    do
    {
        printf("--------Menu Modification-------\n");
        printf("1-Modifier le poste du joueur. \n");
        printf("2-Modifier l age du joueur. \n");
        printf("3-Modifier le nombre de buts marques par un joueur. \n");
        printf("0-Quitter \n");
        printf("saisir votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            modifierPoste();
            break;
        case 2:
            modifierAge();
            break;
        case 3:
            modifierNombreButs();
            break;
        default:
            printf("choix invalid \n");
        }
    }

    while (choix != 0);
}
//-----------------------------------------------------------------------------------------------------------------------------------------

void rechercherParId()
{
    char idj[10];
    int trouve = 0;
    printf("saisir id \n");
    scanf("%s", idj);
    getchar();
    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (strcasecmp(joueurs[i].id, idj) == 0)
        {
            printf("-------joueur ; %s-------- : \n id: %s \n- Nom: %s \n- Prenom: %s  \n- numeroMaillot: %d \n- Poste: %s  \n- Age: %d  \n- Buts: %d \n- Statut: %s \n",
                   joueurs[i].nom,
                   joueurs[i].id,
                   joueurs[i].nom,
                   joueurs[i].prenom,
                   joueurs[i].numeroMaillot,
                   joueurs[i].poste,
                   joueurs[i].age,
                   joueurs[i].buts,
                   joueurs[i].statut);
            trouve = 1;
        }
    }
    if (!trouve)
    {
        printf("aucun joueur trouve avec ce ID \n");
    }
}
//-----------------------------------------------------------------------

void rechercherParNom()
{
    char nomDeRecherche[10];
    int trouve = 0;
    printf("saisir le nom a rechercher \n");
    scanf("%s", nomDeRecherche);
    getchar();
    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (strcasecmp(joueurs[i].nom, nomDeRecherche) == 0)
        {
            printf("-------joueur ; %s-------- : \n id: %s \n- Nom: %s \n- Prenom: %s  \n- numeroMaillot: %d \n- Poste: %s  \n- Age: %d  \n- Buts: %d \n- Statut: %s \n",
                   joueurs[i].nom,
                   joueurs[i].id,
                   joueurs[i].nom,
                   joueurs[i].prenom,
                   joueurs[i].numeroMaillot,
                   joueurs[i].poste,
                   joueurs[i].age,
                   joueurs[i].buts,
                   joueurs[i].statut);
            trouve = 1;
            break;
        }
    }
    if (!trouve)
    {
        printf("aucun joueur trouve avec ce nom \n");
    }
}
//-----------------------------------------------------------------------

void rechercherj()
{

    int choix;
    do
    {
        printf("\n--- Menu De Recherche---\n");
        printf("1. Rechercher un joueur par Identifiant. \n");
        printf("2. Rechercher un joueur par Nom. \n");
        printf("0. Quitter\n");
        printf("saisir votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            rechercherParId();
            break;
        case 2:
            rechercherParNom();
            break;
        default:
            printf("choix invalid \n");
        }
    } while (choix != 0);
}
//-----------------------------------------------------------------------------------------------------------------------------
void nombreDesJoueurs()
{
    printf("le nombre des joueurs est : %d \n", nombreJoueurs);
}
void ageMoyenJoueurs()
{
    int sm = 0;
    float moyen = 0;
    for (int i = 0; i < nombreJoueurs; i++)
    {
        sm += joueurs[i].age;
    }

    moyen = sm / nombreJoueurs;
    printf(" L'age moyen des joueurs est: %.0f ans\n", moyen);
}

void JoueursParButs()
{
    int NbrButs;
    int trouve = 0;
    printf("saisir un nombre de Buts \n");
    scanf("%d", &NbrButs);
    printf("les joueurs ayant marque plus de %d buts \n", NbrButs);

    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (joueurs[i].buts > NbrButs)
        {
            printf("joueur %d - Nom: %s -Prenom: %s \n", i + 1, joueurs[i].nom, joueurs[i].prenom);
            printf("nombre de Buts: %d \n", joueurs[i].buts);
            trouve = 1;
        }
    }
    if (!trouve)
    {
        printf("aucun joueur marque plus de %d buts \n", NbrButs);
    }
}
void meilleurButeur()
{
    int maxButs = 0;
    char nommeilleurB[30];
    char pnommeilleurB[30];
    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (joueurs[i].buts > maxButs)
        {
            maxButs = joueurs[i].buts;
            strcpy(nommeilleurB, joueurs[i].nom);
            strcpy(pnommeilleurB, joueurs[i].prenom);
        }
    }
    printf(" le meilleur buteur est :  %s %s avec %d Bute", nommeilleurB, pnommeilleurB, maxButs);
}
void joueurAgeAndJeune()
{
    int maxAge = joueurs[0].age;
    int minAge = joueurs[0].age;
    char nomMinAge[20];
    char pnomminAge[20];
    char nomMaxAge[20];
    char pnommaxAge[20];

    for (int i = 0; i < nombreJoueurs; i++)
    {
        if (joueurs[i].age < minAge)
        {
            minAge = joueurs[i].age;
            strcpy(nomMinAge, joueurs[i].nom);
            strcpy(pnomminAge, joueurs[i].prenom);
        }
    }
    printf("le joueur le plus jeune :|--%s %s--| ", nomMinAge, pnomminAge);

    for (int j = 0; j < nombreJoueurs; j++)
    {
        if (joueurs[j].age > maxAge)
        {
            maxAge = joueurs[j].age;
            strcpy(pnommaxAge, joueurs[j].prenom);
            strcpy(nomMaxAge, joueurs[j].nom);
        }
    }
    printf(" le joueur le plus âgé |--%s %s--|", nomMaxAge, pnommaxAge);
}

//-----------------------------------------------------------------------

void statistiquej()
{

    int choix;
    do
    {
        printf("\n--- Menu De Statistique---\n");
        printf("1.Afficher le nombre total de joueurs dans l equipe.  \n");
        printf("2.Afficher l age moyen des joueurs.  \n");
        printf("3.Afficher les joueurs ayant marque plus de X buts (X introduit par l utilisateur).  \n");
        printf("4.Afficher le meilleur buteur (joueur avec le maximum de buts).  \n");
        printf("5. Afficher le joueur le plus jeune et le plus age. \n");
        printf("0.Quitter \n");
        printf("saisir votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            nombreDesJoueurs();
            break;
        case 2:
            ageMoyenJoueurs();
            break;
        case 3:
            JoueursParButs();
            break;
        case 4:
            meilleurButeur();
            break;
        case 5:
            joueurAgeAndJeune();
            break;
        default:
            printf("choix invalid \n");
        }
    } while (choix != 0);
}
//-----------------------------------------------------------------------

void afficherj()
{

    int choix;
    do
    {
        printf("\n--- Menu Affichage ---\n");
        printf("1. Liste normale\n");
        printf("2. Trier par nom (alphabetique)\n");
        printf("3. Trier par age\n");
        printf("4. Afficher par poste\n");
        printf("0. Quitter\n");
        printf("saisir votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            triNormale();
            break;
        case 2:
            triParNom();
            break;
        case 3:
            triParAge();
            break;
        case 4:
            triParPoste();
            break;
        default:
            printf("choix invalid \n");
        }
    } while (choix != 0);
}
//---------------------------------------------------------------------------------------------------------------------------------

int main()
{
    int choix;
    do
    {
        printf("\n------ Menu ------\n");
        printf("1. Ajouter des joueurs \n");
        printf("2.  Afficher tous les joueurs\n");
        printf("3. Supprimer un joueur\n");
        printf("4. Modifier un joueur\n");
        printf("5. Rechercher un joueur\n");
        printf("6. Statistiques\n");
        printf("0. Quitter\n");
        printf("------------------\n");
        printf("Votre choix : ");

        if (scanf("%d", &choix) == 0)
        {
            choix = 8;
            while (getchar() != '\n')
                ;
        }

        switch (choix)
        {
        case 1:
            ajouterplusierjoueur();
            break;
        case 2:
            afficherj();
            break;
        case 3:
            supprimerJ();
            break;
        case 4:
            modifierJoueur();
            break;
        case 5:
            rechercherj();
            break;
        case 6:
            statistiquej();
            break;
        case 0:
            printf("au revoir\n");
            break;
        default:
            printf("choix invalid \n");
            break;
        }

    } while (choix != 0);
}