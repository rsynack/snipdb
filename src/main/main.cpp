#include "key.h"
#include "database.h"

#include <iostream>
#include <string>
#include <optional>

using namespace std;
using namespace snipdb;

int main()
{
    Database db("/test");

    db.open();

    Collection user = db.createCollection({name : "id", type : KeyType::Number}, "user");

    IKey key = user.insert("{ pseudonym: \"synack\", email: \"synack@foo.bar\" }");

    optional<string> json = user.find(key);
    if (json.has_value())
    {
        cout << "Find 1:" << json.value() << endl;
    }

    uint64_t keyValue = key.cast<LongKey>()->value;
    // IKey key2 = user.buildKey<uint64_t>(keyValue);

    // optional<string> json = user.find(key2);
    // if (json.has_value()) {
    //     cout << "Find 2" << json.value() << endl;
    // }

    user.update("{ id: \"0\", pseudonym: \"acksyn\", email: \"acksyn@bar.foo\" }");

    return 0;
}