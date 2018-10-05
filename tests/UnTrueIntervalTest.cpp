/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#include <cstdint>

#define BOOST_TEST_MODULE UnTrueIntervalTest
//#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <aia/FunctionsMap.hpp>

using namespace aia; 

template <typename T>
class TestHelper : public FunctionsMap<T>
{     
     public:
     void test_exactly_relation(    const Relations& relation_in,
                                    const DeterminedInterval<T>& lhs, 
                                    const DeterminedInterval<T>& rhs)
     {
        for( auto const& [rel, fun] : this->_function_map )
        {
            if (relation_in == rel)
                BOOST_TEST(fun(lhs, rhs) == true);
            else
                BOOST_TEST( fun(lhs, rhs) == false,
                            "expected " << relation_in <<
                            " but also " << rel <<
                            " with (lhs " << lhs << ", rhs " << rhs <<") got true");
        }

     }
};


BOOST_AUTO_TEST_SUITE( UnTrueIntervalTest )

using TimeType = std::uint_fast32_t;
using IntervalType = DeterminedInterval<TimeType>;
TestHelper<TimeType> helper;


BOOST_AUTO_TEST_CASE( precedes_test )
{
    IntervalType foo (10);
    IntervalType bar (20,30);
    helper.test_exactly_relation(Relations::precedes, foo, bar);
}

BOOST_AUTO_TEST_CASE( preceded_by_test )
{
    IntervalType foo (300);
    IntervalType bar (100,200);
    helper.test_exactly_relation(Relations::preceded_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( meets_test )
{
    IntervalType foo (20);
    IntervalType bar (20,30);
    helper.test_exactly_relation(Relations::meets, foo, bar);
}

BOOST_AUTO_TEST_CASE( met_by_test )
{
    IntervalType foo (20);
    IntervalType bar (10,20);
    helper.test_exactly_relation(Relations::met_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( overlaps_test )
{
    IntervalType foo (20);
    IntervalType bar (15,30);
    helper.test_exactly_relation(Relations::overlaps, foo, bar);
}

BOOST_AUTO_TEST_CASE( overlapped_by_test )
{
    IntervalType foo (15);
    IntervalType bar (10,20);
    helper.test_exactly_relation(Relations::overlapped_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( starts_test )
{
    IntervalType foo (10);
    IntervalType bar (10,30);
    helper.test_exactly_relation(Relations::starts, foo, bar);
}

BOOST_AUTO_TEST_CASE( started_by_test )
{
    IntervalType foo (15);
    IntervalType bar (15,20);
    helper.test_exactly_relation(Relations::started_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( during_test )
{
    IntervalType foo (15);
    IntervalType bar (10,30);
    helper.test_exactly_relation(Relations::during, foo, bar);
}

BOOST_AUTO_TEST_CASE( contains_test )
{
    IntervalType foo (50);
    IntervalType bar (60,70);
    helper.test_exactly_relation(Relations::contains, foo, bar);
}

BOOST_AUTO_TEST_CASE( finishes_test )
{
    IntervalType foo (30);
    IntervalType bar (10,30);
    helper.test_exactly_relation(Relations::finishes, foo, bar);
}

BOOST_AUTO_TEST_CASE( finished_by_test )
{
    IntervalType foo (30);
    IntervalType bar (20,30);
    helper.test_exactly_relation(Relations::finished_by, foo, bar);
}
BOOST_AUTO_TEST_CASE( equal_test )
{
    IntervalType foo (1,4711);
    helper.test_exactly_relation(Relations::equals, foo, foo);
}

BOOST_AUTO_TEST_SUITE_END()