/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#include <cstdint>
#include <functional>

#include <aia/FunctionsMap.hpp>

int main()
{
    aia::FunctionsMap<uint_fast32_t> myMap;
    aia::DeterminedInterval<uint_fast32_t> foo(7,19);
    std::cout << "using myMap=" << myMap.is_valid(aia::Relations::equals,foo,foo) << std::endl;


    return EXIT_SUCCESS;
}