############################################
Hello Poly - Polyphonic MIDI to CV interface
############################################

Polyphonic MIDI to CV module for modular synths, designed primarily for (but not limited to) Eurorack systems.

Features:

- 6x 12bit DACs with a range of 0-~8.192V, 4x Note outputs, 2x Control outputs
- 4x Gate outputs
- Configurable CV range 1V/Octave or 1.2V/Octave (providing 100mV/step)
- Fully assignable routing of MIDI messages by channel and
- Multiple Polyphony modes (mono, Order based, Position based)
- Support for multiple programs (controlled via program change events)
- All configuration via MIDI.

Hardware

- Designed around an 32 bit ARM STM module
- Using MSP4822 12bit DACs
- Supporting an SSD1306 OLED display
