#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowUsersListScreen.h"
#include "clsShowAddUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsShowUpdateUserScreen.h"
#include "clsShowFindUserScreen.h"

using namespace std;
class clsMangeUsersScreen:protected clsScreen
{
private:
	enum enMangeUsersOptions { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4,
								eFindUser = 5, eMainMenue = 6};

	static short _ReadMangeUsersOption()
	{
		cout << "Choose What do you want to do? [1 to 6]? ";
		short Option = clsInputValidate::ReadShortNumberBetween(1,6,"Please enter between [1 to 6]? ");
		return Option;
	}

	static void _ShowUsersListScreen()
	{
		clsShowUsersListScreen::ShowUsersListScreen();
	}

	static void _ShowAddUsersScreen()
	{
		clsShowAddUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsShowUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsShowFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToMangeUsersMenue()
	{
		cout << "\n\tPress Any Key to go back to Mange Users Menue...\n";
		system("pause>0");
		ShowMangeUsersMenue();
	}

	static void _PerformMangeUsersOption(enMangeUsersOptions Option)
	{
		switch (Option)
		{
		case clsMangeUsersScreen::eListUsers:
			system("cls");
			_ShowUsersListScreen();
			 _GoBackToMangeUsersMenue();
			break;
		case clsMangeUsersScreen::eAddNewUser:
			system("cls");
			_ShowAddUsersScreen();
			 _GoBackToMangeUsersMenue();
			break;
		case clsMangeUsersScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			 _GoBackToMangeUsersMenue();
			break;
		case clsMangeUsersScreen::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			 _GoBackToMangeUsersMenue();
			break;
		case clsMangeUsersScreen::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			 _GoBackToMangeUsersMenue();
			break;
		case clsMangeUsersScreen::eMainMenue:
		{

		}
		}
	}

public:

	static void ShowMangeUsersMenue()
	{
		system("cls");
		_DrawScreenHeader("\t Mange Users Screen");

		cout << "\t\t\t\t==============================================\n";
		cout << "\t\t\t\t\t\tMange Users Menue\n";
		cout << "\t\t\t\t==============================================\n";

		cout << "\t\t\t\t\t[1] List Users.\n";
		cout << "\t\t\t\t\t[2] Add New User.\n";
		cout << "\t\t\t\t\t[3] Delete User.\n";
		cout << "\t\t\t\t\t[4] Update User.\n";
		cout << "\t\t\t\t\t[5] Find User.\n";
		cout << "\t\t\t\t\t[6] Main Menue.\n";
		cout << "\t\t\t\t==============================================\n";

		_PerformMangeUsersOption((enMangeUsersOptions) _ReadMangeUsersOption());

	}
};

