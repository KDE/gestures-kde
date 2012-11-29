/**
 * @file /src/Gestures.h
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
#ifndef GESTURES_H
#define GESTURES_H

#include "src/util/Include.h"
#include "src/windows/WindowListener.h"
#include "src/gestures/collector/GestureCollector.h"
#include "src/gestures/handler/GestureHandler.h"

#include <KDEDModule>

/**
 * Initializes and launches GesturesKDE. To do this uses these three clases:
 * - WindowListener: To detect the creation or destruction of the windows and listen, if is neccessary, the multitouch
 *   events in that window.
 * - GestureCollector: To get the multitouch events in the windows selected by the WindowListener.
 * - GestureHandler: To treat the multitouch events collected by the GestureCollector.
 */
class Gestures : public KDEDModule
{
    Q_OBJECT
public:
    /**
     * Creates all the necessary classes, but Touchégg will be launched in the start() slot, when uTouch will be ready.
     */
    Gestures(QObject *parent, const QVariantList &args);
    ~Gestures();

private slots:
    /**
     * This slot is called when uTouch is ready. Launches Touchégg.
     */
    void start();

private:
    /**
     * Class to get the creation and destruction of windows.
     * @see x11EventFilter()
     * @see WindowListener
     */
    WindowListener *m_windowListener;

    /**
     * Class to collect all the gestures.
     * @see GestureCollector
     */
    GestureCollector *m_gestureCollector;

    /**
     * Class to treat the gestures and execute the corresponding action.
     * @see GestureHandler
     */
    GestureHandler *m_gestureHandler;

};

#endif // GESTURES_H
