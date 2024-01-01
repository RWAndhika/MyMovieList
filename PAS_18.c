/*  
    End of Semester Project
    "MyMovieList"

    Algoritma dan Pemrograman-01
    Group 18:
    Irfan Arif Maulana              (1906379270)
    Raden Wisnu Andhika Pranidhia   (1906354545)

    Teknik Elektro
    Departemen Teknik Elektro Fakultas Teknik
    Universitas Indonesia
    2021
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "data.h"
#include "titles.h"
#include "login.h"
#include "sort-search.h"
#include "linked-list.h"
#include "admin.h"
#include "user.h"

int main() {
    int reset = 1, login;

    titleScreen();
    getData();

    do {
        switch(programMenu()) {
            case 1: // Run program as admin
                login = loginScreenAdmin();
                if(login) {
                    do {
                        switch(mainMenuAdmin()) {
                            case 1: displayMovieScreen();
                                    break;
                            case 2: editMovieScreen();
                                    break;
                            case 3: newMovieScreen();
                                    break;
                            default: login = 0;
                                    break;
                        }
                    } while(login);
                }
                break;
            case 2: // Run program as user
                login = loginScreenUser();
                if(login) {
                    do {
                        switch(mainMenuUser()) {
                            case 1: planWLScreen();
                                    break;
                            case 2: viewWLScreen(usr[loginToken].headPtr);
                                    break;
                            default: login = 0;
                                     loginToken = 0; // No user is logged in
                                    break;
                        }
                    } while(login);
                }
                break;
            case 3:
                helpScreen();
                break;
            default:
                reset = 0;
                break;
        }
    } while(reset);

    exitScreen();

    return 0;
}
