#include <iostream>
#include <vector>
class priorityQueue {
public:
	std::vector<int> data;
	void maxHeapify(int i) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left<data.size() && data[left]>data[largest])
			largest = left;
		if (right<data.size() && data[right]>data[largest])
			largest = right;
		if (largest != i) {
			std::swap(data[largest], data[i]);
			maxHeapify(largest);
		}
	}
	void extractMax() {
		data[0] = data[data.size() - 1];
		data.pop_back();
		maxHeapify(0);
	}
	int maxElement() {
		return data[0];
	}
	void increasePriority(int i, int val) {
		if (val > data[i]) {
			data[i] = val;
			int p = (i - 1) / 2;
			while (i > 0 && val > data[p]) {
				data[i] = data[p];
				i = p;
				p = (i - 1) / 2;
			}
			data[i] = val;
		}
	}
	void insert(int val) {
		data.push_back(0);
		increasePriority(data.size() - 1, val);
	}
	void print() {
		for (int i = 0; i < data.size(); i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};
int main()
{
	priorityQueue p;
	int optiune;
	std::cout << "Comanda 1 pentru inserarea unui nou element;" << std::endl;
	std::cout << "Comanda 2 pentru extragerea elementului maxim;" << std::endl;
	std::cout << "Comanda 3 pentru afisarea elementului prioritate maxima;" << std::endl;
	std::cout << "Comanda 4 pentru afisare;" << std::endl;
	std::cout << "Comanda 0 pentru iesire." << std::endl;
	do {
		std::cout << "Alege o optiune: ";
		std::cin >> optiune;
		switch (optiune) {
		case 0:
			break;
		case 1:
			int valoare;
			std::cout << "Inserati: ";
			std::cin >> valoare;
			p.insert(valoare);
			break;
		case 2:
			p.extractMax();
			break;
		case 3:
			std::cout << p.maxElement();
			std::cout << std::endl;
			break;
		case 4:
			p.print();
			break;
		default:
			std::cout << "Optiune invalida." << std::endl;
			break;
		}
	} while (optiune != 0);
	r
		e
		t
		u
		r
		n
		0;
}