#include "Settings.h"

using namespace vgs::settings;

Settings::~Settings()
{
  SettingsItem* item = m_firstItem;
  while (item)
  {
    SettingsItem* temp = item->getNext();
    delete item;
    item = temp;
  }
}

void Settings::addItem(SettingsItem* item)
{
  m_numItems++;
    
  if(m_numItems == 1)
  {
    m_currentItem = item;
    m_firstItem = item;
  }
  else
  {
    m_lastItem->setNext(item);
    item->setPrevious(m_lastItem);
  }

  m_lastItem = item;
}

void Settings::moveNext()
{
  if (m_numItems == 0)
  {
    return;
  }
  if (m_currentItem->getNext())
  {
    m_currentItem = m_currentItem->getNext();
    m_currentItemIndex++;
  }
  else
  {
    m_currentItem = m_firstItem;
    m_currentItemIndex = 0;
  }
}

void Settings::movePrevious()
{
  if (m_numItems == 0)
  {
      return;
  }
  if (m_currentItem->getPrevious())
  {
    m_currentItem = m_currentItem->getPrevious();
    m_currentItemIndex--;
  }
  else
  {
    m_currentItem = m_lastItem;
    m_currentItemIndex = m_numItems - 1;
  }
}

SettingsItem& Settings::getCurrentItem() const
{
  return *m_currentItem;
}

int Settings::getCurrentItemIndex() const
{
  return m_currentItemIndex;
}

int Settings::size() const
{
  return m_numItems;
}

void Settings::dumpData(int* data) const
{
  SettingsItem* item = m_firstItem;

  for (int i = 0; i < m_numItems; i++)
  {
    data[i] = item->getValueInt();
    item = item->getNext();
  }
}

void Settings::loadData(const int* data)
{
  SettingsItem* item = m_firstItem;

  for (int i = 0; i < m_numItems; i++)
  {
    item->setValueInt(data[i]);
    item = item->getNext();
  }
}
