/**
 ** This file is part of the uConfig project.
 ** Copyright 2018 Robotips sebastien.caux@robotips.fr.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program. If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef COMPONENTSCENE_H
#define COMPONENTSCENE_H

#include "kicad_global.h"

#include <QGraphicsScene>

#include "model/component.h"
#include "componentitem.h"

class KICAD_EXPORT ComponentScene : public QGraphicsScene
{
public:
    ComponentScene(qreal x=-5000, qreal y=-5000, qreal w=10000, qreal h=10000);

    bool grid() const;
    void setGrid(bool grid);

    bool elecType() const;
    void setElecType(bool elecType);

    Component *component() const;
    void setComponent(Component *component, int layer=1);

    ComponentItem *componentItem() const;
    void setComponentItem(ComponentItem *componentItem);

    void saveAsPdf(const QString &fileName);
    void saveAsImage(const QString &fileName, const QSize &size=QSize(1000, 1000));

protected:
    bool _grid;
    int _prevGridSize;

    bool _elecType;

    Component *_component;
    ComponentItem *_componentItem;

    void drawBackground(QPainter *painter, const QRectF &rect);
};

#endif // COMPONENTSCENE_H
