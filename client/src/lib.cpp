#include "plot/lib.hpp"

#include <iostream>
#include <vector>

#include "rapidxml.hpp"

GpsDatum::GpsDatum() {}

GpsContainer::GpsContainer() {}

void GpsContainer::Parse(std::istream *in) {
    // Read xml data from istream
    std::istreambuf_iterator<char> it{*in};
    std::vector<char> buf(it, std::istreambuf_iterator<char>());
    buf.push_back('\0');

    // Parse the buffer using the xml istream into variable doc
    rapidxml::xml_document<> doc;
    doc.parse<0>(&buf[0]);

    // Find trkseg as root node
    rapidxml::xml_node<> *root_node = doc.first_node("trkseg");
    for (rapidxml::xml_node<> *trkpt_node = root_node->first_node("trkpt");
         trkpt_node; trkpt_node = trkpt_node->next_sibling()) {
        std::cout << trkpt_node;
    }
}
