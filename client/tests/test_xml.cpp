#include <gtest/gtest.h>

#include <sstream>

#include "plot/lib.hpp"
#include "plot/xml.hpp"
#include "rapidxml.hpp"

TEST(SearchTrksegNode, xml) {
    std::istringstream s1(
        u8R"##(
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<gpx xmlns="http://www.topografix.com/GPX/1/1" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:mytracks="http://mytracks.stichling.info/myTracksGPX/1/0" creator="myTracks" version="1.1" xsi:schemaLocation="http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd">
    <trk>
        <name>track-7</name>
        <desc>Log every 5 sec, 0 m</desc>
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
    </trk>
</gpx>
)##");

    rapidxml::xml_node<> *trkseg = search_trkseg_node(&s1);
    EXPECT_NE(trkseg, nullptr);
    GpsDataSeg seg;
    seg.ParseNode(trkseg);

    EXPECT_EQ(seg.size(), 1);
}
