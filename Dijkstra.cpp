#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>

using namespace std;

struct Edge 
{
    int destination;
    int weight;
};

void Dijkstra(vector<vector<Edge>>& graph, int source) 
{
    int numVertices = graph.size();
    vector<int> dist(numVertices, INT_MAX); 
    dist[source] = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, source });

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) 
        {
            int v = edge.destination;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v]) 
            {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    cout << "���������� ���������� �� ������� " << source << " �� ���� ��������� ������:" << endl;
    for (int i = 0; i < numVertices; i++) 
    {
        cout << "������� " << i << ": " << dist[i] << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    ifstream inputFile("matrix.txt");
    if (!inputFile)
    {
        cout << "�� ������� ������� ���� matrix.txt " << endl;
        return 1;
    }

    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;

    vector<vector<Edge>> graph(numVertices);

    cout << "������� ��������� �����:" << endl;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++) 
        {
            int weight;
            inputFile >> weight;
            if (weight > 0) 
            {
                graph[i].push_back({ j, weight });
            }
            cout << weight << " ";
        }
        cout << endl;
    }

    inputFile.close();

    int source;
    cout << "������� ��������� �������: ";
    cin >> source;

    Dijkstra(graph, source);

    return 0;
}