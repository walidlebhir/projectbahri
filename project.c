#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<locale.h>
typedef struct {
    int jour;
    int mois;
    int anne;
} date;

typedef struct {
    int idclient;
    int idhistorique;
    int password;
    char CIN[20];
    char nom[20];
    char prenom[20];
    char adress[100];
    char phone[20];
    date d;
    char lieudenaissa[20];
} client;

void clear_screen() {
    system("cls");
}

void remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void ecrituredansfichier(FILE *fich, client c1) {
    fich = fopen("client.txt", "a+");
    if (fich == NULL) {
        printf("Impossible d'ouverture de fichier ");
        return;
    }

    fprintf(fich, "%-10d | %-10s | %-10s | %02d/%02d/%04d     | %-17s | %-8s | %-30s | +212 %-10s | %-7d | %-15d\n",
            c1.idclient, c1.nom, c1.prenom, c1.d.jour, c1.d.mois, c1.d.anne,
            c1.lieudenaissa, c1.CIN, c1.adress, c1.phone, c1.password, c1.idhistorique);

    fclose(fich);
    clear_screen();
}

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int getLastClientId(FILE *fich) {
    int lastId = 100000;
    int tempId;

    fich = fopen("client.txt", "r");
    if (fich == NULL) {
        printf("Fichier non trouve. Initialisation de l'ID à %d.\n", lastId);
        return lastId;
    }

    char line[200];
    while (fgets(line, sizeof(line), fich) != NULL) {
        if (sscanf(line, "%d", &tempId) == 1) {
            if (tempId > lastId) {
                lastId = tempId;
            }
        }
    }

    fclose(fich);
    return lastId;
}
void quitter(){
                system("cls");
            gotoxy(32,5);
            printf("--------------------------------------------");
            for(int i =0 ;i<5 ;i++){   
                printf("|");
            }
            printf("--------------------------------------------");
            
            gotoxy(67,10);
            printf("Merci pour votre Visite ..... ");
            gotoxy(32,15);
            printf("--------------------------------------------");
            for(int i =0 ;i<5 ;i++){   
                printf("|");
            }
            printf("--------------------------------------------");          
}
void erreur(){
       system("cls");
            gotoxy(32,5);
            printf("--------------------------------------------");
            for(int i =0 ;i<5 ;i++){   
                printf("|");
            }
            printf("--------------------------------------------");
            
            gotoxy(67,10);
            printf("erreur de saisir  :\n");
            gotoxy(32,15);
            printf("--------------------------------------------");
            for(int i =0 ;i<5 ;i++){   
                printf("|");
            }
            printf("--------------------------------------------");       
    
}
void afficher_menu() {
    int choix=0;
    int x = 30;
    int y = 2;  
    client c;
    int idclient;
    double montant;
    FILE* fich;
    date d;
    system("cls");
 do
    {
    gotoxy(x,y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ MAIN MENU ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 1-CREATION DE COMPTE .\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 2-AFFICHAGE DE COMPTE .\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 3-FAIRE UNE TRANSACTION .\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 4-EFFECTUER UN RETRAIT  .\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 5-EFFECTUER UN DÉPÔT .\n");

     gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 6-SUPPRIMER LE COMPTE .\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 7-QUITTER L'APPLICATION.\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");
    gotoxy(x,y++);
    printf("donner votre choix : ");
    scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            system("cls");
            CREATIONDECOMPTE(fich,idlcient);
            break;
        case 2:
            system("cls");
            AFFICHAGEDECOMPTE(fich,idclient);
            break;
        case 3:
         
            break;
        case 4:
           
            break;
        case 5:
            
            break;
         case 6:
          
            break;
        case 7:
            quitter();
            break;
        default:
            erreur();
            break;
        }
    } while (choix != 6);
    
}
int CREATIONDECOMPTE(FILE* fich, client c1) {
  
    char choix = 'N';
    int lastId = getLastClientId(fich);
    c1.idclient = lastId + 1;

    int lastIdhis = 1;
    fich = fopen("client.txt", "r");
    if (fich != NULL) {
        char line[200];
        while (fgets(line, sizeof(line), fich) != NULL) {
            if (sscanf(line, "ID HISTORIQUE : %d", &lastIdhis) == 1) {
                lastIdhis++;
            }
        }
        fclose(fich);
    }
    c1.idhistorique = lastIdhis;

    int x = 30, y = 2;
    do {
        gotoxy(x, y++);
        printf("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ CREATION DE COMPTE ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");

        gotoxy(x, y++);
        printf("ATTENTION : VOUS ÊTES RESPONSABLE DE CHAQUE ERREUR DANS VOS INFORMATIONS.\n");
        getchar();
        gotoxy(x, y++);
        printf("Donner votre nom:  \t ");
        fgets(c1.nom, sizeof(c1.nom), stdin);
        
        remove_newline(c1.nom);
        
        gotoxy(x, y++);
        printf(" Donner votre prenom: \t");
        fgets(c1.prenom, sizeof(c1.prenom), stdin);
        
        remove_newline(c1.prenom);

        do {
            gotoxy(x, y++);
            printf("Donner votre date de naissance (JJ MM AAAA): ");
            scanf("%d %d %d", &c1.d.jour, &c1.d.mois, &c1.d.anne);
            while (getchar() != '\n'); // Flush remaining characters

            if (c1.d.jour > 31 || c1.d.mois > 12 || c1.d.anne < 1900 || c1.d.anne > 9999) {
                printf("Date incorrecte ! Veuillez entrer une date valide.\n");
            }
        } while (c1.d.jour > 31 || c1.d.mois > 12 || c1.d.anne < 1900 || c1.d.anne > 9999);

        gotoxy(x, y++);
        printf("Donner votre lieu de naissance :\t");
        fgets(c1.lieudenaissa, sizeof(c1.lieudenaissa), stdin);
        remove_newline(c1.lieudenaissa);

        gotoxy(x, y++);
        printf("Donner votre numero de carte national (CIN): \t");
        fgets(c1.CIN, sizeof(c1.CIN), stdin);
        remove_newline(c1.CIN);

        gotoxy(x, y++);
        printf("Donner votre adresse : \t ");
        fgets(c1.adress, sizeof(c1.adress), stdin);
        remove_newline(c1.adress);

        do {
            gotoxy(x, y++);
            printf("Donner votre numero de telephone : +212 ");
            scanf("%s", c1.phone);
            while (getchar() != '\n'); 

            if (strlen(c1.phone) != 9) {
                printf("Le numero est incorrect ! Il doit contenir exactement 9 chiffres.\n");
            }
        } while (strlen(c1.phone) != 9);

        gotoxy(x, y++);
        printf("TU PEUX SAUVEGARDER VOTRE INFORMATIONS O/N : \n");
        scanf(" %c", &choix);
        while (getchar() != '\n'); 
    } while (choix == 'N' || choix =='n');

    gotoxy(x, y++);
    printf("TU peux donner le mot de passe (4 chiffres) : ");
    scanf("%d", &c1.password);
    while (getchar() != '\n'); 

    system("cls");
    gotoxy(x, y++);
    printf("Ton compte a ete enregistre avec succes. ");
    ecrituredansfichier(fich, c1);

    return 0;
}
int AFFICHAGEDECOMPTE(FILE* fich, int clientid){
     int choix=0;
    int x = 30;
    int y = 2;  
  
    date d;
    
 do
    {
    gotoxy(x,y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ AFFICHAGE DE COMPTE  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 1-AFFICHER  VOTRE INFORMATIONS PERSONNELES .\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 2-AFFICHER VOTRE SOLDE .\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 3-AFFICHER VOTRE HISTORIQUES.\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 4-MODIFIER VOTRE INFORMATIONS .\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 5-CHANGER VOTRE MOT DE PASS  .\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓░ 6-RETURNER AU MENU PRINCIPALE.\n");

    gotoxy(x, y++);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");
    gotoxy(x,y++);
  
    printf("donner votre choix : ");
    scanf("\t%d",&choix);
    printf("%d %d",x,y);
        switch (choix)
        {
        case 1:
           
            
            break;
        case 2:
           
            break;
        case 3:
         
            break;
        case 4:
           
            break;
        case 5:
            
            break;
        case 6:
            afficher_menu();
            break;
        default:
            erreur();
            break;
        }
    } while (choix != 6);
    
}
int main() {
    setlocale(LC_ALL, "fr_FR.UTF-8");  
    SetConsoleOutputCP(65001);
    system("COLOR 0A");
    afficher_menu();
    
    return 0;
}