/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#pragma once
#include <functional>
#include <unordered_map>
#include <utility>


#include <aia/Functions.hpp>
#include <aia/Relations.hpp>

namespace aia {

    template <typename T>
    using relation_func_t = std::function<bool( const DeterminedInterval<T>& lhs, 
                                                const DeterminedInterval<T>& rhs)>;
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
                map.emplace(  Relations::overlaps, overlaps<T>);
                map.emplace(  Relations::overlapped_by, overlapped_by<T>);
                map.emplace(  Relations::starts, starts<T>);
                map.emplace(  Relations::started_by, started_by<T>);
                map.emplace(  Relations::during, during<T>);
                map.emplace(  Relations::contains, contains<T>);
                map.emplace(  Relations::finishes, finishes<T>);
                map.emplace(  Relations::finished_by, finished_by<T>);
                map.emplace(  Relations::equals, equals<T>);
                return map;
            }
        public:
            FunctionsMap()
            :  _function_map(create_map())
            {}

            virtual ~FunctionsMap()
            {}

            bool is_valid(  const Relations& rel,
                            const DeterminedInterval<T>& lhs, 
                            const DeterminedInterval<T>& rhs)
            {
                return _function_map.at(rel)(lhs,rhs);
            }
    };
}