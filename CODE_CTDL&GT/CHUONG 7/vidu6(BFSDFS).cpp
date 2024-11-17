#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_VERTICES = 100;

vector<int> adj[MAX_VERTICES];
bool visited[MAX_VERTICES];

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < adj[v].size(); i++) {
        if (!visited[adj[v][i]]) {
            DFS(adj[v][i]);
        }
    }
}

void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        cout << v << " ";
        q.pop();

        for (int i = 0; i < adj[v].size(); i++) {
            if (!visited[adj[v][i]]) {
                visited[adj[v][i]] = true;
                q.push(adj[v][i]);
            }
        }
    }
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void displayGraph(int n) {
    cout << "\nCau truc do thi (danh sach ke):\n";
    for (int i = 0; i < n; i++) {
        cout << "Dinh " << i << ": ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, e;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> e;

    cout << "Nhap cac canh (u v): " << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    int chon;
    do { system("cls");
        cout << "Chon chuc nang:\n";
        cout << "1. Tim kiem theo chieu sau (DFS)\n";
        cout << "2. Tim kiem theo chieu rong (BFS)\n";
        cout << "3. Hien thi do thi\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> chon;

        for (int i = 0; i < MAX_VERTICES; i++) {
            visited[i] = false;
        }

        switch (chon) {
            case 1:
                cout << "Duyet theo chieu sau (DFS): ";
                DFS(0);
                cout << endl;
                break;

            case 2:
                cout << "Duyet theo chieu rong (BFS): ";
                BFS(0);
                cout << endl;
                break;

            case 3:
                displayGraph(n);
                break;

            case 0:
                cout << "Thoat chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        } system("pause");
    } while (chon != 0);

    return 0;
}

