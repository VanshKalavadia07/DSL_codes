#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class BookIndex
{
    struct Book
    {
        int id;
        char title[100];
    };

    struct Index
    {
        int id;
        long position;
        char title[100];
    };

public:

    void insertBook()
    {
        Book b;
        Index idx;

        cout << "\nEnter Book ID: ";
        cin >> b.id;

        cin.ignore();

        cout << "Enter Book Title: ";
        cin.getline(b.title, 100);

        fstream data("books.dat", ios::binary | ios::app);
        fstream index("index.dat", ios::binary | ios::app);

        data.seekp(0, ios::end);

        idx.id = b.id;
        idx.position = data.tellp();
        strcpy(idx.title, b.title);

        data.write((char*)&b, sizeof(b));
        index.write((char*)&idx, sizeof(idx));

        data.close();
        index.close();

        cout << "\nBook inserted successfully!\n";
    }

    void displayIndex()
    {
        Index idx;

        ifstream file("index.dat", ios::binary);

        cout << "\n--- BOOK INDEX RECORDS ---\n";
        cout << "Book ID\tBook Title\tPosition\n";

        while (file.read((char*)&idx, sizeof(idx)))
        {
            cout << idx.id << "\t"
                 << idx.title << "\t"
                 << idx.position << endl;
        }

        file.close();
    }

    void searchBook()
    {
        int key;
        Index idx;
        Book b;
        bool found = false;

        cout << "\nEnter Book ID to search: ";
        cin >> key;

        ifstream index("index.dat", ios::binary);
        ifstream data("books.dat", ios::binary);

        while (index.read((char*)&idx, sizeof(idx)))
        {
            if (idx.id == key)
            {
                found = true;

                data.seekg(idx.position);
                data.read((char*)&b, sizeof(b));

                cout << "\nBook Found!\n";
                cout << "Book ID: " << b.id << endl;
                cout << "Book Title: " << b.title << endl;

                break;
            }
        }

        if (!found)
            cout << "\nBook not found!\n";

        index.close();
        data.close();
    }
};

int main()
{
    BookIndex obj;
    int choice;

    do
    {
        cout << "\n===== LIBRARY BOOK INDEX MANAGEMENT =====";
        cout << "\n1. Insert Book Record";
        cout << "\n2. Display Index Records";
        cout << "\n3. Search Book by ID";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                obj.insertBook();
                break;

            case 2:
                obj.displayIndex();
                break;

            case 3:
                obj.searchBook();
                break;

            case 4:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
