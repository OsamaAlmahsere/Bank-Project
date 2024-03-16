#pragma once
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsScreen.h"
#include<iostream>

class clsUpdateCurrencyRateScreen:protected clsScreen
{

private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

	

public :

	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");

		string CurrencyCode = "";

		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\n\nUpdate Currency Rate:";
			cout << "\n____________________\n";

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrency(Currency);
		}
	}
};

