#include "maze_generator.h"
#include <iostream>
#include <random>

using namespace std;

int main()
{
    string x;
    string y;

    getline(cin, x);
    getline(cin, y);

    maze_generator(stoi(x), stoi(y));
}

