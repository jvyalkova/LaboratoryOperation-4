#include <iostream>
#include <fstream>

#define max_int 999999

using namespace std;
int main() 
{
    setlocale(LC_ALL, "RUS");
    ifstream inputFile("matrixPrima.txt");

    int n; 
    inputFile >> n;

    int** matrix;
    matrix = new int* [n];
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            inputFile >> matrix[i][j];
        }
    }

    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) 
    {
        visited[i] = false;
    }

    visited[0] = true; 

    int numVisited = 1; 
    int totalWeight = 0; 

    while (numVisited < n) 
    {
        int minWeight = max_int; 
        int from, to; 

        for (int i = 0; i < n; i++) 
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && matrix[i][j] != 0 && matrix[i][j] < minWeight) 
                    {
                        minWeight = matrix[i][j];
                        from = i;
                        to = j;
                    }
                }
            }
        }

        
        cout << "Ребро: " << from << " - " << to << ", Вес: " << minWeight << endl;

        visited[to] = true;
        numVisited++;
        totalWeight += minWeight;
    }

    cout << "Общий вес минимального остовного дерева: " << totalWeight << endl;
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] visited;

    inputFile.close();

    return 0;
}
