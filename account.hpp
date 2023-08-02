#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "user.hpp"

class Account
{
private:
    User *m_user;

    const std::string c_special = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz._";
    const std::string c_digits = "0123456789";
    const std::string c_uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string c_lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string c_none = "None";

    bool has_special_chars(const std::string &);
    bool contains(const std::string &, const std::string);

    bool valid_password(std::string);
    bool valid_username(std::string);

public:
    Account(std::string, std::string);
    Account();
    ~Account();

    std::string username();
    void set_username(std::string);
    std::string password();
    void set_password(std::string);

    bool initialized(std::string);
};

#endif //ACCOUNT_HPP