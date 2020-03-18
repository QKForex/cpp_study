// Copyright (c) 2020 by Chrono
//
// apt install python3-pip
// pip3 install pybind11
//
// apt install python3-dev
// mkdir build && cd build
// cmake .. -DPYBIND11_TEST=OFF
//
// g++ pybind.cpp -std=c++11 -shared -fPIC `python3 -m pybind11 --includes` -o pydemo`python3-config --extension-suffix`
// g++ pybind.cpp -std=c++14 -shared -fPIC `python3 -m pybind11 --includes` -o pydemo`python3-config --extension-suffix`

#include <iostream>

#include <pybind11/pybind11.h>

using namespace std;

class Point final
{
private:
    int x = 0;
public:
    Point() = default;
   ~Point() = default;

    Point(int a) : x(a) {}
public:
    int get() const
    {
        return x;
    }

    void set(int a)
    {
        x = a;
    }
};

PYBIND11_MODULE(pydemo, m)
{
    m.doc() = "pybind11 demo doc";

    m.def("info",
        []()
        {
            cout << "c++ version = " << __cplusplus << endl;
            cout << "gcc version = " << __VERSION__ << endl;
            cout << "libstdc++   = " << __GLIBCXX__ << endl;
        }
    );

    m.def("add",
        [](int a, int b)
        {
            return a + b;
        }
    );

    pybind11::class_<Point>(m, "Point")
        .def(pybind11::init())
        .def(pybind11::init<int>())
        .def("get", &Point::get)
        .def("set", &Point::set)
        ;
}

#if 0
void info()
{
    cout << "c++ version = " << __cplusplus << endl;
    cout << "gcc version = " << __VERSION__ << endl;
    cout << "libstdc++   = " << __GLIBCXX__ << endl;
}

int add(int a, int b)
{
    return a + b;
}

PYBIND11_MODULE(pydemo, m)
{
    m.doc() = "pybind11 demodoc";

    m.def("info", &info, "cpp info");
    m.def("add", &add, "add func");
}
#endif

#if 0

int main()
{
    cout << "pybind demo" << endl;
}
#endif
