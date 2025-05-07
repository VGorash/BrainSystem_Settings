#include "ListSettingsItem.h"

using namespace vgs::settings;

ListSettingsItem::ListSettingsItem(const char* name, int numValues, const char* const* values) : SettingsItem(name), m_counter(0), m_numValues(numValues), m_values(values)
{
  
}

int ListSettingsItem::getValueInt() const
{
  return m_counter;
}

const char* ListSettingsItem::getValueStr() const
{
  return m_values[m_counter];
}

void ListSettingsItem::increment()
{
  m_counter++;

  if (m_counter >= m_numValues)
  {
    m_counter = 0;
  }
}

void ListSettingsItem::decrement()
{
  m_counter--;

  if (m_counter < 0)
  {
    m_counter = m_numValues - 1;
  }
}

bool ListSettingsItem::setValueInt(int value)
{
  if(value < 0 || value >= m_numValues)
  {
    return false;
  }

  m_counter = value;

  return true;
}
