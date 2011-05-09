/*  Copyright Reid Levenick 2011
 *  Distributed under the Boost Software License, Version 1.0
 *  (See accompanying file LICENSE or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 */

#include "lexer/lexer.hpp"

#include <iostream>

int main( int argc, char** argv )
{
    if( argc != 2 )
    {
        std::cerr << "You must provide one string to tokenize.\n";
    }
    else
    {
        lex::Lexer Lexer( argv[ 1 ] );
        lex::Token Token;
        while( Lexer.Tokenize( &Token ) )
        {
            std::cout << '\"' << Token.Data << "\" " << Token.Type << std::endl;
        }
    }

    return 0;
}