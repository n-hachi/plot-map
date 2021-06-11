#include "plot/lib.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "rapidxml.hpp"

GpsData::GpsData() {}

void GpsData::ParseNode(rapidxml::xml_node<> *node) {
    char *ptr = node->first_attribute("lat")->value();
    latitude_ = std::stod(ptr);

    ptr = node->first_attribute("lon")->value();
    longitude_ = std::stod(ptr);

    ptr = node->first_node("ele")->value();
    elevation_ = std::stod(ptr);

    ptr = node->first_node("time")->value();
    datetime_ = std::string(ptr);
    std::istringstream ss(ptr);
    ss >> std::get_time(&time_, "%Y-%m-%dT%H:%M:%SZ");
}

void GpsData::Parse(std::istream *in) {
    // Read xml data from istream
    std::istreambuf_iterator<char> it{*in};
    std::vector<char> buf(it, std::istreambuf_iterator<char>());
    buf.push_back('\0');

    // Parse the buffer using the xml istream into variable doc
    rapidxml::xml_document<> doc;
    doc.parse<0>(&buf[0]);

    // Find trkseg as root node
    rapidxml::xml_node<> *root_node = doc.first_node("trkpt");

    // Parse root_node
    ParseNode(root_node);
}
