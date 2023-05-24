#pragma once

#include "TreeItem.h"

class WindingData : public TreeItem
{
public:
    explicit WindingData(const QString &itemName = "绕组", DataType dataType = WINDING)
        : TreeItem(itemName, dataType)
    {
    }
};
