#include <vector>
#include <iostream>
#include <random>

using namespace std;

struct Plate {
    vector<int> Cakes;
    Plate() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 5);
        Cakes.resize(2, dis(gen));
    }
};

vector<vector<int>> adjacencyMatrix;
vector<Plate> Plates;

void initGlobalvar() {
    Plate plate;
    int MAXCAKE = plate.Cakes.size(); 
    int CAKETYPE = 2;  
    int TABLE_HORIZONTAL = 3;  
    int TABLE_VERTICAL = 4;
    adjacencyMatrix.resize(TABLE_HORIZONTAL * TABLE_VERTICAL, vector<int>(TABLE_HORIZONTAL * TABLE_VERTICAL, 0));
    Plates.resize(TABLE_HORIZONTAL * TABLE_VERTICAL);
}

void initAdjacencyMatrix(int horizontal, int vertical) {
    for (int i = 0; i < horizontal * vertical; i++) {
        if (i % horizontal != 0) {
            adjacencyMatrix[i][i - 1] = 1;
            adjacencyMatrix[i - 1][i] = 1;
        }
        if (i >= horizontal) {
            adjacencyMatrix[i][i - horizontal] = 1;
            adjacencyMatrix[i - horizontal][i] = 1;
        }
    }
}

void printAdjacencyMatrix() {
    for (const auto &row : adjacencyMatrix) {
        for (const auto &element : row) {
            cout << element << " ";
        }
        cout << "\n";
    }
}

int main() {
    initGlobalvar();
    initAdjacencyMatrix(3, 4);
    printAdjacencyMatrix();
    return 0;
}