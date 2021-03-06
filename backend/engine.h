/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Copyright (C) 2017 Simon Stuerz <simon.stuerz@guh.io>                  *
 *                                                                         *
 *  This file is part of guh-control.                                      *
 *                                                                         *
 *  guh-control is free software: you can redistribute it and/or modify    *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, version 3 of the License.                *
 *                                                                         *
 *  guh-control is distributed in the hope that it will be useful,         *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with guh-control. If not, see <http://www.gnu.org/licenses/>.    *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>

#include "devicemanager.h"
#include "websocketinterface.h"
#include "jsonrpc/jsonrpcclient.h"

class Engine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged)
    Q_PROPERTY(DeviceManager *deviceManager READ deviceManager CONSTANT)
    Q_PROPERTY(JsonRpcClient *jsonRpcClient READ jsonRpcClient CONSTANT)
    Q_PROPERTY(WebsocketInterface *interface READ interface CONSTANT)

public:
    static Engine *instance();
    static QObject *qmlInstance(QQmlEngine *qmlEngine, QJSEngine *jsEngine);

    bool connected() const;

    DeviceManager *deviceManager();
    JsonRpcClient *jsonRpcClient();
    WebsocketInterface *interface();

    Q_INVOKABLE void connectGuh();

private:
    explicit Engine(QObject *parent = 0);
    static Engine *s_instance;

    bool m_connected;

    DeviceManager *m_deviceManager;
    JsonRpcClient *m_jsonRpcClient;
    WebsocketInterface *m_interface;

    void setConnected(const bool &connected);

signals:
    void connectedChanged(const bool &connected);

private slots:
    void onConnectedChanged(const bool &connected);

public slots:

};

#endif // ENGINE_H
