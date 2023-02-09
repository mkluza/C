/*Autor: Mariusz Kluza*/
/*Program tworzy baze danych artykulow w sklepie (wersja oparta na tablicach)*/

#include <stdio.h>

#define NAME 25         /*maksymalna dlugosc nazwy*/
#define MAX_NUMBER 100      /*maksymalna ilosc artykulow w bazie*/

struct part {
    int numer_id;
    char nazwa[NAME+1];         /*dodatkowe miejsce na znak pusty na koncu nazwy*/
    int ilosc;
    double cena;
} Dane[MAX_NUMBER];

int num_art = 0;        /*ilosc artykolow w bazie*/

/*deklaracje funkcji uzytych w programie*/
int znajdz_id(int numer_id);
void dodaj();
void wyszukaj();
void aktualizuj_nazwe();
void aktualizuj_ilosc();
void aktualizuj_cene();
void pokaz();
void zapisz();
void czytaj_nazwe(char A[], int n);

int main()      /*nieskonczona petla sluzaca do wyboru danej opercaji z menu*/
{
    int num_oper;

    printf("************************************************************************\n"
           "*                                                                      *\n"
           "*                           BAZA DANYCH                                *\n"
           "*                                                                      *\n"
           "************************************************************************\n");
    for(;;) {
        printf("------------------------------\n"
               "Opercaje mozliwe do wykonania:\n"
               "------------------------------\n"
               "1.Dodaj artykul  do bazy\n"
               "2.Wyszukaj artykul w bazie\n"
               "3.Aktualizuj nazwe artykulu w bazie\n"
               "4.Aktualizuj ilosc artykulu w bazie\n"
               "5.Aktualizuj cene artykulu w bazie\n"
               "6.Pokaz biezacy stan bazy\n"
               "7.Zapisz baze do pliku tekstowego\n"
               "0.Wyjscie\n");
        printf("Wybierz numer operacji jaka chcesz wykonac:...");
        scanf(" %d", &num_oper);

        switch(num_oper) {
            case 1: dodaj(); break;
            case 2: wyszukaj(); break;
            case 3: aktualizuj_nazwe(); break;
            case 4: aktualizuj_ilosc(); break;
            case 5: aktualizuj_cene(); break;
            case 6: pokaz(); break;
            case 7: zapisz(); break;
            case 0: return 0;
            default: printf("Niepoprawny numer operacji...\n");
            }
            printf("\n");
    }
}

/*********************************************************************************************************
 * znajdz_id: Sprawdza czy artykul o podanym numerze ID znajduje sie juz w bazie,                        *
 *            jesli tak to zwraca indeks (num_art) pod jakim jest zapisany, jesli nie to zwraca -1.      *
 *********************************************************************************************************/
int znajdz_id(int numer_id){
    int n;

    for(n=0; n<num_art; n++)
        if(Dane[n].numer_id==numer_id)
            return n;
return -1;
}

/*****************************************************************************************
 * dodaj: Pyta uzytkownika o dane nowego artykulu i wprowadza je do bazy danych.         *
 *        Jesli wprowadzony artykul juz znajduje sie w bazie, lub baza jest pelna,       *
 *        wypisuje odpowiedni komunikat i konczy dzialanie.                              *
 *****************************************************************************************/
void dodaj(){
    int k;

    if(num_art==MAX_NUMBER){
        printf("Baza danych przepelniona: nie mozna dodac artykulu.\n");
        printf("\n");
        return;
    }

    printf("Podaj numer ID artykulu:...");
    scanf(" %d", &k);
    if(znajdz_id(k)>=0){
        printf("Artykul o takim numerze ID jest juz obecny w bazie.\n");
        printf("\n");
        return;
    }
    getchar();          /*sczytuje zbedny znak nowego wiersza (enter)*/

    Dane[num_art].numer_id=k;
    printf("Podaj nazwe artykulu:...");
    czytaj_nazwe(Dane[num_art].nazwa, NAME);        /*wywoluje funkcje czytaj_nazwe*/
    printf("Podaj ilosc artykulu:...");
    scanf(" %d", &Dane[num_art].ilosc);
    printf("Podaj cene artykulu:...");
    scanf(" %lf", &Dane[num_art].cena);
    num_art++;
    printf("Artykul zostal pomyslnie dodany do bazy.");
    printf("\n");
}

/**********************************************************************************************
 * wyszukaj: Pyta uzytkownika o numer ID artykulu i szuka go w bazie. Jesli znajdzie,         *
 *           wypisuje jego nazwe, ilosc i cene, jesli nie, wypisuje odpowiedni komunikat.     *
 **********************************************************************************************/
void wyszukaj(){
    int numer, i;

    printf("Podaj numer ID artykulu:...");
    scanf(" %d", &numer);

    i=znajdz_id(numer);
    if(i>=0){
        printf("Nazwa artykulu: %s\n", Dane[i].nazwa);
        printf("Ilosc artykulu: %d\n", Dane[i].ilosc);
        printf("Cena artykulu: %lf\n", Dane[i].cena);
    } else
        printf("Nie znaleziono artykulu o takim numerze ID.");
    printf("\n");
}

