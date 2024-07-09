#include <unity.h>

#include <dsmr.h>

void setUp() {}
void tearDown() {}

Parser parser;

void test_uint32_t() {
  const char msg[] =
    "/KFM5KAIFA-METER\r\n"
    "\r\n"
    "1-0:1.8.1(000671.578*kWh)\r\n"
    "1-0:1.7.0(00.318*kW)\r\n"
    "!1E1D\r\n";

  ParsedData<
    /* String */ identification,
    /* FixedValue */ power_delivered
  > myData;

  ParseResult<void> res = P1Parser::parse(&myData, msg, lengthof(msg));

  TEST_ASSERT_FALSE(res.err);
  TEST_ASSERT_EQUAL_UINT32(318, myData.power_delivered.int_val());
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_uint32_t);
  return UNITY_END();
}
