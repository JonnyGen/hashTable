#include <iostream>
#include <list>
#include <vector>
#include <ctime>

using namespace std;

class HashTable {
private:
    int size;
    vector<list<int>> table;

    // Hash function to map values to indexes
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    // Insert value into hash table
    void insert(int value) {
        clock_t start = clock();

        int index = hashFunction(value);
        table[index].push_back(value);

        clock_t end = clock();
        double elapsedTime = double(end - start) / CLOCKS_PER_SEC;
        cout << "Insertion time: " << elapsedTime << " seconds" << endl;
    }

    // Search for a value in the hash table
    bool search(int value) {
        clock_t start = clock();

        int index = hashFunction(value);
        for (int item : table[index]) {
            if (item == value) {
                clock_t end = clock();
                double elapsedTime = double(end - start) / CLOCKS_PER_SEC;
                cout << "Search time: " << elapsedTime << " seconds" << endl;
                return true;
            }
        }

        clock_t end = clock();
        double elapsedTime = double(end - start) / CLOCKS_PER_SEC;
        cout << "Search time: " << elapsedTime << " seconds" << endl;
        return false;
    }

    // Remove a value from the hash table
    void remove(int value) {
        clock_t start = clock();

        int index = hashFunction(value);
        table[index].remove(value);

        clock_t end = clock();
        double elapsedTime = double(end - start) / CLOCKS_PER_SEC;
        cout << "Removal time: " << elapsedTime << " seconds" << endl;
    }

    // Print the contents of the hash table
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << "Index " << i << ": ";
            for (int item : table[i]) {
                cout << item << " -> ";
            }
            cout << "item" << endl;
        }
    }
};

int main() {
    // Create a hash table with size
    HashTable hashTable(100000);
    for (int i=0; i<100; i++)
    {
        hashTable = 1 + rand() % 100;

        hashTable.insert(i);
    }
    
    // Insert some values
    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(15);
    hashTable.insert(60);
    hashTable.insert(80);
    hashTable.insert(150);
    // Display the hash table
    cout << "Hash Table contents after insertion:" << endl;
    hashTable.display();

    // Search for a value
    cout << "Searching for 20: " << (hashTable.search(15) ? "Found" : "Not Found") << endl;

    // Remove a value
    hashTable.remove(20);
    cout << "Hash Table contents after removal:" << endl;
    hashTable.display();

    return 0;
}
