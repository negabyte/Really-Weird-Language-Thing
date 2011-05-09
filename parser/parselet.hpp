/*  Copyright Reid Levenick 2011
 *  Distributed under the Boost Software License, Version 1.0
 *  (See accompanying file LICENSE or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef PARSER_PARSELET_HPP
#define PARSER_PARSELET_HPP

#include "expression.hpp"
#include "../lexer/token.hpp"

namespace parser
{
    class PrefixParselet
    {
        public:
            PrefixParselet() = default;
            virtual ~PrefixParselet() = 0;

            virtual Expression Parse( const Parser&, const lexer::Token& ) = 0;
        private:
        protected:
    };
    class OtherfixParselet
    {
        public:
            OtherfixParselet() = default;
            virtual ~OtherfixParselet() = 0;

            virtual const int Precedence() = 0;
            virtual Expression Parse( const Parser&, const Expression&, const lexer::Token& ) = 0;
        private:
        protected:
    };
}

#endif