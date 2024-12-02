#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class LinearSearch {
private:
    returnVector<int> array;
    int target;
    bool found;
    size_t currentIndex;
    returnRenderWindow& window;
    returnFont font;
    returnText statusText;

public:
    LinearSearch(returnRenderWindow& win);

    void setTarget(int t);
    void setArray(const returnVector<int>& arr);
    void search();
    void render();

    bool isFound() const;
    bool isSearching() const;

    void displayMessage(const returnString& message);
    void handleTextInput(returnEvent event);
};

#endif // LINEARSEARCH_H
