//
// Tim Rochford, 2016
//
#include <vector>
#include <cmath>  // abs()
#include <iostream>
#include <chrono>
#include <random>
#include <limits> // std::numeric_limits
#include <string> // stoi

using namespace std;

void printDungeon(const vector<vector<int>>& d) {
    for (auto row : d) {
        for (auto cell : row) {
            // line up the cells...
            if (cell < 0)
                cout << cell << ", ";
            else
                cout << " " << cell << ", ";
        }
        cout << endl;
    }
}

vector<vector<int>> randomMatrix(int rows, int columns, int min, int max) {

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_int_distribution<int> distribution(min,max);

    vector<vector<int>> d;
    for (int x = 0; x < rows; x++) {
        vector<int> row;
        for (int y = 0; y < columns; y++) {
            int cellValue = distribution(generator);
            row.push_back(cellValue);
        }
        d.push_back(row);
    }

    return d;
}

int calculateMinimumKnightHitPointsToRescuePrincess(const vector<vector<int>>& dungeon) {

    default_random_engine generator;
    uniform_int_distribution<int> distribution(0,1);

    int width = dungeon[0].size() - 1;
    int height = dungeon.size() - 1;

    // dungeon[y][x]. All moves must increment x OR Y.
    // Start location dungeon[0][0].
    // goal location is dungeon[height][width]
    int bestScore = numeric_limits<int>::min();
    int iterations = pow(width,height) * 10;
    while (iterations-- > 0) {
        int currentPosX = 0;
        int currentPosY = 0;
        int currentScore = 0;
        currentScore += dungeon[currentPosY][currentPosX];
        while (true) {
//            cout << "pos: (" << currentPosY << ", " << currentPosX<< "), cell value: " << dungeon[currentPosY][currentPosX] << endl;

            bool moved = false;
            int randomMove = distribution(generator);
            if (randomMove == 1) {
                // try move right
                if (currentPosX != width) {
                    currentPosX++;
//                    cout << "RIGHT->";
                    moved = true;
                }
            } else {
                // try move down
                if (currentPosY != height) {
                    currentPosY++;
//                    cout << "DOWN->";
                    moved = true;
                }
            }
            if (moved) {
                currentScore += dungeon[currentPosY][currentPosX];
//                cout << " currentscore: " << currentScore << endl;
            }

            // Is the knight in the princess square bottom right?
            if ( (currentPosX == width) && (currentPosY == height)) {
                if (currentScore > bestScore) {
                    bestScore = currentScore;
//                    cout << "New best score: " << bestScore << endl;
                }
                break;
            }
        }
    }
    if (bestScore < 0)
        bestScore = abs(bestScore);
    else
        bestScore = -bestScore;
//    cout << endl << "returning best score: " << bestScore << endl;
    return bestScore;
}


int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: a.out dungeon_rows dungeon_columns" << endl;
        return -1;
    }
    int rows = 3 ;
    int columns = 3;
    try {
        rows = stoi(argv[1]);
        columns = stoi(argv[2]);
    }
    catch(exception& e) {
        cout << "could not understand input using 3x3 dungeon grid!" << endl;
        rows = 3 ;
        columns = 3;
    }

    auto dungeon = randomMatrix(rows, columns, -4, 2);
    printDungeon(dungeon);
    int hp = calculateMinimumKnightHitPointsToRescuePrincess(dungeon);
    cout << "Minimum Knight HitPoints to rescue princess: " << hp << endl;
}
