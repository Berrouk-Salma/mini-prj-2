#include <stdio.h>
#include <string.h>

typedef struct {
    char nom[10];
    char adress_email[20];
    int nomero;
} contact;

int count = 0;
contact user[100];

int main() {
    int choix;
    char adress_email[20];
    int i, j;
    int index = -1;
    char new_adress_email[20];

    do {
        printf("1: Ajouter un Contact.\n");
        printf("2: Afficher Tous les Contacts: \n");
        printf("3: Supprimer un Contact : \n");
        printf("4: Modifier un Contact \n");
        printf("5: Rechercher un Contact: \n");
        printf("6: Quiter le programe : \n");

        printf("entrez votre choix :");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("saisir le nom :\n ");
                scanf("%s", user[count].nom);
                printf("saisir adress email: \n");
                scanf("%s", user[count].adress_email);
                printf("saisir le nomero : \n");
                scanf("%d", &user[count].nomero);
                count++;
                break;

            case 3:
                printf("donne moi email user \n");
                scanf("%s", adress_email);
                for (i = 0; i < count; i++) {
                    if (strcmp(user[i].adress_email, adress_email) == 0) {
                        for (j = i; j < count - 1; j++)
                            user[j] = user[j + 1];
                        count--;
                        break; // exit after deleting
                    }
                }
                break;

            case 4:
                printf("donne moi adress email d user la Modifier \n");
                scanf("%s", adress_email);
                for (i = 0; i < count; i++) {
                    if (strcmp(user[i].adress_email, adress_email) == 0) {
                        printf("______________________________\n");
                        printf("nom : %s \n", user[i].nom);
                        printf("adress_email : %s \n", user[i].adress_email);
                        printf("nomero : %d \n", user[i].nomero);
                        index = i;
                    }
                }
                if (index != -1) {
                    printf("Entrez la nouvel email : ");
                    scanf("%s", new_adress_email);
                    strcpy(user[index].adress_email, new_adress_email);
                }
                break;

            case 5:
                printf("entrer user pour faire la recherche\n");
                scanf("%s", adress_email);
                for (i = 0; i < count; i++) {
                    if (strcmp(user[i].adress_email, adress_email) == 0) {
                        printf("________________________\n");
                        printf("nom: %s \n", user[i].nom);
                        printf("adress email: %s \n", user[i].adress_email);
                        printf("nomero: %d \n", user[i].nomero);
                        index = i;
                    }     
                }
                break;

            case 6:
                printf("bye bye\n");
                break;
        }
        index = -1;
        printf("_______________________\n");
    } while (choix != 6);

    return 0;
}
