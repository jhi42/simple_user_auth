#include <iostream>
#include <string>
#include "account.hpp"

void seperator()
{
    std::cout << "---------------------------------" << std::endl;  // print line
}

void make_account()
{
    bool valid_username = false, valid_passwd = false;
    std::string username, passwd;
    Account account = Account();    // empty account object

    do 
    {
        seperator();

        std::cout << "Username: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> passwd;
    
        seperator();

        // later than cin to not interrupt user input
        account.set_username(username);
        account.set_password(passwd);

        // return "None" if not initialized
        valid_username = account.initialized(account.username());
        valid_passwd = account.initialized(account.password());
    } 
    while (!valid_passwd || !valid_username);

    std::cout << "Successfully created user!" << 
        std::endl;
}

int main() 
{
    make_account();
    return 0;
}