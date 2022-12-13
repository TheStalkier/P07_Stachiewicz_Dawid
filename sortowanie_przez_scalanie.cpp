//Dawid Stachiewicz- projekt
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;


int d[N],p[N];

//p[ ]	- zbiór pomocniczy, który zawiera tyle samo elementów, co zbiór d[ ].

// Procedura sortuj¹ca
//--------------------

void MergeSort(int i_p, int i_k)
{
  int i_s,i1,i2,i;

//i1	- indeks elementów w m³odszej po³ówce zbioru d[ ],
//i2	- indeks elementów w starszej po³ówce zbioru d[ ]
//i	- indeks elementów w zbiorze pomocniczym p[ ]

//ip	- indeks pierwszego elementu w m³odszym podzbiorze
//ik	- indeks ostatniego elementu w starszym podzbiorze

  i_s = (i_p + i_k + 1) / 2;
  if(i_s - i_p > 1) MergeSort(i_p, i_s - 1);
  if(i_k - i_s > 0) MergeSort(i_s, i_k);
  i1 = i_p; i2 = i_s;
  for(i = i_p; i <= i_k; i++)
    p[i] = ((i1 == i_s) || ((i2 <= i_k) && (d[i1] > d[i2]))) ? d[i2++] : d[i1++];
  for(i = i_p; i <= i_k; i++) d[i] = p[i];
}

// Program g³ówny
//---------------

int main()
{
    int i;
    cout<<"Podaj liczebnosc zbioru: \n";
    cin>>N;
// Najpierw wype³niamy tablicê d[] liczbami pseudolosowymi
// a nastêpnie wyœwietlamy jej zawartoœæ

  srand((unsigned)time(NULL));

  for(i = 0; i < N; i++) d[i] = rand() % 100;
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;

// Sortujemy
    auto start = high_resolution_clock::now();
  MergeSort(0,N-1);

// Wyœwietlamy wynik sortowania

  cout << "Po sortowaniu:\n\n";
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Czas wykonania: " << duration.count() << " sekund" << endl;
    return 0;
}
