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

#include "eventtype.h"

EventType::EventType(QObject *parent) :
    QObject(parent)
{
}

QUuid EventType::id() const
{
    return m_id;
}

void EventType::setId(const QUuid &id)
{
    m_id = id;
}

QString EventType::name() const
{
    return m_name;
}

void EventType::setName(const QString &name)
{
    m_name = name;
}

int EventType::index() const
{
    return m_index;
}

void EventType::setIndex(const int &index)
{
    m_index = index;
}

ParamTypes *EventType::paramTypes() const
{
    return m_paramTypes;
}

void EventType::setParamTypes(ParamTypes *paramTypes)
{
    m_paramTypes = paramTypes;
}

