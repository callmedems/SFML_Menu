cmake_minimum_required(VERSION 3.20)
project(proyecto_SFML)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Specify the path to SFML
set(SFML_DIR "D:/SFML-2.6.2/lib/cmake/SFML")

# Find SFML
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# Add your executable
add_executable(proyecto_SFML main.cpp
        mainMENU.cpp
        mainMENU.h
        subMenu.cpp
        subMenu.h
        linearSearch.h linearSearch.cpp
        fontManager.h
        fontManager.cpp
        binarySearch.cpp
        binarySearch.h
        bubbleSort.cpp
        bubbleSort.h
        selectionSort.cpp
        selectionSort.h
        insertionSort.cpp
        insertionSort.h
        mergeSort.cpp
        mergeSort.h
        quickSort.cpp
        quickSort.h
        stacks.cpp
        stacks.h
        Queues.cpp
        Queues.h
)

# Link SFML libraries
target_link_libraries(proyecto_SFML sfml-graphics sfml-window sfml-system sfml-audio)
