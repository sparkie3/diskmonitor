/****************************************************************************
 * DisKMonitor, KDE tools to monitor SMART and MDRaid health status         *
 * Copyright (C) 2014-2015 Michaël Lhomme <papylhomme@gmail.com>            *
 *                                                                          *
 * This program is free software; you can redistribute it and/or modify     *
 * it under the terms of the GNU General Public License as published by     *
 * the Free Software Foundation; either version 2 of the License, or        *
 * (at your option) any later version.                                      *
 *                                                                          *
 * This program is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 * GNU General Public License for more details.                             *
 *                                                                          *
 * You should have received a copy of the GNU General Public License along  *
 * with this program; if not, write to the Free Software Foundation, Inc.,  *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.              *
 ****************************************************************************/


#ifndef MDRAIDPROPERTIESMODEL_H
#define MDRAIDPROPERTIESMODEL_H

#include "storageunitpropertiesmodel.h"
#include "mdraid.h"


/*
 * A Qt model to display raid attributes in a table
 */
class MDRaidPropertiesModel : public StorageUnitPropertiesModel
{
  Q_OBJECT

public:
  MDRaidPropertiesModel();
  ~MDRaidPropertiesModel();

  MDRaid* getMDRaid() const;


  virtual int rowCount(const QModelIndex& index) const override;
  virtual int columnCount(const QModelIndex& index) const override;
  virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
  virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
  QStringList headerLabels;
};

#endif // MDRAIDPROPERTIESMODEL_H
