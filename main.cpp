#include "ALDict.hpp"
#include "LLDict.hpp"
#include <string>

int main() {
    Dictionary<string, string>* dict;
    string userWord, s;
    int userChoice = 0;
    bool flag = false;

    do {
        cout << "Enter 1 for ALDict or 2 for LLDict: ";
        cin >> userChoice;
    } while (userChoice != 1 && userChoice != 2);

    if (userChoice == 1) {
        dict = new ALDict<string, string>();
    }
    else if (userChoice == 2) {
        dict = new LLDict<string, string>();
    }

    dict->insert("dog", "a domesticated fluff ball");
    dict->insert("igloo", "a cool house");
    dict->insert("banana", "a fruit that many like, or a phone");
    dict->insert("haskell", "fantastic programming language, go learn it");
    dict->insert("graph", "an awesome data structure!");
    dict->insert("quack", "said Mr. Duck");
    dict->insert("phoenix", "a bird on fire");
    dict->insert("cactus", "a pointy plant");

    cout << "Welcome to my dictionary program!\n";
    cout << "Here are your options:\n";
    cout << "\t1. Find\n";
    cout << "\t2. Insert\n";
    cout << "\t3. Remove\n";
    cout << "\t4. Sort\n";
    cout << "\t5. Size\n";
    cout << "\t6. Clear\n";
    cout << "\t7. Print\n";
    cout << "\t8. Quit\n";

    do {
        cout << "Enter your option: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                try {
                    cout << "Enter a key to search my dictionary: ";
                    cin.ignore();
                    getline(cin, userWord);
                    s = dict->find(userWord);
                    cout << s << endl;
                }
                catch (...) { }
                break;

            case 2:
                cout << "Enter the key of the new record: ";
                cin.ignore();
                getline(cin, userWord);
                cout << "Enter the value of the new record: ";
                getline(cin, s);
                dict->insert(userWord, s);
                break;

            case 3:
                cout << "Enter the key of the record to be "
                     << "removed from my dictionary: ";
                cin.ignore();
                getline(cin, userWord);
                dict->remove(userWord);
                break;

            case 4:
                do {
                    cout << "What kind of sort algorithm should be used?\n"
                         << "\t1. Bubble sort\n"
                         << "\t2. Selection sort\n"
                         << "\t3. Insertion sort\n"
                         << "\t4. Merge sort\n"
                         << "\t5. Quicksort\n";
                    cin >> userChoice;
                } while (userChoice < 1 || userChoice > 5);
                dict->sort(userChoice);
                break;

            case 5:
                cout << "Dictionary size is " << dict->size() << endl;
                break;

            case 6:
                cout << "Clearing out my dictionary . . . ";
                dict->clear();
                cout << "cleared!\n";
                break;

            case 7:
                dict->print();
                break;

            case 8:
                flag = true;
                break;
        }
    } while (!flag);

    delete dict;

    return 0;
}
