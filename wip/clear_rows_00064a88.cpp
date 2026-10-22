/* HSTMATCH module=EBOOT.BIN start=0x00064a88 end=0x00064bf4 symbol=FUN_00064a88 lang=c++ */
/* NEAR MISS: 93/91 words, 85 differ (the frame is right but the locals sit 4 bytes high and the
   row pointer is coloured v1 instead of s1, which shifts everything after 0x64b70). */
/* Clears a table of 12-byte rows: every row holds a vector of item pointers, every item is
   released through its virtual destructor (vtable slot 0, the deleting dtor) and then the row
   array is rebuilt by FUN_00065a88 and swapped back into the object.
   MATCHED so far: the loop guards use the inline Eq/Ne helpers on raw pointers (that is what
   gives retail's xor/sltiu/xori instead of a plain bne), `delete item` on a class with a virtual
   destructor gives retail's null check plus `lw t9,0(a0); lw t9,8(t9); jalr t9` with a1 = 1, the
   three fields are swapped with a load/load/store/store pair each, and the empty tag argument of
   FUN_00065a88 reproduces retail's 48-byte frame.
   DIFFERENCE: (1) retail loads the row pointer straight into s1 and copies `self` into s2 in the
   branch delay slot, ours keeps the row pointer in v1 and copies it to s1 later; (2) retail's
   locals are the 12-byte block at sp+28 and the flag byte at sp+24, ours has the block at sp+32
   and the flag at sp+47; the flag byte is read uninitialised in retail (never written), which is
   why it has to stay in memory (volatile here) instead of a register.
   RULED OUT: an Out struct with a leading flag byte (the member offsets then do not match), the
   flag byte as a normal local (MWCC keeps it in s0, which costs a saved register), passing the
   `done`/`flag` value as the third argument of FUN_00066098-like calls (MWCC then keeps it in a
   saved register), and the empty tag on the other two calls (the frame grows but the argument
   setup changes). */
struct Item {
    virtual ~Item();
};

struct Row {
    Item **items;
    int count;
    int pad;
};

struct Out {
    Row *rows;
    int count;
    int fc;
};

struct Self {
    char pad[4];
    Row *rows;
    int count;
    int fc;
};

struct False {};

extern "C" void FUN_00065dd0(Row *rows, int count, signed char flag);
extern "C" void FUN_00065a88(Out *out, Row *first, Row *last, signed char flag, False tag);
extern "C" void FUN_00065fa0(Out *p, int n);

static inline bool Eq(const void *a, const void *b) { return a == b; }
static inline bool Ne(const void *a, const void *b) { return !Eq(a, b); }

extern "C" void FUN_00064a88(Self *self)
{
    Row *row = self->rows;
    while (Ne(row, self->rows + self->count)) {
        Item **p = row->items;
        while (Ne(p, row->items + row->count)) {
            Item *item = *p;
            delete item;
            p++;
        }
        row++;
    }
    FUN_00065dd0(self->rows, self->count, 0);
    Out out;
    volatile char flag;
    out.rows = 0;
    out.count = 0;
    out.fc = 0;
    FUN_00065a88(&out, self->rows, self->rows + self->count, flag, False());
    {
        int t = out.fc;
        out.fc = self->fc;
        self->fc = t;
    }
    {
        Row *tr = out.rows;
        out.rows = self->rows;
        self->rows = tr;
    }
    {
        int t = out.count;
        out.count = self->count;
        self->count = t;
    }
    FUN_00065fa0(&out, 0);
}
// near miss from lane om1 (unreviewed)
