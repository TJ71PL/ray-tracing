#ifndef COLOR_H
#define COLOR_H

#include "vector3.h"
#include <iostream>

using color = vector3;

void write_color(std::ostream& out, const color& pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    int red_value = int(255.999 * r);
    int green_value = int(255.999 * g);
    int blue_value = int(255.999 * b);

    out << red_value << " " << green_value << " " << blue_value << "\n";
}

#endif