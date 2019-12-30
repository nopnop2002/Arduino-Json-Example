// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License
//
// This example shows the different ways you can use String with ArduinoJson.
//
// Use String objects sparingly, because ArduinoJson duplicates them in the
// JsonDocument. Prefer plain old char[], as they are more efficient in term of
// code size, speed, and memory usage.
//

#include <ArduinoJson.h> // https://github.com/bblanchon/ArduinoJson

void parseVariant(JsonVariant variant) {
  JsonVariant val_id = variant.getMember("id");
  int id = val_id.as<int>();
  Serial.print("id=");
  Serial.println(id);

  JsonVariant val_user_id = variant.getMember("user_id");
  int user_id = val_user_id.as<int>();
  Serial.print("user_id=");
  Serial.println(user_id);

  JsonVariant val_category_id = variant.getMember("category_id");
  int category_id = val_category_id.as<int>();
  Serial.print("category_id=");
  Serial.println(category_id);

  JsonVariant val_content = variant.getMember("content");
  const char * content = val_content.as<char*>();
  Serial.print("content=");
  Serial.println(content);
}



int parseString(String input) {
  DynamicJsonDocument doc(1024);
  
  //deserializeJson(doc, input);
  DeserializationError error = deserializeJson(doc, input);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return 0;
  }   

#if 0      
  Serial.print("measureJson=");
  Serial.println(measureJson(doc));
#endif
  
  JsonObject root = doc.as<JsonObject>();

#if 0
  const char * records = root["records"];
  Serial.print("records=");
  Serial.println(records);
#endif
  JsonArray array = root.getMember("records");
  //Serial.print("val_records.size()=");
  //Serial.println(val_records.size());

  //JsonArray array  = doc.as<JsonArray>();
  Serial.print("array.size()=");
  Serial.println(array.size());
  if (array.size() == 0) {
    JsonVariant variant = doc.as<JsonVariant>();
    parseVariant(variant);
  } else {
    for(int i=0; i<array.size(); i++) {
      JsonVariant variant = array[i];
      parseVariant(variant);
      Serial.println();
    }
  }
  return measureJson(doc);
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  DynamicJsonDocument doc(1024);

  // You can use a String as your JSON input.
  // WARNING: the string in the input  will be duplicated in the JsonDocument.
  // WARNING: the string in the input  will be duplicated in the JsonDocument.
  String input = "\
{\"records\":\
[\
{\"id\":1,\"user_id\":1,\"category_id\":1,\"content\":\"blog started\"},\
{\"id\":2,\"user_id\":1,\"category_id\":2,\"content\":\"It works!\"}\
]\
}\
";

  Serial.println("input=");
  Serial.println(input);

  parseString(input);
 
}

void loop() {
  // not used in this example
}

// See also
// --------
//
// https://arduinojson.org/ contains the documentation for all the functions
// used above. It also includes an FAQ that will help you solve any problem.
//
// The book "Mastering ArduinoJson" contains a quick C++ course that explains
// how your microcontroller stores strings in memory. On several occasions, it
// shows how you can avoid String in your program.
// Learn more at https://arduinojson.org/book/
// Use the coupon code TWENTY for a 20% discount ❤❤❤❤❤
