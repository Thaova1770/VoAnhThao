#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream inputFile("data.txt");
    string line;
    int dem = 0;
    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            dem++;
            if (line.compare(0, 1, "-") == 0) {
                cout << line << endl;
            }
        }
        inputFile.close();
    }
    else {
        cout << "Khong the mo file  data.txt." << endl;
    }

    cout << "So dong dem duoc : " << dem << endl;

    return 0;
}