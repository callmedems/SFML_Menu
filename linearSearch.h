#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

class linearSearch {
  private:
    RenderWindow& window;
    vector<int> array;
    int target;
    int resultIndex;

    // this will help to draw the array with the current and target indexs
    void drawArray(int currentIndex, int targetIndex);

  public:
    // Constructor
    LinearSearch(RenderWindow& win, const std::vector<int>& arr, int tgt);

    // this will perform linear search with visualization
    void search();

    // to get the index of the target
    int getResultIndex() const;

};

#endif //LINEARSEARCH_H
