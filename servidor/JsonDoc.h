//
// Created by manuel on 03/04/19.
//

#ifndef SERVIDOR_JSONDOC_H
#define SERVIDOR_JSONDOC_H

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;


class JsonDoc {

public: void sample_basic() {
        // 1. Parse a JSON string into DOM.
        const char* json = "{\"scrabble\":\"fichas\",\"posicion\":20}";
        Document document;
        document.Parse(json);

        // 2. Modify it by DOM.
        Value& s = document["posicion"];
        s.SetInt(s.GetInt() + 1);


        // 3. Stringify the DOM
        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        document.Accept(writer);

        // Output {"project":"rapidjson","stars":11}
        std::cout << buffer.GetString() << std::endl;
    }

public: void sample_other() {
        // document is the root of a json message
        rapidjson::Document document;

        // define the document as an object rather than an array
        document.SetObject();

        // create a rapidjson array type with similar syntax to std::vector
        rapidjson::Value array(rapidjson::kArrayType);

        // must pass an allocator when the object may need to allocate memory
        rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

        // chain methods as rapidjson provides a fluent interface when modifying its objects
        array.PushBack("hello", allocator).PushBack("world", allocator);//"array":["hello","world"]

        document.AddMember("Name", "XYZ", allocator);
        document.AddMember("Rollnumer", 2, allocator);
        document.AddMember("array", array, allocator);

        // create a rapidjson object type
        rapidjson::Value object(rapidjson::kObjectType);
        object.AddMember("Math", "50", allocator);
        object.AddMember("Science", "70", allocator);
        object.AddMember("English", "50", allocator);
        object.AddMember("Social Science", "70", allocator);
        document.AddMember("Marks", object, allocator);
        //	fromScratch["object"]["hello"] = "Yourname";

        StringBuffer strbuf;
        Writer<StringBuffer> writer(strbuf);
        document.Accept(writer);

        std::cout << strbuf.GetString() << std::endl;
    }

public: void sample_sendapi() {
        Document d;
        Document::AllocatorType& alloc = d.GetAllocator();

        std::string mytext = "this is my text";

        d.SetObject();

        d.AddMember("Posicion X", " X ", alloc);
        d.AddMember("Posicion Y", " Y ", alloc);
        d.AddMember("Letra", " o ", alloc);


        {
            Value recipients(kArrayType);

            {
                Value recipient(kObjectType);
                recipient.AddMember("Email", "recipient@gmail.com", alloc);
                recipients.PushBack(recipient, alloc);
            }

            d.AddMember("Recipients", recipients, alloc);
        }

        {
            Value textPart;
            textPart.SetString(mytext.c_str(), alloc);
            d.AddMember("Text-part", textPart, alloc);
        }

        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        d.Accept(writer);

        std::cout << buffer.GetString() << std::endl;
    }


};





/*

int main() {
    sample_basic();

    sample_other();

    sample_sendapi();

    return 0;
}
*/
#endif //SERVIDOR_JSONDOC_H
