#include "account.hpp"
#include <iostream>

Account::Account(std::string username, std::string password)
{
    m_user = new User();
    set_username(username);
    set_password(password);
}

Account::Account()
{
    m_user = new User();
    m_user->set_username("");
    m_user->set_password("");
}

Account::~Account()
{
    if (m_user != NULL)
        delete m_user;
}

bool Account::valid_password(std::string password)
{
    // at least 10 characters
    if (password.length() <= 9)
        return false;
    // at least 1 uppercase letter
    if (!contains(password, c_uppercase))
        return false;
    // at least 1 lowercase letter
    if (!contains(password, c_lowercase))
        return false;
    // at least 1 digit
    if (!contains(password, c_digits))
        return false;

    return true;
}

bool Account::valid_username(std::string username)
{
    // at least 3 characters
    if (username.length() <= 2)
        return false;
    // only uppercase and lowercase, digits or . and _
    if (has_special_chars(username))
        return false;

    return true;
}

bool Account::has_special_chars(const std::string &str)
{
    if (str.find_first_not_of(c_special) != std::string::npos)
        return true;
    
    return false;
}

std::string Account::username()
{
    if (m_user->username() != "")
        return m_user->username();
    else
        return c_none;
}

std::string Account::password()
{
    // empty string with std::hash
    size_t empty = 6142509188972423790;

    if (m_user->password() != empty)
        return std::to_string(m_user->password());
    else
        return c_none;
}

bool Account::initialized(std::string str)
{
    return str != c_none;
}

bool Account::contains(const std::string &str, const std::string chars)
{
    if (str.find_first_of(chars) != std::string::npos)
        return true;
    
    return false;
}

void Account::set_password(std::string password)
{
    if (valid_password(password))
        m_user->set_password(password);
    else
    {
        std::cerr << 
            "Invalid password!" << std::endl << 
            "Usage:\n" << 
            "- min. 10 characters" << std::endl <<
            "- min. 1 uppercase letter (A-Z)" << std::endl << 
            "- min. 1 lowercase letter (a-z)" << std::endl << 
            "- min. 1 digit (0-9)" << std::endl;
    }
}

void Account::set_username(std::string username)
{
    if (valid_username(username))
        m_user->set_username(username);
    else
    {
        std::cerr << 
            "Invalid username!" << std::endl << 
            "Usage:\n" << 
            "- min. 3 characters" << std::endl <<
            "- only letters (a-z or A-Z) and digits (0-9)" << std::endl << 
            "- '_' (underscore) or '.' (dot)" << std::endl;
    }
}