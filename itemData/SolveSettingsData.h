#pragma once

#include "TreeItem.h"

class SolveSettingsData : public TreeItem
{
public:
    explicit SolveSettingsData(const QString &itemName = "求解设置", DataType dataType = SOLVE_SETTINGS)
        : TreeItem(itemName, dataType)
    {
    }
};
