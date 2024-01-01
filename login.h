#ifndef LOGIN_H
#define LOGIN_H

// ==================== MACROS ==========================

#define ENTER 13
#define TAB 9
#define BKSP 8

// ==================== GLOBAL VARIABLES ===============

int loginToken = 0; // To save which user is logged in

// ==================== DECLARATIONS ====================

int loginScreenAdmin();
void newAdmin();

int loginScreenUser();
void newUser();

void passwordEntry(char[]);

// ==================== DEFINITIONS =====================

int loginScreenAdmin() {
    char uname[SIZE], pass[SIZE];
    int i;
    
    runNewAdmin:
    while(1) {
        myMovieListBanner();
        printf("ADMIN LOGIN\n\n\n");
        printf("Input '0' to go back to program menu\n");
        printf("Input '1' to register a new login account\n\n");

        printf("Username\t: ");
        scanf("\n%[^\n]s", &uname);
        if(strcmp(uname, "0") == 0) {
            return 0;
        } else if(strcmp(uname, "1") == 0) {
            newAdmin();
            goto runNewAdmin;
        }

        printf("Password\t: ");
        passwordEntry(pass);
        if(strcmp(pass, "0") == 0) {
            return 0;
        } else if(strcmp(pass, "1") == 0) {
            newAdmin();
            goto runNewAdmin;
        }

        for(i = 0; i < countAdmin; i++) {
            if(strcmp(uname, adm[i].uname) == 0 && strcmp(pass, adm[i].pass) == 0) {
                printf("\n\nLogin successful.");
                holdScreen();
                return 1;
            }
        }

        printf("\n\nUsername / password is incorrect.\n\n\n\nPress any key to try again. ");
        getch();
    }
}

void newAdmin() {
    char uname[SIZE], pass[SIZE];
    char confirm;

    myMovieListBanner();
    printf("REGISTER NEW ADMIN ACCOUNT\n\n\n");
    printf("Input '0' to go back to login screen\n\n");

    while(1) {
        printf("Username\t: ");
        scanf("\n%[^\n]s", &uname);
        if(strcmp(uname, "0") == 0) return;
        if(strlen(uname) >= 4) break;
        else printf("Username must be at least 4 characters long!\n\n");
    }
    
    while(1) {
        printf("Password\t: ");
        scanf("\n%[^\n]s", &pass);
        if(strcmp(pass, "0") == 0) return;
        if(strlen(pass) >= 4) break;
        else printf("Password must be at least 4 characters long!\n\n");
    }
    
    printf("\n\nConfirm to register a new admin account? (Y/y or N/n): ");
    confirm = confirmEntry();

    if(confirm == 'Y' || confirm == 'y') {
        strcpy(adm[countAdmin].uname, uname);
        strcpy(adm[countAdmin].pass, pass);
        countAdmin++;
        printf("New account successfully registered.");
    } else {
        printf("New account registration canceled.");
    }

    printf("\n\n\n\nPress any key to go back to login screen. ");
    getch();
}


int loginScreenUser() {
    char uname[SIZE], pass[SIZE];
    int i;
    
    runNewUser:
    while(1) {
        myMovieListBanner();
        printf("USER LOGIN\n\n\n");
        printf("Input '0' to go back to program menu\n");
        printf("Input '1' to register a new login account\n\n");

        printf("Username\t: ");
        scanf("\n%[^\n]s", &uname);
        if(strcmp(uname, "0") == 0) {
            return 0;
        } else if(strcmp(uname, "1") == 0) {
            newUser();
            goto runNewUser;
        }

        printf("Password\t: ");
        passwordEntry(pass);
        if(strcmp(pass, "0") == 0) {
            return 0;
        } else if(strcmp(pass, "1") == 0) {
            newUser();
            goto runNewUser;
        }

        for(i = 0; i < countUser; i++) {
            if(strcmp(uname, usr[i].uname) == 0 && strcmp(pass, usr[i].pass) == 0) {
                loginToken = i;
                printf("\n\nLogin successful.");
                holdScreen();
                return 1;
            }
        }

        printf("\n\nUsername / password is incorrect.\n\n\n\nPress any key to try again. ");
        getch();
    }
}

void newUser() {
    char uname[SIZE], pass[SIZE];
    char confirm;

    myMovieListBanner();
    printf("REGISTER NEW USER ACCOUNT\n\n\n");
    printf("Input '0' to go back to login screen\n\n");

    while(1) {
        printf("Username\t: ");
        scanf("\n%[^\n]s", &uname);
        if(strcmp(uname, "0") == 0) return;
        if(strlen(uname) >= 4) break;
        else printf("Username must be at least 4 characters long!\n\n");
    }
    
    while(1) {
        printf("Password\t: ");
        scanf("\n%[^\n]s", &pass);
        if(strcmp(pass, "0") == 0) return;
        if(strlen(pass) >= 4) break;
        else printf("Password must be at least 4 characters long!\n\n");
    }
    
    printf("\n\nConfirm to register a new user account? (Y/y or N/n): ");
    confirm = confirmEntry();

    if(confirm == 'Y' || confirm == 'y') {
        strcpy(usr[countUser].uname, uname);
        strcpy(usr[countUser].pass, pass);
        countUser++;
        printf("New account successfully registered.");
    } else {
        printf("New account registration canceled.");
    }

    printf("\n\n\n\nPress any key to go back to login screen. ");
    getch();
}


void passwordEntry(char pass[]) {
    char temp;
    int i = 0;

    while(1) {
        temp = getch();
        if(temp == ENTER || temp == TAB) {
            pass[i] = '\0';
            break;
        } else if(temp == BKSP) {
            if(i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            pass[i] = temp;
            i++;
            printf("*");
        }
    }
}

#endif