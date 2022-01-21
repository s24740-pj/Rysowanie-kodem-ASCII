#ifndef FUNKCJE_H_INCLUDED
#define FUNKCJE_H_INCLUDED


int wzor(char *znak, char przerwa, int wielkosc, int *x, int *y);
int rysunek(int width, int height, char znak);

int menu_wyswietl(int width, int height, char znak);
int menu(int width, int height, char znak);

int Ustawienia_wyswietl(int width, int height, char znak);
int Ustawienia(int width, int height, char znak);

int rozdzielczosc_wyswietl(int width, int height, char znak);
int rozdzielczosc(int width, int height, char znak);

int kolory_wyswietl(int width, int height, char znak);
int kolory(int width, int height, char znak);

int znak_wyswietl(int width, int height, char znak);
int znak_funkcja(int width, int height, char znak);


int menu_wyswietl(int aktualne){

    //Ruch po menu
    system("cls");
    char aktywne[3];
    for(int i=0; i<3; i++){
        aktywne[i] = 45;
    }

    aktywne[aktualne] = 43;
    //Wylacza kursor
    printf("\e[?25l");

    //Wyswietlenie menu

    std::cout << "+-----Menu-----+" << std::endl;
    std::cout << "|" << aktywne[0] << "Start" << "        |" << std::endl;
    std::cout << "|" << aktywne[1] << "Ustawienia" "   |" << std::endl;
    std::cout << "|" << aktywne[2] << "Wyjscie" "      |" << std::endl;
    std::cout << "+--------------+" << std::endl;

    return 1;
}

int menu(int width, int height, char znak){
    //Ustawienia rozdzielczosci
    HWND hwnd = GetConsoleWindow();
    RECT rect = {0, 0, width, height};
    MoveWindow(hwnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,TRUE);

    //Ustawienia menu
    int aktualne = 0;
    menu_wyswietl(aktualne);
    //Sterowanie
    char key;
    int asciiValue;
    while(1){
        key = getch();
        asciiValue=key;
        if(asciiValue==27)
            break;
        //Gora
        if(asciiValue == 72){
            if(aktualne >= 1){
                aktualne -= 1;
                menu_wyswietl(aktualne);
            }
        }
        //Dol
        if(asciiValue == 80){
            if(aktualne < 2){
                aktualne += 1;
                menu_wyswietl(aktualne);
            }
        }
        //Enter
        if(asciiValue == 13){

            if(aktualne == 0){
                system("cls");
                rysunek(width, height, znak);
            }
            if(aktualne == 1){
                Ustawienia(width, height, znak);
            }
            if(aktualne == 2){
                exit(0);
            }

        }
    }
    return 1;
}

int Ustawienia_wyswietl(int aktualne){

    //Ruch po menu
    system("cls");
    char aktywne[4];
    for(int i=0; i<4; i++){
        aktywne[i] = 45;
    }

    aktywne[aktualne] = 43;

    //Wyswietlenie menu

    std::cout << "+----Ustawienia----+" << std::endl;
    std::cout << "|"<< aktywne[0] << "Rozdzielczosc" << "    |" << std::endl;
    std::cout << "|"<< aktywne[1] << "Wzor" << "             |" << std::endl;
    std::cout << "|"<< aktywne[2] << "Kolory" << "           |" << std::endl;
    std::cout << "|"<< aktywne[3] << "Cofnij" << "           |" << std::endl;
    std::cout << "+------------------+" << std::endl;

    return 1;
}

int Ustawienia(int width, int height, char znak){

    //Ustawienia rozdzielczosci
    HWND hwnd = GetConsoleWindow();
    RECT rect = {0, 0, width, height};
    MoveWindow(hwnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,TRUE);

    //Ustawienia menu
    int aktualne = 0;
    Ustawienia_wyswietl(aktualne);
    //Sterowanie
    char key;
    int asciiValue;
    while(1){
        key = getch();
        asciiValue=key;
        if(asciiValue==27)
            break;
        //Gora
        if(asciiValue == 72){
            if(aktualne >= 1){
                aktualne -= 1;
                Ustawienia_wyswietl(aktualne);
            }
        }
        //Dol
        if(asciiValue == 80){
            if(aktualne < 3){
                aktualne += 1;
                Ustawienia_wyswietl(aktualne);
            }
        }
        //Enter
        if(asciiValue == 13){

            if(aktualne == 0){
                rozdzielczosc(width, height, znak);
            }
            if(aktualne == 1){
                znak_funkcja(width, height, znak);
            }
            if(aktualne == 2){
                kolory(width, height, znak);
            }
            if(aktualne == 3){
                menu(width, height, znak);
            }

        }
    }

    return 1;
}

