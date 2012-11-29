/**
 * @file /src/actions/implementation/ChangeViewport.h
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
 * @class  ChangeDesktop
 */
#ifndef CHANGEVIEWPORT_H
#define CHANGEVIEWPORT_H

#include "src/util/Include.h"
#include "src/actions/implementation/Action.h"

/**
 * Change the viewport.
 */
class ChangeViewport : public Action
{

public:

    ChangeViewport(const QString &settings, Window window);

    void executeStart(const QHash<QString, QVariant>& attrs);

    void executeUpdate(const QHash<QString, QVariant>& attrs);

    void executeFinish(const QHash<QString, QVariant>& attrs);

private:

    /**
     * Direction to switch desktops.
     */
    bool next;

};

#endif // CHANGEVIEWPORT_H
