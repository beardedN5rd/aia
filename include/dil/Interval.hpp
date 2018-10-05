/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#pragma once
#include <iostream>
#include <stdexcept>

namespace dil {

/* 
An determined interval can be used to reason about temporal intervals.

Intervals are always closed intervals here.
*/
template <typename PointInTimeType> class Interval
{
  public:
    explicit Interval(const PointInTimeType & lwb, const PointInTimeType & upb)
    : _lwb(lwb)
    , _upb(upb)
    {
      is_true_interval(lwb, upb);
    }

    virtual ~Interval()
    {}

    PointInTimeType lower() const
    { return _lwb; }

    PointInTimeType upper() const
    { return _upb; }

  private:
    PointInTimeType _lwb;
    PointInTimeType _upb;

    static void is_true_interval(const PointInTimeType & lwb, const PointInTimeType & upb)
    {
      if ( lwb >= upb )
        throw std::invalid_argument( "Boundaries are not strictly monotonous increasing." );
    }    
};

template <typename PointInTimeType>
std::ostream& operator<<(std::ostream& os, const Interval<PointInTimeType>& interval)  
{  
    os << '[' << interval.lower() << ',' << interval.upper() << ']';  
    return os;  
}

}