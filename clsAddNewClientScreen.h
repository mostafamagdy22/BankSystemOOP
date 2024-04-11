#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsAddNewClientScreen:protected clsScreen
{
protected:
   static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

   static void _PrintClient(clsBankClient Client)
   {
       cout << "\nClient Card:";
       cout << "\n___________________";
       cout << "\nFirstName   : " << Client.FirstName;
       cout << "\nLastName    : " << Client.LastName;
       cout << "\nFull Name   : " << Client.FullName();
       cout << "\nEmail       : " << Client.Email;
       cout << "\nPhone       : " << Client.Phone;
       cout << "\nAcc. Number : " << Client.AccountNumber();
       cout << "\nPassword    : " << Client.PinCode;
       cout << "\nBalance     : " << Client.AccountBalance;
       cout << "\n___________________\n";

   }


public:
   static void AddNewClient()
    {

        string AccountNumber = "";

        _DrawScreenHeader("\t\tAdd Client Screen");

        cout << "\nPlease Enter Account Number? ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::isClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResults;

        SaveResults = NewClient.Save();

        switch (SaveResults)
        {
        case clsBankClient::enSaveResults::svSuccessed:
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "\nError account was not saved because it's Empty";
            break;
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }

    }
};

