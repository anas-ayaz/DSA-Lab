#include <iostream>
using namespace std;

template <class T>
class List {
protected:
    T* arr;
    int maxSize;
    int currentSize;

public:
    List(int ms) {
        maxSize = ms;
        currentSize = 0;
        arr = new T[maxSize];
    }

    virtual void addElementAtFirstIndex(T value) = 0;
    virtual void addElementAtLastIndex(T value) = 0;
    virtual T removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;
    virtual void display() = 0;

    virtual ~List() { delete[] arr; }
};

template <class T>
class Derived : public List<T> {
public:
    Derived(int ms) : List<T>(ms) {}

    void addElementAtFirstIndex(T value) {
        if (this->currentSize < this->maxSize) {
            for (int i = this->currentSize; i > 0; i--) {
                this->arr[i] = this->arr[i - 1];
            }
            this->arr[0] = value;
            this->currentSize++;
        } else {
            cout << "List is full!" << endl;
        }
    }

    void addElementAtLastIndex(T value) {
        if (this->currentSize < this->maxSize) {
            this->arr[this->currentSize] = value;
            this->currentSize++;
        } else {
            cout << "List is full!" << endl;
        }
    }

    T removeElementFromEnd() {
        if (this->currentSize > 0) {
            this->currentSize--;
            return this->arr[this->currentSize];
        } else {
            cout << "List is empty!" << endl;
            return T();
        }
    }

    void removeElementFromStart() {
        if (this->currentSize > 0) {
            for (int i = 0; i < this->currentSize - 1; i++) {
                this->arr[i] = this->arr[i + 1];
            }
            this->currentSize--;
        } else {
            cout << "List is empty!" << endl;
        }
    }

    void display() {
        for (int i = 0; i < this->currentSize; i++) {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Derived<int> d(5);
    d.addElementAtLastIndex(1);
    d.addElementAtLastIndex(2);
    d.addElementAtLastIndex(3);
    d.addElementAtLastIndex(4);
    d.addElementAtLastIndex(5);

    d.display();
    d.addElementAtFirstIndex(0);
    d.display();
    d.addElementAtLastIndex(6);
    d.display();
    d.removeElementFromEnd();
    d.display();
    d.removeElementFromStart();
    d.display();
    return 0;
}
