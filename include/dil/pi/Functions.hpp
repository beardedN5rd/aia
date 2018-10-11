/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#pragma once
#include <dil/Interval.hpp>

namespace dil {
namespace pi {

template <typename T>
inline bool precedes(const T& lhs, const Interval<T>& rhs)
{
    return (lhs < rhs.lower()); 
}

template <typename T>
inline bool preceded_by(const T& lhs, const Interval<T>& rhs)
{
    return (lhs > rhs.upper()); 
}

template <typename T>
inline bool meets(const T& lhs, const Interval<T>& rhs)
{
    return ( lhs == rhs.lower()); 
}

template <typename T>
inline bool met_by(const T& lhs, const Interval<T>& rhs)
{
    return ( lhs == rhs.upper()); 
}

template <typename T>
inline bool during(const T& lhs, const Interval<T>& rhs)
{
    return (    (lhs > rhs.lower())
            &&  (lhs < rhs.upper())); 
}


}
}