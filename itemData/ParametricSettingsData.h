#pragma once

#include "TreeItem.h"

class ParametricSettingsData : public TreeItem
{
public:
    explicit ParametricSettingsData(const QString &itemName = "参数化设置", DataType dataType = PARAMETRIC_SETTINGS)
        : TreeItem(itemName, dataType)
    {
    }
};
