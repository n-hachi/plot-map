#ifndef CLIENT_INCLUDE_PLOT_LIB_HPP
#define CLIENT_INCLUDE_PLOT_LIB_HPP

#include <ctime>
#include <iostream>
#include <vector>

#include "rapidxml.hpp"

class GpsData {
   public:
    GpsData();
    void Parse(std::istream *in);
    void ParseNode(rapidxml::xml_node<> *node);
    const double latitude() { return latitude_; };
    const double longitude() { return longitude_; };
    const double elevation() { return elevation_; };
    const std::tm time() { return time_; };
    const time_t Mktime() { return std::mktime(&time_); };

   private:
    double latitude_;
    double longitude_;
    double elevation_;
    std::string datetime_;
    std::tm time_;
};

class GpsDataSeg {
   public:
    GpsDataSeg();
    void Parse(std::istream *in);
    void ParseNode(rapidxml::xml_node<> *node);
    const std::size_t size() { return vec_.size(); };
    GpsData operator[](int i) const;

   private:
    std::vector<GpsData> vec_;
};

#endif
