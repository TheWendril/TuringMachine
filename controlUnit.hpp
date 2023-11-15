#ifndef CONTROLUNIT_HPP
#define CONTROLUNIT_HPP

#include <list>
#include "state.hpp"
#include "symbol.hpp"
#include "tape.hpp"
#include "transition.hpp"
#include <algorithm>

class ControlUnit {

private:

    std::list<State> states;
    State current;
    std::list<Transition> transitions;

public:

    ControlUnit(std::list<State> states, std::list<Transition> transitions){
        this->states = states;
        this->transitions = transitions;
        this->current  = * std::find_if( states.begin(), states.end(), [](const State& state){return state.initial == true;} );
    }

    State get(){
        return this->current;
    }

    void process(Symbol symbol){

        Transition transition = * std::find_if(this->transitions.begin(), this->transitions.end(), [this, symbol](const Transition& t){ 
                                     return t.current.name == this->current.name and t.read == symbol; });
        this->current = transition.next;
    }

    bool process_list(Tape& tape){
        
        if(tape.read() == Symbol::BEGIN){

            tape.right();

            while(tape.read() != Symbol::END){

                this->process(tape.read());
                tape.right();
            }

            return this->current.acceptance;
        }

        return false;
    }

};

#endif