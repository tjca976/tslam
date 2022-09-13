//
// Created by jan on 9/12/22.
//
#include "../include/frame.hpp"

using namespace tslam;


template<typename T>
Image<T>::Image(const Size &size) : size_(size), width_(size.width_), height_(size.height_) {
    data_.resize(width_*height_); // TODO: or new T[width_*height_]
}

template<class T>
Image<T>::Image(const uint32_t width, const uint32_t height) : width_(width), height_(height), size_{width_, height_} { // TODO: Use () or {} here ?

}

template<typename T, typename = typename std::enable_if_t<std::is_integral<T>::value, bool> = true>
Image<T>::Image() { // TODO: initialize member variables here or during definition?

}





