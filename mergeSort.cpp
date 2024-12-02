#include "mergeSort.h"
#include "fontManager.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void drawArray(RenderWindow &window, const vector<RectangleShape> &bars, const Text &statusText) {
    window.clear();
    window.draw(statusText);
    for (const auto &bar : bars) {
        window.draw(bar);
    }
    window.display();
    sf::sleep(sf::milliseconds(500)); // Pause to visualize the process
}

void merge(vector<int> &arr, int left, int mid, int right, vector<RectangleShape> &bars, RenderWindow &window, Text &statusText) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            bars[k].setSize(Vector2f(bars[k].getSize().x, L[i] * 10));
            bars[k].setFillColor(Color::Green);
            i++;
        } else {
            arr[k] = R[j];
            bars[k].setSize(Vector2f(bars[k].getSize().x, R[j] * 10));
            bars[k].setFillColor(Color::Red);
            j++;
        }
        k++;
        drawArray(window, bars, statusText);
    }

    while (i < n1) {
        arr[k] = L[i];
        bars[k].setSize(Vector2f(bars[k].getSize().x, L[i] * 10));
        bars[k].setFillColor(Color::Green);
        i++;
        k++;
        drawArray(window, bars, statusText);
    }

    while (j < n2) {
        arr[k] = R[j];
        bars[k].setSize(Vector2f(bars[k].getSize().x, R[j] * 10));
        bars[k].setFillColor(Color::Red);
        j++;
        k++;
        drawArray(window, bars, statusText);
    }
}

void mergeSort(vector<int> &arr, int left, int right, vector<RectangleShape> &bars, RenderWindow &window, Text &statusText) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, bars, window, statusText);
        mergeSort(arr, mid + 1, right, bars, window, statusText);
        merge(arr, left, mid, right, bars, window, statusText);
    }
}

void MergeSort::run(RenderWindow &window) {
    int n;
    cout << "Numero de elementos del array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Introduce los " << n << " elementos del array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arr[i];
    }

    vector<RectangleShape> bars;
    float barWidth = 50.0f;
    float gap = 10.0f;

    for (int i = 0; i < arr.size(); ++i) {
        RectangleShape bar(Vector2f(barWidth, arr[i] * 10));
        bar.setPosition(100 + i * (barWidth + gap), 500 - bar.getSize().y);
        bar.setFillColor(Color::Blue);
        bars.push_back(bar);
    }

    Text statusText("Sorting...", FontManager::font, 20);
    statusText.setPosition(10, 10);
    statusText.setFillColor(Color::White);

    mergeSort(arr, 0, n - 1, bars, window, statusText);

    statusText.setString("Ordenamiento completado");
    drawArray(window, bars, statusText);

    cout << "Array ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    sf::sleep(sf::seconds(5)); // Pause to show the sorted array
}
