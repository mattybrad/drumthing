#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlayMemory          playMem1;       //xy=66,290
AudioSynthNoisePink      pink1;          //xy=69,219
AudioMixer4              mixer1;         //xy=218,318
AudioFilterStateVariable filter2;        //xy=365,318
AudioFilterStateVariable filter3;        //xy=365,382
AudioFilterStateVariable filter1;        //xy=366,239
AudioEffectEnvelope      envelope2;      //xy=514,307
AudioEffectEnvelope      envelope3;      //xy=515,360
AudioEffectEnvelope      envelope1;      //xy=517,258
AudioMixer4              mixer2;         //xy=665,322
AudioOutputI2S           i2s1;           //xy=801,321
AudioConnection          patchCord1(playMem1, 0, mixer1, 1);
AudioConnection          patchCord2(pink1, 0, mixer1, 0);
AudioConnection          patchCord3(mixer1, 0, filter1, 0);
AudioConnection          patchCord4(mixer1, 0, filter2, 0);
AudioConnection          patchCord5(mixer1, 0, filter3, 0);
AudioConnection          patchCord6(filter2, 1, envelope2, 0);
AudioConnection          patchCord7(filter3, 2, envelope3, 0);
AudioConnection          patchCord8(filter1, 0, envelope1, 0);
AudioConnection          patchCord9(envelope2, 0, mixer2, 1);
AudioConnection          patchCord10(envelope3, 0, mixer2, 2);
AudioConnection          patchCord11(envelope1, 0, mixer2, 0);
AudioConnection          patchCord12(mixer2, 0, i2s1, 0);
AudioConnection          patchCord13(mixer2, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=281,34
// GUItool: end automatically generated code

#include "AudioSampleChoir.h";

void setup() {
  // put your setup code here, to run once:
  AudioMemory(50);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.7);
  pink1.amplitude(0.7);
  filter1.frequency(100);
  filter1.resonance(2);
  filter2.frequency(800);
  filter3.frequency(300);
  envelope1.sustain(0.6);
  envelope2.sustain(0.1);
  envelope3.sustain(0.3);
  envelope1.release(200);
  envelope2.release(80);
  envelope3.release(500);
  mixer1.gain(0,0.1);
  mixer2.gain(0,1);
  mixer2.gain(1,0.1);
  mixer2.gain(2,0.05);
}

void loop() {
  playMem1.play(AudioSampleChoir);
  // put your main code here, to run repeatedly:
  switch(random(4)) {
    case 0:
    envelope1.noteOn();
    delay(50);
    envelope1.noteOff();
    break;
    
    case 1:
    envelope2.noteOn();
    delay(50);
    envelope2.noteOff();
    break;

    case 2:
    envelope3.noteOn();
    delay(50);
    envelope3.noteOff();
    break;

    default:
    delay(50);
  }
  delay(120);
}
