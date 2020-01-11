//
// Created by magom on 23.12.2019.
//

#ifndef OOP_EXERCISE_08_FIGURE_H
#define OOP_EXERCISE_08_FIGURE_H

#include <iostream>
#include "point.h"
#include <fstream>

struct figure {
    virtual Vertex<double> center() const = 0;
    virtual void print(std::ostream&) const = 0 ;
    virtual void help_print(std::ofstream&) const = 0;
    virtual void read_file(std::istream &is) = 0;
    virtual double square() const = 0;
    virtual ~figure() = default;
};

#endif //OOP_EXERCISE_08_FIGURE_H
