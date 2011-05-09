/*  Copyright Reid Levenick 2011
 *  Distributed under the Boost Software License, Version 1.0
 *  (See accompanying file LICENSE or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 */

#include "token.hpp"

namespace lexer
{
    Token::Token()
        : Data(), Type( type::None )
    {
    }
}