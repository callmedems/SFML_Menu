#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include <SFML/Graphics.hpp>
#include "SubMenu.h"
#include "linearSearch.h"

using namespace std;
using namespace sf;

class SearchAlgorithms : public SubMenu {
    private:
        LinearSearch* linearSearch;
        vector<int> array;

    public:
        SearchAlgorithms(RenderWindow& win);

        void show() override; // an override to handle algorithm choices
};

#endif // SEARCHALGORITHMS_H
