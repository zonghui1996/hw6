#ifndef LL_DICT_HPP
#define LL_DICT_HPP

#include "Dictionary.hpp"
#include "LinkedList.hpp"
#include <iomanip>

template <typename Key, typename Val>
class LLDict : public Dictionary<Key, Val> {
    private:
        // an element in a dictionary, contains a key and a value
        struct Record {
            Key k;
            Val v;

            // constructors
            Record() : k(Key()), v(Val()) { }
            Record(Key x, Val y) : k(x), v(y) { }

            // overloaded relational operators
            bool operator<(Record& rightObj) const { return this->k < rightObj.k; }
            bool operator<=(Record& rightObj) const { return this->k <= rightObj.k; }
            bool operator>(Record& rightObj) const { return this->k > rightObj.k; }
            bool operator>=(Record& rightObj) const { return this->k >= rightObj.k; }
            bool operator==(Record& rightObj) const { return this->k == rightObj.k; }
            bool operator!=(Record& rightObj) const { return this->k != rightObj.k; }
        };

        // the underlying linked list
        LinkedList<Record>* list;

    public:
        // default constructor
        LLDict();

        // destructor
        virtual ~LLDict();

        // remove all records in the dictionary
        virtual void clear() override;

        // retrieve the record that matches the argument key
        // if multiple records match, return an arbitrary one
        virtual Val find(const Key&) const override;

        // add the record as a key-value pair to the dictionary
        virtual void insert(const Key&, const Val&) override;

        // print the records in the dictionary
        virtual void print() const override;

        // remove the record that matches the argument key from the dictionary
        // if multiple records match, remove an arbitrary one
        virtual void remove(const Key&) override;

        // return the number of records in the dictionary
        virtual int size() const override;

        // sort the records in the dictionary using the algorithm (argument 1)
        //      1 --> bubble sort
        //      2 --> selection sort
        //      3 --> insertion sort
        //      4 --> merge sort
        virtual void sort(int) override;
};

template <typename Key, typename Val>
LLDict<Key, Val>::LLDict() {
    list = new LinkedList<Record>;
}

template <typename Key, typename Val>
LLDict<Key, Val>::~LLDict() {
    delete list;
}

template <typename Key, typename Val>
void LLDict<Key, Val>::clear() {
    list->clear();
}

template <typename Key, typename Val>
Val LLDict<Key, Val>::find(const Key& target) const {
    Record r;

    for (int i = 0; i < list->getLength(); i++) {
        r = list->getElement(i);
        if (r.k == target) {
            return r.v;
        }
    }

    cout << "ERROR: unable to find record\n";
    throw -1;
}

template <typename Key, typename Val>
void LLDict<Key, Val>::insert(const Key& k, const Val& v) {
    list->append(Record(k, v));
}

template <typename Key, typename Val>
void LLDict<Key, Val>::print() const {
    const char FILL = '-';
    const int WIDTH = 80;
    const int SLOT_WIDTH = 4;
    const int KEY_WIDTH = 25;
    Record r;

    if (size() == 0) {
        cout << "Dictionary is empty!\n";
        return;
    }

    cout << setfill(FILL) << setw(WIDTH) << "" << endl << setfill(' ');

    for (int i = 0; i < list->getLength(); i++) {
        r = list->getElement(i);
        cout << right << setw(SLOT_WIDTH) << i << " | "
             << left << setw(KEY_WIDTH)
             << r.k << " | " << r.v << endl;
    }

    cout << setfill(FILL) << setw(WIDTH) << "" << endl;
}

template <typename Key, typename Val>
void LLDict<Key, Val>::remove(const Key& k) {
    bool flag = false;

    for (int i = 0; i < list->getLength(); i++) {
        if (list->getElement(i).k == k) {
            list->remove(i);
            flag = true;
            break;
        }
    }

    if (!flag) {
        cout << "Unable to find record with matching key to remove\n";
    }
}

template <typename Key, typename Val>
int LLDict<Key, Val>::size() const {
    return list->getLength();
}

template <typename Key, typename Val>
void LLDict<Key, Val>::sort(int algo) {
    list->sort(algo);
}

#endif
