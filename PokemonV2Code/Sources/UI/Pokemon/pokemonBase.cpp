#include "UI/Pokemon/pokemonBase.h"


PokemonBase::PokemonBase() :
	currentDirectionLeft(true),
	pokemonWidth(0),
	pokemonHeight(0),
	moveSpeed(0),
	currentFrameIndex(0),
	frameSumCount(0)
{

}

QRectF PokemonBase::boundingRect() const
{ 
	std::cout << "boundingRect need TODO" << std::endl;
	return QRectF();
}

QPainterPath PokemonBase::shape() const
{ 
	std::cout << "boundingRect need TODO" << std::endl; 
	return QPainterPath();
}

void PokemonBase::switchDirection(bool isLeft)
{
	currentDirectionLeft = isLeft;
}

void PokemonBase::playNextFrame()
{
	if (currentFrameIndex < frameSumCount - 1)
		++currentFrameIndex;
	else
		currentFrameIndex = 0;
}

QPixmap PokemonBase::flipPixmap(const QPixmap& pixmap)
{
	QTransform transform;
	transform.scale(-1, 1); // 水平翻转
	return pixmap.transformed(transform, Qt::SmoothTransformation);
}
