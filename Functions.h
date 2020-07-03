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
String^ del_sign(String^ T) {
	array <wchar_t>^ Stop;
	Stop = gcnew array <wchar_t> {'.', ',', '!', '?'}; // Это заданные знаки.
	// Поиск по строке.
	int Found = 0;
	while (1) {
		// Найти.
		Found = T->IndexOfAny(Stop, Found);
		if (Found != -1) {
			// Убить.
			T = T->Remove(Found, 1);
			Found++;
		}
		else break;
	}
	return T;
}

void Transform(String^ T) {
	del_sign(T);
	for (int i = 0; i < T->Length; i++)
	{
		if (T[i] == ' ')
		{
			if ((T[i - 1] == 'я' && T[i - 2] == 'а' && T[i - 3] == 'к') || (T[i - 1] == 'е' && T[i - 2] == 'о' && T[i - 3] == 'к'))
				T->Remove(i - 3, 3);
		}
	}
}
array <wchar_t>^ del(String^ text)
{
	array <wchar_t>^ My_Chars;
	My_Chars = gcnew array <wchar_t>(text->Length+1);
	My_Chars = text->ToCharArray();
	int count = text->Length;
	for (int i = 0; i < count-1; i++)
	{
		for (int i = 0; i < count-1; i++)
		{
			if (My_Chars[i] == ' ' || My_Chars[i] == ',' || My_Chars[i] == '!' || My_Chars[i] == '?' || My_Chars[i] == '.')
			{
				for (int k = i; k < count-1; k++)
				{
					My_Chars[k] = My_Chars[k + 1];
				}
				count--;
			}
		}
		return My_Chars;
	}
}
//
//bool find(array <String^>^ Words, String ^text)
//{
//	for (int i = 0; i < Words->Length; i++)
//		if (Words[i] == text)
//			return false;
//	return true;
//}
//array <String^>^ Dictionary(array <String^> ^Words, String^ Text)
//{
//	int len1 = Text->Length;
//	int len = 0;
//	int k = 0;
//	String^ Word;
//	array <wchar_t>^ p = ' '
//	Text->(Convert::ToString(" "));
//	do
//	{
//		k = Text->IndexOfAny(;
//		if (k == -1) break;
//		// От начала строки до пробела записать в словарь.
//		if (find(Words, len, Text.substr(0, k)) == 1)
//			Words[len++] = Text.substr(0, k);
//		Text.erase(0, k + 1);		// Изменить Text;
//	} while (k != -1);
//}
