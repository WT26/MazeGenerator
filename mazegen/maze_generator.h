#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct
{
    int x;
    int y;
} coordinates;

void maze_generator(int size_x, int size_y);
void print_maze(int x, int y, vector<string>, int generation, int tunnel_length);

string create_entrance_row(int place_of_entrance, int size_x);

vector<string> change_row_connections(vector<string>maze, int size_x, int size_y);
vector<string> change_line_connections(vector<string>maze, int size_x, int size_y);
vector<string> delete_open_areas(vector<string> maze, int size_x, int size_y);

vector<coordinates> coords_under_inspection(vector<string> maze, int current_x, int current_y, vector<coordinates> already_checked, vector<coordinates> under_inspection);

bool surrounding_pieces_open(vector<string> maze, int location_x, int location_y);

int how_long_is_the_tunnel(vector<string> maze, int current_x, int current_y, vector<coordinates> already_checked, int tunnel_sofar);

#endif // MAZE_GENERATOR_H
