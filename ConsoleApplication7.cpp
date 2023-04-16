
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Car {
public:
    string model;
    virtual ~Car() {}
};

class Mercedes : public Car {
public:
    Mercedes(string a) {
        model = a;
    }
    ~Mercedes() {
        cout << "Mercedes " << model << endl;
    }
};

class Audi : public Car {
public:
    Audi(string a) {
        model = a;
    }
    ~Audi() {
        cout << "Audi " << model << endl;
    }
};

int main()
{
    ifstream file;
    file.open("cars.txt");

    vector <Car*> v;
    string temp;

    while (!file.eof()) {
        file >> temp;
        if (temp == "Audi") {
            file >> temp;
            Car* elem = new Audi(temp);
            v.push_back(elem);
        }
        else if (temp == "Mercedes") {
            file >> temp;
            Car* elem = new Mercedes(temp);
            v.push_back(elem);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        delete v[i];
        v[i] = 0;
    }

    return 0;
}