#pragma once

#include "TreeItem.h"

class SymmetricBoundaryData : public TreeItem
{
public:
    explicit SymmetricBoundaryData(const QString &itemName = "对称边界", DataType dataType = SYMMETRIC_BOUNDARY)
        : TreeItem(itemName, dataType)
    {
    }
};
