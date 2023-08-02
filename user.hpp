#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <unordered_map>

class User
{
private:
    size_t m_password;
    std::string m_username;
public:
    User();

    void set_username(std::string);
    void set_password(std::string);

    std::string username();
    size_t password();

    bool compare(std::string);
};

#endif //USER_HPP