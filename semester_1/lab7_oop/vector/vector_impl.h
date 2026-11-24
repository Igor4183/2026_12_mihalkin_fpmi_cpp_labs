#pragma once
#include <initializer_list>
#include <iostream>
#include <iosfwd>
#include <stdexcept>
#include <utility>

class Vector {
    size_t sz = 0;
    size_t cap = 0;
    int* arr = nullptr;

public:
    Vector();
    Vector(const size_t sz);
    Vector(const std::initializer_list<int> list);
    Vector(const Vector& other);

    Vector& operator=(const Vector& other);
    const int& operator[](const size_t idx) const;
    int& operator[](const size_t idx);

    void Swap(Vector& other);
    const int& At(const size_t idx) const;
    int& At(const size_t idx);
    size_t Size() const;
    size_t Capacity() const;
    void PushBack(const int val);
    void PopBack();
    void Clear();
    void Reserve(size_t new_cap);

    friend std::ostream& operator<<(std::ostream& out, const Vector& v);

    ~Vector();
};
