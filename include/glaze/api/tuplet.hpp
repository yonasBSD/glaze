// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#include "glaze/api/name.hpp"
#include "glaze/tuplet/tuple.hpp"

namespace glz
{
   namespace detail
   {
      template <class... T, size_t... I>
      constexpr std::string_view tuplet_name_impl(std::index_sequence<I...>)
      {
         return join_v<chars<"glz::tuplet::tuple<">,
                       ((I != sizeof...(T) - 1) ? join_v<name_v<T>, chars<",">> : join_v<name_v<T>>)..., chars<">">>;
      }
   }

   template <class... T>
   struct meta<glz::tuplet::tuple<T...>>
   {
      static constexpr std::string_view name = detail::tuplet_name_impl<T...>(std::make_index_sequence<sizeof...(T)>());
   };
}
