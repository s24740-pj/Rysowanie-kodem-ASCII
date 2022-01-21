#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "Funkcje.h"

int main()
{
    //Wywolanie menu
    menu(640, 480, 65);
    return 0;
}

// Projekt na studia | I semestr | Programowanie | Numer 130
// Kamil Powierza | s24740
// Program, ktory rysuje znakiem ASCII
//
// Wymagania:
// - Wybor znaku kodu ASCII ✔
// - Wczytywanie poczatkowych rozmiarow figury ✔
// - Przesuwanie figury klawiszami ✔
// - Powiekszanie figury + i - ✔
// - Ograniczenie przesuwania i rozmiarow figury do obszaru ekranu ✔
// - Punkt poczatkowy (kropka) znajduje sie na srodku ekranu ✔
// - Uzywanie funkcji ✔
// - Wywolanie funkcji w main() ✔
// - Brak zmiennych globalnych ✔
//
// Dodatkowe opcje:
// - Mozliwosc w pelni poruszania sie po menu,
// - Zmiana rozdzielczosci,
// - Zmiana znaku, z ktorego sklada sie wzor,
// - Edycja koloru tekstu oraz tla calego terminala.
//
// Sterowanie:
// - Poruszanie sie po menu strzalkami oraz akceptowanie enterem,
// - Poruszanie sie znakiem strzalkami,
// - Plus i minus zwieksza lub zmniejsza wzor,
// - W niektorych miejscach w menu jest wprost pokazane sterowanie.
