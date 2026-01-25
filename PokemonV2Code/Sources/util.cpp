#include <iostream>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDir>
#include "util.h"


bool Util::enableCustomConsoleStream = false;

// 转换实例： ":/Button/start_button" -> "startButton"
QString Util::pathToLowerCamelCase(QString resourcePath)
{
	// 提取资源别名
	// 搜索别名的起始索引
	int aliasStartIdx = resourcePath.size() - 1;
	for (; aliasStartIdx >= 0; --aliasStartIdx)
	{
		if (resourcePath[aliasStartIdx] == '/')
			break;
	}
	// 截取
	resourcePath = resourcePath.mid(aliasStartIdx + 1);

	// 转换成小驼峰
	bool needCapital = false;
	int resourcePathSize = resourcePath.size();
	QString retString;
	for (int i = 0; i < resourcePathSize; ++i)
	{
		if (resourcePath[i] == '_')
		{
			needCapital = true;
		}
		else if (needCapital && resourcePath[i].isLetter())
		{
			needCapital = false;
			retString += resourcePath[i].toUpper();
		}
		else
		{
			retString += resourcePath[i];
		}
	}

	return retString;
}

void Util::customMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
	// 1. 定义日志级别文本
	QString levelText;
	switch (type) {
	case QtDebugMsg:
		levelText = "DEBUG";
		break;
	case QtWarningMsg:
		levelText = "WARNING";
		break;
	case QtCriticalMsg:
		levelText = "CRITICAL";
		break;
	case QtFatalMsg:
		levelText = "FATAL";
		break;
	case QtInfoMsg: // Qt5.5+ 新增的 info 级别
		levelText = "INFO";
		break;
	default:
		levelText = "UNKNOWN";
		break;
	}

	// 2. 格式化日志内容（包含时间、级别、消息、文件行号）
	QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
	QString logText = QString("[%1] [%2] %3 (File: %4, Line: %5)")
		.arg(currentTime)
		.arg(levelText)
		.arg(msg)
		.arg(context.file ? context.file : "unknown")
		.arg(context.line);

	// 3. 输出到控制台（保留原有控制台输出）
#ifdef Q_OS_WIN
	QString outputText = enableCustomConsoleStream ? logText : msg;
	QByteArray consoleData = outputText.toLocal8Bit(); // Windows 下自动转 GBK
	fwrite(consoleData.data(), 1, consoleData.size(), stdout);
	fputs("\n", stdout);
	fflush(stdout); // 强制刷新缓冲区，避免积压
#else
	// Linux/macOS 用 QTextStream + UTF-8
	QTextStream consoleStream(stdout);
	consoleStream.setEncoding(QStringConverter::Utf8);
	if (enableCustomConsoleStream)
		consoleStream << logText << Qt::endl;
	else
		consoleStream << msg << Qt::endl;
#endif

	// 4. 写入日志文件
	// 日志文件路径（可自定义，这里按日期命名，放在程序运行目录的 log 文件夹下）
	QString logDir = QCoreApplication::applicationDirPath() + "../../../../log";
	QDir dir;
	if (!dir.exists(logDir)) {
		dir.mkpath(logDir); // 自动创建日志目录
	}
	QString logFileName = logDir + "/" + QDate::currentDate().toString("yyyy-MM-dd") + ".log";

	// 以追加模式打开文件
	QFile file(logFileName);
	if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
		QTextStream fileStream(&file);
		fileStream << logText << Qt::endl;
		file.close();
	}

	// 处理致命错误，确保程序退出
	if (type == QtFatalMsg) {
		abort();
	}
}
