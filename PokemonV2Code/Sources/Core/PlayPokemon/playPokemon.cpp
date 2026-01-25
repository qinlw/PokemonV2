#include "Core/PlayPokemon/playPokemon.h"


PokemonBase* PlayPokemon::playPokemon1P = PokemonBulbasaur::getInstance1P();
PokemonBase* PlayPokemon::playPokemon2P = PokemonBulbasaur::getInstance2P();
PokemonType PlayPokemon::currentPokemon1P = PokemonType::Bulbasaur;
PokemonType PlayPokemon::currentPokemon2P = PokemonType::Bulbasaur;

void PlayPokemon::switchPreviousPokemon(bool isSwitch1P)
{
	PokemonType& currentPokemon = isSwitch1P ? currentPokemon1P : currentPokemon2P;
	if (currentPokemon - 1 == PokemonType::Begin)
		currentPokemon = static_cast<PokemonType>(PokemonType::End - 1);
	else
		currentPokemon = static_cast<PokemonType>(currentPokemon - 1);
	updatePlayPokemon(isSwitch1P);
}

void PlayPokemon::switchNextPokemon(bool isSwitch1P)
{
	PokemonType& currentPokemon = isSwitch1P ? currentPokemon1P : currentPokemon2P;
	if (currentPokemon + 1 == PokemonType::End)
		currentPokemon = static_cast<PokemonType>(PokemonType::Begin + 1);
	else
		currentPokemon = static_cast<PokemonType>(currentPokemon + 1);
	updatePlayPokemon(isSwitch1P);
}

void PlayPokemon::updatePlayPokemon(bool isSwitch1P)
{
	PokemonBase*& playPokemon = isSwitch1P ? playPokemon1P : playPokemon2P;
	PokemonType& currentPokemon = isSwitch1P ? currentPokemon1P : currentPokemon2P;
	switch (currentPokemon)
	{
	case Bulbasaur:
		playPokemon = isSwitch1P ? PokemonBulbasaur::getInstance1P() : PokemonBulbasaur::getInstance2P();
		break;
	default:
		qWarning() << "currentPokemon is invalid";
		break;
	}
}

