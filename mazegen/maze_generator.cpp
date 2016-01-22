#include "maze_generator.h"
#include <iostream>
#include <vector>
#include <random>
#include "time.h"

using namespace std;

void maze_generator(int size_x, int size_y)
{
    srand (time(NULL));
    vector<string> maze;
    int place_of_entrance = rand()%size_x; if (place_of_entrance == size_x){ size_x -= 1; };
    maze.push_back(create_entrance_row(place_of_entrance, size_x));

    for(int i{0}; i != size_y-2; i++){
        string row = "#";

        for(int index{0}; index != size_x-2; index++){
            if(rand()%100 > 85){ row += " "; }   else{ row += "#"; }
        }

        maze.push_back(row += "#");
    }
    // Creates last row, -26 is not acceptable position of x so its fully blocked
    maze.push_back(create_entrance_row(-26, size_x));

    maze = change_row_connections(maze, size_x, size_y);

    print_maze(size_x, size_y, maze);

}

void print_maze(int x, int y, vector<string> maze){
    for (int i{0}; i != y; i++){
        cout << maze[i];
        cout<<"\n";
    }
}

string create_entrance_row(int place_of_entrance, int size_x){
    string first_row;
    for(int i{0}; i != size_x; i++){
        if (i == place_of_entrance){ first_row += " "; }    else{ (first_row += "#"); }
    }

    return first_row;
}

vector<string> change_row_connections(vector<string>maze, int size_x, int size_y){
    for(int i{1}; i != size_y; i++){

        for(int indeksi{1}; indeksi != size_x-1; indeksi++){

            if (maze[i][indeksi]){

            }
            maze[i][indeksi] = maze[i][indeksi]

        }
    }
}
