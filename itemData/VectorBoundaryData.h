#pragma once

#include "TreeItem.h"

class VectorBoundaryData : public TreeItem
{
public:
    explicit VectorBoundaryData(const QString &itemName = "矢量边界", DataType dataType = VECTOR_BOUNDARY)
        : TreeItem(itemName, dataType)
    {
    }
};
