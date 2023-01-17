#include <Arduino.h>
#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>

TMRpcm audio;

unsigned long time = 0;

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    Serial.print("Initializing SD card...\n");
    if (!SD.begin(10)) {
        Serial.println("initialization failed!\n");
        return;
    }
    Serial.println("initialization done.\n");


    pinMode(LED_BUILTIN, OUTPUT);

    audio.speakerPin = 9;

    audio.setVolume(5);
    audio.play("scatman2.wav");

    if (audio.isPlaying()) {
        Serial.println("Playing...");
    } else {
        Serial.println("Not playing...");
    }

    // // open the file. note that only one file can be open at a time,
    // // so you have to close this one before opening another.
    // File soundFile = SD.open("sound.mp3", FILE_READ);
    // // if the file opened okay, write to it:
    // if (soundFile) {
    //     Serial.print("Playing sound.mp3...");
    //     Serial.write(soundFile.read());
    //     Serial.println("done.");
    // } else {
    //     Serial.println("error opening sound.mp3");
    // }
}

void loop() {
    // blink the LED manually to demonstrate music playback is independant of main loop
    if (audio.isPlaying() && millis() - time > 50 ) {      
        digitalWrite(13, !digitalRead(13));
        time = millis();    
    } else if (millis() - time > 500) {     
        digitalWrite(13, !digitalRead(13)); 
        time = millis(); 
    }

    if(Serial.available()){    
        switch(Serial.read()) {
            case 'd': audio.play("music"); break;
            case 'P': audio.play("supermusic.wav"); break;
            case 't': audio.play("sound.wav"); break;
            case 'p': audio.pause(); break;
            case '?': if(audio.isPlaying()){ Serial.println("A wav file is being played");} else { Serial.println("No sound is being played");} break;
            case 'S': audio.stopPlayback(); break;
            case '=': audio.volume(1); break;
            case '-': audio.volume(0); break;
            case '0': audio.quality(0); break;
            case '1': audio.quality(1); break;
            default: break;
        }
    }
}
