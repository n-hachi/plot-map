#include "plot/lib.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "plot/xml.hpp"
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

GpsDataSeg::GpsDataSeg() {}

void GpsDataSeg::ParseNode(rapidxml::xml_node<> *node) {
    // Iterator over the trkpt
    for (rapidxml::xml_node<> *trkpt = node->first_node("trkpt"); trkpt;
         trkpt = trkpt->next_sibling()) {
        GpsData data;
        data.ParseNode(trkpt);
        vec_.push_back(data);
    }
}

void GpsDataSeg::Parse(std::istream *in) {
    // Read xml data from istream
    std::istreambuf_iterator<char> it{*in};
    std::vector<char> buf(it, std::istreambuf_iterator<char>());
    buf.push_back('\0');

    // Parse the buffer using the xml istream into variable doc
    rapidxml::xml_document<> doc;
    doc.parse<0>(&buf[0]);

    // Find trkseg as root node
    rapidxml::xml_node<> *trkseg = doc.first_node("trkseg");

    // Parse root_node
    ParseNode(trkseg);
}

GpsData GpsDataSeg::operator[](int i) const { return vec_[i]; };
