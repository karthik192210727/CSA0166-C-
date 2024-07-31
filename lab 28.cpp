#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;

class group {
private:
    struct person {
        char flag;
        char empcode[5];
        char name[40];
        int age;
        float sal;
    } p;
    fstream file;

public:
    group();
    void addrec();
    void listrec();
    void modirec();
    void delrec();
    void recallrec();
    void packrec();
    void exit();
};

int main() {
    char choice;
    group g;
    do {
        cout << "1. Add records" << endl;
        cout << "2. List records" << endl;
        cout << "3. Modify records" << endl;
        cout << "4. Delete records" << endl;
        cout << "5. Recall records" << endl;
        cout << "6. Pack records" << endl;
        cout << "0. Exit" << endl;
        cout << "Your Choice? ";
        cin >> choice;

        switch (choice) {
        case '1':
            g.addrec();
            break;
        case '2':
            g.listrec();
            break;
        case '3':
            g.modirec();
            break;
        case '4':
            g.delrec();
            break;
        case '5':
            g.recallrec();
            break;
        case '6':
            g.packrec();
            break;
        case '0':
            g.exit();
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != '0');

    return 0;
}

group::group() {
    file.open("emp.dat", ios::binary | ios::in | ios::out | ios::app);
    if (!file) {
        cerr << "Unable to open file" << endl;
        std::exit(1);
    }
}

void group::addrec() {
    char ch;
    file.clear(); // Clear any error flags
    file.seekp(0L, ios::end);
    do {
        cout << "Enter emp code, name, age & salary: ";
        cin >> p.empcode >> p.name >> p.age >> p.sal;
        p.flag = ' ';
        file.write(reinterpret_cast<char*>(&p), sizeof(p));
        cout << "Add another record? (Y/N): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

void group::listrec() {
    int j = 0;
    file.clear(); // Clear any error flags
    file.seekg(0L, ios::beg);
    while (file.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        if (p.flag != '*') {
            cout << "Record#" << j++ << setw(6) << p.empcode
                 << setw(20) << p.name << setw(4) << p.age << setw(9) << p.sal << endl;
        }
    }
}

void group::modirec() {
    char code[5];
    int count = 0;
    long pos;
    cout << "Enter employee code: ";
    cin >> code;
    file.clear(); // Clear any error flags
    file.seekg(0L, ios::beg);
    while (file.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        if (strcmp(p.empcode, code) == 0) {
            cout << "Enter new record (emp code, name, age, salary): ";
            cin >> p.empcode >> p.name >> p.age >> p.sal;
            p.flag = ' ';
            pos = count * sizeof(p);
            file.seekp(pos, ios::beg);
            file.write(reinterpret_cast<char*>(&p), sizeof(p));
            return;
        }
        count++;
    }
    cout << "No employee in file with code = " << code << endl;
}

void group::delrec() {
    char code[5];
    long pos;
    int count = 0;
    cout << "Enter employee code: ";
    cin >> code;
    file.clear(); // Clear any error flags
    file.seekg(0L, ios::beg);
    while (file.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        if (strcmp(p.empcode, code) == 0) {
            p.flag = '*';
            pos = count * sizeof(p);
            file.seekp(pos, ios::beg);
            file.write(reinterpret_cast<char*>(&p), sizeof(p));
            return;
        }
        count++;
    }
    cout << "No employee in file with code = " << code << endl;
}

void group::recallrec() {
    char code[5];
    long pos;
    int count = 0;
    cout << "Enter employee code: ";
    cin >> code;
    file.clear(); // Clear any error flags
    file.seekg(0L, ios::beg);
    while (file.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        if (strcmp(p.empcode, code) == 0) {
            p.flag = ' ';
            pos = count * sizeof(p);
            file.seekp(pos, ios::beg);
            file.write(reinterpret_cast<char*>(&p), sizeof(p));
            return;
        }
        count++;
    }
    cout << "No employee in file with code = " << code << endl;
}

void group::packrec() {
    ofstream outfile("TEMP.dat", ios::out | ios::binary);
    if (!outfile) {
        cerr << "Unable to open temporary file" << endl;
        return;
    }
    file.clear(); // Clear any error flags
    file.seekg(0, ios::beg);
    while (file.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        if (p.flag != '*') {
            outfile.write(reinterpret_cast<char*>(&p), sizeof(p));
        }
    }
    outfile.close();
    file.close();
    remove("emp.dat");
    rename("TEMP.dat", "emp.dat");
    file.open("emp.dat", ios::binary | ios::in | ios::out | ios::app);
}

void group::exit() {
    file.close();
}
