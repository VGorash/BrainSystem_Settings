#ifndef SETTINGS_ITEM_H
#define SETTINGS_ITEM_H

namespace vgs::settings
{

class SettingsItem
{
friend class Settings;

public:
  // IMPORTANT: to reduce memory usage it doesn't copy name. Name pointer should be always available!
  SettingsItem(const char* name);

  const char* getName() const;

  virtual int getValueInt() const = 0;
  virtual const char* getValueStr() const = 0;

  virtual void increment() = 0;
  virtual void decrement() = 0;

  virtual bool setValueInt(int value) = 0;

protected:
  SettingsItem* getPrevious() const;
  SettingsItem* getNext() const;

  void setPrevious(SettingsItem* item);
  void setNext(SettingsItem* item);

protected:
  const char* m_name;

  SettingsItem* m_previous = nullptr;
  SettingsItem* m_next = nullptr;
};

} // namespace vgs::settings

#endif
