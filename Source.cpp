#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

class ConstrMat {
	friend class SubControls;
	friend class SupControls;
public:
	int _cypher;
	int _stock;
	double _distance;
	int _amount;
	double _price;
public:
	ConstrMat() : 
		_cypher{ 0 }, 
		_stock{ 0 }, 
		_distance{ 0 }, 
		_amount{ 0 },
		_price{ 0 }
	{};
	~ConstrMat() {};
	ConstrMat(const ConstrMat& i) : 
		_cypher{ i._cypher }, 
		_stock{ i._stock }, 
		_distance{ i._distance }, 
		_amount{ i._amount }, 
		_price{ i._price } 
	{};
	const ConstrMat& operator = (const ConstrMat& i) {
		if (this != &i) {
			this->_cypher = i._cypher;
			this->_stock = i._stock;
			this->_distance = i._distance;
			this->_amount = i._amount;
			this->_price = i._price;
		}
		return *this;
	}
};

class SubControls {
	friend class SupControls;
private:
	int Amount;
public:
	void setCypher(ConstrMat& i, int n) {
		i._cypher = n;
	}
	void setStock(ConstrMat& i, int n) {
		i._stock = n;
	}
	void setDistance(ConstrMat& i, double n) {
		i._distance = n;
	}
	void setAmount(ConstrMat& i, int n) {
		i._amount = n;
	}
	void setPrice(ConstrMat& i, double n) {
		i._price = n;
	}

	void writeMat(const ConstrMat& i, ofstream& out) {
		out << i._cypher << ' ' << i._stock << ' ' << i._distance << ' ' << i._amount << ' ' << i._price << endl;
	}
	void readMat(ConstrMat& i, ifstream& inp) {
		inp >> i._cypher; 
		inp >> i._stock;
		inp >> i._distance;
		inp >> i._amount;
		inp >> i._price;
	}

	void writeArrMat(const ConstrMat* ptr, const int size) {
		ofstream out("d://memory.txt");
		Amount = size;
		out << Amount << endl;
		for (int i = 0; i < size; i++)
			writeMat(ptr[i], out);
		out.close();
	}
	void readArrMat(ConstrMat*& ptr) {
		ifstream inp("d://memory.txt");
		//inp.seekg(subAmount(Amount));
		inp >> Amount;
		ptr = new ConstrMat[Amount];
		for (int i = 0; i < Amount; i++) {
			readMat(ptr[i], inp);
		}
		inp.close();
	}
	int subAmount(int digit) {
		int counter = 0;
		while ((digit /= 10) > 0) counter++;
		return counter;
	}
};

class SupControls {
	friend class SubControls;
public:
	void printMat(ConstrMat& i, const int index) {
		const int p = 15;
		cout 
			<< left
			<< setw(2)
			<< index 
			<< right
			<< setw(p) 
			<< i._cypher 
			<< setw(p) 
			<< i._stock 
			<< setw(p) 
			<< i._distance 
			<< setw(p) 
			<< i._amount 
			<< setw(p) 
			<< i._price 
			<< endl;
	}
	void printArrMat(ConstrMat* ptr, const int size) {
		const int p = 17;
		cout
			<< right
			<< setw(p)
			<< "Шифр"
			<< setw(p)
			<< "Номер"
			<< setw(p)
			<< "Расстояние"
			<< setw(p)
			<< "Количество"
			<< setw(p)
			<< "Цена"
			<< endl;
		for (int i = 0; i < size; i++) printMat(ptr[i], i + 1);
	}
	void createMat() {
		ConstrMat* ptr, * tmp;
		SubControls subControl;
		subControl.readArrMat(ptr);
		subControl.Amount++;
		tmp = new (nothrow) ConstrMat[subControl.Amount];
		memcpy(tmp, ptr, 32*(subControl.Amount-1));
		cout << "Введите шифр материала: ";
		cin >> tmp[subControl.Amount - 1]._cypher;
		cout << "\nВведите номер склада с материалом: ";
		cin >> tmp[subControl.Amount - 1]._stock;
		cout << "\nВведите расстояние до склада: ";
		cin >> tmp[subControl.Amount - 1]._distance;
		cout << "\nВведите количество материала: ";
		cin >> tmp[subControl.Amount - 1]._amount;
		cout << "\nВведите цену материала: ";
		cin >> tmp[subControl.Amount - 1]._price;
		subControl.writeArrMat(tmp, subControl.Amount);
	}
	void deleteMat() {
		ConstrMat* ptr;
		SubControls subControl;
		subControl.readArrMat(ptr);
		int pos;
		cout << "Введите номер удаляемого элемента: ";
		cin >> pos;
		for (int i = --pos; i < subControl.Amount - 1; i++) ptr[i] = ptr[i + 1];
		subControl.Amount--;
		subControl.writeArrMat(ptr, subControl.Amount);
	}
	void editMat() {
		ConstrMat* ptr;
		SubControls subControl;
		subControl.readArrMat(ptr);
		int pos;
		printArrMat(ptr, subControl.Amount);
		cout << "Введите номер редактируемого элемента: ";
		cin >> pos;
		printMat(ptr[pos - 1], pos);
		cout << "Выберите замену: ";
		while (true) {
			int choice;
			cout << "1) Шифр\n2) Номер\n3) Расстояние\n4) Количество\n5) Цена\n6) Сохранить\n ";
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "Введите значение: ";
				cin >> ptr[pos - 1]._cypher;
				printMat(ptr[pos - 1], pos);
				break;
			case 2:
				cout << "Введите значение: ";
				cin >> ptr[pos - 1]._stock;
				printMat(ptr[pos - 1], pos);
				break;
			case 3:
				cout << "Введите значение: ";
				cin >> ptr[pos - 1]._distance;
				printMat(ptr[pos - 1], pos);
				break;
			case 4:
				cout << "Введите значение: ";
				cin >> ptr[pos - 1]._amount;
				printMat(ptr[pos - 1], pos);
				break;
			case 5:
				cout << "Введите значение: ";
				cin >> ptr[pos - 1]._price;
				printMat(ptr[pos - 1], pos);
				break;
			case 6:
				subControl.writeArrMat(ptr, subControl.Amount);
				printArrMat(ptr, subControl.Amount);
				return;
			}
		}
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	ConstrMat Materials[10];
	SubControls subControl;
	SupControls supControl;
	ifstream inp("d://memory.txt");
	supControl.editMat();

	//subControl.readArrMat(Materials);

	//supControl.printArrMat(Materials, 10);

	system("pause");
	return 0;
}