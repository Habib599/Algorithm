#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <ctime>
using namespace std;

struct Book {
    string title, author, ISBN;
    bool isAvailable = true;
};

struct Borrower {
    string name;
    unordered_map<string, time_t> borrowedBooks; // ISBN -> checkout time
};

class Library {
private:
    vector<Book> books;
    unordered_map<string, Borrower> borrowers; // name -> Borrower
    const int finePerDay = 5;
    const int loanPeriod = 7 * 24 * 60 * 60; // 7 days in seconds

public:
    void addBook(string title, string author, string ISBN) {
        books.push_back({title, author, ISBN});
    }

    void searchBook(string keyword) {
        for (auto& b : books) {
            if (b.title == keyword || b.author == keyword || b.ISBN == keyword) {
                cout << "Found: " << b.title << " by " << b.author << " [" << b.ISBN << "] - ";
                cout << (b.isAvailable ? "Available" : "Checked out") << endl;
            }
        }
    }

    void checkoutBook(string borrowerName, string ISBN) {
        for (auto& b : books) {
            if (b.ISBN == ISBN && b.isAvailable) {
                b.isAvailable = false;
                borrowers[borrowerName].name = borrowerName;
                borrowers[borrowerName].borrowedBooks[ISBN] = time(0);
                cout << "Book checked out to " << borrowerName << endl;
                return;
            }
        }
        cout << "Book not available or not found.\n";
    }

    void returnBook(string borrowerName, string ISBN) {
        for (auto& b : books) {
            if (b.ISBN == ISBN && !b.isAvailable) {
                b.isAvailable = true;
                time_t borrowedTime = borrowers[borrowerName].borrowedBooks[ISBN];
                time_t currentTime = time(0);
                int overdue = difftime(currentTime, borrowedTime) - loanPeriod;
                if (overdue > 0) {
                    int fine = (overdue / (60 * 60 * 24)) * finePerDay;
                    cout << "Book returned. Fine: " << fine << " Taka\n";
                } else {
                    cout << "Book returned. No fine.\n";
                }
                borrowers[borrowerName].borrowedBooks.erase(ISBN);
                return;
            }
        }
        cout << "Book not found in system or already returned.\n";
    }

    void showAllBooks() {
        for (auto& b : books) {
            cout << b.title << " | " << b.author << " | " << b.ISBN << " | " << (b.isAvailable ? "Available" : "Checked Out") << endl;
        }
    }
};

int main() {
    Library lib;
    lib.addBook("C++ Basics", "Bjarne Stroustrup", "123");
    lib.addBook("Intro to Algorithms", "CLRS", "456");

    lib.searchBook("C++ Basics");
    lib.checkoutBook("Alice", "123");
    lib.showAllBooks();
    lib.returnBook("Alice", "123");
    lib.showAllBooks();
    return 0;
}
