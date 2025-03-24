#include<iostream>

using namespace std;

template<class t>
class List {
protected:
	t* arr;
	int maxSize;
	int currentSize;
public:
	List(t* a, int ms, int cs)
	{
		arr = a;
		maxSize = ms;
		currentSize = cs;
	}
	virtual void addElementAtFirstIndex(Type) = 0;
	virtual void addElementAtLastIndex(Type) = 0;
	virtual t removeElementFromEnd() = 0;
	virtual void removeElementFromStart() = 0;
	virtual void display() = 0;

	List(List& other) {
		arr = other.arr;
		maxSize = other.maxSize;
		currentSize = other.currentSize;
	}

	~List() {
		Cout << "Destructor called! " << endl;
	}
};

class Derived :public List {
protected:
	int* arr;
	int maxSize;
	int currentSize;
public:
	Derived(int* a, int ms, int cs) : List(a, ms, cs)
	{
		arr = a;
		maxSize = ms;
		currentSize = cs;
	}
	void addElementAtFirstIndex(Type) {
		if (currentSize < maxSize) {
			for (int i = currentSize; i > 0; i--) {
				arr[i] = arr[i - 1];
			}
			arr[0] = Type;
			currentSize++;
		}
		else {
			cout << "List is full!" << endl;
		}
	}
	void addElementAtLastIndex(Type) {
		if (currentSize < maxSize) {
			arr[currentSize] = Type;
			currentSize++;
		}
		else {
			cout << "List is full!" << endl;
		}
	}
	t removeElementFromEnd() {
		if (currentSize > 0) {
			currentSize--;
			return arr[currentSize];
		}
		else {
			cout << "List is empty!" << endl;
		}
	}
	void removeElementFromStart() {
		if (currentSize > 0) {
			for (int i = 0; i < currentSize - 1; i++) {
				arr[i] = arr[i + 1];
			}
			currentSize--;
		}
		else {
			cout << "List is empty!" << endl;
		}
	}
	void display() {
		for (int i = 0; i < currentSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	Derived(Derived& other) : List(other) {
		arr = other.arr;
		maxSize = other.maxSize;
		currentSize = other.currentSize;
	}
	~Derived() {
		cout << "Destructor called! " << endl;
	}
};


int main()
{
	int arr[5] = { 1,2,3,4,5 };
	Derived d(arr, 5, 5);
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