#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include <iomanip>

using namespace std;

class clsTransactionsMenue:protected clsScreen
{
private:

	enum enTransactionsMenue { eDeposit =  1,eWithDraw = 2, eShowTotalBalance = 3, eShowMainMenue = 4 };

	static short _ReadTransActionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose What do you want to do? [1 to 4]? ";
		short Choise = clsInputValidate::ReadShortNumberBetween(1,4,"Please enter Number from 1 to 4");

		return Choise;
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithDrawScreen()
	{
		clsWithDrawScreen::ShowWithDrawScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalanceScreen::ShowTotalBalance();
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\nPress any Key To Back To Transactions Menue...\n";
		system("pause>0");
		ShowTransActionsMenue();
	}

	static void _PerformTransactionsMenueOption(enTransactionsMenue TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case clsTransactionsMenue::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsMenue::eWithDraw:
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsMenue::eShowTotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsMenue::eShowMainMenue:
		{

		}
		}
	}

public:

	static void ShowTransActionsMenue()
	{
		system("cls");
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenueOption((enTransactionsMenue)_ReadTransActionsMenueOption());
	}

};

