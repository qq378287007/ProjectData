#pragma once

#include <QList>
#include <QSharedPointer>

#include "TreeItem.h"

#include "MotionAreaData.h"

class MotionAreaContainerData : public TreeItem
{
public:
    explicit MotionAreaContainerData(const QString &itemName = "运动区域", DataType dataType = MOTION_AREA_CONTAINER)
        : TreeItem(itemName, dataType)
    {
    }

    void addNode() override {
        removeChildAll();

        foreach(auto item, m_MotionArea)
            appendChild(item);
    }

    void addItem(TreeItem::DataType) override
    {
        QSharedPointer<MotionAreaData> item(new MotionAreaData());
        item->setItemName(QString("运动区域%1").arg(QString::number(++MotionAreaNum)));
        m_MotionArea.append(item);
        appendChild(item);
    }

    void removeItem(TreeItem::DataType) override
    {
        removeChildLast();
        if(m_MotionArea.count() > 0)
            m_MotionArea.removeLast();
        //addNode();
    }
public:
    QList<QSharedPointer<MotionAreaData>>  motionArea() const {
        return m_MotionArea;
    }
    void setMotionArea(const QList<QSharedPointer<MotionAreaData>> &MotionArea){
        m_MotionArea = MotionArea;
        //addNode();
    }
private:
    QList<QSharedPointer<MotionAreaData>> m_MotionArea;//运动区域
private:
    int MotionAreaNum = 0;
};
