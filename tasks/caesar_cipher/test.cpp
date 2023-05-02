#include <catch.hpp>

#include "caesar_cipher.h"

TEST_CASE("Simple") {
    REQUIRE(Decipher("XPSE", 1) == "WORD");
    REQUIRE(Decipher("ZABC", 3) == "WXYZ");
    REQUIRE(Decipher("DEF[", 20) == "XYZUV");
}
