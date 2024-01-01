#ifndef ADMIN_H
#define ADMIN_H

// ==================== DECLARATIONS ====================

int mainMenuAdmin();

void displayMovieScreen();
void sortMenuScreenAdmin();
void searchMenuScreenAdmin();

void editMovieScreen();
void newMovieScreen();

// ==================== DEFINITIONS =====================

int mainMenuAdmin() {
    myMovieListBanner();
    printf("MAIN MENU:\n");
    printf("1. Display movie list\n2. Edit movie data\n3. Add new movie to database\n");
    printf("4. Logout\n\n");
    return inputOptionRange(1, 4);
}


void displayMovieScreen() {
    int i;
    
    bubbleSortTitle(0);
    myMovieListBanner();
    tableTitle();
    for(i = 0; i < countMovie; i++) {
        printf("%5d", i + 1);
        displayPerMovie(i);
    }
    printf("\n\n");

    printf("Display Menu:\n");
    printf("1. Sort\n2. Search\n");
    printf("3. Back to main menu\n\n");
    switch(inputOptionRange(1, 3)) {
        case 1: sortMenuScreenAdmin();
                break;
        case 2: searchMenuScreenAdmin();
                break;
        default: return;
                 break;
    }
}

void sortMenuScreenAdmin() {
    int exit = 0, i;
    
    myMovieListBanner();

    do {
        printf("SORT MENU:\n");
        printf("1. Title (A-Z)\n2. Title (Z-A)\n");
        printf("3. Year (oldest to newest)\n4. Year (newest to oldest)\n");
        printf("5. Rating (lowest to highest)\n6. Rating (highest to lowest)\n");
        printf("7. Back to main menu\n\n");

        switch(inputOptionRange(1, 7)) {
            case 1: bubbleSortTitle(0);
                    break;
            case 2: bubbleSortTitle(1);
                    break;
            case 3: bubbleSortYear(0);
                    break;
            case 4: bubbleSortYear(1);
                    break;
            case 5: bubbleSortRating(0);
                    break;
            case 6: bubbleSortRating(1);
                    break;
            default: exit = 1;
                     break;
        }

        if(exit == 0) {
            myMovieListBanner();
            tableTitle();
            for(i = 0; i < countMovie; i++) {
                printf("%5d", i + 1);
                displayPerMovie(i);
            }
            printf("\n\n");
        }
    } while(exit == 0);
}

void searchMenuScreenAdmin() {
    int exit = 0;

    myMovieListBanner();

    do {
        printf("SEARCH MENU:\n");
        printf("1. General search\n");
        printf("2. Year (range)\n3. Rating (minimum)\n");
        printf("4. Back to main menu\n\n");

        switch(inputOptionRange(1, 4)) {
            case 1: searchGeneralAdmin();
                    break;
            case 2: searchYearRangeAdmin();
                    break;
            case 3: searchRatingMinimumAdmin();
                    break;
            default: exit = 1;
                     break;
        }
    } while(exit == 0);
}


void editMovieScreen() {
    char title[SIZE], director[SIZE], actor[SIZE];
    int year;
    float rating;

    int index, i;
    char confirm;

    bubbleSortTitle(0);

    myMovieListBanner();
    printf("EDIT MOVIE DATA\n\n");

    printf("No.\tTitle\n");
    printf("======================================================================\n"); // 70
    for(i = 0; i < countMovie; i++) printf("%d\t%s (%d)\n", i + 1, mv[i].title, mv[i].year);

    printf("\nWhich movie would you like to edit?\n");
    index = inputOptionRange(1, countMovie) - 1;

    myMovieListBanner();
    printf("EDIT MOVIE DATA\n\n");
    printf("Old movie details\n");
    printf("Title\t\t: %s\n", mv[index].title);
    printf("Year released\t: %d\n", mv[index].year);
    printf("Director\t: %s\n", mv[index].director);
    printf("Actor\t\t: %s\n", mv[index].actor);
    printf("Rating\t\t: %.1f\n", mv[index].rating);
    printf("\n\n");

    printf("New movie details\n");
    printf("Title\t\t: ");
    scanf("\n%[^\n]s", &title);
    printf("Year released\t: ");
    year = inputYearRange(1880);
    printf("Director\t: ");
    scanf("\n%[^\n]s", &director);
    printf("Actor\t\t: ");
    scanf("\n%[^\n]s", &actor);
    printf("Rating\t\t: ");
    rating = inputRatingRange(1, 10);

    printf("\n\nDo you want to confirm your entry? (Y/y or N/n): ");
    confirm = confirmEntry();

    if(confirm == 'Y' || confirm == 'y') {
        strcpy(mv[index].title, title);
        mv[index].year = year;
        strcpy(mv[index].director, director);
        strcpy(mv[index].actor, actor);
        mv[index].rating = rating;
        printf("New entry successfully added.");
    } else {
        printf("New entry canceled.");
    }

    holdScreen();
}

void newMovieScreen() {
    char title[SIZE], director[SIZE], actor[SIZE];
    int year;
    float rating;

    char confirm;

    myMovieListBanner();
    printf("ADD NEW MOVIE TO DATABASE\n\n");

    printf("Title\t\t: ");
    scanf("\n%[^\n]s", &title);
    printf("Year released\t: ");
    year = inputYearRange(1880);
    printf("Director\t: ");
    scanf("\n%[^\n]s", &director);
    printf("Actor\t\t: ");
    scanf("\n%[^\n]s", &actor);
    printf("Rating\t\t: ");
    rating = inputRatingRange(1, 10);

    printf("\n\nDo you want to confirm your entry? (Y/y or N/n): ");
    confirm = confirmEntry();

    if(confirm == 'Y' || confirm == 'y') {
        strcpy(mv[countMovie].title, title);
        mv[countMovie].year = year;
        strcpy(mv[countMovie].director, director);
        strcpy(mv[countMovie].actor, actor);
        mv[countMovie].rating = rating;
        countMovie++;
        printf("New entry successfully added.");
    } else {
        printf("New entry canceled.");
    }

    holdScreen();
}

#endif