/* HSTMATCH module=EBOOT.BIN start=0x00203ba8 end=0x00203dcc symbol=FUN_00203ba8 lang=c99 */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
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

typedef union {
    unsigned int w;
    unsigned char b[4];
} Col;

typedef struct {
    float x;
    float y;
    float w;
    float h;
} Ext;

typedef struct {
    float x;
    float y;
    float w;
    float h;
    float pad[3];
    unsigned int col;
} Blk;

extern float DAT_002ef1d0;
extern float DAT_0032b190[];

extern void FUN_00051490(int, int, int, int, int, int, int);
extern void FUN_00203dcc(int, int, int);
extern void FUN_0005185c(int);
extern void FUN_00022548(Ext *, float *, Ext *);
extern void FUN_00051398(int, float);
extern void FUN_00051a10(int, unsigned int, float, float, float, float, float);

void FUN_00203ba8(int param_1)
{
  int i;
  int a;
  int n;
  int m;
  int d;
  int den;
  unsigned char alpha;
  float f20;
  float fv;
  Blk blk;

  if (*(unsigned char *)(param_1 + 0x4e4) == 0) return;
  FUN_00051490(*(int *)(param_1 + 0x520), 0, 0, 0x1e0, 0x110, 0, 0);
  i = 1;
  if (*(int *)(param_1 + 0x14) > 1) {
    do {
      FUN_00203dcc(param_1, i, 0);
      i = i + 1;
    } while (i < *(int *)(param_1 + 0x14));
  }
  FUN_0005185c(*(int *)(param_1 + 0x520));
  if (DAT_002ef1d0 == 0.0f) return;
  a = *(int *)(param_1 + 0xe4);
  n = (int)(*(float *)(param_1 + 0x514) * (float)(a << 3));
  if (n > 0xff) n = 0xff;
  m = (int)(*(float *)(param_1 + 0x510) * 4096.0f);
  d = a << 4;
  if (4096 - d < m) {
    den = d;
    if (den == 0) den = 1;
    blk.col = *(unsigned int *)(param_1 + 0xf0);
    fv = (float)((n * (m - (4096 - d))) / den);
    fv = fv * DAT_002ef1d0;
    alpha = (unsigned char)(fv / 2.0f);
    ((unsigned char *)&blk.col)[3] = alpha;
    blk.x = 0.0f;
    blk.y = 0.0f;
    blk.w = 1000.0f;
    blk.h = 1.0f;
    FUN_00022548((Ext *)&blk, DAT_0032b190, (Ext *)&blk);
    f20 = blk.w / blk.h;
    FUN_00051398(*(int *)(param_1 + 0x524), 3000.0f);
    FUN_00051490(*(int *)(param_1 + 0x524), 0, 0, 0x1e0, 0x110, 0, 0);
    FUN_00051a10(*(int *)(param_1 + 0x524), blk.col, 0.0f, 0.0f, 480.0f, 272.0f, f20);
    FUN_0005185c(*(int *)(param_1 + 0x524));
  }
  return;
}

/* Matching notes: the colour argument of FUN_00051a10 is declared unsigned int (with int, the handle and colour loads swap); the clamp must be `n > 0xff` (`n >= 0x100` allocates the slti to v1 instead of at); the 4-float extent is the first 16 bytes of the 32-byte Blk aggregate whose last word is the colour. */
