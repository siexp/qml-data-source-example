#include "user.h"

User::User(QObject *parent) :
    QObject{ parent },
    m_username{ "user" },
    m_password{ "5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8" },
    m_email{ "user@example.com" },
    m_balance{ 0 }
{
}

QString User::username() const
{
    return m_username;
}

void User::setUsername(const QString &username)
{
    if ( m_username != username )
    {
        m_username = username;
        emit usernameChanged();
    }
}

QString User::password() const
{
    return m_password;
}

void User::setPassword(const QString &password)
{
    if ( m_password != password )
    {
        m_password = password;
        emit passwordChanged();
    }
}

QString User::email() const
{
    return m_email;
}

void User::setEmail(const QString &email)
{
    if ( m_email != email )
    {
        m_email = email;
        emit emailChanged();
    }
}

qint64 User::balance() const
{
    return m_balance;
}

void User::setBalance(const qint64 &balance)
{
    if ( m_balance != balance )
    {
        m_balance = balance;
        emit balanceChanged();
    }
}
