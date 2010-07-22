#ifndef ENDOSCOPE_OBJECTPROPERTYMODEL_H
#define ENDOSCOPE_OBJECTPROPERTYMODEL_H

#include <qabstractitemmodel.h>


namespace Endoscope {

class ObjectPropertyModel : public QAbstractTableModel
{
  Q_OBJECT
  public:
    ObjectPropertyModel(QObject* parent = 0);
    void setObject( QObject *object );

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex& index) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;

  private:
    QObject *m_obj;
};

}

#endif // ENDOSCOPE_OBJECTPROPERTYMODEL_H
