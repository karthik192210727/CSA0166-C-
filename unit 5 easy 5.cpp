#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
class Paper {
private:
    vector<int> authors;

public:
    void getAuthors() {
        int num;
        cout << "Enter the authors details: ";
        for (int i = 0; i < 5; i++) {
            cin >> num;
            authors.push_back(num);
        }
    }

    void displayAuthors() const {
        cout << "Authors on the paper: ";
        for (vector<int>::const_iterator it = authors.begin(); it != authors.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    void removeAuthor(int author) {
        vector<int>::iterator it = find(authors.begin(), authors.end(), author);
        if (it != authors.end()) {
            authors.erase(it);
            cout << "Author No. " << author << " is removed from the paper...." << endl;
        } else {
            cout << "Author No. " << author << " not found in the list." << endl;
        }
    }

    void addAuthor(int author) {
        authors.push_back(author);
        cout << "Author No. " << author << " is inserted...." << endl;
    }
};

int main() {
    Paper paper;
    paper.getAuthors();
    paper.displayAuthors();
    int authorToRemove = 1;
    paper.removeAuthor(authorToRemove);
    paper.displayAuthors();
    int newAuthor = 5;
    paper.addAuthor(newAuthor);
    paper.displayAuthors();

    return 0;
}
