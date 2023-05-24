#pragma once

#include "TreeItem.h"

class FieldDiagramData : public TreeItem
{
public:
    explicit FieldDiagramData(const QString &itemName = "场图", DataType dataType = FIELD_DIAGRAM)
        : TreeItem(itemName, dataType)
    {
    }
};
