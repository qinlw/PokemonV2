#include <QPainter>
#include "UI/Pokemon/pokemonBase.h"


PokemonBase::PokemonBase() :
	currentDirectionLeft(true),
	pokemonWidth(0),
	pokemonHeight(0),
	moveSpeed(0),
	currentFrameIndex(0),
	frameSumCount(0)
{
	globalPicture = Picture::getInstance();
	globalString = ResourceStringName::getInstance();
}

std::vector<QPixmap> PokemonBase::getSelectorPokemonPixmap()
{
	return selectorPokemonPixmap;
}

std::vector<QPixmap> PokemonBase::getPokemonPixmap()
{
	return pokemonPixmap;
}

PokemonBase::~PokemonBase()
{
	pokemonPixmap.clear();
	selectorPokemonPixmap.clear();
	collisionShape = QPainterPath();
}

QRectF PokemonBase::boundingRect() const
{
	return QRectF(-1, -1, pokemonWidth + 2, pokemonHeight + 2);
}

QPainterPath PokemonBase::shape() const
{
	// 如果未生成碰撞路径，返回默认矩形
	if (collisionShape.isEmpty()) {
		QPainterPath path;
		path.addRect(0, 0, pokemonWidth, pokemonHeight);
		return path;
	}
	return collisionShape;
}

void PokemonBase::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	if (pokemonPixmap.empty() || currentFrameIndex >= pokemonPixmap.size()) {
		qWarning() << "pokemonPixmap is nullptr || currentFrameIndex >= pokemonPixmap.size()！";
		return;
	}

	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->setRenderHint(QPainter::SmoothPixmapTransform, true);

	const QPixmap& currentFrame = pokemonPixmap[currentFrameIndex];

	if (!currentDirectionLeft) {
		painter->translate(currentFrame.width(), 0);
		painter->scale(-1, 1);
	}

	painter->drawPixmap(0, 0, currentFrame);
}

void PokemonBase::switchDirection(bool isLeft)
{
	if (currentDirectionLeft != isLeft)
	{
		currentDirectionLeft = isLeft;
		update();
	}
}

void PokemonBase::createCollisionShapeFromFrame(int frameIndex, int alphaThreshold)
{
	if (pokemonPixmap.empty() || frameIndex < 0 || frameIndex >= pokemonPixmap.size()) {
		qWarning() << "frameIndex is invalid, generate collision path fail!";
		collisionShape = QPainterPath(); 
		return;
	}

	const QPixmap& framePixmap = pokemonPixmap[frameIndex];
	QImage frameImage = framePixmap.toImage();
	int width = frameImage.width();
	int height = frameImage.height();

	QPainterPath shapePath;

	for (int y = 0; y < height; ++y) {
		uchar* scanLine = frameImage.scanLine(y);
		bool inOpaqueRegion = false;
		int startX = 0;

		for (int x = 0; x < width; ++x) {
			uchar alpha = scanLine[x * 4];

			if (alpha > alphaThreshold && !inOpaqueRegion) {
				startX = x;
				inOpaqueRegion = true;
			}
			else if (alpha <= alphaThreshold && inOpaqueRegion) {
				shapePath.addRect(startX, y, x - startX, 1);
				inOpaqueRegion = false;
			}
		}

		if (inOpaqueRegion) {
			shapePath.addRect(startX, y, width - startX, 1);
		}
	}

	collisionShape = shapePath.simplified();
	qDebug() << "Collision path generation completed. Number of nodes: " << collisionShape.elementCount();
}

void PokemonBase::playNextFrame()
{
	if (currentFrameIndex < frameSumCount - 1)
		++currentFrameIndex;
	else
		currentFrameIndex = 0;
	update();
}

QPixmap PokemonBase::flipPixmap(const QPixmap& pixmap)
{
	QTransform transform;
	transform.scale(-1, 1); // 水平翻转
	return pixmap.transformed(transform, Qt::SmoothTransformation);
}
