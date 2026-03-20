#include <iostream>
using namespace std;

struct student {
    int studentID;
    string name;
    string course;
    double gpa;
};

// Input Function
void input(int num, student s[]) {
    for(int i = 0; i < num; i++) {

        // Check duplicate ID safely
        bool duplicate;
        do {
            duplicate = false;

            cout << "StudentID: ";
            cin >> s[i].studentID;
            cin.ignore();

            for(int j = 0; j < i; j++) {
                if(s[j].studentID == s[i].studentID) {
                    cout << "Student already exists!\n";
                    duplicate = true;
                    break;
                }
            }

        } while(duplicate);

        cout << "Name: ";
        getline(cin, s[i].name);

        cout << "Course: ";
        getline(cin, s[i].course);

        // GPA validation
        do {
            cout << "GPA: ";
            cin >> s[i].gpa;
            cin.ignore();

            if (s[i].gpa < 0 || s[i].gpa > 100) {
                cout << "0 to 100 only\n";
            }

        } while(s[i].gpa < 0 || s[i].gpa > 100);

        cout << endl;
    }
}

// Display Function
void display(int num, student s[]) {
    cout << "StudentID\tName\t\tCourse\t\tGPA\tStanding\n";
    cout << "====================================================================\n";

    for(int i = 0; i < num; i++) {
        cout << s[i].studentID << "\t\t";
        cout << s[i].name << "\t\t";
        cout << s[i].course << "\t\t";
        cout << s[i].gpa << "\t";

        if(s[i].gpa >= 90) {
            cout << "Excellent";
        }
        else if(s[i].gpa >= 80) {
            cout << "Very Good";
        }
        else if(s[i].gpa >= 70) {
            cout << "Good";
        }
        else if(s[i].gpa >= 60) {
            cout << "Passing";
        }
        else {
            cout << "Failed";
        }

        cout << endl;
    }

    cout << "====================================================================\n";
}

// Main Function
int main() {
    char choice;

    do {
        int num;

        cout << "How many students: ";
        cin >> num;
        cin.ignore();

        student s[num];

        input(num, s);   
        display(num, s); 

        cout << "Try again? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}
