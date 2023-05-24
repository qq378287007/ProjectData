#pragma once

#include "TreeItem.h"

class GraphData : public TreeItem
{
public:
    explicit GraphData(const QString &itemName = "曲线图", DataType dataType = GRAPH)
        : TreeItem(itemName, dataType)
    {
    }
};
