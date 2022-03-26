//Threading
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

//penambahan delay/waktu dalam thread
void delay(int t) {
	this_thread::sleep_for(chrono::milliseconds(t));
}

//oddnumber dengan bilangan ganjil
void oddnumber(int x) {
	for (int i = 1; i <= x; i++) {
		if (i % 2 != 0) {
			delay(1000);//delay selama 1 second
			cout << "Antrean No." << i << " (Oddnumber)" << endl;
			cout << "waktu delay 1 second" << endl << endl;
		}
	}
}

//evennumber dengan bilangan genap
void evennumber(int y) {
	for (int i = 1; i <= y; i++) {
		if (i % 2 == 0) {
			delay(2500);//delay selama 2,5 second
			cout << "Antrean No." << i << " (evennumber)" << endl;
			cout << "waktu delay 2.5 seconds" << endl << endl;
		}
	}
}

int main() {
	//berfungsi sebagai print out odd dan evennumber
	thread Guwi(oddnumber, 26);
	thread Dwi (evennumber, 26);

	//untuk synchronization thread.
	//dan memastikan thread hingga selesai.
	Guwi .join();
	Dwi .join();

	cout << "Tidak ada antrean lagi!" << endl;
	return 0;
}