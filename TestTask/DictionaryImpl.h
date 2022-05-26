#include "dictionary.h"
#include <map>

#ifndef DictImpl
#define DictImol

template<class Key>
class NotFoundException : public not_found_exception<Key>
{
private:
    Key key; //храним ключ в объекте
public:
    NotFoundException(Key _key) { key = _key; }
    const Key& get_key() const noexcept { return key; }
};

template<class Key, class Value>
class DictionaryImpl : public dictionary<Key, Value>
{
private:
    std::map<Key, Value> data;

public:
    DictionaryImpl() = default;
    const Value& get(const Key& key) const 
    {
        if (this->is_set(key))
            return this->data.at(key);
        throw NotFoundException<Key>(key);
    }
    void set(const Key& key, const Value& value)
    {
        if (this->is_set(key))
            throw "value already exists for this key";
        this->data[key] = value;
    }
    bool is_set(const Key& key) const {
        if (this->data.count(key))
            return true;
        return false;
    }
};
#endif
