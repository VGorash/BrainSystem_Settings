#include "SettingsItem.h"

using namespace vgs::settings;

SettingsItem::SettingsItem(const char* name) : m_name(name)
{
  
}

const char* SettingsItem::getName() const
{
  return m_name;
}

SettingsItem* SettingsItem::getPrevious() const
{
  return m_previous;
}

SettingsItem* SettingsItem::getNext() const
{
  return m_next;
}

void SettingsItem::setPrevious(SettingsItem* item)
{
  m_previous = item;
}

void SettingsItem::setNext(SettingsItem* item)
{
  m_next = item;
}
