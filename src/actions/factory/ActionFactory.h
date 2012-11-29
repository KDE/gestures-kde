/**
 * @file /src/actions/factory/ActionFactory.h
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
 * @class  ActionFactory
 */
#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

#include "src/actions/types/ActionTypeEnum.h"
#include "src/util/Include.h"
#include "src/actions/types/ActionTypeEnum.h"
#include "src/actions/implementation/Action.h"
#include "src/actions/implementation/MouseClick.h"
#include "src/actions/implementation/Scroll.h"
#include "src/actions/implementation/MinimizeWindow.h"
#include "src/actions/implementation/MaximizeRestoreWindow.h"
#include "src/actions/implementation/CloseWindow.h"
#include "src/actions/implementation/ResizeWindow.h"
#include "src/actions/implementation/ShowDesktop.h"
#include "src/actions/implementation/ChangeDesktop.h"
#include "src/actions/implementation/ChangeViewport.h"
#include "src/actions/implementation/SendKeys.h"
#include "src/actions/implementation/MoveWindow.h"
#include "src/actions/implementation/RunCommand.h"
#include "src/actions/implementation/DragAndDrop.h"

/**
 * Factory to create the different actions.
 */
class ActionFactory
{

public:

    /**
     * Only method to get an instance of the class.
     * @return The single instance of the class.
     */
    static ActionFactory *getInstance();

    /**
     * Creates the specified action, if it not exist returns NULL.
     * IMPORTANT: Don't forget to free memory.
     * @param  actionType Action type to create.
     * @param  settings   Action settings.
     * @param  window     Window on which execute the action.
     * @return The action.
     */
    Action *createAction(ActionTypeEnum::ActionType actionType, const QString &settings, Window window);

private:

    /**
     * Single instance of the class.
     */
    static ActionFactory *instance;

    // Hide constructors
    ActionFactory() {}
    ActionFactory(const ActionFactory &);
    const ActionFactory &operator = (const ActionFactory &);
};

#endif // ACTIONFACTORY_H
