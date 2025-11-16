#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#define FI "MaTranKe.inp"
#define FO "MaTranKe.out"

void Nhap(int& n, std::vector<std::vector<int>>& a) {
    std::ifstream fi;
    fi.open(FI);
    if (!fi.is_open()) {
        std::cerr << "Loi: Khong the mo file " << FI << std::endl;
        exit(1);
    }
    fi >> n;
    a.resize(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fi >> a[i][j];
        }
    }
    fi.close();
}

void Xuat(int n, const std::vector<int>& bacDinh) {
    std::ofstream fo;
    fo.open(FO);
    if (!fo.is_open()) {
        std::cerr << "Loi: Khong the mo file " << FO << std::endl;
        exit(1);
    }
    fo << n << std::endl;
    for (int i = 0; i < n; ++i) {
        fo << bacDinh[i] << std::endl;
    }
    fo.close();
}

void XuLy(int n, const std::vector<std::vector<int>>& a, std::vector<int>& bacDinh) {
    bacDinh.resize(n);
    for (int i = 0; i < n; ++i) {
        int bac = 0;
        for (int j = 0; j < n; ++j) {
            bac += a[i][j];
        }
        bacDinh[i] = bac;
    }
}

int main() {
    int n;
    std::vector<std::vector<int>> a;
    std::vector<int> bacDinh;

    Nhap(n, a);
    XuLy(n, a, bacDinh);
    Xuat(n, bacDinh);

    std::cout << "Da tinh toan xong va ghi ket qua vao file '" << FO << "'." << std::endl;

    return 0;
}