# ArduinoJson_Example
Example to handle Arrays with ArduinoJson.   
ArduinoJson is [here](https://github.com/bblanchon/ArduinoJson)

# Purpose:
I want to parse these JSON string using ArduinoJson.   

```
[
  {
    "id": 1,
    "title": "Hello World!",
    "time": 1351824120,
    "data": [
      1,
      2,
      3
    ]
  },
  {
    "id": 2,
    "title": "Hello Japan!",
    "time": 1351824240,
    "data": [
      1.11,
      2.22
    ]
  }
]
```

# Result:
```
input=
[
  {
    "id": 1,
    "title": "Hello World!",
    "time": 1351824120,
    "data": [
      1,
      2,
      3
    ]
  },
  {
    "id": 2,
    "title": "Hello Japan!",
    "time": 1351824240,
    "data": [
      1.11,
      2.22
    ]
  }
]

measureJson=135
array.size()=2
id=1
title=Hello World!
time=1351824120
val_data.size()=3
data[0]=1.00
data[1]=2.00
data[2]=3.00
id=2
title=Hello Japan!
time=1351824240
val_data.size()=2
data[0]=1.11
data[1]=2.22
```

---

# Purpose:
I want to parse these JSON string using ArduinoJson.   

```
{"records":
  [
    {"id":1,"user_id":1,"category_id":1,"content":"blog started"},
    {"id":2,"user_id":1,"category_id":2,"content":"It works!"}
  ]
}
```

# Result:
```
input=
{"records":
  [
    {"id":1,"user_id":1,"category_id":1,"content":"blog started"},
    {"id":2,"user_id":1,"category_id":2,"content":"It works!"}
  ]
}

array.size()=2
id=1
user_id=1
category_id=1
content=blog started

id=2
user_id=1
category_id=2
content=It works!

```


