#include <iostream>
using namespace std;

int main() {
    char repeat;

    do {
        double sales[5][4] = {0};
        int salesperson, product;
        double amount;
        char choice;

        do {
            cout << "\nEnter Salesperson number (1-4): ";
            cin >> salesperson;

            cout << "Enter Product number (1-5): ";
            cin >> product;

            cout << "Enter Amount: ";
            cin >> amount;

            sales[product - 1][salesperson - 1] += amount;

            cout << "Enter another? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        cout << "\n--- Sales Summary ---\n";

        double grandTotal = 0;

        for (int i = 0; i < 5; i++) {
            double rowTotal = 0;

            cout << "\nProduct " << i + 1 << endl;

            for (int j = 0; j < 4; j++) {
                cout << "Salesperson " << j + 1
                     << ": " << sales[i][j] << endl;

                rowTotal += sales[i][j];
            }

            cout << "Total for Product "
                 << i + 1 << ": "
                 << rowTotal << endl;

            grandTotal += rowTotal;
        }

        cout << "\n--- Total Sales per Salesperson ---\n";

        for (int j = 0; j < 4; j++) {
            double colTotal = 0;

            for (int i = 0; i < 5; i++) {
                colTotal += sales[i][j];
            }

            cout << "Salesperson "
                 << j + 1 << ": "
                 << colTotal << endl;
        }

        cout << "\nGrand Total Sales: "
             << grandTotal << endl;

        cout << "\nRun program again? (Y/N): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

        cout << "\nEnding program...";

    return 0;
}