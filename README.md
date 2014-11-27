SCDrummer
=========
This project is a wrapper to allow you to trigger a solenoid powered mechanical beater from SuperCollider and Arduino

The assumption is that your solenoid is triggered by a transistor or relay that is connected to a digital out on the Arduino board

Load the sketch drumOut onto your Arduino

Put the class DrumOut.sc in your SuperCollider class library (Platform.userExtensionDir) and recompile the library

Run this code
//Make an instance, it will automatically find an arduino if one is attached
~drumBot=DrumOut.new(nil,nil);

//Add an arm (name, arduinoPin, strikeRate)
//The strikeRate is how long the solenoid is turned on before being turned off again
~drumBot.addArm(\drum1,13,0.5);

//Trigger the drum
~drumBot.strike(\drum1)

