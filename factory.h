#ifndef OOP_EXERCISE_08_FACTORY_H
#define OOP_EXERCISE_08_FACTORY_H

#include <memory>
#include <iostream>
#include <fstream>
#include "six_angles.h"
#include "eight_angles.h"
#include "five_angles.h"
#include <string>

struct factory
{
    std::shared_ptr<figure> FigureCreate(std::istream& is);
    std::shared_ptr<figure> FigureCreateFile(std::ifstream& is);
};

#endif //OOP_EXERCISE_08_FACTORY_H
