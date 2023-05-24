#pragma once

#include "TreeItem.h"

class StatorRotorData : public TreeItem
{
public:
    explicit StatorRotorData(const QString &itemName = "定子和转子", DataType dataType = STATOR_ROTOR)
        : TreeItem(itemName, dataType)
    {
    }
};
