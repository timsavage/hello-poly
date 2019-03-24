############################################
Hello Poly - Polyphonic MIDI to CV interface
############################################

Polyphonic MIDI to CV module for modular synths, designed primarily for (but not limited to) Eurorack systems.

Features:

- 6x 12bit DACs with a range of 0-~8.192V (assignable as either Note or Control outputs)
- 4x Gate outputs
- Configurable CV range 1V/Octave or 1.2V/Octave (providing a 100mV/step)
- Fully assignable routing of MIDI messages by channel
- Assignable Pitchbend and Channel Aftertouch
- Multiple Polyphony modes
- Support for multiple programs (controlled via program change events)
- Configuration via MIDI
- Gate controlled LFO.

Hardware

- Designed around an 32 bit ARM STM module
- MSP4822 12bit DACs
- 192x32 SSD1306 OLED display
