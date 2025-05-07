#ifndef SETTINGS_H
#define SETTINGS_H

#include "SettingsItem.h"

namespace vgs::settings
{

class Settings
{
public:

  ~Settings();

  void addItem(SettingsItem* item);

  void moveNext();
  void movePrevious();

  SettingsItem& getCurrentItem() const;
  int getCurrentItemIndex() const;

  int size() const;

  void dumpData(int* data) const;
  void loadData(const int* data);

protected:
  int m_numItems = 0;
  int m_currentItemIndex = 0; 

  SettingsItem* m_firstItem = nullptr;
  SettingsItem* m_lastItem = nullptr;
  SettingsItem* m_currentItem = nullptr;

};

} //namespace vgs

#endif
