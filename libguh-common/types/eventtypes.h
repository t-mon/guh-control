/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Copyright (C) 2017 Simon Stuerz <simon.stuerz@guh.io>                  *
 *                                                                         *
 *  This file is part of guh-control                                       *
 *                                                                         *
 *  This library is free software; you can redistribute it and/or          *
 *  modify it under the terms of the GNU Lesser General Public             *
 *  License as published by the Free Software Foundation; either           *
 *  version 2.1 of the License, or (at your option) any later version.     *
 *                                                                         *
 *  This library is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      *
 *  Lesser General Public License for more details.                        *
 *                                                                         *
 *  You should have received a copy of the GNU Lesser General Public       *
 *  License along with this library; If not, see                           *
 *  <http://www.gnu.org/licenses/>.                                        *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef EVENTTYPES_H
#define EVENTTYPES_H

#include <QObject>
#include <QAbstractListModel>

#include "eventtype.h"

class EventTypes : public QAbstractListModel
{
    Q_OBJECT

public:
    enum EventTypeRole {
        NameRole = Qt::DisplayRole,
        IdRole
    };

    EventTypes(QObject *parent = 0);

    QList<EventType *> eventTypes();

    Q_INVOKABLE int count() const;
    Q_INVOKABLE EventType *get(int index) const;
    Q_INVOKABLE EventType *getEventType(const QUuid &eventTypeId) const;

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    void addEventType(EventType *eventType);

    void clearModel();

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<EventType *> m_eventTypes;

};

#endif // EVENTTYPES_H
