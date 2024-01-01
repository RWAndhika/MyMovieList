#ifndef TITLES_H
#define TITLES_H

// ==================== DECLARATIONS ====================

void titleScreen();
void myMovieListBanner();
void holdScreen();
int programMenu();
void helpScreen();
void exitScreen();

void tableTitle();
void displayPerMovie(int);

int inputOptionRange(int, int);
int inputYearRange(int);
float inputRatingRange(float, float);
char confirmEntry();

// ==================== DEFINITIONS =====================

void titleScreen() {
    system("cls");
    printf("END OF SEMESTER PROJECT - \"MyMovieList\"\n\n");
    printf("Algoritma dan Pemrograman-01\n");
    printf("Group 18:\n");
    printf("Irfan Arif Maulana\t\t(1906379270)\n");
    printf("Raden Wisnu Andhika Pranidhia\t(1906379270)\n\n");
    printf("Teknik Elektro Fakultas Teknik\n");
    printf("Universitas Indonesia 2021");
    holdScreen();

    myMovieListBanner();
    holdScreen();
}

void myMovieListBanner() {
    system("cls");
    printf("=======================================================================================================================================================\n\n");
    printf("\t\t#####      #####            #####      #####                                        ####                               \n");
    printf("\t\t######    ######            ######    ######                                        ####                               \n");
    printf("\t\t#######  ####### ###   ###  #######  #######   ######  ###      #### ###  #######   ####        ### #######    ###     \n");
    printf("\t\t################ #### ###   ################  ###  ###  ###     #### ### ###   ###  ####        ### ##         ###     \n");
    printf("\t\t#### ###### ####  ######    #### ###### #### ###    ###  ###    ###  ### ########   ####        ### ####    #########  \n");
    printf("\t\t####  ####  ####    ###     ####  ####  #### ###    ###   ###  ###   ### ###        ####        ###   ####     ###     \n");
    printf("\t\t####   ##   ####    ###     ####   ##   ####  ###  ###     #####     ### ####       ########### ###     ###    ###  ###\n");
    printf("\t\t####        ####   ###      ####        ####   #####        ###      ###  ########  ########### ### #######    ####### \n\n");
    printf("=======================================================================================================================================================\n\n");
    printf("\n\n");
}

void holdScreen() {
    printf("\n\n\n\nPress any key to continue . . . ");
    getch();
}

int programMenu() {
    system("cls");
    printf("PROGRAM MENU\n\n\n");
    printf("Menu:\n");
    printf("1. Run program as admin\n");
    printf("2. Run program as user\n");
    printf("3. Help\n4. Exit program");
    printf("\n\n");
    return inputOptionRange(1, 4);
}

void helpScreen() {
    system("cls");
    printf("HELP\n\n");
    printf("1. Movie ratings are on the scale of 1 to 10.\n");
    printf("2. Special inputs (e.g. input '0' to go back) can be inserted to all input fields (e.g. both username and password).\n");
    printf("3. This program does not store new admin login, user login, and movie data.\n");
    printf("4. User's watchlist feature uses linked list data structure.\n");
    printf("\n\nPress any key to go back . . . ");
    getch();
}

void exitScreen() {
    system("cls");
    printf("Thank you!\n");
    printf("-Irfan and Andhika");

    printf("\n\n\n\nPress any key to exit program . . . ");
    getch();
}


void tableTitle() {
    printf("%5s", "No.");
    printf("%50s", "Title");
    printf("%8s", "Year");
    printf("%20s", "Director");
    printf("%60s", "Actor(s)/Actress(es)");
    printf("%8s", "Rating");
    printf("\n===================================================================================================="); // 100
    printf("===================================================\n"); // 51
}

void displayPerMovie(int i) {
    printf("%50s", mv[i].title);
    printf("%8d", mv[i].year);
    printf("%20s", mv[i].director);
    printf("%60s", mv[i].actor);
    printf("%8.1f", mv[i].rating);
    printf("\n");
}


int inputOptionRange(int low, int up) {
    int input;

    printf("Input your selection (number): ");
    if(low < up) {
        while(1) {
            scanf("%d", &input);
            if(input >= low && input <= up) break;
            else printf("Option %d is not available.\n\nPlease re-input: ", input);
        }
        return input;
    } else {
        printf("\n\nPROGRAMMER ERROR\n");
        printf("Invalid argument (%d >= %d). Lower bound must be less than upper bound!", low, up);
        printf("\n\n\n\nExiting with return value of 1.\nPress any key to end program . . . ");
        getch();
        exit(1);
    }
}

int inputYearRange(int low) {
    int input;

    while(1) {
        scanf("%d", &input);
        if(input >= low) break;
        else printf("Input is out of range (%d <= %d)!\n\nPlease re-input: ", low, input);
    }
    return input;
}

float inputRatingRange(float low, float up) {
    float input;

    if(low < up) {
        while(1) {
            scanf("%f", &input);
            if(input >= low && input <= up) break;
            else printf("Input is out of range (%.1f <= %.1f <= %.1f)!\n\nPlease re-input: ", low, input, up);
        }
        return input;
    } else {
        printf("\n\nPROGRAMMER ERROR\n");
        printf("Invalid argument (%.1f >= %.1f). Lower bound must be less than upper bound!", low, up);
        printf("\n\n\n\nExiting with return value of 1.\nPress any key to end program . . . ");
        getch();
        exit(1);
    }
}

char confirmEntry() {
    char confirm;
    while(1) {
        scanf(" %c", &confirm);
        if(confirm == 'Y' || confirm == 'y' || confirm == 'N' || confirm == 'n') break;
        else printf("Invalid input.\n\nPlease re-input: ");
    }
    return confirm;
}

#endif