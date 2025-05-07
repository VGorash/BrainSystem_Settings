#ifndef LIST_SETTINGS_ITEM_H
#define LIST_SETTINGS_ITEM_H

#include "SettingsItem.h"

namespace vgs::settings
{

class ListSettingsItem : public SettingsItem
{
public:
  // IMPORTANT: to reduce memory usage it doesn't copy values. Values pointer and string pointers inside it should be always available!
  ListSettingsItem(const char* name, int numValues, const char* const* values);

  int getValueInt() const override;
  const char* getValueStr() const override;

  void increment() override;
  void decrement() override;

  bool setValueInt(int value) override;

protected:
  int m_numValues;
  const char* const* m_values;
  int m_counter;
};

} // namespace vgs::settings

#endif
