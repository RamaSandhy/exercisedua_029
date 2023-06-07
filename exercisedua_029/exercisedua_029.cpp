#include <iostream>
#include <cmath>

using namespace std;

class bidangDatar {
private:
    int x; // variabel untuk menyimpan Input dari lingkaran maupun bujursangkar

public:
    bidangDatar() { // constructor
        x = 0;
    }
    
    virtual void input() = 0; // fungsi yang menerima input dan mengirim input melalui fungsi setx untuk disimpan di x
    virtual float Luas() = 0; // fungsi untuk menghitung luas
    virtual float Keliling() = 0; // fungsi untuk menghitung keliling
    void setx(int a) { // fungsi untuk memberi/mengirin nilal pada x
        this->x = a;
    }

    int getx() { // fungsi untuk membaca/mengambil nilai dalam x
        return x;
    }
};

class Lingkaran : public bidangDatar {
public:
    void input() {
        cout << "Masukkan jejari: ";
        int r;
        cin >> r;
        setx(r);
    }

    float Luas() {
        float r = getx();
        return 3.14 * r * r;
    }

    float Keliling() {
        float r = getx();
        return 2 * 3.14 * r;
    }
};

class Bujursangkar : public bidangDatar {
    void input() {
        cout << "Masukkan sisi kanan dan kiri: ";
        int s;
        cin >> s;
        setx(s);
    }

    float Luas() {
        int s = getx();
        return s * s;
    }

    float Keliling() {
        int s = getx();
        return 4 * s;
    };

};

int main() {
    bidangDatar* obj;

    // Membuat objek Lingkaran
    cout << "Lingkaran dibuat" << endl;
    obj = new Lingkaran();
    obj->input();
    cout << "Luas Lingkaran: " << obj->Luas() << endl;
    cout << "Keliling Lingkaran: " << obj->Keliling() << endl;

    // Membuat objek Bujursangkar
    cout << endl << "Bujursangkar dibuat" << endl;
    obj = new Bujursangkar();
    obj->input();
    cout << "Luas Bujursangkar: " << obj->Luas() << endl;
    cout << "Keliling Bujursangkar: " << obj->Keliling() << endl;

    delete obj; // Menghapus objek

    return 0;
}

