#include <iostream>
#include "controlUnit.hpp"


int main(){

    std::string input{"00111111101"};

    std::list<Symbol> symbolList = Tape::str_2_symbol(input);
    Tape tape = Tape{symbolList};
    
    State q1{"q1", false, true}, q2{"q2", true, false};
    
    std::list<State> states = std::list<State>{q1, q2};

    Transition t1{Symbol::A, Symbol::READ, Moviment::RIGHT, q1, q2},
               t2{Symbol::B, Symbol::READ, Moviment::RIGHT, q1, q1},
               t3{Symbol::A, Symbol::READ, Moviment::RIGHT, q2, q1},
               t4{Symbol::B, Symbol::READ, Moviment::RIGHT, q2, q2};


    std::list<Transition> transitions = std::list<Transition>{t1, t2, t3, t4};

    ControlUnit controlunit = ControlUnit{states, transitions};

    bool is_valid = controlunit.process_list(tape);

    std::cout << is_valid << std::endl;

return 0;
}