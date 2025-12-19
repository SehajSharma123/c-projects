#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    void addBook() {
        cout << "Enter Book ID: "; cin >> id;
        cin.ignore(); // Clear buffer
        cout << "Enter Book Title: "; getline(cin, title);
        cout << "Enter Author Name: "; getline(cin, author);
        
        ofstream file("library.txt", ios::app);
        file << id << "|" << title << "|" << author << endl;
        file.close();
        cout << "Book added successfully!\n";
    }

    static void displayAll() {
        ifstream file("library.txt");
        string line;
        cout << "\n--- Library Records ---\n";
        cout << left << setw(10) << "ID" << setw(25) << "Title" << setw(20) << "Author" << endl;
        cout << "------------------------------------------------------------\n";
        
        while (getline(file, line)) {
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);
            
            string id = line.substr(0, pos1);
            string title = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string author = line.substr(pos2 + 1);
            
            cout << left << setw(10) << id << setw(25) << title << setw(20) << author << endl;
        }
        file.close();
    }
};

void menu() {
    int choice;
    Book b;
    do {
        cout << "\n1. Add Book\n2. View All Books\n3. Exit\nEnter Choice: ";
        cin >> choice;
        switch(choice) {
            case 1: b.addBook(); break;
            case 2: Book::displayAll(); break;
            case 3: cout << "Exiting..."; break;
            default: cout << "Invalid Choice!";
        }
    } while(choice != 3);
}

int main() {
    menu();
    return 0;
}