int rozdzielczosc_wyswietl(int aktualne, int width, int height){

    //Ruch po menu
    system("cls");
    char aktywne[8];
    for(int i=0; i<8; i++){
        aktywne[i] = 45;
    }

    aktywne[aktualne] = 43;

    //Wyswietlenie menu

    std::cout << "+---Rozdzielczosc---+" << std::endl;
    std::cout << "|"<< aktywne[0] << "640x480" << "           |" << std::endl;
    std::cout << "|"<< aktywne[1] << "800x600" << "           |"<< std::endl;
    std::cout << "|"<< aktywne[2] << "1280x720" << "          |"<< std::endl;
    std::cout << "|"<< aktywne[3] << "1280x960" << "          |"<< std::endl;
    std::cout << "|"<< aktywne[4] << "1440x1080" << "         |"<< std::endl;
    std::cout << "|"<< aktywne[5] << "1600x900" << "          |"<< std::endl;
    std::cout << "|"<< aktywne[6] << "1920x1080" << "         |"<< std::endl;
    std::cout << "|"<< aktywne[7] << "Cofnij" << "            |"<< std::endl;
    std::cout << "+-------------------+" << std::endl;

    std::cout << std::endl;
    std::cout << "+------------------------------+" << std::endl;
    std::cout << "Aktualna rodzielczosc: " << width << "x" << height << std::endl;
    std::cout << "+------------------------------+" << std::endl;

    return 1;
}

int rozdzielczosc(int width, int height, char znak){

    //Ustawienia rozdzielczosci
    HWND hwnd = GetConsoleWindow();
    RECT rect = {0, 0, width, height};
    MoveWindow(hwnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,TRUE);

    //Ustawienia menu
    int aktualne = 0;
    rozdzielczosc_wyswietl(aktualne, width, height);
    //Sterowanie
    char key;
    int asciiValue;
    while(1){
        key = getch();
        asciiValue=key;
        if(asciiValue==27)
            break;
        //Gora
        if(asciiValue == 72){
            if(aktualne >= 1){
                aktualne -= 1;
                rozdzielczosc_wyswietl(aktualne, width, height);
            }
        }
        //Dol
        if(asciiValue == 80){
            if(aktualne < 7){
                aktualne += 1;
                rozdzielczosc_wyswietl(aktualne, width, height);
            }
        }
        //Enter
        if(asciiValue == 13){

            if(aktualne == 0){
                width = 640;
                height = 480;
            }
            if(aktualne == 1){
                width = 800;
                height = 600;
            }
            if(aktualne == 2){
                width = 1280;
                height = 720;
            }
            if(aktualne == 3){
                width = 1280;
                height = 960;
            }
            if(aktualne == 4){
                width = 1440;
                height = 1080;
            }
            if(aktualne == 5){
                width = 1600;
                height = 900;
            }
            if(aktualne == 6){
                width = 1920;
                height = 1080;
            }
            if(aktualne == 7){
                Ustawienia(width, height, znak);
            }

            rozdzielczosc_wyswietl(aktualne, width, height);
            HWND hwnd = GetConsoleWindow();
            RECT rect = {0, 0, width, height};
            MoveWindow(hwnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,TRUE);

        }
    }

    return 1;
}

int kolory_wyswietl(int aktualne, int width, int height){

    //Ruch po menu
    system("cls");
    char aktywne[13];
    for(int i=0; i<13; i++){
        aktywne[i] = 45;
    }

    aktywne[aktualne] = 43;

    //Wyswietlenie menu

    std::cout << "+----------Kolory----------+" << std::endl;
    std::cout << "|"<< aktywne[0] << "ciemno niebieski" << "         |" << std::endl;
    std::cout << "|"<< aktywne[1] << "zielony" << "                  |"<< std::endl;
    std::cout << "|"<< aktywne[2] << "jasno niebieski" << "          |"<< std::endl;
    std::cout << "|"<< aktywne[3] << "czerwony" << "                 |"<< std::endl;
    std::cout << "|"<< aktywne[4] << "magenta" << "                  |"<< std::endl;
    std::cout << "|"<< aktywne[5] << "pomaranczowy" << "             |"<< std::endl;
    std::cout << "|"<< aktywne[6] << "bialy" << "                    |"<< std::endl;
    std::cout << "|"<< aktywne[7] << "szary" << "                    |"<< std::endl;
    std::cout << "|"<< aktywne[8] << "niebieski" << "                |"<< std::endl;
    std::cout << "|"<< aktywne[9] << "jasno zielony" << "            |"<< std::endl;
    std::cout << "|"<< aktywne[10] << "aqua" << "                     |"<< std::endl;
    std::cout << "|"<< aktywne[11] << "jasno czerwony" << "           |"<< std::endl;
    std::cout << "|"<< aktywne[12] << "Cofnij" << "                   |"<< std::endl;
    std::cout << "+--------------------------+-------+" << std::endl;
    std::cout << "| MINUS - zmienia kolor tekstu     |" << std::endl;
    std::cout << "| PLUS - zmienia kolor tla         |" << std::endl;
    std::cout << "| ENTER - dziala tylko przy cofnij |" << std::endl;
    std::cout << "+----------------------------------+" << std::endl;

    return 1;
}

