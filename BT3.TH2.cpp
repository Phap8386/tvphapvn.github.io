#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#define FI "DanhSachKe.inp"
#define FO "DanhSachKe.out"

void Nhap(int& n, std::vector<std::vector<int>>& adjList) {
    std::ifstream fi;
    fi.open(FI);
    if (!fi.is_open()) {
        std::cerr << "Loi: Khong the mo file " << FI << std::endl;
        return;
    }
    fi >> n;
    adjList.resize(n);
    std::string line;
    std::getline(fi, line);
    for (int i = 0; i < n; ++i) {
        std::getline(fi, line);
        std::stringstream ss(line);
        int vertex;
        while (ss >> vertex) {
            adjList[i].push_back(vertex);
        }
    }
    fi.close();
}

void Xuat(int n, const std::vector<int>& bacDinh) {
    std::ofstream fo;
    fo.open(FO);
    if (!fo.is_open()) {
        std::cerr << "Loi: Khong the mo file " << FO << std::endl;
        return;
    }
    fo << n << std::endl;
    for (int i = 0; i < n; ++i) {
        fo << bacDinh[i] << std::endl;
    }
    fo.close();
}

void XuLy(int n, const std::vector<std::vector<int>>& adjList, std::vector<int>& bacDinh) {
    bacDinh.resize(n);
    for (int i = 0; i < n; ++i) {
        bacDinh[i] = adjList[i].size();
    }
}

int main() {
    int n;
    std::vector<std::vector<int>> adjList;
    std::vector<int> bacDinh;

    Nhap(n, adjList);
    XuLy(n, adjList, bacDinh);
    Xuat(n, bacDinh);

    std::cout << "Da tinh toan xong va ghi ket qua vao file '" << FO << "'." << std::endl;
    return 0;
}