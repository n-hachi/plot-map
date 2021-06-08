#ifndef CLIENT_INCLUDE_PLOT_LIB_HPP
#define CLIENT_INCLUDE_PLOT_LIB_HPP

#include <iostream>
#include <vector>

class GpsDatum {
   public:
    GpsDatum();

   private:
};

class GpsContainer {
   public:
    GpsContainer();
    void Parse(std::istream *in);

   private:
};
#endif
