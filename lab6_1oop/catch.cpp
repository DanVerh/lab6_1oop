#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Array.hpp"
#include "Array.cpp"
typedef Array::value_type* TArray;

TEST_CASE( "Arguments initialized") {
    int n = 26;
    Array c = Array(2 * n);
    TArray a = new Array::value_type[n];
    a[0] = -2;
    for(int i = 1; i < 50; i++)
        a[i] = 0;
    a[50] = 4;
    Array::iterator l = const_cast<Array::iterator>(c.begin());
    for (int j = 0; j < 2 * n; j++, l++)
        *l = a[j];
    c.NegativeHalfsumFifty();
    REQUIRE( c[50] == 4);
}
