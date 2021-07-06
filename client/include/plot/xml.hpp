#ifndef CLIENT_INCLUDE_PLOT_XML_HPP
#define CLIENT_INCLUDE_PLOT_XML_HPP

#include <iostream>

#include "rapidxml.hpp"

rapidxml::xml_node<>* search_trkseg_node(std::istream* in);

#endif
