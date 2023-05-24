#include "TreeView.h"

TreeView::TreeView(QWidget *parent )
    : QTreeView(parent)
{
    setSelectionBehavior(QTreeView::SelectRows);         //一次选中整行
    setSelectionMode(QTreeView::SingleSelection);        //单选，配合上面的整行就是一次选单行
    setFocusPolicy(Qt::NoFocus);                         //去掉鼠标移到单元格上时的虚线框
    setHeaderHidden(true);
    setContextMenuPolicy(Qt::CustomContextMenu);//右键菜单

    menu = new QMenu(this);

    addMotionAreaAction = new QAction("增加运动区域", this);
    addVectorBoundaryAction = new QAction("增加矢量边界", this);
    addSymmetricBoundaryAction= new QAction("增加对称边界", this);
    addAnalysisPlanAction = new QAction("增加分析方案", this);
    addIncentiveAction = new QAction("增加激励", this);

    removeMotionAreaAction = new QAction("删除运动区域", this);
    removeVectorBoundaryAction = new QAction("删除矢量边界", this);
    removeSymmetricBoundaryAction= new QAction("删除对称边界", this);
    removeAnalysisPlanAction = new QAction("删除分析方案", this);
    removeIncentiveAction = new QAction("删除激励", this);

    connect(addMotionAreaAction, &QAction::triggered, [&]{
        item->addItem();

        QModelIndex index = currentIndex();
        expandRecursively(index);

        int n = item->childCount();
        QModelIndex m_ModelIndex = currentIndex().child(n-1, 0);
        setCurrentIndex(m_ModelIndex);

        doItemsLayout();
    });

    connect(addVectorBoundaryAction, &QAction::triggered, [&]{
        item->addItem(TreeItem::VECTOR_BOUNDARY);

        QModelIndex index = currentIndex();
        expandRecursively(index);

        int n = item->childCount();
        QModelIndex m_ModelIndex = currentIndex().child(n-1, 0);
        setCurrentIndex(m_ModelIndex);

        doItemsLayout();
    });

    connect(addSymmetricBoundaryAction, &QAction::triggered, [&]{
        item->addItem(TreeItem::SYMMETRIC_BOUNDARY);

        QModelIndex cur_index = currentIndex();
        expandRecursively(cur_index);

        int n = item->childCount();
        QModelIndex m_ModelIndex = currentIndex().child(n-1, 0);
        setCurrentIndex(m_ModelIndex);

        doItemsLayout();
    });

    connect(addAnalysisPlanAction, &QAction::triggered, [&]{
        item->addItem();

        QModelIndex index = currentIndex();
        expandRecursively(index);

        int n = item->childCount();
        QModelIndex m_ModelIndex = currentIndex().child(n-1, 0);
        setCurrentIndex(m_ModelIndex);

        doItemsLayout();
    });

    connect(addIncentiveAction, &QAction::triggered, [&]{
        item->addItem();

        QModelIndex index = currentIndex();
        expandRecursively(index);

        int n = item->childCount();
        QModelIndex m_ModelIndex = currentIndex().child(n-1, 0);
        setCurrentIndex(m_ModelIndex);

        doItemsLayout();
    });

    connect(removeMotionAreaAction, &QAction::triggered, [&]{
        setCurrentIndex(QModelIndex());
        item->removeItem();
        doItemsLayout();
    });

    connect(removeVectorBoundaryAction, &QAction::triggered, [&]{
        item->removeItem(TreeItem::VECTOR_BOUNDARY);
        doItemsLayout();
    });

    connect(removeSymmetricBoundaryAction, &QAction::triggered, [&]{
        item->removeItem(TreeItem::SYMMETRIC_BOUNDARY);
        doItemsLayout();
    });

    connect(removeAnalysisPlanAction, &QAction::triggered, [&]{
        item->removeItem();
        doItemsLayout();
    });

    connect(removeIncentiveAction, &QAction::triggered, [&]{
        item->removeItem();
        doItemsLayout();
    });

    connect(this, &QTreeView::customContextMenuRequested, [=](const QPoint &pos){
        QModelIndex index = indexAt(pos);        //当前右击元素的index
        if (index.isValid())
        {
            item = static_cast<TreeItem*>(index.internalPointer());
            switch (item->dataType())
            {
            case TreeItem::MOTION_AREA_CONTAINER:
            {
                menu->clear();
                menu->addAction(addMotionAreaAction);
                menu->addAction(removeMotionAreaAction);
                menu->exec(mapToGlobal(pos));
                break;
            }
            case TreeItem::MOTION_AREA:
            {
                menu->clear();
                //menu->addAction(addMotionAreaAction);
                menu->addAction(removeMotionAreaAction);
                menu->exec(mapToGlobal(pos));
                break;
            }
            case TreeItem::BOUNDARY_CONTAINER:
            {
                menu->clear();
                menu->addAction(addVectorBoundaryAction);
                menu->addAction(addSymmetricBoundaryAction);
                menu->addAction(removeVectorBoundaryAction);
                menu->addAction(removeSymmetricBoundaryAction);
                menu->exec(mapToGlobal(pos));
                break;
            }
            case TreeItem::PERMANENT_MAGNET_SYNC_MOTOR_PROJECT:
            {
                menu->clear();
                menu->addAction(addAnalysisPlanAction);
                menu->addAction(removeAnalysisPlanAction);
                menu->exec(mapToGlobal(pos));
                break;
            }
            case TreeItem::INCENTIVE_CONTAINER:
            {
                menu->clear();
                menu->addAction(addIncentiveAction);
                menu->addAction(removeIncentiveAction);
                menu->exec(mapToGlobal(pos));
                break;
            }
            default:
                break;
            }
        }
    });
}
