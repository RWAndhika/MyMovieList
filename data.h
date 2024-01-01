/* Abbreviation note: WL = WatchList */

#ifndef DATA_H
#define DATA_H

// ==================== MACROS =========================

#define QTTY 100
#define SIZE 100

// ==================== GLOBAL VARIABLES ===============

struct WLNode {
	char title[SIZE];
    int year;
	struct WLNode *nextPtr;
};

typedef struct WLNode WLNode;
typedef WLNode *WLNodePtr;

typedef struct Admin {
    char uname[SIZE];
    char pass[SIZE];
} Admin;

typedef struct User {
    char uname[SIZE];
    char pass[SIZE];
    WLNodePtr headPtr;
    WLNodePtr tailPtr;
} User;

typedef struct Movie {
    char title[SIZE];
    int year;
    char director[SIZE];
    char actor[SIZE];
    float rating;
} Movie;

Admin adm[QTTY];
User usr[QTTY];
Movie mv[QTTY];

int countAdmin = 0;
int countUser = 0;
int countMovie = 0;

// ==================== DECLARATIONS ====================

void getData();
void adminData();
void userData();
void movieData();

// ==================== DEFINITIONS =====================

void getData() {
    adminData();
    userData();
    movieData();
}

void adminData() {
    int i = 0;

    strcpy(adm[i].uname, "Andhika");
    strcpy(adm[i].pass, "alprog asiq");
    i++;

    strcpy(adm[i].uname, "Irfan");
    strcpy(adm[i].pass, "alprog ez");
    i++;

    countAdmin += i;
}

void userData() {
    int i = 0;

    strcpy(usr[i].uname, "Dika");
    strcpy(usr[i].pass, "stack");
    usr[i].headPtr = NULL;
    usr[i].tailPtr = NULL;
    i++;

    strcpy(usr[i].uname, "Irfan123");
    strcpy(usr[i].pass, "queue");
    usr[i].headPtr = NULL;
    usr[i].tailPtr = NULL;
    i++;

    countUser += i;
}

