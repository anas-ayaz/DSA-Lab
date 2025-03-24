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

	virtual bool empty() = 0;
	virtual bool full() = 0;
	virtual int size() = 0;
	virtual bool insertAt() = 0;
	virtual t last() = 0;
	virtual bool search() = 0;



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

	bool empty() {
		return currentSize == 0;
	}

	bool full() {
		return currentSize == maxSize;
	}

	int size() {
		return currentSize;
	}

	bool insertAt(int index, Type value) {
		if (currentSize < maxSize) {
			for (int i = currentSize; i > index; i--) {
				arr[i] = arr[i - 1];
			}
			arr[index] = value;
			currentSize++;
			return true;
		}
		else {
			cout << "List is full!" << endl;
			return false;
		}
	}

	t last() {
		if (currentSize > 0) {
			return arr[currentSize - 1];
		}
		else {
			cout << "List is empty!" << endl;
		}
	}

	bool search(Type value) {
		for (int i = 0; i < currentSize; i++) {
			if (arr[i] == value) {
				return true;
			}
		}
		return false;
	}

	Derived& operator=(Derived& other) {
		if (this != &other) {
			delete[] arr;
			arr = new int[other.maxSize];
			for (int i = 0; i < other.currentSize; i++) {
				arr[i] = other.arr[i];
			}
			maxSize = other.maxSize;
			currentSize = other.currentSize;
		}
		return *this;
	}

	bool search(t) {
		for (int i = 0; i < currentSize; i++) {
			if (arr[i] == value) {
				return true;
			}
		}
		return false;
	}

	t sum_ofPrime() {
		int sum = 0;
		for (int i = 0; i < currentSize; i++) {
			if (isPrime(arr[i])) {
				sum += arr[i];
			}
		}
		return sum;
	}

	int secondMaxEven() {
		int maxEven = int_min;
		int secondMaxEven = int_min;

		for (int i = 0; i < currentSize; i++) {
			if (arr[i] % 2 == 0) {
				if (arr[i] > maxEven) {
					secondMaxEven = maxEven;
					maxEven = arr[i];
				}
				else if (arr[i] > secondMaxEven && arr[i] != maxEven) {
					secondMaxEven = arr[i];
				}
			}
		}

		if (secondMaxEven == int_min) {
			cout << "There is no second maximum even number." << endl;
			return -1; 
		}

		return secondMaxEven;
	}

	int secondMinOdd() {
		int minOdd = int_max;
		int secondMinOdd = int_max;

		for (int i = 0; i < currentSize; i++) {
			if (arr[i] % 2 != 0) {
				if (arr[i] < minOdd) {
					secondMinOdd = minOdd;
					minOdd = arr[i];
				}
				else if (arr[i] < secondMinOdd && arr[i] != minOdd) {
					secondMinOdd = arr[i];
				}
			}
		}

		if (secondMinOdd == int_max) 
		{
			cout << "There is no second smallest odd number." << endl;
			return 0; 
		}

		return secondMinOdd;
	}

	void printDuplicates() {
		bool hasDuplicates = false;
		cout << "Duplicate elements in the array are: ";
		for (int i = 0; i < currentSize; i++) {
			for (int j = i + 1; j < currentSize; j++) {
				if (arr[i] == arr[j]) {
					cout << arr[i] << " ";
					hasDuplicates = true;
					break;
				}
			}
		}
		if (!hasDuplicates) {
			cout << "None";
		}
		cout << endl;
	}

	void rotateClockwise() {
		int temp = arr[currentSize - 1];
		for (int i = currentSize - 1; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = temp;
	}

	void rotateCounterClockwise() {
		int temp = arr[0];
		for (int i = 0; i < currentSize - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[currentSize - 1] = temp;
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
	int arr[5] = { 1,2,3,4,5,6,7,8,9,10 };
	Derived d(arr, 20, 10);
	d.display();

	d.addElementAtFirstIndex(0);
	d.display();

	d.addElementAtLastIndex(6);
	d.display();

	d.removeElementFromEnd();
	d.display();

	d.removeElementFromStart();
	d.display();

	d.full();
	d.insertAt(3, 43);

	cout << "Sum of prime Numbers: " << d.sum_ofPrime() << endl;

	cout << "Second Maximum Even Number: " << d.secondMaxEven() << endl;

	cout << "Second Minimum Odd Number: " << d.secondMinOdd() << endl;

	d.printDuplicates();

	d.rotateClockwise();

	d.rotateCounterClockwise();

	d.display();

	return 0;
}