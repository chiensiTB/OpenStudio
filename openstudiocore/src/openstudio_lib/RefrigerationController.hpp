/**********************************************************************
 *  Copyright (c) 2008-2013, Alliance for Sustainable Energy.  
 *  All rights reserved.
 *  
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *  
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *  
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#ifndef OPENSTUDIO_REFRIGERATIONCONTROLLER_H
#define OPENSTUDIO_REFRIGERATIONCONTROLLER_H

#include <QObject>
#include <boost/optional.hpp>
#include "../shared_gui_components/OSListController.hpp"
#include "model/RefrigerationSystem.hpp"

class QGraphicsScene;
class QGraphicsView;
class QGraphicsObject;

namespace openstudio {

class RefrigerationSystemGridView;
class RefrigerationSystemListController;
class RefrigerationScene;

class RefrigerationController : public QObject
{
  Q_OBJECT

  public:

  RefrigerationController();

  virtual ~RefrigerationController();

  QGraphicsView * refrigerationGraphicsView() const;

  QSharedPointer<RefrigerationSystemListController> refrigerationSystemListController() const;

  public slots:

  void zoomInOnSystem(model::RefrigerationSystem & refrigerationSystem);

  private:

  QPointer<QGraphicsView> m_refrigerationGraphicsView;

  QSharedPointer<RefrigerationSystemGridView> m_refrigerationSystemGridView;

  QSharedPointer<RefrigerationSystemListController> m_refrigerationSystemListController;

  QSharedPointer<QGraphicsScene> m_refrigerationGridScene;

  QSharedPointer<QGraphicsScene> m_refrigerationScene;
};

class RefrigerationSystemListController : public OSListController
{
  Q_OBJECT

  public:

  RefrigerationSystemListController(RefrigerationController * refrigerationController);

  RefrigerationController * refrigerationController() const;

  QSharedPointer<OSListItem> itemAt(int i);

  int count();

  public slots:

  void createNewSystem();

  void removeSystem(model::RefrigerationSystem & refrigerationSystem);

  private:

  std::vector<model::RefrigerationSystem> systems() const;

  int systemIndex(const model::RefrigerationSystem & system) const;

  QPointer<RefrigerationController> m_refrigerationController;
};

// A delegate to provide cells of the refigeration system grid
class RefrigerationSystemItemDelegate : public OSGraphicsItemDelegate
{
  Q_OBJECT;

  public:

  virtual ~RefrigerationSystemItemDelegate() {}

  virtual QGraphicsObject * view(QSharedPointer<OSListItem> dataSource);
};

class RefrigerationSystemListDropZoneItem : public OSListItem
{
  Q_OBJECT

  public:

  RefrigerationSystemListDropZoneItem(OSListController * listController = 0);

  ~RefrigerationSystemListDropZoneItem() {}
};

class RefrigerationSystemListItem : public OSListItem
{
  Q_OBJECT

  public:

  RefrigerationSystemListItem(const model::RefrigerationSystem & refrigerationSystem, OSListController * listController = 0);

  virtual ~RefrigerationSystemListItem() {}

  QString systemName() const;

  public slots:

  void remove();

  void zoomInOnSystem();

  private:

  model::RefrigerationSystem m_refrigerationSystem;
};

} // openstudio

#endif // OPENSTUDIO_REFRIGERATIONCONTROLLER_H
