#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void writeToFile(const std::string& filename, const std::vector<int>& numbers, bool append = false) {
    std::ofstream file;
    if (append) {
        file.open(filename, std::ios::app);  // 打开文件以追加数据
    } else {
        file.open(filename);  // 打开文件以写入数据
    }
    for (int num : numbers) {
        file << num << std::endl;
    }
    file.close();
}

std::vector<int> readFromFile(const std::string& filename) {
    std::vector<int> numbers;
    std::ifstream file(filename);
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }
    file.close();
    return numbers;
}

int main() {
    std::vector<int> integers(20);
    std::cout << "请输入20个整数（用空格分隔）：" << std::endl;

    // 从用户输入读取20个整数
    for (int i = 0; i < 20; ++i) {
        std::cin >> integers[i];
    }

    // 将前10个数写入f1.dat，后10个数写入f2.dat
    writeToFile("f1.dat", std::vector<int>(integers.begin(), integers.begin() + 10));
    writeToFile("f2.dat", std::vector<int>(integers.begin() + 10, integers.end()));

    // 从f1.dat读取数据并追加到f2.dat
    std::vector<int> f1Data = readFromFile("f1.dat");
    writeToFile("f2.dat", f1Data, true);

    // 从f2.dat读取数据，排序，然后重新写入
    std::vector<int> f2Data = readFromFile("f2.dat");
    std::sort(f2Data.begin(), f2Data.end());
    writeToFile("f2.dat", f2Data, false);

    return 0;
}

