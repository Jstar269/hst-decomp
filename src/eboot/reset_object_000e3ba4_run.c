/* HSTMATCH module=EBOOT.BIN start=0x000e3ba4 end=0x000e3cd8 symbol=FUN_000e3ba4 lang=c99 */
/* Clone of src/sharing_main/reset_object_000e8534_run.c (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; two-function run (0xe8534 ends in a tail call `j` to the next function 0xe861c, defined in the same file); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_00051398(float, void *);
extern void FUN_000513a0(void *, int);
extern void FUN_000513fc(void *, int);

typedef struct { short s0; short count; } Info;
typedef struct { char b0; char pad[111]; } Rec;
typedef struct {
  char pad0[0x3c];
  Info *info;
  char pad1[8];
  void *h48;
  char pad2[4];
  Rec *recs;
  char buf[0xc0 - 0x54];
} Obj;

void FUN_000e3c8c(Obj *o);

void FUN_000e3ba4(Obj *o)
{
  char *p = (char *)o + 0x54;
  int n = 0xc0 - ((int)p - (int)o);
  int i;
  for (i = 0; i < n; i++) {
    *p++ = 0;
  }
  o->buf[4] = 1;
  o->buf[5] = 1;
  {
    int j;
    for (j = 0; j < o->info->count; j++) {
      o->recs[j].b0 = 0;
    }
  }
  FUN_000e3c8c(o);
}

void FUN_000e3c8c(Obj *o)
{
  FUN_000513a0(o->h48, 1);
  FUN_000513fc(o->h48, 1);
  FUN_00051398(5500.0f, o->h48);
}
