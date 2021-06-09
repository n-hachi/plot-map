#ifndef CLIENT_INCLUDE_PLOT_LIB_HPP
#define CLIENT_INCLUDE_PLOT_LIB_HPP

#include <iostream>
#include <vector>

#include "rapidxml.hpp"

class GpsData {
   public:
    GpsData();
    void Parse(std::istream *in);
    const double latitude() { return latitude_; };
    const double longitude() { return longitude_; };
    const double elevation() { return elevation_; };

   private:
    double latitude_;
    double longitude_;
    double elevation_;
    std::string datetime_;

    void ParseNode(rapidxml::xml_node<> *node);
};

#endif
