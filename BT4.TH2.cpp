#include <iostream>
#include <vector>
#include <fstream>

#define FI "DanhSachCanh.inp"
#define FO "DanhSachCanh.out"

void Nhap(int& n, int& m, std::vector<std::pair<int, int>>& edgeList) {
    std::ifstream fi;
    fi.open(FI);
    if (!fi.is_open()) {
        std::cerr << "Loi: Khong the mo file " << FI << std::endl;
        return;
    }
    fi >> n >> m;
    edgeList.resize(m);
    for (int i = 0; i < m; ++i) {
        fi >> edgeList[i].first >> edgeList[i].second;
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

void XuLy(int n, const std::vector<std::pair<int, int>>& edgeList, std::vector<int>& bacDinh) {
    bacDinh.resize(n + 1, 0); // Kích thước n+1 vì đỉnh bắt đầu từ 1
    for (const auto& edge : edgeList) {
        bacDinh[edge.first]++;
        bacDinh[edge.second]++;
    }
}

int main() {
    int n, m;
    std::vector<std::pair<int, int>> edgeList;
    std::vector<int> bacDinh;

    Nhap(n, m, edgeList);
    XuLy(n, edgeList, bacDinh);
    Xuat(n, bacDinh);

    std::cout << "Da tinh toan xong va ghi ket qua vao file '" << FO << "'." << std::endl;
    return 0;
}