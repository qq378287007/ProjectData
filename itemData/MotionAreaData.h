#pragma once

#include "TreeItem.h"

class MotionAreaData : public TreeItem
{
public:
    explicit MotionAreaData(const QString &itemName = "", DataType dataType = MOTION_AREA)
        : TreeItem(itemName, dataType)
    {
    }
    ~MotionAreaData(){
        qDebug()<<"~MotionAreaData()";
    }

    void removeItem(TreeItem::DataType) override
    {
        parent()->removeItem();
        //addNode();
    }
};
