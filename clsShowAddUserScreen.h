#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;
class clsShowAddUserScreen:protected clsScreen
{
private:


	static void _ReadUserInfo(clsUser &User)
	{
		

		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions: ";
		User.Permissions = _ReadPermissionsToSet();

	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFulName     : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions   : " << User.Permissions;
		cout << "\n__________________\n";
	}

	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		
		cout << "\nDo you want to gie full access? y/n? ";
		bool Answer = clsInputValidate::ReadYandN();

		if (Answer)
			return -1;

		cout << "\nDo you want to give access to: \n";

		cout << "\nShow Client List? y/n? ";
		Answer = clsInputValidate::ReadYandN();

		if (Answer)
			Permissions += clsUser::enPermissions::pListClients;

		cout << "\nAdd New Client? y/n? ";
		Answer = clsInputValidate::ReadYandN();

		if (Answer)
			Permissions += clsUser::enPermissions::pAddNewClient;

		cout << "\nDelete Client? y/n? ";
		Answer = clsInputValidate::ReadYandN();

		if (Answer)
			Permissions += clsUser::enPermissions::pDeleteClient;

		cout << "\nUpdate Client? y/n? ";
		Answer = clsInputValidate::ReadYandN();
	
		if (Answer)
			Permissions += clsUser::enPermissions::pUpdateClients;

		cout << "\nFind Client? y/n? ";
		Answer = clsInputValidate::ReadYandN();

		if (Answer)
			Permissions += clsUser::enPermissions::pFindClient;
	
		cout << "\nTransactions Menue? y/n? ";
		Answer = clsInputValidate::ReadYandN();

		if (Answer)
			Permissions += clsUser::enPermissions::pTransactions;

		cout << "\nMange Users Menue? y/n? ";
		Answer = clsInputValidate::ReadYandN();

		if (Answer)
			Permissions += clsUser::enPermissions::pMangeUsers;
	
		return Permissions;
	}

public:
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t   Add New User Screen");
		
		string UserName = "";

		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "UserName Is Already Used, Choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::svFaildEmptyObject:
		{
			cout << "\nERROR User was not saved because it's Empty.\n";
			break;
		}
		case clsUser::svSucceeded:
		{
			cout << "\nUser Addeded Successfully :-)\n";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::svFaildUserExists:
		{
			cout << "\nERROR User was not saved because UserName is used!\n";
			break;
		}
		}

	}
};

