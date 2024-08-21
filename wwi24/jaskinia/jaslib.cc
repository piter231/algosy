// Format wejścia
// n - ilość drzwi w jaskini
// n liczb z zakresu [0, 1] oznaczających położenie przelacznika
// n liczb z zakresu [0, n-1] oznaczające za ktore drzwi odpowiada dany przelacznik

#include "jas.h"
#include <bits/stdc++.h>

using namespace std;

static constexpr int MAXN = 5000;

static int __n;
static int __U[MAXN];
static int __P[MAXN];
static int __P_inv[MAXN];

static bool __init_done = false;
static bool __search_done = false;
static int __queries = 0;

int init() {
    cin >> __n;
    for (int i = 0; i < __n; i++) {
        cin >> __U[i];
    }
    for (int i = 0; i < __n; i++) {
        cin >> __P[i];
    }
    for (int i = 0; i < __n; i++) {
        __P_inv[__P[i]] = i;
    }
    __init_done = true;
    return __n;
}

int wyprobuj(bool U[]) {
    __queries++;
    if (__queries > 70000) {
        cout << "Za duzo zapytan!" << endl;
        exit(1);
    }
    if (not __init_done or __search_done) {
        cout << "Wywolano `wyprobuj` w zlym momencie!" << endl;
        exit(1);
    }
    for (int i = 0; i < __n; i++) {
        if (U[__P_inv[i]] != __U[__P_inv[i]]) {
            return i;
        }
    }
    return -1;
}

void odpowiedz(bool U[], int P[]) {
    if (not __init_done) {
        cout << "Nie zainicjalizowano sprawdzaczki przez wywolaniem `odpowiedz`!" << endl;
        exit(1);
    }
    __search_done = true;

    for (int i = 0; i < __n; i++) {
        if (__U[i] != U[i]) {
            cout << "Niepoprawna kombinacja przelacznikow otwierajaca drzwi!" << endl;
            exit(1);
        }
    }
    
    for (int i = 0; i < __n; i++) {
        if (__P[i] != P[i]) {
            cout << "Niepoprawna kolejnosc drzwi!" << endl;
            exit(1);
        }
    }

    cout << "OK" << endl;
    cout << "Zapytania: " << __queries << "\n";
}
