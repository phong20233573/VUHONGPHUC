#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_TEACHERS = 100;

struct Teacher {
    string name;
    int age;
    string address;
    string school;
    int experience;
};

void inputTeacherInfo(Teacher teachers[], int &teacherCount) {
    if (teacherCount >= MAX_TEACHERS) {
        cout << "Khong the them giao vien, danh sach da day!" << endl;
        return;
    }

    Teacher &t = teachers[teacherCount];
    cout << "Nhap ten giao vien: ";
    cin.ignore();
    getline(cin, t.name);
    cout << "Nhap tuoi: ";
    cin >> t.age;
    cin.ignore();  // Bỏ qua ký tự newline
    cout << "Nhap dia chi: ";
    getline(cin, t.address);
    cout << "Nhap truong tot nghiep: ";
    getline(cin, t.school);
    cout << "Nhap so nam kinh nghiem day hoc: ";
    cin >> t.experience;

    teacherCount++;
}

void printTeacherInfo(const Teacher &t) {
    cout << "Ten: " << t.name << endl;
    cout << "Tuoi: " << t.age << endl;
    cout << "Dia chi: " << t.address << endl;
    cout << "Truong tot nghiep: " << t.school << endl;
    cout << "So nam kinh nghiem day hoc: " << t.experience << endl;
    cout << "--------------------------" << endl;
}

void printTeachersInfo(const Teacher teachers[], int teacherCount) {
    if (teacherCount == 0) {
        cout << "Chua co thong tin giao vien nao!" << endl;
        return;
    }

    for (int i = 0; i < teacherCount; i++) {
        const Teacher &t = teachers[i];
        cout << "Giao vien thu " << i + 1 << ":" << endl;
        printTeacherInfo(t);
    }
}

void sortTeachersByName(Teacher teachers[], int teacherCount) {
    sort(teachers, teachers + teacherCount, [](const Teacher &a, const Teacher &b) {
        return a.name < b.name;
    });
    cout << "Danh sách giáo viên sau khi sắp xếp theo tên:" << endl;
    printTeachersInfo(teachers, teacherCount);
}

void searchTeacherByName(const Teacher teachers[], int teacherCount) {
    if (teacherCount == 0) {
        cout << "Chua co thong tin giao vien nao!" << endl;
        return;
    }

    cout << "Nhap ten giao vien can tim: ";
    cin.ignore();
    string searchName;
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < teacherCount; i++) {
        if (teachers[i].name.find(searchName) != string::npos) {
            printTeacherInfo(teachers[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay giao vien nao voi ten " << searchName << endl;
    }
}

void saveTeachersInfoToFile(const Teacher teachers[], int teacherCount) {
    ofstream outFile("Danhsachgv.txt");

    if (!outFile) {
        cout << "Khong the mo file de ghi!" << endl;
        return;
    }

    for (int i = 0; i < teacherCount; i++) {
        const Teacher &t = teachers[i];
        outFile << "Giao vien thu " << i + 1 << ":\n";
        outFile << "Ten: " << t.name << '\n';
        outFile << "Tuoi: " << t.age << '\n';
        outFile << "Dia chi: " << t.address << '\n';
        outFile << "Truong tot nghiep: " << t.school << '\n';
        outFile << "So nam kinh nghiem day hoc: " << t.experience << '\n';
        outFile << "--------------------------" << '\n';
    }

    outFile.close();
    cout << "Thong tin giao vien da duoc luu vao file Danhsachgv.txt" << endl;
}

int main() {
    Teacher teachers[MAX_TEACHERS];
    int teacherCount = 0;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Nhap thong tin giao vien" << endl;
        cout << "2. In thong tin tat ca giao vien" << endl;
        cout << "3. Sap xep danh sach theo ten" << endl;
        cout << "4. Tim kiem giao vien theo ten" << endl;
        cout << "5. In danh sach thong tin giao vien ra file" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputTeacherInfo(teachers, teacherCount);
                break;
            case 2:
                printTeachersInfo(teachers, teacherCount);
                break;
            case 3:
                sortTeachersByName(teachers, teacherCount);
                cout << "Danh sach giao vien da duoc sap xep theo ten." << endl;
                break;
            case 4:
                searchTeacherByName(teachers, teacherCount);
                break;
            case 5:
                sortTeachersByName(teachers, teacherCount);
                saveTeachersInfoToFile(teachers, teacherCount);
                break;
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ, vui lòng thử lại!" << endl;
        }
    } while (choice != 0);

    return 0;
}

