#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> surnames;
vector<string> initials;
vector<string> positions;
vector<int> hire_years;
vector<double> salaries;

void inputEmployee() {
    string surname, initial, position;
    int hire_year;
    double salary;

    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter initials: ";
    cin >> initial;
    cout << "Enter position: ";
    cin >> position;
    cout << "Enter hire year: ";
    cin >> hire_year;
    cout << "Enter salary: ";
    cin >> salary;

    surnames.push_back(surname);
    initials.push_back(initial);
    positions.push_back(position);
    hire_years.push_back(hire_year);
    salaries.push_back(salary);
}

void printEmployee(int index) {
    cout << "Surname: " << surnames[index] << "\nInitials: " << initials[index]
        << "\nPosition: " << positions[index]
        << "\nHire Year: " << hire_years[index]
        << "\nSalary: " << salaries[index] << endl;
}

void printAllEmployees() {
    sort(surnames.begin(), surnames.end());
    for (int i = 0; i < surnames.size(); i++) {
        int index = distance(surnames.begin(),
            find(surnames.begin(), surnames.end(), surnames[i]));
        printEmployee(index);
        cout << endl;
    }
}

void saveToFile() {
    ofstream file("employees.txt");
    for (int i = 0; i < surnames.size(); i++) {
        file << surnames[i] << " " << initials[i] << " " << positions[i] << " "
            << hire_years[i] << " " << salaries[i] << "\n";
    }
    file.close();
}

void loadFromFile() {
    ifstream file("employees.txt");
    string surname, initial, position;
    int hire_year;
    double salary;
    while (file >> surname >> initial >> position >> hire_year >> salary) {
        surnames.push_back(surname);
        initials.push_back(initial);
        positions.push_back(position);
        hire_years.push_back(hire_year);
        salaries.push_back(salary);
    }
    file.close();
}

void sortEmployees() {
    vector<pair<string, int>> sorted_surnames;
    for (int i = 0; i < surnames.size(); i++) {
        sorted_surnames.push_back(make_pair(surnames[i], i));
    }
    sort(sorted_surnames.begin(), sorted_surnames.end());

    vector<string> sorted_initials(surnames.size());
    vector<string> sorted_positions(surnames.size());
    vector<int> sorted_hire_years(surnames.size());
    vector<double> sorted_salaries(surnames.size());

    for (int i = 0; i < surnames.size(); i++) {
        surnames[i] = sorted_surnames[i].first;
        sorted_initials[i] = initials[sorted_surnames[i].second];
        sorted_positions[i] = positions[sorted_surnames[i].second];
        sorted_hire_years[i] = hire_years[sorted_surnames[i].second];
        sorted_salaries[i] = salaries[sorted_surnames[i].second];
    }

    initials = sorted_initials;
    positions = sorted_positions;
    hire_years = sorted_hire_years;
    salaries = sorted_salaries;
}

int main() {
    loadFromFile();
    while (true) {
        cout << "1. Add employee\n2. Delete employee\n3. Edit employee\n4. Sort "
            "employees\n5. Print employee\n6. Print all employees\n7. Exit\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            inputEmployee();
        }
        else if (choice == 2) {
            string surname;
            cout << "Enter surname: ";
            cin >> surname;
            auto it = find(surnames.begin(), surnames.end(), surname);
            if (it != surnames.end()) {
                int index = distance(surnames.begin(), it);
                surnames.erase(surnames.begin() + index);
                initials.erase(initials.begin() + index);
                positions.erase(positions.begin() + index);
                hire_years.erase(hire_years.begin() + index);
                salaries.erase(salaries.begin() + index);
            }
        }
        else if (choice == 3) {
            string surname;
            cout << "Enter surname: ";
            cin >> surname;
            auto it = find(surnames.begin(), surnames.end(), surname);
            if (it != surnames.end()) {
                int index = distance(surnames.begin(), it);
                inputEmployee();
                surnames[index] = surnames.back();
                initials[index] = initials.back();
                positions[index] = positions.back();
                hire_years[index] = hire_years.back();
                salaries[index] = salaries.back();
                surnames.pop_back();
                initials.pop_back();
                positions.pop_back();
                hire_years.pop_back();
                salaries.pop_back();
            }
        }
        else if (choice == 4) {
            sortEmployees();
        }
        else if (choice == 5) {
            string surname;
            cout << "Enter surname: ";
            cin >> surname;
            auto it = find(surnames.begin(), surnames.end(), surname);
            if (it != surnames.end()) {
                int index = distance(surnames.begin(), it);
                printEmployee(index);
            }
        }
        else if (choice == 6) {
            printAllEmployees();
        }
        else if (choice == 7) {
            saveToFile();
            break;
        }
    }

    return 0;
}