#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template<typename T>
class Array {
public:
    T* data;
    int size;

    Array(int n) : size(n) {
        data = new T[size];
    }

    ~Array() {
        delete[] data;
    }

    friend istream& operator>>(istream& in, Array<T>& arr) {
        for (int i = 0; i < arr.size; i++) {
            in >> arr.data[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Array<T>& arr) {
        for (int i = 0; i < arr.size; i++) {
            out << arr.data[i] << " ";
        }
        return out;
    }

    T& operator[](int i) {
        if (i < 0 || i >= size) {
            cout << "Out of boundary!" << endl;
            exit(1);
        }
        return data[i];
    }

    void sort() {
        std::sort(data, data + size);
    }

    int search(T e) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == e) {
                return i;
            }
        }
        return -1;
    }
};

template<typename T>
void Process(Array<T> &a) {
    int pos;
    T key;
    cin >> a;
    cout << a << endl;
    a.sort();
    cout << a << endl;
    cin >> pos;
    cout << a[pos] << endl;
    cin >> key;
    int index = a.search(key);
    cout << index << endl;
}

int main() {
    string type;
    int n;

    cin >> type >> n;
    if (type == "int") {
        Array<int> a(n);
        Process(a);
    } else if (type == "double") {
        Array<double> a(n);
        Process(a);
    } else if (type == "string") {
        Array<string> a(n);
        Process(a);
    } else {
        cout << "Input error!" << endl;
    }

    return 0;
}
