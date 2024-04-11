#pragma once
#include "clsScreen.h"
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteUserScreen:protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName    : " << User.FirstName;
		cout << "\nLastName     : " << User.LastName;
		cout << "\nFullName     : " << User.FullName();
		cout << "\nEmail        : " << User.Email;
		cout << "\nPhome        : " << User.Phone;
		cout << "\nUser Name    : " << User.UserName;
		cout << "\nPassword     : " << User.Password;
		cout << "\nPermissions  : " << User.Permissions;
		cout << "\n___________________\n";
	}
public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\tDelete User Screen");

		string UserName = "";
		cout << "\nPlease enter User Name To Delete User? ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser With this username (" << UserName << ") isnt exist! please enter another: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		cout << "\nAre you sure you want to delete this user? y/n? ";
		bool Answer = clsInputValidate::ReadYandN();

		if (Answer)
			User.Delete();
		else
			cout << "\nDelete Operation is Cancelled.\n";

	}
};

