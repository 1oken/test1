#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void writeToFile(const std::string& filename, const std::vector<int>& numbers, bool append = false) {
    std::ofstream file;
    if (append) {
        file.open(filename, std::ios::app);  // ���ļ���׷������
    } else {
        file.open(filename);  // ���ļ���д������
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
    std::cout << "������20���������ÿո�ָ�����" << std::endl;

    // ���û������ȡ20������
    for (int i = 0; i < 20; ++i) {
        std::cin >> integers[i];
    }

    // ��ǰ10����д��f1.dat����10����д��f2.dat
    writeToFile("f1.dat", std::vector<int>(integers.begin(), integers.begin() + 10));
    writeToFile("f2.dat", std::vector<int>(integers.begin() + 10, integers.end()));

    // ��f1.dat��ȡ���ݲ�׷�ӵ�f2.dat
    std::vector<int> f1Data = readFromFile("f1.dat");
    writeToFile("f2.dat", f1Data, true);

    // ��f2.dat��ȡ���ݣ�����Ȼ������д��
    std::vector<int> f2Data = readFromFile("f2.dat");
    std::sort(f2Data.begin(), f2Data.end());
    writeToFile("f2.dat", f2Data, false);

    return 0;
}

