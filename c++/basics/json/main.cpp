#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

using namespace rapidjson;

int main()
{
	// 1. Parse a JSON string
	const char* json = "{\"name\":\"John\", \"age\":30, \"active\":true}";
	
	Document doc;
	doc.Parse(json);
	
	// If it has name 
	if(doc.HasMember("name") && doc["name"].IsString())
	{
		std::cout << "Name: " << doc["name"].GetString() << std::endl;
	}

	// if it has age 
	if(doc.HasMember("age") && doc["age"].IsInt())
	{
		std::cout << "Age: " << doc["age"].GetInt() << std::endl;
	}

	// if it has active
	if(doc.HasMember("active") && doc["active"].IsBool())
	{
		std::cout << "Active: " << std::boolalpha << doc["active"].GetBool() << std::endl;
	}

	// 2. Create a JSON object
	Document outputDoc;
	outputDoc.SetObject();

	Document::AllocatorType& allocator = outputDoc.GetAllocator();
	outputDoc.AddMember("status", "success", allocator);
	outputDoc.AddMember("message", "JSON processing completed", allocator);

	// 3. Serialize the JSON object to a string 
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	outputDoc.Accept(writer);

	std::cout << "Generated JSON: " << buffer.GetString() << std::endl;

	return 0;
}
