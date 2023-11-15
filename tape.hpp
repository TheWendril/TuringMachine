#ifndef TAPE_HPP
#define TAPE_HPP

#include <list>
#include "symbol.hpp"

class Tape {

private:

    std::list<Symbol> symbolTape;
    std::list<Symbol>::iterator current;

public:

    Tape(std::list<Symbol> symbolList){
        this->symbolTape = symbolList;
        this->current = this->symbolTape.begin();
    }

    void right(){
        this->current++;
    }
    void left(){
        this->current--;
    }

    Symbol read(){
        return *this->current;
    }

    void write(Symbol newSymbol){
        *this->current = newSymbol;
    }

    static std::list<Symbol> str_2_symbol(std::string input){
        
        std::list<Symbol> symbols = std::list<Symbol>{};
        symbols.push_back(Symbol::BEGIN);

        for(auto i : input){
            
            if(i == 48)
                symbols.push_back(Symbol::A);
            else if(i == 49)
                symbols.push_back(Symbol::B);

        }

        symbols.push_back(Symbol::END);
        return symbols;
    }

};



#endif
