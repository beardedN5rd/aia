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
namespace pi{


enum class Relations {
  precedes,
  preceded_by,
  meets,
  met_by,
  during,
};

constexpr Relations p   = Relations::precedes;
constexpr Relations pi  = Relations::preceded_by;
constexpr Relations m   = Relations::meets;
constexpr Relations mi  = Relations::met_by;
constexpr Relations d   = Relations::during;

std::ostream& operator<<(std::ostream& os, const Relations& relation)
{
    const static std::unordered_map<Relations, std::string> name_map
    ( { {Relations::precedes, "precedes"}
      , {Relations::preceded_by, "preceded_by"}
      , {Relations::meets, "meets"}
      , {Relations::met_by, "met_by"}
      , {Relations::during, "during"}
      });

    os << name_map.at(relation);
    return os;
}

}
}
