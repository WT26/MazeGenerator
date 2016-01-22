#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void maze_generator(int size_x, int size_y);
void print_maze(int x, int y, vector<string>);

string create_entrance_row(int place_of_entrance, int size_x);

vector<string> change_row_connections(vector<string>maze, int size_x, int size_y);

#endif // MAZE_GENERATOR_H