int kolory(int width, int height, char znak){

    //Ustawienia rozdzielczosci
    HWND hwnd = GetConsoleWindow();
    RECT rect = {0, 0, width, height};
    MoveWindow(hwnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,TRUE);

    //Ustawienia menu
    int aktualne = 0;
    kolory_wyswietl(aktualne, width, height);
    //Sterowanie
    char key;
    int asciiValue;
    int aktualny_kolor_tekstu = 0;
    int aktualny_kolor_tla = 0;
    while(1){

        key = getch();
        asciiValue=key;
        if(asciiValue==27)
            break;
        //Gora
        if(asciiValue == 72){
            if(aktualne >= 1){
                aktualne -= 1;
                kolory_wyswietl(aktualne, width, height);
            }
        }
        //Dol
        if(asciiValue == 80){
            if(aktualne < 12){
                aktualne += 1;
                kolory_wyswietl(aktualne, width, height);
            }
        }
        //Enter
        if(asciiValue == 13){
            if(aktualne == 12){
                Ustawienia(width, height, znak);
            }

            kolory_wyswietl(aktualne, width, height);
            HWND hwnd = GetConsoleWindow();
            RECT rect = {0, 0, width, height};
            MoveWindow(hwnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,TRUE);
        }
        //minus
        if(asciiValue == 45){
            if(aktualne != 12){
                //Ustawienie kolorow
                HANDLE  hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                aktualny_kolor_tekstu=aktualne+1;

                SetConsoleTextAttribute(hConsole, aktualny_kolor_tekstu | aktualny_kolor_tla);
            }
            kolory_wyswietl(aktualne, width, height);
            HWND hwnd = GetConsoleWindow();
            RECT rect = {0, 0, width, height};
            MoveWindow(hwnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,TRUE);
    }
    if(asciiValue == 43){
            if(aktualne != 12){
                //Ustawienie kolorow
                HANDLE  hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

                aktualny_kolor_tla = 16*(aktualne+1);

                SetConsoleTextAttribute(hConsole, aktualny_kolor_tekstu | aktualny_kolor_tla);
            }
            kolory_wyswietl(aktualne, width, height);
            HWND hwnd = GetConsoleWindow();
            RECT rect = {0, 0, width, height};
            MoveWindow(hwnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,TRUE);
    }


}
return 1;
}

int znak_wyswietl(int aktualne, int width, int height, char znak){

    //Ruch po menu
    char aktualny_znak = znak;
    int ZmianaZnaku = 0;
    system("cls");
    for(int i=33; i<122; i++){
        char znak2 = i;
        std::cout << i-32 << ": " << znak2 << ", ID=" << i << std::endl;
    }


    //Wyswietlenie menu

    std::cout << std::endl;
    std::cout << "+----------------------+" << std::endl;
    std::cout << "Aktualny znak: " << aktualny_znak << std::endl;
    std::cout << "+----------------------+" << std::endl;
    std::cout << "Wpisz ID znalu (Kliknij enter by zapisac i wyjsc): ";
    std::cin >> ZmianaZnaku;
    Ustawienia(width, height,ZmianaZnaku);

    return 1;
}

int znak_funkcja(int width, int height, char znak){

    //Ustawienia rozdzielczosci
    HWND hwnd = GetConsoleWindow();
    RECT rect = {0, 0, width, height};
    MoveWindow(hwnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,TRUE);

    //Ustawienia menu
    int aktualne = 0;
    znak_wyswietl(aktualne, width, height, znak);
    //Sterowanie
    char key;
    int asciiValue;
    while(1){
        key = getch();
        asciiValue=key;
        if(asciiValue==27)
            break;
        //Enter
//        if(asciiValue == 13){
//            Ustawienia(width, height, znak);
//        }
    }

    return 1;
}

