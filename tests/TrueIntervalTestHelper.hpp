/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#pragma once

#include <boost/test/unit_test.hpp>

#include <dil/ii/FunctionsMap.hpp>
using namespace dil;


template <typename T>
class TestHelper : public ii::FunctionsMap<T>
{     
     public:
     void test_exactly_relation(    const ii::Relations& relation_in,
                                    const Interval<T>& lhs, 
                                    const Interval<T>& rhs)
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
