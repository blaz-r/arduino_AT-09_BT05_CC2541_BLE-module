# arduino_AT-09_BT05_CC2541_BLE-module
ArduinoIDE code for AT-09 (BT05, CC2541 chip) BLE-module configuration

This code was written for this particular module: https://www.aliexpress.com/item/32826166129.html . It could probably work with any similar module, but mind that the commands can be different.
Main reason for making this guide is that as it appears these Chinese modules have some quirks, and it took quite some searching to find everything.

The following scheme shows how to wire module to arduino.
![wiring scheme](
https://github.com/blaz-r/arduino_AT-09_BT05_CC2541_BLE-module/blob/main/wiring_scheme.png)

You can change assigned RX and TX pins in code if you don't want to use pin 3 and 4. Just mind that you need to connect RXD pin on module to assigned TX pin on arduino, and TXD on module to RX on arduino.
```
SoftwareSerial Serial1(3, 4); // RX->3  TX->4
```

The code is simple, it just reads serial input from module and writes to it. This way you can use commands to configure the module.

Upload code to your arduino and then use serial monitor set to 115200 baudrate. It could work with other baud rates but this one seemed to work for this module. Now the next step is very important for this module. You need to set serial monitor to send both NL & CR when you send a command.
This module requires all commands to end with "NL + CR" and Serial.write() command in code removes "\\r\\n" symbols. It's also easier to configure it interactively.


Once you have all that set up, you simply write the commands and use send or "enter" to send them.
Command "AT" should give "OK" reply. Then you can use "AT+HELP" to get list of all commands. There's also a list of commands, for previously linked module, included in this repository: "AT09commands.txt".

A little example:
![serial monitor configuration](
https://github.com/blaz-r/arduino_AT-09_BT05_CC2541_BLE-module/blob/main/serial_monitor.png)

Mind that this set of commands and "NL + CR" requirement is needed for the module linked on top. Other modules could have a bit different commands, so you can try just using new line on end etc.
"AT" command should work in pretty much any case, so try using that.
