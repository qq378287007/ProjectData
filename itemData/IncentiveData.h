#pragma once

#include "TreeItem.h"

class IncentiveData : public TreeItem
{
public:
    explicit IncentiveData(const QString &itemName = "", DataType dataType = INCENTIVE)
        : TreeItem(itemName, dataType)
    {
    }
};
