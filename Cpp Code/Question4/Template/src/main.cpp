#include "std_lib_facilities.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL)); // initialize random number generator with current time

    int num_trials = 1000000; // number of trials to run
    int total_steps = 0; // total number of steps taken over all trials

    for (int i = 0; i < num_trials; i++) {
        int current_vertex = rand() % 8; // choose a random starting vertex
        int steps = 0; // number of steps taken to reach diagonally opposite vertex

        while (current_vertex != 6) { // 6 is the index of the diagonally opposite vertex
            int adjacent_vertices[3]; // array to hold indices of adjacent vertices
            int num_adjacent_vertices = 0; // number of adjacent vertices

            // populate adjacent_vertices array with indices of adjacent vertices
            switch (current_vertex) {
                case 0:
                    adjacent_vertices[0] = 1;
                    adjacent_vertices[1] = 3;
                    adjacent_vertices[2] = 4;
                    num_adjacent_vertices = 3;
                    break;
                case 1:
                    adjacent_vertices[0] = 0;
                    adjacent_vertices[1] = 2;
                    adjacent_vertices[2] = 5;
                    num_adjacent_vertices = 3;
                    break;
                case 2:
                    adjacent_vertices[0] = 1;
                    adjacent_vertices[1] = 3;
                    adjacent_vertices[2] = 6;
                    num_adjacent_vertices = 3;
                    break;
                case 3:
                    adjacent_vertices[0] = 0;
                    adjacent_vertices[1] = 2;
                    adjacent_vertices[2] = 7;
                    num_adjacent_vertices = 3;
                    break;
                case 4:
                    adjacent_vertices[0] = 0;
                    adjacent_vertices[1] = 5;
                    adjacent_vertices[2] = 7;
                    num_adjacent_vertices = 3;
                    break;
                case 5:
                    adjacent_vertices[0] = 1;
                    adjacent_vertices[1] = 4;
                    adjacent_vertices[2] = 6;
                    num_adjacent_vertices = 3;
                    break;
                case 6:
                    // diagonally opposite vertex, no adjacent vertices
                    num_adjacent_vertices = 0;
                    break;
                case 7:
                    adjacent_vertices[0] = 3;
                    adjacent_vertices[1] = 4;
                    adjacent_vertices[2] = 5;
                    num_adjacent_vertices = 3;
                    break;
            }

            // choose a random adjacent vertex and move to it
            int random_index = rand() % num_adjacent_vertices;
            current_vertex = adjacent_vertices[random_index];
            steps++; // increment the number of steps taken
        }

        total_steps += steps; // add the number of steps taken in this trial to the total
    }

    double expected_steps = (double) total_steps / num_trials; // compute the expected number of steps
    cout << "Expected number of steps: " << expected_steps << endl;

    return 0;
}



