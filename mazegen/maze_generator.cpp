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
            if(rand()%100 > 90){ row += " "; }   else{ row += "#"; }
        }

        maze.push_back(row += "#");
    }
    // Creates last row, -26 is not acceptable position of x so its fully blocked
    maze.push_back(create_entrance_row(-26, size_x));

    int generation{1};
    print_maze(size_x, size_y, maze, generation);

    for(int i{0}; i != 10; i++){
        maze = change_row_connections(maze, size_x, size_y);
        maze = change_line_connections(maze, size_x, size_y);
        maze = delete_open_areas(maze, size_x, size_y);
        generation++;
        print_maze(size_x, size_y, maze, generation);
    }
}

void print_maze(int x, int y, vector<string> maze, int generation){
    cout<<"Generation: "<<generation<<"\n";
    for (int i{0}; i != y; i++){
        cout << maze[i];
        cout<<"\n";
    }
    cout<<"\n\n\n";
}

string create_entrance_row(int place_of_entrance, int size_x){
    string first_row;
    for(int i{0}; i != size_x; i++){
        if (i == place_of_entrance){ first_row += " "; }    else{ (first_row += "#"); }
    }

    return first_row;
}

vector<string> change_row_connections(vector<string>maze, int size_x, int size_y){
    for(int i{1}; i <= size_y; i++){
        for(int indeksi{1}; indeksi != size_x-1; indeksi++){

            if (maze[i][indeksi] == ' ' && indeksi+1 != size_x-1 && rand()%100 > 30) {
                maze[i][indeksi+1] = ' ';
            }
        }
        if(i != size_y - 1){
            i++;
        }
    }
    return maze;
}

vector<string> change_line_connections(vector<string>maze, int size_x, int size_y){
    for(int i{1}; i != size_y; i++){
        for(int indeksi{1}; indeksi != size_x-1; indeksi++){

            if (maze[i][indeksi] == ' ' && i != size_y && rand()%100 > 30) {
                for(int number{0}; number != 6; number++){
                    if (i != size_y - number  && rand()%100 >50 && i-number != 0){
                        maze[i-number][indeksi] = ' ';
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return maze;
}


vector<string> delete_open_areas(vector<string> maze, int size_x, int size_y){
    //todo Delete areas where spot your inspecting has 8/8 surrounding pieces empty too.

    for(int i{1}; i != size_y; i++){
        for(int indeksi{1}; indeksi != size_x-1; indeksi++){

            if (surrounding_pieces_open(maze, indeksi, i)) {
                maze[i][indeksi] = '#';
                if(rand()%100 >50){
                    int number_of_side = rand()%3;
                    if(number_of_side == 0){
                        maze[i-1][indeksi] = '#';
                    }
                    else if(number_of_side == 1){
                        maze[i+1][indeksi] = '#';
                    }
                    else if(number_of_side == 2){
                        maze[i][indeksi - 1] = '#';
                    }
                    else if(number_of_side == 3){
                        maze[i][indeksi + 1] = '#';
                    }
                }
            }
        }
    }
    return maze;
}

bool surrounding_pieces_open(vector<string> maze, int location_x, int location_y){
    if(maze[location_y][location_x] == ' ' && maze[location_y][location_x - 1] == ' ' && maze[location_y][location_x + 1] == ' ' &&
            maze[location_y - 1][location_x] == ' ' && maze[location_y - 1][location_x - 1] == ' ' && maze[location_y - 1][location_x + 1] == ' ' &&
            maze[location_y + 1][location_x] == ' ' && maze[location_y + 1][location_x - 1] == ' ' && maze[location_y + 1][location_x + 1] == ' '){
            return true;
    }
    else {
        return false;
    }
}
