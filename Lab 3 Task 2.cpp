#include <iostream>

using namespace std;

template <class t>
class List {
protected:
    t* arr;
    int maxSize;
    int currentSize;
public:
    List(t* a, int ms, int cs) {
        arr = new t[ms];
        for (int i = 0; i < cs; i++) {
            arr[i] = a[i];
        }
        maxSize = ms;
        currentSize = cs;
    }

    virtual void addElementAtFirstIndex(t) = 0;
    virtual void addElementAtLastIndex(t) = 0;
    virtual t removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;
    virtual void display() = 0;
    virtual bool empty() = 0;
    virtual bool full() = 0;
    virtual int size() = 0;
    virtual bool insertAt(int, t) = 0;
    virtual t last() = 0;
    virtual bool search(t) = 0;

    List(const List& other) {
        arr = new t[other.maxSize];
        for (int i = 0; i < other.currentSize; i++) {
            arr[i] = other.arr[i];
        }
        maxSize = other.maxSize;
        currentSize = other.currentSize;
    }

    virtual ~List() {
        delete[] arr;
    }
};

template <class t>
class Derived : public List<t> {
public:
    Derived(t* a, int ms, int cs) : List<t>(a, ms, cs) {}

    void addElementAtFirstIndex(t value) {
        if (this->currentSize < this->maxSize) {
            for (int i = this->currentSize; i > 0; i--) {
                this->arr[i] = this->arr[i - 1];
            }
            this->arr[0] = value;
            this->currentSize++;
        }
    }

    void addElementAtLastIndex(t value) {
        if (this->currentSize < this->maxSize) {
            this->arr[this->currentSize++] = value;
        }
    }

    t removeElementFromEnd() {
        if (this->currentSize > 0) {
            return this->arr[--this->currentSize];
        }
        return t();
    }

    void removeElementFromStart() {
        if (this->currentSize > 0) {
            for (int i = 0; i < this->currentSize - 1; i++) {
                this->arr[i] = this->arr[i + 1];
            }
            this->currentSize--;
        }
    }

    void display() {
        for (int i = 0; i < this->currentSize; i++) {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }

    bool empty() { return this->currentSize == 0; }
    bool full() { return this->currentSize == this->maxSize; }
    int size() { return this->currentSize; }

    bool insertAt(int index, t value) {
        if (index < 0 || index > this->currentSize || this->full()) {
            return false;
        }
        for (int i = this->currentSize; i > index; i--) {
            this->arr[i] = this->arr[i - 1];
        }
        this->arr[index] = value;
        this->currentSize++;
        return true;
    }

    t last() {
        if (this->currentSize > 0) {
            return this->arr[this->currentSize - 1];
        }
        return t();
    }

    bool search(t value) {
        for (int i = 0; i < this->currentSize; i++) {
            if (this->arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    Derived& operator=(const Derived& other) {
        if (this != &other) {
            delete[] this->arr;
            this->arr = new t[other.maxSize];
            for (int i = 0; i < other.currentSize; i++) {
                this->arr[i] = other.arr[i];
            }
            this->maxSize = other.maxSize;
            this->currentSize = other.currentSize;
        }
        return *this;
    }

    Derived(const Derived& other) : List<t>(other) {}
};

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    Derived<int> d(arr, 10, 5);
    d.display();
    d.addElementAtFirstIndex(0);
    d.display();
    d.addElementAtLastIndex(6);
    d.display();
    d.removeElementFromEnd();
    d.display();
    d.removeElementFromStart();
    d.display();
    d.insertAt(3, 43);
    d.display();
    return 0;
}
