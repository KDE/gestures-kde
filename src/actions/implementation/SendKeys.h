/**
 * @file /src/actions/implementation/SendKeys.h
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
 * @class  SendKeys
 */
#ifndef SENDKEYS_H
#define SENDKEYS_H

#include "src/util/Include.h"
#include "src/actions/implementation/Action.h"

/**
 * Sends the keys indicated in the configuration to the window under the cursor.
 */
class SendKeys : public Action
{

public:

    SendKeys(const QString &settings, Window window);

    void executeStart(const QHash<QString, QVariant>& attrs);

    void executeUpdate(const QHash<QString, QVariant>& attrs);

    void executeFinish(const QHash<QString, QVariant>& attrs);

private:

    /**
     * Keys to hold down while sending the rest of keys.
     */
    QList<KeyCode> holdDownKeys;

    /**
     * Keys to send while holdDownKeys are sending.
     */
    QList<KeyCode> pressBetweenKeys;

};

#endif // SENDKEYS_H
