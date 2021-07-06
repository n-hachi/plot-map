#include "plot/xml.hpp"

#include <iostream>
#include <sstream>
#include <vector>

#include "rapidxml.hpp"

rapidxml::xml_node<>* search_trkseg_node(std::istream* in) {
    std::istreambuf_iterator<char> it{*in};
    std::vector<char> buf(it, std::istreambuf_iterator<char>());
    buf.push_back('\0');

    // Parse the buffer using the xml istream into variable doc
    rapidxml::xml_document<> doc;
    doc.parse<0>(&buf[0]);

    // TODO
    // You need to check at every hop.
    rapidxml::xml_node<>* trkseg =
        doc.first_node("gpx")->first_node("trk")->first_node("trkseg");
    return trkseg;
}
