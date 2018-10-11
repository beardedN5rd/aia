/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

namespace dil {
namespace ii{


enum class Relations {
  precedes,
  preceded_by,
  meets,
  met_by,
  overlaps,
  overlapped_by,
  starts,
  started_by,
  during,
  contains,
  finishes,
  finished_by,
  equals
};

constexpr Relations p   = Relations::precedes;
constexpr Relations pi  = Relations::preceded_by;
constexpr Relations m   = Relations::meets;
constexpr Relations mi  = Relations::met_by;
constexpr Relations o   = Relations::overlaps;
constexpr Relations oi  = Relations::overlapped_by;
constexpr Relations s   = Relations::starts;
constexpr Relations si  = Relations::started_by;
constexpr Relations d   = Relations::during;
constexpr Relations di  = Relations::contains;
constexpr Relations f   = Relations::finishes;
constexpr Relations fi  = Relations::finished_by;
constexpr Relations e   = Relations::equals;

std::ostream& operator<<(std::ostream& os, const Relations& relation)
{
    const static std::unordered_map<Relations, std::string> name_map
    ( { {Relations::precedes, "precedes"}
      , {Relations::preceded_by, "preceded_by"}
      , {Relations::meets, "meets"}
      , {Relations::met_by, "met_by"}
      , {Relations::overlaps, "overlaps"}
      , {Relations::overlapped_by, "overlapped_by"}
      , {Relations::starts, "starts"}
      , {Relations::started_by, "started_by"}
      , {Relations::during, "during"}
      , {Relations::contains, "contains"}
      , {Relations::finishes, "finishes"}
      , {Relations::finished_by, "finished_by"}
      , {Relations::equals, "equals"}
      });

    os << name_map.at(relation);
    return os;
}

}
}
