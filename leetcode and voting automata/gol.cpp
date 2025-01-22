#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

const int rows = 50;
const int cols = 50;
vector<vector<int>> grid(rows, vector<int>(cols, 0)); // Using std::vector for grid

const int numIterations = 100000;
const int numGenerations = 50;

int countNeighbors(int x, int y);
void nextGen();
void printGrid();
void clearGrid();
int countAlive();
void printPoints(int count, const vector<pair<int, int>>& p); // const added here

static bool cmp(pair<int, vector<pair<int, int>>> a, pair<int, vector<pair<int, int>>> b) {
    return a.first > b.first;
}

int main() {
    srand(time(0));

    clearGrid();

    vector<pair<int, vector<pair<int, int>>>> pointsCount;

    for (int i = 0; i < numIterations; i++) {
        vector<pair<int, int>> points;
        for (int j = 0; j < 50; j++) {
            int g = rand() % 40 + 5;
            int h = rand() % 40 + 5;
            pair<int, int> temp;
            temp.first = g;
            temp.second = h;
            points.push_back(temp);
            grid[g][h] = 1;
        }
        for (int j = 0; j < numGenerations; j++) {
            nextGen();
        }
        int count = countAlive();
        //if (count > 15) {
            pair<int, vector<pair<int, int>>> temp;
            temp.first = count;
            temp.second = points;
            pointsCount.push_back(temp);
        //}

        clearGrid();
    }

    for (int i = 0; i < pointsCount.size(); i++) {
        if (pointsCount[i].first == numGenerations) {
            cout << pointsCount[i].first << ": \n";
            for (int j = 0; j < pointsCount[i].second.size(); j++) {
                cout << "[" << pointsCount[i].second[j].first << ", " << pointsCount[i].second[j].second << "], ";
            }
            cout << endl << endl;
        }
    }

    // sort(pointsCount.begin(), pointsCount.end(), cmp);
    // for (int i = 0; i < 5; i++) {
    //     // Output the top 5 results
    //     cout << pointsCount[i].first << ": \n";
    //     printPoints(pointsCount[i].first, pointsCount[i].second);
    // }
}

void printPoints(int count, const vector<pair<int, int>>& p) {
    cout << count << ": \n";
    for (int i = 0; i < p.size(); i++) {
        cout << "[" << p[i].first << ", " << p[i].second << "], ";
    }
    cout << endl << endl;
}

int countNeighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int ni = x + i;
            int nj = y + j;
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                count += grid[ni][nj];
            }
        }
    }
    return count;
}

void clearGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }
}

void nextGen() {
    vector<vector<int>> newGrid(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = countNeighbors(i, j);

            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }

    grid = newGrid; // Assign the new grid back to the original grid
}

void printGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int countAlive() {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j]) {
                count++;
            }
        }
    }
    return count;
}
