/*  Copyright Reid Levenick 2011
 *  Distributed under the Boost Software License, Version 1.0
 *  (See accompanying file LICENSE or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 */

#include "lexer.hpp"

#include <locale>

namespace lexer
{
    Lexer::Lexer( const std::string& Source )
        : _source( Source ), _iter( _source.cbegin() )
    {
    }

    void Lexer::SetSource( const std::string& String )
    {
        _source = String;
        _iter = _source.cbegin();
    }
    const bool Lexer::Tokenize( Token* const NextToken )
    {
        if( _iter != _source.cend() )
        {
            while( std::isspace( *_iter ) )
                ++_iter;

            if( _iter != _source.cend() )
            {
                NextToken->Type = Token::type::None;
                NextToken->Data.clear();

                if( std::isalpha( *_iter ) || *_iter == '_' )
                {
                    NextToken->Type = Token::type::Word;

                    while( std::isalpha( *_iter ) || std::isdigit( *_iter ) || *_iter == '_' )
                        NextToken->Data += *_iter++;
                }
                else if( std::isdigit( *_iter ) )
                {
                    //TODO: Handle hex and octal
                    NextToken->Type = Token::type::Number;

                    while( std::isdigit( *_iter ) )
                        NextToken->Data += *_iter++;
                }
                else if( *_iter == '\"' )
                {
                    //TODO: Handle unended strings.
                    //TODO: Handle escape chars, IE: \n, \t, \r
                    NextToken->Type = Token::type::String;
                    //Skip initial quote...
                    ++_iter;

                    while( *_iter != '\"' )
                    {
                        if( *_iter == '\\' )
                            NextToken->Data += *_iter++;

                        NextToken->Data += *_iter++;
                    }

                    //Skip end quote...
                    ++_iter;
                }
                else
                {
                    NextToken->Type = Token::type::Symbol;

                    while( !std::isspace( *_iter ) && !std::isalpha( *_iter ) && *_iter != '_' && !std::isdigit( *_iter ) && *_iter != '\"' && _iter != _source.cend() )
                        NextToken->Data += *_iter++;
                }

                return true;
            }
        }

        return false;
    }
}