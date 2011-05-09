/*  Copyright Reid Levenick 2011
 *  Distributed under the Boost Software License, Version 1.0
 *  (See accompanying file LICENSE or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef PARSER_PARSER_HPP
#define PARSER_PARSER_HPP

#include "parselet.hpp"
#include "../lexer/token.hpp"

#include <map>

namespace parser
{
    class Parser
    {
        public:
            Parser();
            ~Parser();

            void Register( const lexer::Token::type, const PrefixParselet& );
            void Register( const lexer::Token::type, const OtherfixParselet& );
        private:
        protected:
    };
}

#endif