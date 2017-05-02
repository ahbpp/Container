//
//  Container.hpp
//  1
//
//  Created by Alexey Karpov on 11.04.17.
//  Copyright © 2017 Alexey Karpov. All rights reserved.
//

#ifndef Container_hpp
#define Container_hpp

#include <stdio.h>




template <typename T>
class Vector{
private:
    T *values;
    size_t size;
    size_t capacity;
    void set_capacuty(const size_t cap);
    void increase(const int th);
public:
    template <typename C>
    class Iterator{
    private:
        T *value;
    public:
        Iterator(T *value) {
            this->value = value;
        }
        Iterator(T &value) {
            this->value = &value;
        }
        Iterator(const Iterator<C> &that) {
            this->value = that.value;
        }
        Iterator<C>& operator++(){
            ++this->value;
            return *this;
        }
        Iterator<C> operator+(const size_t n) const{
            return Iterator(this->value + n);
        }
        Iterator<C>& operator--(){
            --this->value;
            return *this;
        }
        Iterator<C> operator-(const size_t n) const{
            return Iterator(this->value - n);
        }
        Iterator<C>& operator=(const Iterator& that) {
            this->value = that.value;
            return *this;
        }
        Iterator<C>& operator=(const T &value) {
            this->value = &value;
            return *this;
        }
        Iterator<C> operator++(int)
        {
            Iterator<C> old(*this);
            ++(*this);
            return old;
        }
        Iterator<C> operator--(int)
        {
            Iterator<C> old(*this);
            --(*this);
            return old;
        }
        T& operator*() const{
            return *(this->value);
        }
        bool operator==(const Iterator<C> &that) const
        {
            return this->value == that.value;
        }
        bool operator!=(const Iterator<C> &that) const
        {
            return this->value != that.value;
        }
    };
    Vector();
    Vector(const T* values, const size_t size);
    Vector(const size_t size);
    ~Vector();
    void push_back(const T &t);
    T pop_back();
    void push_front(const T &t);
    T pop_front();
    T front() const;
    T back() const;
    T& operator[](const size_t index) const;
    void clear();
    void insert(const size_t index, const T &value);
    
    Iterator<T> begin() const
    {
        return Iterator<T>(this->values[0]);
    }
    Iterator<T> end() const
    {
        return Iterator<T>(this->values[this->size]);
    }
};









template <typename T>
void Vector<T>::set_capacuty(const size_t cap){
    this->size = 0;
    this->capacity = cap;
    this->values = new T[this->capacity];
    for (size_t i = 0; i < this->capacity; ++i) {
        this->values[i] = 0;
    }
}
template <typename T>
void Vector<T>::increase(const int th){
    T *newval = new T[this->capacity * 2];
    for (size_t i = 0; i < this->size; i++)
    {
        newval[i + th] = this->values[i];
    }
    delete [] this->values;
    this->capacity *= 2;
    this->values = newval;
}

template <typename T>
Vector<T>::Vector()
{
    set_capacuty(10);
}
template <typename T>
Vector<T>::Vector(const size_t size)
{
    set_capacuty(size * 2);
    this->size = size;
}
template <typename T>
Vector<T>::Vector(const T* values, const size_t size)
{
    set_capacuty(size * 2);
    this->size = size;
    for (size_t i = 0; i < this->size; ++i) {
        this->values[i] = values[i];
    }
}
template <typename T>
Vector<T>::~Vector()
{
    delete [] this->values;
}
template <typename T>
void Vector<T>::push_back(const T &t)
{
    if (this->size == this->capacity)
    {
        increase(0);
    }
    this->values[this->size] = t;
    ++this->size;
}
template <typename T>
void Vector<T>::push_front(const T &t)
{
    if (this->size == this->capacity)
    {
        increase(1);
    } else {
        for (int i = this->size; i > 0; --i)
            this->values[i] = this->values[i - 1];
    }
    this->values[0] = t;
}
template <typename T>
T Vector<T>::pop_back()
{
    T result = this->values[this->size - 1];
    this->values[this->size - 1] = 0;
    this->size--;
    return result;
}
template <typename T>
T Vector<T>::back() const
{
    return this->values[this->size - 1];
}
template <typename T>
T Vector<T>::pop_front()
{
    T result = this->values[0];
    this->size--;
    for (size_t i = 0; i < this->size; ++i)
    {
        this->values[i] = this->values[i + 1];
    }
    return result;
}
template <typename T>
T Vector<T>::front() const
{
    return this->values[0];
}
template <typename T>
T& Vector<T>::operator[](const size_t index) const
{
    return this->values[index];
}
template <typename T>
void Vector<T>::clear()
{
    delete [] this->values;
    set_capacuty(10);
    this->size = 0;
    this->capacity = 10;
}
template <typename T>
void Vector<T>::insert(const size_t index, const T &value)
{
    if (this->size == this->capacity)
    {
        increase(0);
    }
    for (int i = int(this->size); i > index; --i)
    {
        this->values[i] = this->values[i - 1];
    }
    this->values[index] = value;
    this->size++;
}


#endif /* Container_hpp */
