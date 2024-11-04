#pragma once

#include "Stocznia.hpp"
#include "ObjCounter.hpp"
#include "Statki.hpp"

// Funkcja transportująca towary za pomocą floty statków
unsigned int transportujFlota(unsigned int towar) {
    if (towar == 0) return 0;  // Jeżeli towar do transportu wynosi 0, nie twórz żadnego statku

    Stocznia stocznia;  // Tworzymy fabrykę statków
    Stocznia::resetTotalCap();  // Resetujemy całkowitą pojemność przed rozpoczęciem transportu
    CountThis<Zaglowiec>::reset();  // Resetujemy licznik żaglowców przed rozpoczęciem transportu

    unsigned int transported = 0;  // Licznik przetransportowanego towaru

    while (transported < towar) {
        Statek* statek = stocznia();  // Tworzymy nowy statek za pomocą fabryki
        transported += statek->transportuj();  // Dodajemy ilość towaru przetransportowaną przez ten statek
        delete statek;  // Usuwamy utworzony statek
    }

    return CountThis<Zaglowiec>::get();  // Zwracamy liczbę żaglowców użytych do transportu
}