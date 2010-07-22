#include "objectpropertymodel.h"
#include <QtCore/QMetaProperty>

using namespace Endoscope;

ObjectPropertyModel::ObjectPropertyModel(QObject* parent) :
  QAbstractTableModel(parent),
  m_obj( 0 )
{
}

void ObjectPropertyModel::setObject(QObject* object)
{
  m_obj = object;
  reset();
}

QVariant ObjectPropertyModel::data(const QModelIndex& index, int role) const
{
  if ( !index.isValid() || !m_obj || index.row() < 0 || index.row() >= m_obj->metaObject()->propertyCount() )
    return QVariant();

  if ( role == Qt::DisplayRole || role == Qt::EditRole ) {
    const QMetaProperty prop = m_obj->metaObject()->property( index.row() );
    if ( index.column() == 0 )
      return prop.name();
    else if ( index.column() == 1 )
      return prop.read( m_obj );
    else if ( index.column() == 2 )
      return prop.typeName();
  }

  return QVariant();
}

bool ObjectPropertyModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
  if ( index.isValid() && m_obj && index.column() == 1 && index.row() >= 0
    && index.row() < m_obj->metaObject()->propertyCount() && role == Qt::EditRole )
  {
    const QMetaProperty prop = m_obj->metaObject()->property( index.row() );
    return prop.write( m_obj, value );
  }
  return QAbstractItemModel::setData(index, value, role);
}

Qt::ItemFlags ObjectPropertyModel::flags(const QModelIndex& index) const
{
  const Qt::ItemFlags flags = QAbstractItemModel::flags(index);

  if ( !index.isValid() || !m_obj || index.column() != 1 || index.row() < 0
    || index.row() >= m_obj->metaObject()->propertyCount() )
  {
    return flags;
  }

  const QMetaProperty prop = m_obj->metaObject()->property( index.row() );
  if ( prop.isWritable() )
    return flags | Qt::ItemIsEditable;
  return flags;
}

int ObjectPropertyModel::columnCount(const QModelIndex& parent) const
{
  if ( parent.isValid() )
    return 0;
  return 3;
}

int ObjectPropertyModel::rowCount(const QModelIndex& parent) const
{
  if ( !m_obj || parent.isValid() )
    return 0;
  return m_obj->metaObject()->propertyCount();
}

#include "objectpropertymodel.h"