/******************************************************************************************************************
 * aktualizuj_nazwe: Pyta uzytkownika o numer ID artykulu. Jesli artykulu nie ma w bazie,                         *
 *                   wypisuje odpowiedni komunikat, a jesli jest, pyta o nowa nazwe i aktualizuje baze danych.    *
 ******************************************************************************************************************/
void aktualizuj_nazwe(){
    int numer, i, nowy;

    printf("Podaj numer ID artykulu:...");
    scanf(" %d", &numer);
    i=znajdz_id(numer);
    if(i>=0){
        getchar();          /*sczytuje zbedny znak nowego wiersza (enter)*/
        printf("Podaj nowa nazwe artykulu:...");
        czytaj_nazwe(Dane[i].nazwa, NAME);        /*wywoluje funkcje czytaj_nazwe*/
        printf("Nazwa artykulu zostala zaktualizowana.");
    } else
        printf("Nie znaleziono artykulu o takim numerze ID.");
    printf("\n");
}

/******************************************************************************************************************
 * aktualizuj_ilosc: Pyta uzytkownika o numer ID artykulu. Jesli artykulu nie ma w bazie,                         *
 *                   wypisuje odpowiedni komunikat, a jesli jest, pyta o nowa ilosc i aktualizuje baze danych.    *
 ******************************************************************************************************************/
void aktualizuj_ilosc(){
    int numer, i, nowy;

    printf("Podaj numer ID artykulu:...");
    scanf(" %d", &numer);
    i=znajdz_id(numer);
    if(i>=0){
        printf("Podaj aktualna ilosc artykulu:...");
        scanf(" %d", &nowy);
        Dane[i].ilosc=nowy;
        printf("Ilosc artykulu zostala zaktualizowana.");
    } else
        printf("Nie znaleziono artykulu o takim numerze ID.");
    printf("\n");
}

/******************************************************************************************************************
 * aktualizuj_cene: Pyta uzytkownika o numer ID artykulu. Jesli artykulu nie ma w bazie,                          *
 *                   wypisuje odpowiedni komunikat, a jesli jest, pyta o nowa cene i aktualizuje baze danych.     *
 ******************************************************************************************************************/
void aktualizuj_cene(){
 int numer, i;
 double nowy;

    printf("Podaj numer ID artykulu:...");
    scanf(" %d", &numer);
    i=znajdz_id(numer);
    if(i>=0){
        printf("Podaj aktualna cene artykulu:...");
        scanf(" %lf", &nowy);
        Dane[i].cena=nowy;
        printf("Cena artykulu zostala zaktualizowana.");
    } else
        printf("Nie znaleziono artykulu o takim numerze ID.");
    printf("\n");
}

/************************************************************************************************
 * pokaz: Wypisuje artykuly znajdujace sie w bazie danych (numer ID, nazwe, ilosc i cene).      *
 *        Artykuly sa wypisywane w takiej kolejnosci, w jakiej dodawane byly do bazy.           *
 ************************************************************************************************/
void pokaz(){
    int i;

    printf("Numer ID      Nazwa                    Ilosc     Cena\n");
    for(i=0; i<num_art; i++)
        printf("%-13d %-24s %-9d %-10.2lf\n", Dane[i].numer_id, Dane[i].nazwa, Dane[i].ilosc, Dane[i].cena);
    printf("\n");
}

/***************************************************************************************************
 * czytaj_nazwe: Wczytuje kolejne znakii zapisuje je w tablicy A, az do znaku nowego wiersza.      *
 *               Znaki niemieszczace sie w tablicy sa ignorowane.                                  *
 ***************************************************************************************************/
void czytaj_nazwe(char A[], int n){
    int ch, i=0;
    ch=getchar();
    while(ch!='\n'){
        if(i<n) A[i++]=ch;
        ch=getchar();
    }
    A[i]='\0';      /*wstawienie znaku pustego na koncu nazwy*/
}

/******************************************************************************************
* zapisz: Zapisuje biezaca baze danych do pliku tekstowego o nazwie "dane.txt"            *
*******************************************************************************************/
void zapisz(){
    int i=0;
    FILE *f=fopen("../dane.txt", "a");

    if(f==NULL){
		printf("Zapisywanie nie powiodlo sie.\n");
		printf("\n");
		return;
    }

    fprintf(f, "Numer ID      Nazwa                    Ilosc     Cena\n");
    for(i=0; i<num_art; i++)
        fprintf(f, "%-13d %-24s %-9d %-10.2lf\n", Dane[i].numer_id, Dane[i].nazwa, Dane[i].ilosc, Dane[i].cena);
    fprintf(f,"\n");
    fclose(f);

    printf("Baza zostala pomyslnie zapisana do pliku.");
    printf("\n");
}
