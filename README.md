# VG BrainSystem Settings
Данная библиотека предназначена для управления настройками брейн-системы. Все классы находятся в пространстве имен vgs::settings

## Пример использования
   
  	constexpr const char* gameNames[3] = {"БЕЗ ОТСЧЕТА", "СВОЯ ИГРА", "БРЕЙН-РИНГ"};
	constexpr const char* modeNames[2] = {"БЕЗ ФАЛЬСТАРТОВ", "С ФАЛЬСТАРТАМИ"};

	Settings settings;
	settings.addItem(new ListSettingsItem("Тип игры", 3, gameNames));
	settings.addItem(new ListSettingsItem("Режим", 2, modeNames));
		
## Класс SettingsItem
Данный класс является абстракцией элемента настроек (одного пункта). Такой элемент содержит текстовое имя и какое-то значение. Значение можно получить либо в виде строки, либо в виде целого числа.

### Конструктор
- `SettingsItem(const char* name)`

**Важно: строка имени не копируется, поэтому требуется, чтобы указатель был доступен все время существования элемента настроек**

### Методы
- `const char* getName() const` - получить имя

Также у класса есть абстрактные методы, которые не реализованы:

- `virtual int getValueInt() const` - получить значение в виде целого числа
- `virtual const char* getValueStr() const` - получить значение в виде строки
- `virtual void increment()` - перейти к следующему значению
- `virtual void decrement()` - перейти к предыдущему значению
- `virtual bool setValueInt(int value)` - установить значение из целого числа. Возвращает `true`, если значение соответствует диапазону и успешно установлено

## Класс ListSettingsItem
Класс является расширением SettingsItem. Реализует вариант элемента настроек, который содержит в себе конечный список возможных вариантов.

### Конструктор
- `ListSettingsItem(const char* name, int numValues, const char* const* values)`

Параметры:

 - name - имя элемента
 - numValues - количество возможных значений
 - values - массив строк со значениями

**Важно: строка имени и массив значений не копируются, поэтому требуется, чтобы указатели были доступны все время существования элемента настроек**

## Класс Settings
Класс позволяет хранить элементы настроек и перемещаться между ними. Перемещение происходит по кругу (от последнего элемента переход к первому и наоборот). Поддерживается добавление новых элементов в процессе работы.

### Конструктор

 - `Settings()`

### Методы

- `void addItem(SettingsItem* item)` - добавление нового элемента. Указатель должен быть доступен все время существования класса и будет уничтожен при уничтожении класса.
- `void moveNext()` - переход к следующему элементу
- `void movePrevious()` - переход к предыдущему элементу
- `SettingsItem& getCurrentItem() const` - получение ссылки на текущий элемент
- `int getCurrentItemIndex() const` - получение номера текущего элемента
- `int size()` - получения количества элементов
- `void dumpData(int* data) const` - сохранить числовые значения элементов в массив. Массив должен иметь место, достаточное для размещения всех значений.
- `void loadData(const int* data)` - загрузка числовых значений элементов из массива
