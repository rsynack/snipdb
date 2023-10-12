#ifndef INVALID_ROOT_ERROR_H
#define INVALID_ROOT_ERROR_H

#include <string>
#include <stdexcept>

namespace yson {
    class InvalidRootError : public std::runtime_error {
        
        public:
            InvalidRootError(std::string name)
                : std::runtime_error("Invalid root node type '" + name + "'.") {
            }
    };
}

#endif
#ifndef INVALID_TYPE_ERROR_H
#define INVALID_TYPE_ERROR_H

#include <string>
#include <stdexcept>

namespace yson {
    class InvalidTypeError : public std::runtime_error {
        
        public:
            InvalidTypeError(std::string name)
                : std::runtime_error("Invalid type for name '" + name + "'.") {
            }

            InvalidTypeError(size_t index)
                : std::runtime_error("Invalid type for index '" + std::to_string(index) + "'.") {
            }
    };
}

#endif
#ifndef ROOT_NOT_FOUND_ERROR_H
#define ROOT_NOT_FOUND_ERROR_H

#include <string>
#include <stdexcept>

namespace yson {
    class RootNotFoundError : public std::runtime_error {
        
        public:
            RootNotFoundError()
                : std::runtime_error("Root not found in JSON.") {
            }
    };
}

#endif
#ifndef JVALUE_H
#define JVALUE_H

#include <string>

namespace yson {

    class JValue {

        public:
            virtual const std::string toString() const = 0;
    };

}

#endif
#ifndef JNUMBER_H
#define JNUMBER_H


#include <iostream>

namespace yson {

    class JNumber : public JValue {

        enum ValueType { SINGED, UNSINGED, FLOATING };

        private:
            int64_t singedValue;
            uint64_t unsingedValue;
            double floatingValue;

            ValueType valueType;

            const std::string convertDoubleValueToString() const;

        public:
            JNumber();

            void setSinged(int64_t number);
            void setUnsigned(uint64_t number);
            void setFloating(double number);

            const int64_t getSinged() const {
                return this->singedValue;
            }

            const uint64_t getUnsinged() const {
                return this->unsingedValue;
            }

            const double getFloating() const {
                return this->floatingValue;
            }
            
            const std::string toString() const;
    };
}


#endif
#ifndef JBOOL_H
#define JBOOL_H


#include <string>

namespace yson {

    class JBool : public JValue {

        private:
            bool value;

        public:
            JBool(bool value);

            bool getValue() { return this->value; }

            const std::string toString() const;
    };
}


#endif
#ifndef JSTRING_H
#define JSTRING_H


#include <string>

namespace yson {

    class JString : public JValue {

        private:
            std::string value;

        public:
            JString(std::string value);

            std::string getValue() { return this->value; }

            const std::string toString() const;

    };

}

#endif
#ifndef JARRAY_H
#define JARRAY_H


#include <vector>
#include <memory>
#include <iostream>

namespace yson {

    class JObject;

    class JArray : public JValue {

        private:
            std::vector<std::shared_ptr<JValue>> values;

        public:
            JArray();

            void addValue(std::shared_ptr<JValue> value);
            void addValue(JArray value);
            void addValue(JObject value);
            void addNumber(int64_t value);
            void addNumber(uint64_t value);
            void addNumber(double value);
            void addBoolean(bool value);
            void addString(std::string value);
            void addDate(time_t time);

            template<typename T>
            std::shared_ptr<T> get(size_t index) {
                std::shared_ptr<T> value = std::dynamic_pointer_cast<T>(this->values.at(index));
                if (value.get()) {
                    return value;
                }

                throw InvalidTypeError(index);
            }

            std::shared_ptr<JObject> getObject(size_t index) {
                return get<JObject>(index);
            }

            std::shared_ptr<JNumber> getNumber(size_t index) {
                return get<JNumber>(index);
            }

            bool getBoolean(size_t index) {
                return get<JBool>(index)->getValue();
            }

            void remove(int index);

            const std::string toString() const;
    };
}

#endif
#ifndef JDATE_H
#define JDATE_H


#include <string>

namespace yson {

    class JDate : public JValue {

        private:
            time_t value;

        public:
            JDate(time_t value);

            time_t getValue() { return this->value; }

            const std::string toString() const;
    };
}

#endif
#ifndef JDOCUMENT_H
#define JDOCUMENT_H


#include <memory>
#include <string>

namespace yson {

    class JDocument : public JValue {

        private:
            std::shared_ptr<JValue> root;

        public:
            JDocument(std::shared_ptr<JValue> root) {
                this->root = root;
            }

            template<typename T>
            std::shared_ptr<T> getRoot() { 
                return std::dynamic_pointer_cast<T>(this->root);
            }

            std::shared_ptr<JObject> getObject();

            std::shared_ptr<JArray> getArray();

            const std::string toString() const { return this->root->toString(); }

    };

}

#endif
#ifndef JNULL_H
#define JNULL_H


#include <string>

namespace yson {

    class JNull : public JValue {

        public:
            JNull();

            const std::string toString() const;
    };
}


#endif
#ifndef JOBJECT_H
#define JOBJECT_H


#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <memory>

namespace yson {
 
    class JReader;
    class JArray;

    class JObject : public JValue {

        class AddValueKey {
            friend JReader;

            private:
                AddValueKey() {}
                AddValueKey(AddValueKey const&) = default;
        };

        private:
            std::map<std::string, std::shared_ptr<JValue>> values;
            std::vector<std::string> keys;
            std::map<std::string, int> index;
            
            template<typename T>
            std::shared_ptr<T> getValue(std::string name) {
                if (!this->values.empty() && this->values.find(name) != this->values.end()) {
                    std::shared_ptr<T> value = std::dynamic_pointer_cast<T>(this->values.at(name));
                    if (value) {
                        return value;
                    }
                }

                throw InvalidTypeError(name);
            }

            template<typename T>
            void _addValue(std::string name, T value) {
                this->keys.push_back(name);
                this->index.emplace(make_pair(name, this->keys.size() - 1));
                this->values.emplace(make_pair(name, value));
            }

        public:
            JObject();

            template<typename T>
            void _addValue(std::string name, T value, AddValueKey) { this->_addValue(name, value); };

            void addValue(std::string name, JObject value);
            void addValue(std::string name, JArray value);
            void addValue(std::string name, JNull value);

            void addNumber(std::string name, int64_t value);
            void addNumber(std::string name, uint64_t value);
            void addNumber(std::string name, double value);

            void addBoolean(std::string name, bool value);
            void addString(std::string name, std::string value);
            void addDate(std::string name, time_t time);

            std::shared_ptr<JNumber> getNumber(std::string name);
            bool getBoolean(std::string name);
            std::string getString(std::string name);
            time_t getDate(std::string name);

            void remove(std::string name);

            const std::string toString() const;
    };

}

#endif
#ifndef JREADER_H
#define JREADER_H


#include <istream>

namespace yson {

    class JReader {
        public:
            JReader();
            JDocument parseFile(const char* filename);
            JDocument parse(std::istream &ifs);
            JDocument parse(std::string json);

        private:
            JObject parseJObject(std::istream &ifs);
            void parseAttribute(std::istream &ifs, JObject &obj);
            std::shared_ptr<JValue> parseValue(std::istream &ifs);
            JArray parseArray(std::istream &ifs);
            JString parseString(std::istream &ifs);
            JNumber parseNumber(std::istream &ifs, char c, bool negative);

    };
}

#endif
