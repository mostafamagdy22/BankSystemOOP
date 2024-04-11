#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMenue.h"
#include "clsMangeUsersScreen.h"
using namespace std;

class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenueOptions {
		eListClients = 1,eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4,eFindClient = 5,eShowTransactionsMenue = 6,
		eMangeUsers = 7,eExit = 8
	};

	static short _ReadMainMenueOption()
	{
		short option;

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
		option = clsInputValidate::ReadShortNumberBetween(1,8,"Enter Number between 1 to 8? ");
		return option;
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
	
		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		clsAddNewClientScreen::AddNewClient();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::UpdateClient();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenueScreen()
	{
		clsTransactionsMenue::ShowTransActionsMenue();
	}

	static void _ShowMangeUsersScreen()
	{
		clsMangeUsersScreen::ShowMangeUsersMenue();
	}

	static void _ShowEndScreen()
	{
		cout << "\nEnd Screen Will be here...\n";
	}

	static void _PerformMainMenueOption(enMainMenueOptions MainMenueOption)
	{

		switch (MainMenueOption)
		{
		case clsMainScreen::eListClients:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eShowTransactionsMenue:
			system("cls");
			_ShowTransactionsMenueScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eMangeUsers:
			system("cls");
			_ShowMangeUsersScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eExit:
			system("cls");
			_ShowEndScreen();
			break;
		}

	}
	public:
		static void ShowMainMenue()
		{
			system("cls");
			_DrawScreenHeader("\t\tMain Screen");

			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
			cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
			cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
			cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
			cout << setw(37) << left << "" << "\t[5] Find Client.\n";
			cout << setw(37) << left << "" << "\t[6] Transactions.\n";
			cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
			cout << setw(37) << left << "" << "\t[8] Logout.\n";
			cout << setw(37) << left << "" << "===========================================\n";

			_PerformMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
		}
};

