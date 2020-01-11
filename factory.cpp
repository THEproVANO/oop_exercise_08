#include "factory.h"

std::shared_ptr<figure> factory::FigureCreate(std::istream &is)
{
    std::cout << "Input the number of figure:\n";
    std::cout << "Pentagon: 5\n";
    std::cout << "Hexagon: 6\n";
    std::cout << "Octagon: 8\n";
    std::string name;
    is >> name;
    if ( name == "5" ) {
        return std::shared_ptr<figure> ( new five_angles(is));
    } else if ( name == "6") {
        return std::shared_ptr<figure> ( new six_angles(is));
    } else if ( name == "8") {
        return std::shared_ptr<figure> ( new eight_angles(is));
    } else {
        throw std::logic_error("There is no such figure\n");
    }
}

std::shared_ptr<figure> factory::FigureCreateFile(std::ifstream &is) {
    std::cout << "Input the number of figure:\n";
    std::cout << "Pentagon: 5\n";
    std::cout << "Hexagon: 6\n";
    std::cout << "Octagon: 8\n";
    std::string name;
    is >> name;
    if ( name == "5" ) {
        return std::shared_ptr<figure> ( new five_angles(is));
    } else if ( name == "6") {
        return std::shared_ptr<figure> ( new six_angles(is));
    } else if ( name == "8") {
        return std::shared_ptr<figure> ( new eight_angles(is));
    } else {
        throw std::logic_error("There is no such figure\n");
    }
}

