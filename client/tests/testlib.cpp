#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <sstream>

#include "plot/lib.hpp"

TEST_CASE("GpsData Parse", "[gps]") {
    std::istringstream s1(
        u8R"##(
      <trkpt lat="47.644548" lon="-122.326897">
        <ele>4.46</ele>
        <time>2009-10-17T18:37:26Z</time>
      </trkpt>
)##");
    GpsData data;
    data.Parse(&s1);
    REQUIRE(data.latitude() == Approx(47.644548).epsilon(1e-4));
    REQUIRE(data.longitude() == Approx(-122.326897).epsilon(1e-4));
    REQUIRE(data.elevation() == Approx(4.46).epsilon(1e-4));
    REQUIRE(data.time().tm_year == 2009 - 1900);
    REQUIRE(data.time().tm_mon == 10 - 1);
    REQUIRE(data.time().tm_mday == 17);
    REQUIRE(data.time().tm_hour == 18);
    REQUIRE(data.time().tm_min == 37);
    REQUIRE(data.time().tm_sec == 26);
}
