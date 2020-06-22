#pragma once

#include <QObject>

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(qint64 balance READ balance WRITE setBalance NOTIFY balanceChanged)
public:
    explicit User(QObject *parent = nullptr);

    QString username() const;
    void setUsername(const QString &username);

    QString password() const;
    void setPassword(const QString &password);

    QString email() const;
    void setEmail(const QString &email);

    qint64 balance() const;
    void setBalance(const qint64 &balance);

signals:
    void usernameChanged();
    void passwordChanged();
    void emailChanged();
    void balanceChanged();

private:
    QString m_username;
    QString m_password;
    QString m_email;
    qint64  m_balance;
};
