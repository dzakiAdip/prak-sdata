#include <iostream> // Perbaiki: Gunakan <iostream> tanpa .h di C++ modern (header standar)

#define maks 5 // Mendefinisikan ukuran maksimal queue menjadi 5

class Queue {
    friend std::ostream& operator<<(std::ostream&, const Queue&); // Perbaiki: Perlu menggunakan std::ostream untuk operator overload
public:
    Queue(); // Konstruktor untuk inisialisasi objek Queue
    int penuh(int); // Fungsi untuk mengecek apakah queue penuh
    int kosong(int); // Fungsi untuk mengecek apakah queue kosong
    void cetak(); // Fungsi untuk menampilkan isi queue
    void enqueue(char); // Fungsi untuk menambahkan elemen ke dalam queue
    char dequeue(); // Fungsi untuk mengeluarkan elemen dari queue
private:
    char A[maks]; // Array untuk menampung elemen queue
    int banyak; // Variabel untuk menyimpan jumlah elemen dalam queue
};

std::ostream& operator<<(std::ostream& out, const Queue& s) { // Perbaiki: std::ostream untuk operator overload
    out << "\nIsi Queue : "; // Menampilkan judul untuk isi queue
    for (int i = 0; i < s.banyak; i++) // Loop untuk menampilkan semua elemen dalam queue
        out << s.A[i] << " "; // Menampilkan setiap elemen dalam queue
    return out; // Mengembalikan objek ostream untuk memungkinkan chaining operator <<
}

Queue::Queue() {
    banyak = 0; // Inisialisasi jumlah elemen menjadi 0
    for (int i = 0; i < maks; i++) // Inisialisasi array A dengan karakter '0'
        A[i] = '0';
}

int Queue::penuh(int s) {
    return s == maks ? 1 : 0; // Mengembalikan 1 jika queue penuh (jumlah elemen == maks), 0 jika tidak
}

int Queue::kosong(int s) {
    return s == 0 ? 1 : 0; // Mengembalikan 1 jika queue kosong (jumlah elemen == 0), 0 jika tidak
}

void Queue::cetak() {
    std::cout << "\nIsi Queue : "; // Menampilkan judul untuk isi queue
    for (int i = 0; i < banyak; i++) // Loop untuk menampilkan setiap elemen dalam queue
        std::cout << A[i] << " "; // Menampilkan elemen queue satu per satu
}

void Queue::enqueue(char x) {
    std::cout << "\nElemen : " << x << " masuk antrian"; // Menampilkan pesan bahwa elemen masuk ke dalam queue
    if (penuh(banyak)) // Jika queue penuh
        std::cout << " queue penuh"; // Menampilkan pesan bahwa queue penuh
    else if (A[0] == '0') { // Jika queue kosong (indikasikan dengan A[0] == '0')
        A[0] = x; // Menambahkan elemen di posisi pertama
        banyak++; // Menambah jumlah elemen
    } else {
        for (int i = banyak; i >= 0; i--) { // Loop untuk menggeser elemen-elemen ke kanan agar ada ruang di posisi pertama
            A[i + 1] = A[i]; // Geser elemen ke kanan
        }
        A[0] = x; // Menambahkan elemen baru di posisi pertama
        banyak++; // Menambah jumlah elemen
    }
}

char Queue::dequeue() {
    char temp = A[--banyak]; // Mengambil elemen dari posisi terakhir dan mengurangi jumlah elemen
    std::cout << "\nDequeue elemen --> " << temp; // Menampilkan pesan bahwa elemen telah dikeluarkan
    A[banyak] = '0'; // Mengatur posisi elemen yang dikeluarkan menjadi '0'
    return temp; // Mengembalikan elemen yang dikeluarkan
}

int main() { // Fungsi main harus mendeklarasikan tipe return 'int'
    Queue q; // Membuat objek Queue
    for (char c = 'a'; c < 'd'; c++) { // Loop untuk memasukkan karakter 'a' sampai 'c' ke dalam queue
        q.enqueue(c); // Menambahkan elemen ke dalam queue
        std::cout << q; // Menampilkan isi queue menggunakan operator overload <<
    }
    char p = q.dequeue(); // Mengeluarkan elemen dari queue dan menyimpannya di variabel p
    q.cetak(); // Menampilkan isi queue setelah operasi dequeue
    std::cout << "\n\nCetak pakai overloading : " << q; // Menampilkan isi queue menggunakan operator overload <<
    return 0; // Mengembalikan nilai 0 menandakan bahwa program berjalan dengan sukses
}