void movieData() {
    int i = 0;

    strcpy(mv[i].title, "Maquia");
    mv[i].year = 2018;
    strcpy(mv[i].director, "Mari Okada");
    strcpy(mv[i].actor, "Manaka Iwami");
    mv[i].rating = 8.4;
    i++;

    strcpy(mv[i].title, "Laskar Pelangi");
    mv[i].year = 2008;
    strcpy(mv[i].director, "Riri Riza");
    strcpy(mv[i].actor, "Ikra Nagara");
    mv[i].rating = 7.8;
    i++;

    strcpy(mv[i].title, "Gundala");
    mv[i].year = 2019;
    strcpy(mv[i].director, "Joko Anwar");
    strcpy(mv[i].actor, "Abimana Aryasatya, Tara Basro, Bront Palarae");
    mv[i].rating = 6.2;
    i++;

    strcpy(mv[i].title, "Inception");
    mv[i].year = 2010;
    strcpy(mv[i].director, "Christopher Nolan");
    strcpy(mv[i].actor, "Leonardo DiCaprio");
    mv[i].rating = 8.8;
    i++;

    strcpy(mv[i].title, "Spirited Away");
    mv[i].year = 2001;
    strcpy(mv[i].director, "Hayao Miyazaki");
    strcpy(mv[i].actor, "Rumi Hiiragi");
    mv[i].rating = 8.6;
    i++;

    strcpy(mv[i].title, "Parasite");
    mv[i].year = 2019;
    strcpy(mv[i].director, "Bong Joon Ho");
    strcpy(mv[i].actor, "Woo-sik Choi, So-dam Park");
    mv[i].rating = 8.6;
    i++;

    strcpy(mv[i].title, "Interstellar");
    mv[i].year = 2014;
    strcpy(mv[i].director, "Christopher Nolan");
    strcpy(mv[i].actor, "Matthew McConaughey");
    mv[i].rating = 8.6;
    i++;

    strcpy(mv[i].title, "Joker");
    mv[i].year = 2019;
    strcpy(mv[i].director, "Todd Phillips");
    strcpy(mv[i].actor, "Joaquin Phoneix");
    mv[i].rating = 8.4;
    i++;

    strcpy(mv[i].title, "The Godfather");
    mv[i].year = 1972;
    strcpy(mv[i].director, "Francis Ford C.");
    strcpy(mv[i].actor, "Marlon Brando");
    mv[i].rating = 9.2;
    i++;

    strcpy(mv[i].title, "Police Academy: Mission to Moscow");
    mv[i].year = 1994;
    strcpy(mv[i].director, "Alan Metter");
    strcpy(mv[i].actor, "G. W. Bailey");
    mv[i].rating = 3.5;
    i++;

    strcpy(mv[i].title, "Anti-Life");
    mv[i].year = 2020;
    strcpy(mv[i].director, "John Suits");
    strcpy(mv[i].actor, "Cody Kearsley, Bruce Willis, Rachel Nichols");
    mv[i].rating = 3.0;
    i++;

    strcpy(mv[i].title, "Dragon Wars");
    mv[i].year = 2007;
    strcpy(mv[i].director, "Hyung-rae Shim");
    strcpy(mv[i].actor, "Jason Behr");
    mv[i].rating = 3.5;
    i++;

    strcpy(mv[i].title, "Superfast!");
    mv[i].year = 2015;
    strcpy(mv[i].director, "Jason Friedberg");
    strcpy(mv[i].actor, "Alex Ashbaugh");
    mv[i].rating = 4.1;
    i++;

    strcpy(mv[i].title, "The Human Centipede II");
    mv[i].year = 2011;
    strcpy(mv[i].director, "Tom Six");
    strcpy(mv[i].actor, "Dieter Laser");
    mv[i].rating = 3.8;
    i++;

    strcpy(mv[i].title, "The Human Centipede I");
    mv[i].year = 2009;
    strcpy(mv[i].director, "Tom Six");
    strcpy(mv[i].actor, "Dieter Laser");
    mv[i].rating = 4.4;
    i++;

    strcpy(mv[i].title, "The Human Centipede III");
    mv[i].year = 2015;
    strcpy(mv[i].director, "Tom Six");
    strcpy(mv[i].actor, "Dieter Laser");
    mv[i].rating = 2.7;
    i++;

    strcpy(mv[i].title, "Whiplash");
    mv[i].year = 2014;
    strcpy(mv[i].director, "Damien Chazelle");
    strcpy(mv[i].actor, "Miles Teller");
    mv[i].rating = 8.5;
    i++;

    strcpy(mv[i].title, "Gladiator");
    mv[i].year = 2000;
    strcpy(mv[i].director, "Ridley Scott");
    strcpy(mv[i].actor, "Russell Crowe, Joaquin Phoenix");
    mv[i].rating = 8.5;
    i++;

    strcpy(mv[i].title, "Aliens");
    mv[i].year = 1986;
    strcpy(mv[i].director, "James Cameron");
    strcpy(mv[i].actor, "Michael Biehn");
    mv[i].rating = 8.3;
    i++;

    strcpy(mv[i].title, "Avengers: Endgame");
    mv[i].year = 2019;
    strcpy(mv[i].director, "Russo Brothers");
    strcpy(mv[i].actor, "Robert Downey Jr., Chris Hemsworth, Chris Evan");
    mv[i].rating = 8.4;
    i++;

    strcpy(mv[i].title, "Avengers: Age of Ultron");
    mv[i].year = 2015;
    strcpy(mv[i].director, "Joss Whedon");
    strcpy(mv[i].actor, "Mark Buffalo, Scarlett Johansson, Jeremy Renner");
    mv[i].rating = 7.3;
    i++;

    strcpy(mv[i].title, "Avengers: Assemble");
    mv[i].year = 2012;
    strcpy(mv[i].director, "Joss Whedon");
    strcpy(mv[i].actor, "Samuel L. Jackson, Robert Downey Jr., Chris Evans");
    mv[i].rating = 8.0;
    i++;

    strcpy(mv[i].title, "Avengers: Infinity War");
    mv[i].year = 2018;
    strcpy(mv[i].director, "Russo Brothers");
    strcpy(mv[i].actor, "Benedict Cumberbatch, Don Cheadle, Tom Holland");
    mv[i].rating = 8.4;
    i++;

    strcpy(mv[i].title, "Spider-Man");
    mv[i].year = 2002;
    strcpy(mv[i].director, "Sam Raimi");
    strcpy(mv[i].actor, "Tobey Maguire");
    mv[i].rating = 7.3;
    i++;

    strcpy(mv[i].title, "Spider-Man 2");
    mv[i].year = 2004;
    strcpy(mv[i].director, "Sam Raimi");
    strcpy(mv[i].actor, "Tobey Maguire");
    mv[i].rating = 7.3;
    i++;

    strcpy(mv[i].title, "Spider-Man 3");
    mv[i].year = 2007;
    strcpy(mv[i].director, "Sam Raimi");
    strcpy(mv[i].actor, "Tobey Maguire");
    mv[i].rating = 6.2;
    i++;

    strcpy(mv[i].title, "The Amazing Spider-Man");
    mv[i].year = 2012;
    strcpy(mv[i].director, "Marc Webb");
    strcpy(mv[i].actor, "Andrew Garfield");
    mv[i].rating = 6.9;
    i++;

    strcpy(mv[i].title, "The Amazing Spider-Man 2");
    mv[i].year = 2014;
    strcpy(mv[i].director, "Marc Webb");
    strcpy(mv[i].actor, "Andrew Garfield");
    mv[i].rating = 6.6;
    i++;

    strcpy(mv[i].title, "Spider-Man: Homecoming");
    mv[i].year = 2017;
    strcpy(mv[i].director, "Jon Watts");
    strcpy(mv[i].actor, "Tom Holland");
    mv[i].rating = 7.4;
    i++;

    strcpy(mv[i].title, "Spider-Man: Far from Home");
    mv[i].year = 2019;
    strcpy(mv[i].director, "Jon Watts");
    strcpy(mv[i].actor, "Tom Holland");
    mv[i].rating = 7.4;
    i++;

    strcpy(mv[i].title, "Spider-Man: Into the Spider-Verse");
    mv[i].year = 2019;
    strcpy(mv[i].director, "Peter Ramsey");
    strcpy(mv[i].actor, "Shameik Moore");
    mv[i].rating = 8.4;
    i++;

    strcpy(mv[i].title, "Harry Potter and the Philosopher's Stone");
    mv[i].year = 2001;
    strcpy(mv[i].director, "Chris Columbus");
    strcpy(mv[i].actor, "Daniel Radcliffe");
    mv[i].rating = 7.6;
    i++;

    strcpy(mv[i].title, "Harry Potter and the Chamber of Secrets");
    mv[i].year = 2002;
    strcpy(mv[i].director, "Chris Columbus");
    strcpy(mv[i].actor, "Daniel Radcliffe");
    mv[i].rating = 7.4;
    i++;

    strcpy(mv[i].title, "Harry Potter and the Prisoner of Azkaban");
    mv[i].year = 2004;
    strcpy(mv[i].director, "Alfonso Cuaron");
    strcpy(mv[i].actor, "Daniel Radcliffe");
    mv[i].rating = 7.9;
    i++;

    strcpy(mv[i].title, "Harry Potter and the Goblet of Fire");
    mv[i].year = 2005;
    strcpy(mv[i].director, "Mike Newell");
    strcpy(mv[i].actor, "Daniel Radcliffe");
    mv[i].rating = 7.7;
    i++;

    strcpy(mv[i].title, "Harry Potter and the Order of the Phoenix");
    mv[i].year = 2007;
    strcpy(mv[i].director, "David Yates");
    strcpy(mv[i].actor, "Daniel Radcliffe");
    mv[i].rating = 7.5;
    i++;

    strcpy(mv[i].title, "Harry Potter and the Half-Blood Prince");
    mv[i].year = 2009;
    strcpy(mv[i].director, "David Yates");
    strcpy(mv[i].actor, "Daniel Radcliffe");
    mv[i].rating = 7.6;
    i++;

    strcpy(mv[i].title, "Fantastic Beasts and Where to Find Them");
    mv[i].year = 2016;
    strcpy(mv[i].director, "David Yates");
    strcpy(mv[i].actor, "Eddie Redmayne");
    mv[i].rating = 7.3;
    i++;

    strcpy(mv[i].title, "Fantastic Beasts: The Crimes of Grindelwald");
    mv[i].year = 2018;
    strcpy(mv[i].director, "David Yates");
    strcpy(mv[i].actor, "Eddie Redmayne");
    mv[i].rating = 6.5;
    i++;

    countMovie += i;
}

#endif