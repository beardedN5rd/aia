/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#pragma once
#include <cstdint>

#include "IntervalTestHelper.hpp"

BOOST_AUTO_TEST_SUITE( IntervalTest )

using TimeType = std::uint_fast32_t;
using namespace dil;
using IntervalType = Interval<TimeType>;
ii::TestHelper<TimeType> helper;


BOOST_AUTO_TEST_CASE( precedes_test )
{
    const IntervalType foo (1,10);
    const IntervalType bar (20,30);
    helper.test_exactly_relation(ii::Relations::precedes, foo, bar);
}

BOOST_AUTO_TEST_CASE( preceded_by_test )
{
    const IntervalType foo (300,400);
    const IntervalType bar (100,200);
    helper.test_exactly_relation(ii::Relations::preceded_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( meets_test )
{
    const IntervalType foo (10,20);
    const IntervalType bar (20,30);
    helper.test_exactly_relation(ii::Relations::meets, foo, bar);
}

BOOST_AUTO_TEST_CASE( met_by_test )
{
    const IntervalType foo (20,25);
    const IntervalType bar (10,20);
    helper.test_exactly_relation(ii::Relations::met_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( overlaps_test )
{
    const IntervalType foo (10,20);
    const IntervalType bar (15,30);
    helper.test_exactly_relation(ii::Relations::overlaps, foo, bar);
}

BOOST_AUTO_TEST_CASE( overlapped_by_test )
{
    const IntervalType foo (15,25);
    const IntervalType bar (10,20);
    helper.test_exactly_relation(ii::Relations::overlapped_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( starts_test )
{
    const IntervalType foo (10,20);
    const IntervalType bar (10,30);
    helper.test_exactly_relation(ii::Relations::starts, foo, bar);
}

BOOST_AUTO_TEST_CASE( started_by_test )
{
    const IntervalType foo (15,25);
    const IntervalType bar (15,20);
    helper.test_exactly_relation(ii::Relations::started_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( during_test )
{
    const IntervalType foo (15,25);
    const IntervalType bar (10,30);
    helper.test_exactly_relation(ii::Relations::during, foo, bar);
}

BOOST_AUTO_TEST_CASE( contains_test )
{
    const IntervalType foo (50,100);
    const IntervalType bar (60,70);
    helper.test_exactly_relation(ii::Relations::contains, foo, bar);
}

BOOST_AUTO_TEST_CASE( finishes_test )
{
    const IntervalType foo (20,30);
    const IntervalType bar (10,30);
    helper.test_exactly_relation(ii::Relations::finishes, foo, bar);
}

BOOST_AUTO_TEST_CASE( finished_by_test )
{
    const IntervalType foo (10,30);
    const IntervalType bar (20,30);
    helper.test_exactly_relation(ii::Relations::finished_by, foo, bar);
}
BOOST_AUTO_TEST_CASE( equal_test )
{
    const IntervalType foo (1,4711);
    helper.test_exactly_relation(ii::Relations::equals, foo, foo);
}

BOOST_AUTO_TEST_SUITE_END()