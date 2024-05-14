#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cstdlib>

using namespace std;

//Global variables
int MAXCAKE;
int CAKETYPE;
int TABLE_HORIZONTAL;
int TABLE_VERTICAL;
struct Plate 
{
    vector<int> Cakes = {0,0,0,0,0,0,0};
};
vector<vector<Plate>> Tables;

//Prototype
void initGlobalvar();
void initTables(vector<vector<Plate>>& Tables);
void printTables(const vector<vector<Plate>>& Tables);
void insertToTable(int i, int j, vector<vector<vector<int>>>& Tables);

//Main flow
int main()
{
    // Menginisialisasi meja
    initGlobalvar();
    initTables(Tables);

    printTables(Tables);

    // Mencetak jumlah piring secara horizontal dan vertikal
    cout << "Jumlah piring vertikal: " << Tables.size() << endl;
    cout << "Jumlah piring horizontal: " << Tables[0].size() << endl;

}

void initTables(vector<vector<Plate>>& Tables)
{
    Tables.resize(TABLE_HORIZONTAL, vector<Plate>(TABLE_VERTICAL));
}

void initGlobalvar()
{
    Plate plate;
    MAXCAKE = plate.Cakes.size(); 
    CAKETYPE = 2;  
    TABLE_HORIZONTAL = 3;  
    TABLE_VERTICAL = 4;  
}

void printTables(const vector<vector<Plate>>& Tables)
{
    for (int i = 0; i < TABLE_HORIZONTAL; i++)
    {
        for (int j = 0; j < TABLE_VERTICAL; j++)
        {
            cout << "[";
            for (int k = 0; k < MAXCAKE; k++)
            {
                cout << Tables[i][j].Cakes[k] << " ";
            }
            cout << "] ";
        }
        cout << endl;
    }
}


void insertToTable(int i, int j, vector<vector<vector<int>>>& Tables)
{
    //Membuat dua piring dengan isi yang bisa saling ditukar
    vector<int> Cake (MAXCAKE);

    int MAXGENERATE = rand() % Cake.size();

    //Merandom isi piring dengan maksimal dua jenis
    for (int c = 0; c < MAXGENERATE; c++)
    {
        Cake[c] = rand() % CAKETYPE + 1;
    }

    //Memasukkan kue ke piring
    Tables[i][j] = Cake;
}

