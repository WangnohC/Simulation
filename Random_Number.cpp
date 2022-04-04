/*************************************************************************************
* 文件名称：随机数                                                                   *
* 作    者：                                                                         *
* 版    本：                                                                         *
* 日    期：                                                                         *
* 功能描述：本程序为随机数产生程序，用于产生随机数。                                 *
* 输    入：该程序为单输入，输入为随机数范围的倒数。                                 *
* 输    出：该程序为单输出，输出为特定范围内的随机数。                               *
* 函数列表：1.getRandom_Number()——用于产生随机数。                                 *
* 历    史：                                                                         *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Random_Number.h"
#include <stdlib.h> 
#include <ctime>

Random_Number::Random_Number()
{
}


Random_Number::~Random_Number()
{
}

/*************************************************************************************
* 描述：getRandom_Number()函数用于产生随机数，输入为需要产生随机数的范围Range，输出为*
*       所产生的随机数RN。                                                           *
*************************************************************************************/
double Random_Number::getRandom_Number(int Range)
{
	srand((unsigned)time(NULL));
	double RN = ((double)(rand() % Range));

	return RN;
}