int wzor(char *znak, char przerwa, int wielkosc, int *x, int *y){

    int srodek = ((wielkosc-2)/2) + 1;
    bool po_srodku = false;

    char rysunek[100][100];

    //Przesuwanie sie po osi Y
    for(int i=0; i<*y; i++){
        std::cout << std::endl;
    }
    //Rysunek (ilosc wierszy)
    for(int i=0; i<wielkosc; i++){
        //Przesuwanie siê po osi X
        for(int g=0; g<*x; g++){
            std::cout << " ";
        }

        //Rysunek (ilosc kolumn)
        for(int g=0; g<wielkosc; g++){
            //Pierwsza i ostatnia warstwa
            if(i == 0 || i == wielkosc-1){
                rysunek[i][g] = *znak;
                std::cout << rysunek[i][g];
            }else{
                //Wszystkie inne warstwy poza pierwsza i ostatnia
                rysunek[i][g] = przerwa;
                if(po_srodku ==false){
                    rysunek[i][((wielkosc-i)-1)] = *znak;
                }else{
                    rysunek[i][i] = *znak;
                }
                std::cout << rysunek[i][g];
            }
        }
        //Sprawdza czy skrypt minal srodek by moc zmienic orientacje tej srodkowej linii
        if(i==srodek){
            po_srodku = true;
        }
        std::cout << std::endl;
    }
    std::cout << "x= " << *x+wielkosc << ", y= " << *y+1 << ", size= " << wielkosc << ", Kliknij Q aby wyjsc.";

    return 1;
}

int rysunek(int width, int height, char znak){
    //Ustawienia
    char *w_znak = &znak; //Jakimi znakami na rysowac wzor
    char przerwa = 32; //Tlo wzoru
    int rozmiar = 5; //Wielkosc wzoru
    int x=((width/8)-rozmiar-8)/2; //Polozenie wzgledem osi X (oraz odrazu ustawienie go na srodku)
    int *w_x = &x;
    int y=(((height/16)-1-4))/2; //Polozenie wzgledem osi Y (oraz odrazu ustawienie go na srodku)
    int *w_y = &y;

    //Ustawienia rozdzielczosci
    HWND hwnd = GetConsoleWindow();
    RECT rect = {0, 0, width, height};
    MoveWindow(hwnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,TRUE);

    //Rysowanie wzorku
    wzor(w_znak,przerwa,rozmiar,w_x,w_y);

    //Sterowanie
    char key;
    int asciiValue;
    while(1){
        key = getch();
        asciiValue=key;
        if(asciiValue==27)
            break;
        //Ruch wzorkiem w gore
        if(asciiValue == 72){
            system("cls");
            if(y>0){
                y -= 1;
            }
            wzor(w_znak,przerwa,rozmiar,w_x,w_y);
        }
        //Ruch wzorkiem w dol
        if(asciiValue == 80){
            system("cls");
            if(y<(height/16)-rozmiar-4){
                y += 1;
            }
            wzor(w_znak,przerwa,rozmiar,w_x,w_y);
        }
        //Ruch wzorkiem w lewo
        if(asciiValue == 75){
            system("cls");
            if(x>0){
                x -= 1;
            }
            wzor(w_znak,przerwa,rozmiar,w_x,w_y);
        }
        //Ruch wzorkiem w prawo
        if(asciiValue == 77){
            system("cls");
            if(x<(width/8)-rozmiar-5){
                x += 1;
            }
            wzor(w_znak,przerwa,rozmiar,w_x,w_y);
        }
        //Zwiekszanie wzoru
        if(asciiValue == 43){
            system("cls");
            rozmiar += 2;
            x -= 2;
            if(x<0){
                x = 0;
            }
            if(y>(height/16)-rozmiar-4){
                y -= 2;
            }
            if(rozmiar>(height/16)-10){
                rozmiar -=2;
                x += 2;
            }
            wzor(w_znak,przerwa,rozmiar,w_x,w_y);
        }
        //Zmniejszanie wzoru
        if(asciiValue == 45){
            system("cls");
            if(rozmiar > 1){
                rozmiar -= 2;
                x += 2;
                if(x<0){
                    x = 0;
                }
            }

            wzor(w_znak,przerwa,rozmiar,w_x,w_y);
        }
        //Wyjscie z programu
        if(asciiValue == 113){
            system("cls");
            menu(width, height, znak);
        }
    }

    return 1;
}

#endif // FUNKCJE_H_INCLUDED
