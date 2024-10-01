#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
protected:
    T* data;
    int size;
    int capacity;

    void expand(); // Function to expand the array

public:
    Array(int initialCapacity = 2);
    virtual ~Array();
    virtual void push(const T& value) = 0; // Pure virtual function
    int getSize() const { return size; }
};

template <typename T>
Array<T>::Array(int initialCapacity) : size(0), capacity(initialCapacity) {
    data = new T[capacity];
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
void Array<T>::expand() {
    int newCapacity = capacity * 2; // Example: doubling the capacity
    T* newData = new T[newCapacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}



#endif // ARRAY_H