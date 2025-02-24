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
#ifndef VPNMODULE_H
#define VPNMODULE_H
#include "interface/pagemodule.h"

#include <dtkwidget_global.h>

DWIDGET_BEGIN_NAMESPACE
class DListView;
DWIDGET_END_NAMESPACE

namespace dde {
namespace network {
class ControllItems;
}
}

class VPNModule : public DCC_NAMESPACE::PageModule
{
    Q_OBJECT
public:
    explicit VPNModule(QObject *parent = nullptr);

private Q_SLOTS:
    void initVPNList(DTK_WIDGET_NAMESPACE::DListView *vpnView);
    void editConnection(dde::network::ControllItems *item, QWidget *parent);
    void importVPN();
    void changeVpnId();

private:
    QList<DCC_NAMESPACE::ModuleObject *> m_modules;
    QString m_newConnectionPath;
    QString m_editingConnUuid;
};

#endif // VPNMODULE_H
