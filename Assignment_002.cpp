#include <iostream>
using namespace std;

void analyzeGrades(int *matrix, int students, int subjects) {
    int highest = *(matrix);

    cout << "\nGrade Matrix:\n";

    for(int i = 0; i < students; i++) {
        int sum = 0;

        for(int j = 0; j < subjects; j++) {
            int value = *(matrix + i * subjects + j);

            cout << value << "\t";
            sum += value;

            if(value > highest)
                highest = value;
        }

        double avg = (double)sum / subjects;
        cout << " | Average: " << avg;

        cout << endl;
    }

    cout << "\nHighest Grade in Matrix: " << highest << endl;
}

int main() {
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of subjects: ";
    cin >> subjects;

    int grades[students][subjects];

    cout << "\nEnter grades:\n";

    for(int i = 0; i < students; i++) {
        for(int j = 0; j < subjects; j++) {
            cout << "Student " << i+1 << " Subject " << j+1 << ": ";
            cin >> grades[i][j];
        }
    }

    analyzeGrades(&grades[0][0], students, subjects);

    return 0;
}