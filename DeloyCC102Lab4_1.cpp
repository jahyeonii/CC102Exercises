#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        int students, quizzes;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        double scores[100][100];
        double average[100];

        for (int i = 0; i < students; i++) {
            double sum = 0;

            cout << "\nStudent " << i + 1 << " scores:\n";

            for (int j = 0; j < quizzes; j++) {
                cout << "Quiz " << j + 1 << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            average[i] = sum / quizzes;
        }

        cout << "\n--- Results ---\n";

        for (int i = 0; i < students; i++) {
            cout << "\nStudent " << i + 1 << endl;

            for (int j = 0; j < quizzes; j++) {
                cout << "Quiz " << j + 1 << ": "
                     << scores[i][j] << endl;
            }

            cout << "Average: " << average[i] << endl;
        }

        cout << "\nTry again? (Y/N): ";
        cin >> choice;

    } while (choice == 'y' || choice== 'Y');

    return 0;
}