#pragma once

#include <QString>
#include <QtGlobal>
#include <QMessageLogContext>


class Util
{
public:
	static bool enableCustomConsoleStream;

public:
	static QString pathToLowerCamelCase(QString resourcePath);
	static void customMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg);
};
