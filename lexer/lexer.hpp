/*  Copyright Reid Levenick 2011
 *  Distributed under the Boost Software License, Version 1.0
 *  (See accompanying file LICENSE or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef LEXER_LEXER_HPP
#define LEXER_LEXER_HPP

#include "token.hpp"

#include <string>
#include <vector>

namespace lexer
{
    class Lexer
    {
        public:
            Lexer() = default;
            Lexer( const std::string& );
            ~Lexer() = default;

            void SetSource( const std::string& );
            const bool Tokenize( Token* const );
        private:
            Lexer( const Lexer& ) = delete;
            Lexer& operator=( const Lexer& ) = delete;

            std::string _source;
            std::string::const_iterator _iter;
        protected:
    };
}

#endif