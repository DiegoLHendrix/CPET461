/*
 * my_flag.c
 *
 *  Created on: Feb 23, 2024
 *      Author: diego
 */
#include "my_flags.h"

Flag SFlag1 = Reset;
Flag SFlag2 = Reset;

void Set_Flag (int flag_num)
{
	switch(flag_num)
	{
	case 1 : SFlag1 = Set;
	break;
	case 2 : SFlag2 = Set;
	break;
	}
	return;
}

void Reset_Flag (int flag_num)
{
	switch(flag_num)
	{
	case 1 : SFlag1 = Reset;
	break;
	case 2 : SFlag2 = Reset;
	break;
	}
	return;
}

Flag Check_Flag(int flag_num)
{
	Flag temp;
	switch(flag_num)
	{
	case 1 :  temp = SFlag1;
	break;
	case 2 :  temp = SFlag2;
	break;
	}
	return temp;
}
