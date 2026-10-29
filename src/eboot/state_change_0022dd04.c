/* HSTMATCH module=EBOOT.BIN start=0x0022dd04 end=0x0022e020 symbol=FUN_0022dd04 lang=c99 data=0x002f353c */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed object and address symbols (lui/addiu), if/else-if on the new value rewritten as a range test plus a one-case-group switch (cases 0x22, 0x23, 0x25), table index as an int array, header typedefs dropped; readability pass; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002f353c-0x002f3587) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern char DAT_0034179c[];
extern char DAT_0030ab9c[];
extern char DAT_0030ebf4[];
extern int DAT_002f33e4[];
extern void *FUN_00010184(int, int);
extern void FUN_000104e0(void *);
extern void FUN_000143b0(char *, char *, int);
extern void FUN_0001bfb4(char *, void *, int);
extern void FUN_0001ca58(char *, char *);
extern void FUN_0001cb88(char *);
extern int FUN_0001cbfc(void);
extern int FUN_0001cc54(void);
extern void FUN_001b2430(char *);
extern void FUN_001b322c(char *);
extern void FUN_001b32e0(char *, int);
extern void FUN_001b32f8(char *, int);
extern void FUN_001b3378(char *, int);
extern void FUN_001b338c(char *, int);
extern void FUN_001b3ce8(char *, int);
extern void FUN_001b3e2c(char *);

enum {
  BGM_NONE = -1,
  BGM_LOBBY_FIRST = 0x28,   /* lobby tracks are numbered BGM_LOBBY_FIRST .. BGM_LOBBY_END - 1 */
  BGM_LOBBY_END = 0x32,
  BGM_LOBBY_BASE = 0x27,    /* lobby track number = bgm - BGM_LOBBY_BASE */
  BGM_STREAM_A = 0x22,      /* ids that play the plain stream file */
  BGM_STREAM_B = 0x23,
  BGM_STREAM_C = 0x25,
  STREAM_BUFFER_SIZE = 0xccccc,
  LOBBY_BUFFER_SIZE = 0x173333
};

/* Option screen: the selected bgm id and the one currently playing. */
typedef struct OptionScreen {
  char pad0[0xa4];
  int nextBgm;     /* 0xa4 */
  int curBgm;      /* 0xa8 */
  char pad1[0x25c - 0xac];
  int page;        /* 0x25c */
} OptionScreen;

/* Switches the option screen's background music to the track chosen for the current page. */
void FUN_0022dd04(OptionScreen *o)
{
  void *buffer;
  int data;
  int size;
  int track;
  int next;
  char path[256];

  FUN_001b3e2c(DAT_0034179c);
  FUN_001b2430(DAT_0034179c);
  if (o->curBgm == BGM_NONE) {
    buffer = FUN_00010184(0x40, STREAM_BUFFER_SIZE);
    FUN_0001bfb4(DAT_0030ab9c, buffer, STREAM_BUFFER_SIZE);
    FUN_0001ca58(DAT_0030ebf4, "menu/optionbgm/option_bgm_stream.xb");
    FUN_001b3378(DAT_0034179c, 0);
    FUN_001b3378(DAT_0034179c, 2);
    FUN_001b3378(DAT_0034179c, 6);
    FUN_001b322c(DAT_0034179c);
    FUN_0001cb88(DAT_0030ebf4);
    data = FUN_0001cbfc();
    size = FUN_0001cc54();
    FUN_0001bfb4(DAT_0030ab9c, (void *)data, size);
    FUN_000104e0(buffer);
  }
  next = DAT_002f33e4[o->page];
  o->nextBgm = next;
  if (o->curBgm != next) {
    if (o->curBgm >= BGM_LOBBY_FIRST && o->curBgm < BGM_LOBBY_END) {
      FUN_001b32f8(DAT_0034179c, o->curBgm - BGM_LOBBY_BASE);
    }
    if (o->nextBgm >= BGM_LOBBY_FIRST && o->nextBgm < BGM_LOBBY_END) {
      FUN_001b338c(DAT_0034179c, 0x22);
      FUN_001b338c(DAT_0034179c, 0x23);
      FUN_001b338c(DAT_0034179c, 0x25);
      track = o->nextBgm - BGM_LOBBY_BASE;
      buffer = FUN_00010184(0x40, LOBBY_BUFFER_SIZE);
      FUN_0001bfb4(DAT_0030ab9c, buffer, LOBBY_BUFFER_SIZE);
      FUN_000143b0(path, "menu/optionbgm/option_bgm_lobby%02d.xb", track);
      FUN_0001ca58(DAT_0030ebf4, path);
      FUN_001b32e0(DAT_0034179c, track);
      FUN_0001cb88(DAT_0030ebf4);
      data = FUN_0001cbfc();
      size = FUN_0001cc54();
      FUN_0001bfb4(DAT_0030ab9c, (void *)data, size);
      FUN_000104e0(buffer);
    } else {
      switch (o->nextBgm) {
      case BGM_STREAM_A:
      case BGM_STREAM_B:
      case BGM_STREAM_C:
        buffer = FUN_00010184(0x40, STREAM_BUFFER_SIZE);
        FUN_0001bfb4(DAT_0030ab9c, buffer, STREAM_BUFFER_SIZE);
        FUN_0001ca58(DAT_0030ebf4, "menu/optionbgm/option_bgm_stream.xb");
        FUN_001b3378(DAT_0034179c, o->nextBgm);
        FUN_0001cb88(DAT_0030ebf4);
        data = FUN_0001cbfc();
        size = FUN_0001cc54();
        FUN_0001bfb4(DAT_0030ab9c, (void *)data, size);
        FUN_000104e0(buffer);
        break;
      }
    }
  }
  FUN_001b3ce8(DAT_0034179c, o->nextBgm);
  o->curBgm = o->nextBgm;
}
