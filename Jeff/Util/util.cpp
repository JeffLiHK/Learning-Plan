//
// Created by Jeff Li on 2023/2/10.
//

#include "iostream"
#include "util.h"

template <typename T>
void swap(T& a, T& b)  {
    T temp = a;
    a = b;
    b = temp;
}
