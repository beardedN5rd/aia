/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#pragma once
#include <functional>
#include <utility>


#include <dil/pi/Functions.hpp>
#include <dil/pi/Relations.hpp>

namespace dil {
namespace pi {

    template <typename T>
    using relation_func_t = std::function<bool( const T& lhs, 
                                                const Interval<T>& rhs)>;
    template <typename T>
    using function_map_t = std::unordered_map<Relations, relation_func_t<T>>;

    template <typename T>
    class FunctionsMap
    {
        protected:
            const function_map_t<T> _function_map;

        private:
            static function_map_t<T> create_map()
            {
                function_map_t<T> map;
                map.emplace(  Relations::precedes, precedes<T>);
                map.emplace(  Relations::preceded_by, preceded_by<T>);
                map.emplace(  Relations::meets, meets<T>),
                map.emplace(  Relations::met_by, met_by<T>);
                map.emplace(  Relations::during, during<T>);
                return map;
            }
        public:
            FunctionsMap()
            :  _function_map(create_map())
            {}

            virtual ~FunctionsMap()
            {}

            bool is_valid(  const Relations& rel,
                            const T& lhs, 
                            const Interval<T>& rhs)
            {
                return _function_map.at(rel)(lhs,rhs);
            }
    };

}
}