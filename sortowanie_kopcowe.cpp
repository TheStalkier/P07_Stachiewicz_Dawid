//Dawid Stachiewicz - projekt

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[i] < arr[l])
        largest = l;

    if (r < n && arr[largest] < arr[r])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
void printArray(int tab[], int N)
{
	for (int i = 0; i < N; ++i)
		cout << tab[i] << " ";
	cout << "\n";
}
int main()
{
    int z;
    cout <<"Podaj rozmiar tablicy: \n";
    cin>>z;
    int arr[z];
    srand(time(NULL));
     for (int i = 0; i < z; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "Przed sortowaniem: \n";
    for (int i = 0; i < z; i++)
    {
    cout <<arr[i]<< " ";
    }
    int N = sizeof(arr) / sizeof(arr[0]);

    auto start = high_resolution_clock::now();

    heap_sort(arr, N);

    cout << "\nPosortowane: \n";
    printArray(arr, N);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas wykonania: " << duration.count() << " milisekund" << endl;
    return 0;
}
