#include "user.hpp"

User::User()
{
    m_password = 0;
    m_username = "";
}

void User::set_password(std::string password)
{
    std::hash<std::string> hasher;
    m_password = hasher(password);
}

size_t User::password()
{    
    return m_password;
}

void User::set_username(std::string username)
{
    m_username = username;
}

std::string User::username()
{
    return m_username;
}

bool User::compare(std::string password2)
{
    std::hash<std::string> hasher;
    size_t pw = hasher(password2);

    return pw == m_password;
}