#include "vector_impl.h"

Vector::Vector() = default;

Vector::Vector(const size_t sz) : sz(sz), cap(sz){
    arr = new int[sz];
    for (size_t i = 0; i < sz; i++) {
        arr[i] = 0;
    }
}

Vector::Vector(const std::initializer_list<int> list) : sz(list.size()), cap(list.size()) {
    arr = new int[sz];
    size_t i = 0;
    for (const int val : list) {
        arr[i++] = val;
    }
}

Vector::Vector(const Vector& other) : sz(other.sz), cap(other.cap) {
    arr = new int[cap];
    for (size_t i = 0; i < sz; i++) {
        arr[i] = other.arr[i];
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) return *this;
    delete[] arr;
    sz = other.sz;
    cap = other.cap;
    arr = new int[cap];
    for (size_t i = 0; i < sz; i++) {
        arr[i] = other.arr[i];
    }
    return *this;
}

const int& Vector::operator[](const size_t idx) const {
    if (idx >= sz) {
        throw std::out_of_range("Index out of range");
    }
    return arr[idx];
}

int& Vector::operator[](const size_t idx) {
    if (idx >= sz) {
        throw std::out_of_range("Index out of range");
    }
    return arr[idx];
}

void Vector::Swap(Vector& other) {
    std::swap(sz, other.sz);
    std::swap(cap, other.cap);
    std::swap(arr, other.arr);
}

const int& Vector::At(const size_t idx) const {
    if (idx >= sz) {
        throw std::out_of_range("Index out of range");
    }
    return arr[idx];
}

int& Vector::At(const size_t idx) {
    if (idx >= sz) {
        throw std::out_of_range("Index out of range");
    }
    return arr[idx];
}

size_t Vector::Size() const {
    return sz;
}

size_t Vector::Capacity() const {
    return cap;
}

void Vector::PushBack(const int val) {
    if (sz >= cap) {
        Reserve(cap == 0 ? 1 : cap * 2);
    }
    arr[sz++] = val;
}

void Vector::PopBack() {
    if (sz == 0) {
        throw std::out_of_range("Vector is empty");
    }
    sz--;
}

void Vector::Clear() {
    sz = 0;
}   


void Vector::Reserve(size_t new_cap) {
    if (new_cap <= cap) return;
    int* new_arr = new int[new_cap];
    for (size_t i = 0; i < sz; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    cap = new_cap;
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    out << "[";
    for (size_t i = 0; i < v.sz; i++) {
        out << v.arr[i];
        if (i < v.sz - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

Vector::~Vector() {
    cap = 0;
    sz = 0;
    delete[] arr;
}