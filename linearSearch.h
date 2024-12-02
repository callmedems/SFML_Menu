#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

class linearSearch {
public:
    linearSearch(RenderWindow& window);
    void setTarget(int target);
    void visualizeSearch();  // This will animate the search process
    void search(const vector<int>& arr);

private:
    RenderWindow& window;
    int target;
    vector<int> array;
    Font font;
    Text text;
};

#endif //LINEARSEARCH_H
