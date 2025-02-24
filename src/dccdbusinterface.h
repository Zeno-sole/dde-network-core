/*
 * Copyright (C) 2021 ~ 2023 Deepin Technology Co., Ltd.
 *
 * Author:     caixiangrong <caixiangrong@uniontech.com>
 *
 * Maintainer: caixiangrong <caixiangrong@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DCCDBUSINTERFACE_H
#define DCCDBUSINTERFACE_H

#include <QDBusAbstractInterface>

namespace dde {
namespace network {

class DCCDBusInterfacePrivate;

class DCCDBusInterface : public QDBusAbstractInterface
{
    Q_OBJECT

public:
    explicit DCCDBusInterface(const QString &service, const QString &path, const QString &interface = QString(),
                              const QDBusConnection &connection = QDBusConnection::sessionBus(), QObject *parent = nullptr);
    virtual ~DCCDBusInterface() override;

    QString suffix() const;
    void setSuffix(const QString &suffix);

    QVariant property(const char *propname);
    void setProperty(const char *propname, const QVariant &value);

private:
    QScopedPointer<DCCDBusInterfacePrivate> d_ptr;
    Q_DECLARE_PRIVATE(DCCDBusInterface)
    Q_DISABLE_COPY(DCCDBusInterface)
};

}
}

#endif // DCCDBUSINTERFACE_H
