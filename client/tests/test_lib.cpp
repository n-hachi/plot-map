#include <gtest/gtest.h>

#include <ctime>
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

class GpsDataSegTest : public ::testing::Test {
   protected:
    virtual void SetUp() {
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
            <trkpt lat="35.676502228" lon="139.756057739">
                <ele>17.178711</ele>
                <time>2012-08-15T03:07:17Z</time>
                <desc>Lat.=35.676502, Long.=139.756058, Alt.=17.178711m, Speed=0.320606Km/h</desc>
                <extensions>
                    <mytracks:speed>0.3206059327751585</mytracks:speed>
                    <mytracks:length>0</mytracks:length>
                </extensions>
            </trkpt>
            <trkpt lat="35.676498413" lon="139.756057739">
                <ele>17.179199</ele>
                <time>2012-08-15T03:07:22Z</time>
                <desc>Lat.=35.676498, Long.=139.756058, Alt.=17.179199m, Speed=0.305686Km/h</desc>
                <extensions>
                    <mytracks:speed>0.305685762791301</mytracks:speed>
                    <mytracks:length>0.0004350481890523979</mytracks:length>
                </extensions>
            </trkpt>
        </trkseg>
)##");
        seg.Parse(&s1);
    }

    GpsDataSeg seg;
};

TEST_F(GpsDataSegTest, Size) { EXPECT_EQ(seg.size(), 3); }
TEST_F(GpsDataSegTest, Mktime) {
    time_t t0 = seg[0].Mktime();
    time_t t1 = seg[1].Mktime();
    time_t t2 = seg[2].Mktime();

    EXPECT_EQ(t1 - t0, 5);
    EXPECT_EQ(t2 - t0, 10);
}
