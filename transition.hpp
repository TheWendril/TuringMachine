#ifndef TRANSITION_HPP
#define TRANSITION_HPP

#include "moviment.hpp"
#include "symbol.hpp"
#include "state.hpp"

struct Transition
{
    Symbol read;
    Symbol write;
    Moviment direction;
    State current;
    State next;
};


#endif