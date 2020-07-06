#pragma once
#include <math.h>
#include <string>

using namespace System;
array <int^>^ find_money(String^ S1)
{
	array <int^>^ arr = gcnew array <int^>(3);
	if (Convert::ToDouble(S1) > 1000)
	{
		arr[0] = Convert::ToInt32(Convert::ToDouble(S1) / 1000);
		arr[1] = Convert::ToInt32(Convert::ToDouble(S1) - Convert::ToDouble(arr[0]) * 1000);
		for (int i = 0; i < S1->Length; i++)
		{
			if (S1[i] == ',')
			{
				arr[2] = Convert::ToInt32(S1->Substring(S1->Length - 2)); //Копейки
				if (Convert::ToInt32(arr[2]) > Convert::ToInt32(49))
				{
					arr[1] = Convert::ToInt32(arr[1]) - Convert::ToInt32(1);
				}
				break;
			}
			else arr[2] = 0;
		}
		return arr;
	}
	else
	{
		arr[0] = 0;
		arr[1] = Convert::ToInt32(Convert::ToDouble(S1));
		for (int i = 0; i < S1->Length; i++)
		{
			if (S1[i] == ',')
			{
				arr[2] = Convert::ToInt32(S1->Substring(S1->Length - 2)); //Копейки
				if (Convert::ToInt32(arr[2]) > Convert::ToInt32(49))
				{
					arr[1] = Convert::ToInt32(arr[1]) - Convert::ToInt32(1);
				}
				break;
			}
			else arr[2] = 0;
		}
		return arr;
	}
}
