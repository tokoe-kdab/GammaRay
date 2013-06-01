/*
  selectionmodelinspectorwidget.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2010-2013 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Stephen Kelly <stephen.kelly@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GAMMARAY_SELECTIONMODELINSPECTOR_SELECTIONMODELINSPECTORWIDGET_H
#define GAMMARAY_SELECTIONMODELINSPECTOR_SELECTIONMODELINSPECTORWIDGET_H

#include "include/toolfactory.h"

#include <QItemSelectionModel>
#include <QWidget>

namespace GammaRay {

namespace Ui {
  class SelectionModelInspectorWidget;
}

class SelectionModelInspectorWidget : public QWidget
{
  Q_OBJECT
  public:
    explicit SelectionModelInspectorWidget(QWidget *widget = 0);
    ~SelectionModelInspectorWidget();

  private slots:
    void selectionModelSelected(const QItemSelection &selected, const QItemSelection &deselected);

  private:
    QScopedPointer<Ui::SelectionModelInspectorWidget> ui;
};

}

#endif // GAMMARAY_SELECTIONMODELINSPECTOR_H
