#include "util.h"

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
			resourcePath[i] = resourcePath[i].toUpper();
			needCapital = false;
			retString += resourcePath[i];
		}
		else
		{
			retString += resourcePath[i];
		}
	}

	return retString;
}
