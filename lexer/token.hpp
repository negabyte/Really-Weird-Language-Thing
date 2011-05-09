/*  Copyright Reid Levenick 2011
 *  Distributed under the Boost Software License, Version 1.0
 *  (See accompanying file LICENSE or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef LEXER_TOKEN_HPP
#define LEXER_TOKEN_HPP

#include <string>

namespace lexer
{
    class Token
    {
        public:
            enum type
            {
                None,
                Word,
                Number,
                String,
                Symbol
            };

            Token();
            ~Token() = default;

            std::string Data;
            type Type;
        private:
        protected:
    };
}

#endif