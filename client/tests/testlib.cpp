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

TEST_CASE("GpsDataSeg Parse", "[gps]") {
    std::istringstream s1(
        u8R"##(
<trkseg>
    <trkpt lat="35.676502228" lon="139.756057739">
        <ele>17.185059</ele>
        <time>2012-08-15T03:07:12Z</time>
        <desc>Lat.=35.676502, Long.=139.756058, Alt.=17.185059m, Speed=0.000000Km/h</desc>
        <extensions>
            <mytracks:speed>0</mytracks:speed>
            <mytracks:length>0</mytracks:length>
        </extensions>
    </trkpt>
</trkseg>
)##");
    GpsDataSeg seg;
    seg.Parse(&s1);
    REQUIRE(seg.size() == 1);

    GpsData data = seg[0];
    REQUIRE(data.latitude() == Approx(35.67650228).epsilon(1e-4));
    REQUIRE(data.longitude() == Approx(139.756067739).epsilon(1e-4));
    REQUIRE(data.elevation() == Approx(17.185059).epsilon(1e-4));
    REQUIRE(data.time().tm_year == 2012 - 1900);
    REQUIRE(data.time().tm_mon == 8 - 1);
    REQUIRE(data.time().tm_mday == 15);
    REQUIRE(data.time().tm_hour == 3);
    REQUIRE(data.time().tm_min == 7);
    REQUIRE(data.time().tm_sec == 12);
}
