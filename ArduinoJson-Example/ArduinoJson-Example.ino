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

#include <ArduinoJson.h>

void parseVariant(JsonVariant variant) {
  JsonVariant val_id = variant.getMember("id");
  int id = val_id.as<int>();
  Serial.print("id=");
  Serial.println(id);

  JsonVariant val_title = variant.getMember("title");
  const char * title = val_title.as<char*>();
  Serial.print("title=");
  Serial.println(title);

  JsonVariant val_time = variant.getMember("time");
  long time = val_time.as<long>();
  Serial.print("time=");
  Serial.println(time);

  JsonArray val_data = variant.getMember("data");
  //int arraySize =  val_data.size();
  Serial.print("val_data.size()=");
  Serial.println(val_data.size());
  for (int i = 0; i< val_data.size(); i++){
    double data = val_data[i];
    Serial.print("data[");
    Serial.print(i);
    Serial.print("]=");
    Serial.println(data);
  }
}



int parseJSON(String input) {
  DynamicJsonDocument doc(1024);
  
  //deserializeJson(doc, input);
  DeserializationError error = deserializeJson(doc, input);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return 0;
  }   
      
  Serial.print("measureJson=");
  Serial.println(measureJson(doc));

  
  JsonObject root = doc.as<JsonObject>();

  JsonArray array  = doc.as<JsonArray>();
  Serial.print("array.size()=");
  Serial.println(array.size());
  if (array.size() == 0) {
    JsonVariant variant = doc.as<JsonVariant>();
    parseVariant(variant);
  } else {
    for(int i=0; i<array.size(); i++) {
      JsonVariant variant = array[i];
      parseVariant(variant);
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
[\n\
  {\n\
    \"id\": 1,\n\
    \"title\": \"Hello World!\",\n\
    \"time\": 1351824120,\n\
    \"data\": [\n\
      1,\n\
      2,\n\
      3\n\
    ]\n\
  },\n\
  {\n\
    \"id\": 2,\n\
    \"title\": \"Hello Japan!\",\n\
    \"time\": 1351824240,\n\
    \"data\": [\n\
      1.11,\n\
      2.22\n\
    ]\n\
  }\n\
]\n\
";

  Serial.println("input=");
  Serial.println(input);

  parseJSON(input);
 
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
