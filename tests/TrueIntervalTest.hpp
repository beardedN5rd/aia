/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#pragma once
#include <cstdint>

#include "TrueIntervalTestHelper.hpp"

BOOST_AUTO_TEST_SUITE( TrueIntervalTest )

using TimeType = std::uint_fast32_t;
using IntervalType = dil::DeterminedInterval<TimeType>;
using dil::Relations;
TestHelper<TimeType> helper;


BOOST_AUTO_TEST_CASE( precedes_test )
{
    IntervalType foo (1,10);
    IntervalType bar (20,30);
    helper.test_exactly_relation(Relations::precedes, foo, bar);
}

BOOST_AUTO_TEST_CASE( preceded_by_test )
{
    IntervalType foo (300,400);
    IntervalType bar (100,200);
    helper.test_exactly_relation(Relations::preceded_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( meets_test )
{
    IntervalType foo (10,20);
    IntervalType bar (20,30);
    helper.test_exactly_relation(Relations::meets, foo, bar);
}

BOOST_AUTO_TEST_CASE( met_by_test )
{
    IntervalType foo (20,25);
    IntervalType bar (10,20);
    helper.test_exactly_relation(Relations::met_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( overlaps_test )
{
    IntervalType foo (10,20);
    IntervalType bar (15,30);
    helper.test_exactly_relation(Relations::overlaps, foo, bar);
}

BOOST_AUTO_TEST_CASE( overlapped_by_test )
{
    IntervalType foo (15,25);
    IntervalType bar (10,20);
    helper.test_exactly_relation(Relations::overlapped_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( starts_test )
{
    IntervalType foo (10,20);
    IntervalType bar (10,30);
    helper.test_exactly_relation(Relations::starts, foo, bar);
}

BOOST_AUTO_TEST_CASE( started_by_test )
{
    IntervalType foo (15,25);
    IntervalType bar (15,20);
    helper.test_exactly_relation(Relations::started_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( during_test )
{
    IntervalType foo (15,25);
    IntervalType bar (10,30);
    helper.test_exactly_relation(Relations::during, foo, bar);
}

BOOST_AUTO_TEST_CASE( contains_test )
{
    IntervalType foo (50,100);
    IntervalType bar (60,70);
    helper.test_exactly_relation(Relations::contains, foo, bar);
}

BOOST_AUTO_TEST_CASE( finishes_test )
{
    IntervalType foo (20,30);
    IntervalType bar (10,30);
    helper.test_exactly_relation(Relations::finishes, foo, bar);
}

BOOST_AUTO_TEST_CASE( finished_by_test )
{
    IntervalType foo (10,30);
    IntervalType bar (20,30);
    helper.test_exactly_relation(Relations::finished_by, foo, bar);
}
BOOST_AUTO_TEST_CASE( equal_test )
{
    IntervalType foo (1,4711);
    helper.test_exactly_relation(Relations::equals, foo, foo);
}

BOOST_AUTO_TEST_SUITE_END()