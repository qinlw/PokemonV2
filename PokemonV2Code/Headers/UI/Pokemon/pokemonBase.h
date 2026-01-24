#pragma once 

#include <iostream>
#include <QGraphicsItem>
#include "Resource/picture.h"


class PokemonBase : public QGraphicsItem
{
protected:
	Picture* globalPicture;
	ResourceStringName* globalString;
	// 帧图
	std::vector<QPixmap> selectorPokemonPixmap;
	std::vector<QPixmap> PokemonPixmap;
	// 碰撞
	QPainterPath collisionShape; // 不规则碰撞路径（从帧图生成
	// 宝可梦状态
	bool currentDirectionLeft;
	// 基础尺寸
	double pokemonWidth;
	double pokemonHeight;
	// 移动相关
	double moveSpeed;
	// 动画相关
	int currentFrameIndex;// 当前播放的帧索引
	int frameSumCount;// 总帧数

public:
	explicit PokemonBase();

protected:
	// QGraphicsItem的纯虚函数
	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override { std::cout << "未重写boundingRect函数" << std::endl; }
	// 通用方法（子类可直接用/重写） 
	virtual void switchDirection(bool isLeft);
	virtual void createCollisionShapeFromFrame(int frameIndex = 0, int alphaThreshold = 20) { std::cout << "createCollisionShapeFromFrame need TODO" << std::endl; }
	virtual void playNextFrame();

private:
	// 辅助：翻转Pixmap（用于切换朝向后的帧图显示）
	QPixmap flipPixmap(const QPixmap& pixmap);

};
