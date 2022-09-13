//
// Created by jan on 9/12/22.
//

#ifndef TSLAM_FRAME_HPP
#define TSLAM_FRAME_HPP

#include <mutex>
#include <vector>
#include "basic.hpp"
#include <type_traits>

namespace tslam {

template<typename T>
class Image {

public:

    enum class Type {
        GRAYSCALE_8 = 0,
        GRAYSCALE_16 = 1,
        COLOR_RGB_8 = 2,
        COLOR_RGB_16 = 3,
        COLOR_BGR_8 = 4,
        COLOR_BGR_16 = 5,
        OTHER = -1,
    };

    template<typename std::enable_if_t<std::is_integral<T>::value, bool>::type = true>
    Image();
    Image(const Size& size);
    Image(const uint32_t width, const uint32_t height);
    Image(const uint32_t width, const uint32_t height, Type type, T* data, bool overtake = true);

    ~Image();

private:
    //T *data_{nullptr}; //T* or array?
    std::vector<T> data_;
    Type type_{Type::OTHER};
    uint32_t width_{0};
    uint32_t height_{0};
    Size size_{0,0};
    uint64_t timestamp_{0};
    uint32_t exposure_time_{0};
    std::mutex mutex_;
};



} // tslam
#endif //TSLAM_FRAME_HPP
