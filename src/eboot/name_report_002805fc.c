/* HSTMATCH module=EBOOT.BIN start=0x002805fc end=0x002807d0 symbol=FUN_002805fc lang=c99 data=0x002fe8d4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The three arms are written positive-test-first (formatToBuf != 0, then useAlt != 0): MWCC keeps the fall-through arm
   inline and puts the taken arm out of line, which is retail's layout. Data: its string literals (1 strings, 0x002fe8d4-0x002fe8ea) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern char DAT_002c0e20;
extern char DAT_002c0e1c;
extern char DAT_002c0e18;
extern int DAT_003415ac;

typedef struct Limits {
  char pad0[8];
  int unk8;     /* 0x08 compared with 0x11 */
} Limits;

typedef struct Texts {
  char pad0[0xc0];
  void *table;  /* 0xc0 block holding the text pointers at +0x40 and +0x44 */
  int count;    /* 0xc4 compared with 0x11/0x12 */
} Texts;

typedef struct Node {
  char pad0[4];
  int unk4;     /* 0x04 zero selects the first fallback text */
  Limits *limits; /* 0x08 */
  Texts *texts;   /* 0x0c */
} Node;

extern void FUN_002803d8(char *);
extern Node *FUN_0018c9f4(int);
extern void FUN_00114168(int, int, void *, int, int);
extern void FUN_000143b0(int, void *, ...);

/* Picks a text for the message (one of three fallbacks or a table entry) and passes it on; the first arm
   also formats it into the buffer. */
void FUN_002805fc(int buf, int useAlt, int formatToBuf, int arg)
{
  Node *n;
  char *text;

  if (formatToBuf != 0) {
    n = FUN_0018c9f4(0x11);
    if (n->unk4 == 0)
      text = &DAT_002c0e20;
    else if (n->limits->unk8 < 0x11)
      text = &DAT_002c0e1c;
    else if (n->texts->count < 0x12)
      text = &DAT_002c0e18;
    else
      text = *(char **)((char *)n->texts->table + 0x44);
    FUN_000143b0(buf, text, arg);
    FUN_00114168(DAT_003415ac, 6, (void *)buf, 0, 0);
  } else if (useAlt != 0) {
    n = FUN_0018c9f4(0x11);
    if (n->unk4 == 0)
      text = &DAT_002c0e20;
    else if (n->limits->unk8 < 0x11)
      text = &DAT_002c0e1c;
    else if (n->texts->count < 0x11)
      text = &DAT_002c0e18;
    else
      text = *(char **)((char *)n->texts->table + 0x40);
    FUN_00114168(DAT_003415ac, 6, text, 0, 0);
    if (buf != 0)
      FUN_000143b0(buf, text);
  } else {
    FUN_002803d8("IllegalErrorMessage=\n");
    n = FUN_0018c9f4(0x11);
    if (n->unk4 == 0)
      text = &DAT_002c0e20;
    else if (n->limits->unk8 < 0x11)
      text = &DAT_002c0e1c;
    else if (n->texts->count < 0x11)
      text = &DAT_002c0e18;
    else
      text = *(char **)((char *)n->texts->table + 0x40);
    FUN_00114168(DAT_003415ac, 6, text, 0, 0);
  }
}
