#pragma once

#include "UI/Pokemon/pokemonBase.h"

class PokemonBulbasaur : public PokemonBase
{
public:
	PokemonBulbasaur(const PokemonBulbasaur& obj) = delete;
	PokemonBulbasaur& operator=(const PokemonBulbasaur& obj) = delete;
	static PokemonBulbasaur* getInstance1P();
	static PokemonBulbasaur* getInstance2P();

private:
	PokemonBulbasaur();

};
