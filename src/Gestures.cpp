/**
 * @file /src/Gestures/Gestures.cpp
 *
 * This file is part of Touchégg.
 *
 * Touchégg is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License  as  published by  the  Free Software
 * Foundation,  either version 2 of the License,  or (at your option)  any later
 * version.
 *
 * Touchégg is distributed in the hope that it will be useful,  but  WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the  GNU General Public License  for more details.
 *
 * You should have received a copy of the  GNU General Public License along with
 * Touchégg. If not, see <http://www.gnu.org/licenses/>.
 *
 * @author José Expósito <jose.exposito89@gmail.com> (C) 2011 - 2012
 * @class  Gestures
 */
#include "Gestures.h"

#include <KGenericFactory>

K_PLUGIN_FACTORY(GesturesFactory, registerPlugin<Gestures>();)
K_EXPORT_PLUGIN(GesturesFactory("gestures"))

Gestures::Gestures(QObject *parent, const QVariantList &args) :
    KDEDModule(parent),
    m_windowListener(new WindowListener),
    m_gestureCollector(new GestureCollector(this)),
    m_gestureHandler(new GestureHandler(this))
{
    // There's not much use for args in a KDED
    Q_UNUSED(args)

    qDebug() << "Try to make a multitouch gesture. If everything goes well the "
            "information about the gesture must appear";

    connect(m_gestureCollector, SIGNAL(ready()), this, SLOT(start()));
}

Gestures::~Gestures()
{
    delete m_windowListener;
}

void Gestures::start()
{
    // Connect the WindowListener with the GestureCollector to get the multitouch gestures in the created windows
    connect(m_windowListener, SIGNAL(windowCreated(Window)),
            m_gestureCollector, SLOT(addWindow(Window)));
    connect(m_windowListener, SIGNAL(windowDeleted(Window)),
            m_gestureCollector, SLOT(removeWindow(Window)));

    // The GestureCollector collect the gestures and the GestureHandler perform its and add a layer to perform
    // composed gestures
    connect(m_gestureCollector, SIGNAL(executeGestureStart(
            QString, int, QHash<QString, QVariant>)),
            m_gestureHandler, SLOT(executeGestureStart(
                    QString, int, QHash<QString, QVariant>)));
    connect(m_gestureCollector, SIGNAL(executeGestureUpdate(
            QString, int, QHash<QString, QVariant>)),
            m_gestureHandler, SLOT(executeGestureUpdate(
                    QString, int, QHash<QString, QVariant>)));
    connect(m_gestureCollector, SIGNAL(executeGestureFinish(
            QString, int, QHash<QString, QVariant>)),
            m_gestureHandler, SLOT(executeGestureFinish(
                    QString, int, QHash<QString, QVariant>)));

    // Subscribe to global gestures
    m_gestureCollector->addWindow(QX11Info::appRootWindow());

    // Subscribe to application specific gestures
    foreach(Window w, m_windowListener->getClientList()) {
        m_gestureCollector->addWindow(w);
    }
}
