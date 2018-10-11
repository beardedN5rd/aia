/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#pragma once
#include <cstdint>

#include "PointTestHelper.hpp"

BOOST_AUTO_TEST_SUITE( PointTest )

using TimeType = std::uint_fast32_t;
using namespace dil;

using IntervalType = Interval<TimeType>;
pi::TestHelper<TimeType> helper;


BOOST_AUTO_TEST_CASE( precedes_test )
{
    const TimeType foo = 10;
    const IntervalType bar (20,30);
    helper.test_exactly_relation(pi::Relations::precedes, foo, bar);
}

BOOST_AUTO_TEST_CASE( preceded_by_test )
{
    const TimeType foo = 300;
    const IntervalType bar (100,200);
    helper.test_exactly_relation(pi::Relations::preceded_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( meets_test )
{
    const TimeType foo = 20;
    const IntervalType bar (20,30);
    helper.test_exactly_relation(pi::Relations::meets, foo, bar);
}

BOOST_AUTO_TEST_CASE( met_by_test )
{
    const TimeType foo = 20;
    const IntervalType bar (10,20);
    helper.test_exactly_relation(pi::Relations::met_by, foo, bar);
}

BOOST_AUTO_TEST_CASE( during_test )
{
    const TimeType foo = 20;
    const IntervalType bar (10,30);
    helper.test_exactly_relation(pi::Relations::during, foo, bar);
}


BOOST_AUTO_TEST_SUITE_END()