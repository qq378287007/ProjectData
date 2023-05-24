#pragma once

#include "TreeItem.h"

class MaterialData : public TreeItem
{
public:
    explicit MaterialData(const QString &itemName = "材料", DataType dataType = MATERIAL)
        : TreeItem(itemName, dataType)
    {
    }
};
