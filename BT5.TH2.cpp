#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

// Chuyển đổi Ma trận kề sang Danh sách kề
void MaTranKeToDanhSachKe(const std::vector<std::vector<int>>& adjMatrix, std::vector<std::vector<int>>& adjList, int n) {
    adjList.assign(n, std::vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjMatrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }
}

// Chuyển đổi Ma trận kề sang Danh sách cạnh
void MaTranKeToDanhSachCanh(const std::vector<std::vector<int>>& adjMatrix, std::vector<std::pair<int, int>>& edgeList, int n) {
    edgeList.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (adjMatrix[i][j] == 1) {
                edgeList.push_back({i, j});
            }
        }
    }
}

// Chuyển đổi Danh sách kề sang Ma trận kề
void DanhSachKeToMaTranKe(const std::vector<std::vector<int>>& adjList, std::vector<std::vector<int>>& adjMatrix, int n) {
    adjMatrix.assign(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int neighbor : adjList[i]) {
            adjMatrix[i][neighbor] = 1;
        }
    }
}

// Chuyển đổi Danh sách kề sang Danh sách cạnh
void DanhSachKeToDanhSachCanh(const std::vector<std::vector<int>>& adjList, std::vector<std::pair<int, int>>& edgeList, int n) {
    edgeList.clear();
    for (int i = 0; i < n; ++i) {
        for (int neighbor : adjList[i]) {
            if (i < neighbor) {
                edgeList.push_back({i, neighbor});
            }
        }
    }
}

// Chuyển đổi Danh sách cạnh sang Ma trận kề
void DanhSachCanhToMaTranKe(const std::vector<std::pair<int, int>>& edgeList, std::vector<std::vector<int>>& adjMatrix, int n) {
    adjMatrix.assign(n, std::vector<int>(n, 0));
    for (const auto& edge : edgeList) {
        adjMatrix[edge.first][edge.second] = 1;
        adjMatrix[edge.second][edge.first] = 1;
    }
}

// Chuyển đổi Danh sách cạnh sang Danh sách kề
void DanhSachCanhToDanhSachKe(const std::vector<std::pair<int, int>>& edgeList, std::vector<std::vector<int>>& adjList, int n) {
    adjList.assign(n, std::vector<int>());
    for (const auto& edge : edgeList) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }
}

int main() {
    return 0;
}