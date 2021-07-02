#include <gtest/gtest.h>

#include <sstream>

#include "plot/lib.hpp"

TEST(GpsData_Parse, gps) {
    std::istringstream s1(
        u8R"##(
      <trkpt lat="47.644548" lon="-122.326897">
        <ele>4.46</ele>
        <time>2009-10-17T18:37:26Z</time>
      </trkpt>
)##");
    GpsData data;
    data.Parse(&s1);
    EXPECT_FLOAT_EQ(data.latitude(), 47.644548);
    EXPECT_FLOAT_EQ(data.longitude(), -122.326897);
    EXPECT_FLOAT_EQ(data.elevation(), 4.46);
    EXPECT_EQ(data.time().tm_year, 2009 - 1900);
    EXPECT_EQ(data.time().tm_mon, 10 - 1);
    EXPECT_EQ(data.time().tm_mday, 17);
    EXPECT_EQ(data.time().tm_hour, 18);
    EXPECT_EQ(data.time().tm_min, 37);
    EXPECT_EQ(data.time().tm_sec, 26);
}

TEST(GpsDataSeg_Parse, gps) {
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
    EXPECT_EQ(seg.size(), 1);

    GpsData data = seg[0];
    EXPECT_FLOAT_EQ(data.latitude(), 35.67650228);
    EXPECT_FLOAT_EQ(data.longitude(), 139.756067739);
    EXPECT_FLOAT_EQ(data.elevation(), 17.185059);
    EXPECT_EQ(data.time().tm_year, 2012 - 1900);
    EXPECT_EQ(data.time().tm_mon, 8 - 1);
    EXPECT_EQ(data.time().tm_mday, 15);
    EXPECT_EQ(data.time().tm_hour, 3);
    EXPECT_EQ(data.time().tm_min, 7);
    EXPECT_EQ(data.time().tm_sec, 12);
}
