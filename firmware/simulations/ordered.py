NULL_NOTE = 255

key_events = (
    (True, 1),
    (True, 12),
    (True, 5),
    (True, 8),
    (False, 5),
    (False, 8),
    (True, 5),
    (False, 12),
    (False, 1),
    (False, 5),
    (True, 1),
    (True, 5),
    (True, 8),
    (True, 12),
)


class Ordered:
    def __init__(self, count=3):
        self.count = count
        self.notes = [NULL_NOTE] * (count + 1)
        self.keys = [NULL_NOTE] * count

    def __str__(self):
        notes = ", ".join(f"{n:03}" for n in self.notes)
        keys = ", ".join(f"{n:03}" for n in self.keys)
        return f"[{notes}]{{{keys}}}]"


class OrderedFIFO(Ordered):
    def note_on(self, note):
        for idx in range(self.count - 1, 0, -1):
            self.notes[idx] = self.notes[idx - 1]
        self.notes[0] = note

        try:
            idx = self.keys.index(self.notes[self.count])
        except ValueError:
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


class OrderedLIFO(Ordered):
    def note_on(self, note):
        pass

    def note_off(self, note):
        pass


class OrderedLimit:
    def __init__(self, count=3):
        self.count = count
        self.keys = [NULL_NOTE] * count

    def __str__(self):
        keys = ", ".join(f"{n:03}" for n in self.keys)
        return f"{{{keys}}}"

    def note_on(self, note):
        for idx in range(self.count):
            if self.keys[idx] == NULL_NOTE:
                self.keys[idx] = note
                break

    def note_off(self, note):
        for idx in range(self.count):
            if self.keys[idx] == note:
                self.keys[idx] = NULL_NOTE
                break


fifo_model = OrderedFIFO()
lifo_model = OrderedLIFO()
limit_model = OrderedLimit()
for press, note in key_events:
    if press:
        fifo_model.note_on(note)
        lifo_model.note_on(note)
        limit_model.note_on(note)
        action = "  Press"
    else:
        fifo_model.note_off(note)
        lifo_model.note_off(note)
        limit_model.note_off(note)
        action = "Release"

    print(
        f"{action} [{note:02}] - FIFO: {fifo_model}; LIFO: {lifo_model}; Limit: {limit_model}"
    )
