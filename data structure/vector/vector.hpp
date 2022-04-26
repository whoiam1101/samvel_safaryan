#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdexcept>
#include <ostream>

template<typename T>
class Vector {
private:
    T* _array;
    int _capacity;
    int _size;

public:
    // constructors
    Vector();
    Vector(int, const T& = 0);

    // destructor
    ~Vector();

    // capacity
    int capacity() const;

    // size
    int size() const;

    // element by index
    T operator [](int) const;

    // push back
    void pushBack(const T&);

    // pop back
    void popBack();

    // insert
    void insert(int, const T&);

    // erase
    void erase(int);

    // print all elements
    template<typename _T>
    friend std::ostream& operator << (std::ostream&, const Vector<_T>&);
};

// constructors
template<typename T>
Vector<T>::Vector() {
    _array = new T[32];
    _capacity = 32;
    _size = 0;
}

template<typename T>
Vector<T>::Vector(int size, const T& value) {
    if (size < 0) {
        throw std::invalid_argument("Error: vector size cannot be a negative number!(In constructor of Vector)");
    }
    _size = size;
    _capacity = 1;
    while (_capacity < size) {
        _capacity <<= 1;
    }
    _array = new T[_capacity];
    for (int i = 0; i < size; i++) {
        _array[i] = value;
    }
}

// destructor
template<typename T>
Vector<T>::~Vector() {
    delete[] _array;
    _array = new T[32];
    _capacity = 32;
    _size = 0;
}

// capacity
template<typename T>
int Vector<T>::capacity() const {
    return _capacity;
}

// size
template<typename T>
int Vector<T>::size() const {
    return _size;
}

// element by index
template<typename T>
T Vector<T>::operator [](int index) const {
    if (index < 0 || size() <= index) {
        if (size() == 0) {
            throw std::invalid_argument("Error: vector is empty!(operator [])");
        }
        throw std::invalid_argument("Error: out of bounds exception!(operator [])");
    }
    return _array[index];
}

// push back
template<typename T>
void Vector<T>::pushBack(const T& value) {
    insert(size(), value);
}

// pop back
template<typename T>
void Vector<T>::popBack() {
    if (size() == 0) {
        throw std::invalid_argument("Error: vector is empty!(Vector method: popBack)");
    }
    erase(size() - 1);
}

// insert
template<typename T>
void Vector<T>::insert(int index, const T& value) {
    if (index < 0 || size() < index) {
        throw std::invalid_argument("Error: out of bounds exception!(Vector method: insert)");
    } else if (size() < capacity()) {
        for (int i = size() - 1; i >= index; i--) {
            _array[i + 1] = _array[i];
        }
    } else {
        _capacity <<= 1;
        T* temporary_array = new T[_capacity];
        for (int i = 0; i < size(); i++) {
            if (i < index) {
                temporary_array[i] = _array[i];
            } else if (index <= i) {
                temporary_array[i + 1] = _array[i];
            }
        }
        delete[] _array;
        _array = temporary_array;
    }
    _array[index] = value;
    _size++;
}

// erase
template<typename T>
void Vector<T>::erase(int index) {
    if (index < 0 || size() <= index) {
        if (size() == 0) {
            throw std::invalid_argument("Error: vector is empty!(Vector method: erase)");
        }
        throw std::invalid_argument("Error: out of bounds exception!(Vector method: erase)");
    }
    for (int i = index + 1; i < size(); i++) {
        _array[i - 1] = _array[i];
    }
    _size--;
    if (size() <= (capacity() >> 1)) {
        _capacity >>= 1;
        T* temporary_array = new T[capacity()];
        for (int i = 0; i < size(); i++) {
            temporary_array[i] = _array[i];
        }
        delete[] _array;
        _array = temporary_array;
    }
}

// print all elements
template<typename T>
std::ostream& operator << (std::ostream& out, const Vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        out << vec[i] << " ";
    }
    return out;
}

#endif // __VECTOR_H__