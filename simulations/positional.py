NULL_NOTE = 255

key_events = (
    (True,   1),
    (True,  12),
    (True,   5),
    (True,   8),

    (False,  5),
    (False,  8),
    (True,   5),
    (False, 12),
    (False,  1),
    (False,  5),

    (True,   1),
    (True,   5),
    (True,   8),
    (True,  12),
)


class Position:
    def __init__(self, count=3):
        self.count = count
        self.notes = [NULL_NOTE] * (count + 1)
        self.keys = [NULL_NOTE] * count
    
    def __str__(self):
        notes = ', '.join(f'{n:03}' for n in self.notes)
        keys = ', '.join(f'{n:03}' for n in self.keys)
        return f'[{notes}]{{{keys}}}]'


class PositionLow(Position):
    def note_on(self, note):
        for idx in reversed(range(self.count)):
            if note < self.notes[idx]:
                self.notes[idx + 1] = self.notes[idx]
                self.notes[idx] = note

        try:
            idx = self.keys.index(NULL_NOTE)
        except ValueError:
            try:
                idx = self.keys.index(self.notes[self.count])
            except:
                idx = None

        if idx is not None:
            self.keys[idx] = note

        self.notes[self.count] = NULL_NOTE

    def note_off(self, note):
        for idx in range(self.count):
            if note <= self.notes[idx]:
                self.notes[idx] = self.notes[idx + 1]

        try:
            idx = self.keys.index(note)
        except ValueError:
            pass
        else:
            self.keys[idx] = NULL_NOTE


class PositionHigh(Position):
    def note_on(self, note):
        for idx in reversed(range(self.count)):
            val = self.notes[idx]
            if note > val or val == NULL_NOTE :
                self.notes[idx + 1] = self.notes[idx]
                self.notes[idx] = note
        self.notes[self.count] = NULL_NOTE

    def note_off(self, note):
        for idx in range(self.count):
            if note >= self.notes[idx]:
                self.notes[idx] = self.notes[idx + 1]


lo_model = PositionLow()
hi_model = PositionHigh()
for press, note in key_events:
    if press:
        lo_model.note_on(note)
        hi_model.note_on(note)
        action = '  Press'
    else:
        lo_model.note_off(note)
        hi_model.note_off(note)
        action = 'Release'

    print(f"{action} [{note:02}] - Lo: {lo_model}; Hi: {hi_model}")

