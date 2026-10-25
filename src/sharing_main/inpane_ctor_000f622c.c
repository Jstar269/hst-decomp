/* HSTMATCH module=hstp_trans_main.prx start=0x000f622c end=0x000f644c symbol=FUN_000f622c lang=c99 */
/* Clone of src/eboot/inpane_ctor_000f0b64.c (hstclone.py tag nxc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

typedef struct { short pad[2]; short x, y, x2, y2; } Rect;
extern void FUN_0010873c(void);
extern void FUN_00109a44(int, char *, int);
extern void FUN_00108e6c(int, float);
extern void FUN_001090f4(int, int);
extern int FUN_00109304(int, char *, int);
extern int FUN_00108124(int, int);
extern void FUN_000f6758(int);
extern void FUN_000f644c(int);

extern int DAT_003b0b60;
extern float DAT_0037da74;
extern const float DAT_0037e354;
extern const float DAT_0037e358;
extern char DAT_0037e35c[];
extern char *DAT_0037e24c[];
extern int DAT_0037e2d0[];

static inline int Width(Rect *r) { return r->x2 - r->x; }
static inline int Height(Rect *r) { return r->y2 - r->y; }
int FUN_000f622c(int param_1)
{
  int i;
  int j;
  int k;
  char **name;
  int off;
  int obj;
  int *tbl;

  FUN_0010873c();
  *(undefined4 *)param_1 = (undefined4)&DAT_003b0b60;
  FUN_00109a44(param_1, (char *)&DAT_0037e35c, 0);
  FUN_00108e6c(param_1, DAT_0037da74);
  FUN_001090f4(param_1, 0xffffff05);
  i = 0;
  name = DAT_0037e24c;
  off = 0;
  do {
    obj = FUN_00109304(param_1, *name, 0);
    *(undefined4 *)(param_1 + off + 0x58) = obj;
    i = i + 1;
    name = name + 1;
    off = off + 4;
  } while (i < 3);
  j = 0;
  tbl = DAT_0037e2d0;
  off = 0;
  do {
    obj = FUN_00108124(*(undefined4 *)(param_1 + tbl[0] * 4 + 0x58), tbl[1]);
    *(undefined4 *)(param_1 + off + 0x64) = obj;
    j = j + 1;
    off = off + 4;
    tbl[2] = *(undefined4 *)(obj + 0x24);
    tbl = tbl + 3;
  } while (j < 0xb);
  for (k = 0; k < 0xb; k++) {
    int w = Width(((Rect *)((int *)param_1)[k + 0x19]));
    int h = Height(((Rect *)((int *)param_1)[k + 0x19]));
    float t, u, v;
    t = (float)((Rect *)((int *)param_1)[k + 0x19])->x;
    ((Rect *)((int *)param_1)[k + 0x19])->x = (short)(int)(t * DAT_0037e354);
    t = (float)((Rect *)((int *)param_1)[k + 0x19])->x;
    ((Rect *)((int *)param_1)[k + 0x19])->x = (short)(int)(t + DAT_0037e358);
    u = (float)w;
    t = (float)((Rect *)((int *)param_1)[k + 0x19])->x;
    ((Rect *)((int *)param_1)[k + 0x19])->x2 = (short)(int)(t + u * DAT_0037e354);
    t = (float)((Rect *)((int *)param_1)[k + 0x19])->y;
    ((Rect *)((int *)param_1)[k + 0x19])->y = (short)(int)(t * DAT_0037e354);
    v = (float)h;
    t = (float)((Rect *)((int *)param_1)[k + 0x19])->y;
    ((Rect *)((int *)param_1)[k + 0x19])->y2 = (short)(int)(t + v * DAT_0037e354);
  }
  FUN_000f6758(param_1);
  FUN_000f644c(param_1);
  *(undefined4 *)(param_1 + 0x90) = 0x3f800000;
  *(undefined1 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined1 *)(param_1 + 0xa0) = 0;
  return param_1;
}

