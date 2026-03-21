#pragma once

#include "UI/Pokemon/pokemonBulbasaur.h"


enum PokemonType
{
	Begin,
	Bulbasaur,
	End
};

class PlayPokemon
{
public:
	static PokemonBase* playPokemon1P;
	static PokemonBase* playPokemon2P;
	static PokemonType currentPokemon1P;
	static PokemonType currentPokemon2P;

public:
	// Must be called after resources are loaded (Picture initialized),
	// otherwise Pokemon constructors may try to create QPixmaps prematurely.
	static void init();

	void switchPreviousPokemon(bool isSwitch1P);
	void switchNextPokemon(bool isSwitch1P);
	void updatePlayPokemon(bool isSwitch1P);

};
