#include "UI/Pokemon/pokemonBulbasaur.h"

PokemonBulbasaur::PokemonBulbasaur()
{
	// 初始化帧图
	selectorPokemonPixmap = globalPicture->getPixmapList(globalString->selectorBulbasaur);
	pokemonPixmap = globalPicture->getPixmapList(globalString->bulbasaur);
	// 初始化尺寸 帧数
	if (!pokemonPixmap.empty())
	{
		pokemonWidth = pokemonPixmap[0].width();
		pokemonHeight = pokemonPixmap[0].height();
	}
	frameSumCount = pokemonPixmap.size();
	// 初始化碰撞路径
	createCollisionShapeFromFrame(0, 20);
	// 自定义参数
	moveSpeed = 3.0;
}

PokemonBulbasaur* PokemonBulbasaur::getInstance1P()
{
	static PokemonBulbasaur globalBulbasaur1P;
	return &globalBulbasaur1P;
}

PokemonBulbasaur* PokemonBulbasaur::getInstance2P()
{
	static PokemonBulbasaur globalBulbasaur2P;
	return &globalBulbasaur2P;
}
