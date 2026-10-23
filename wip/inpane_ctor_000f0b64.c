/* HSTMATCH module=EBOOT.BIN start=0x000f0b64 end=0x000f0d84 symbol=FUN_000f0b64 lang=c99 */
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

extern void FUN_00102e38(void);
extern void FUN_00104118(int, char *, int);
extern void FUN_00103540(int, float);
extern void FUN_001037c8(int, int);
extern int FUN_001039d8(int, char *, int);
extern int FUN_001026b8(int, int);
extern void FUN_000f1090(int);
extern void FUN_000f0d84(int);

extern int DAT_00307894;
extern float DAT_002d6c9c;
extern float DAT_002d757c;
extern float DAT_002d7580;
extern char DAT_002d7584[];
extern char *PTR_s_minipoint_002d7474[];
extern int DAT_002d74f8[];

void FUN_000f0b64(int param_1)
{
  int i;
  int off;
  char **name;
  int obj;
  int *tbl;
  short s1;
  short s2;
  short s3;
  short s4;
  float f5;
  float f6;

  FUN_00102e38();
  *(undefined4 *)param_1 = (undefined4)&DAT_00307894;
  FUN_00104118(param_1, (char *)&DAT_002d7584, 0);
  FUN_00103540(param_1, DAT_002d6c9c);
  FUN_001037c8(param_1, 0xffffff05);
  i = 0;
  name = PTR_s_minipoint_002d7474;
  off = 0;
  do {
    obj = FUN_001039d8(param_1, *name, 0);
    *(undefined4 *)(param_1 + off + 0x58) = obj;
    i = i + 1;
    name = name + 1;
    off = off + 4;
  } while (i < 3);
  i = 0;
  tbl = DAT_002d74f8;
  off = 0;
  do {
    obj = FUN_001026b8(*(undefined4 *)(param_1 + tbl[0] * 4 + 0x58), tbl[1]);
    *(undefined4 *)(param_1 + off + 0x64) = obj;
    i = i + 1;
    off = off + 4;
    tbl[2] = *(undefined4 *)(obj + 0x24);
    tbl = tbl + 3;
  } while (i < 0xb);
  f5 = DAT_002d757c;
  f6 = DAT_002d7580;
  off = 0;
  i = 0;
  do {
    obj = *(undefined4 *)(param_1 + off + 0x64);
    i = i + 1;
    s1 = *(short *)(obj + 4);
    s2 = *(short *)(obj + 8);
    s3 = *(short *)(obj + 10);
    s4 = *(short *)(obj + 6);
    *(short *)(obj + 4) = (short)(int)((float)s1 * f5);
    *(short *)(*(undefined4 *)(param_1 + off + 0x64) + 4) =
        (short)(int)((float)*(short *)(*(undefined4 *)(param_1 + off + 0x64) + 4) + f6);
    *(short *)(*(undefined4 *)(param_1 + off + 0x64) + 8) =
        (short)(int)((float)((int)s2 - (int)s1) * f5 +
                     (float)*(short *)(*(undefined4 *)(param_1 + off + 0x64) + 4));
    *(short *)(*(undefined4 *)(param_1 + off + 0x64) + 6) =
        (short)(int)((float)*(short *)(*(undefined4 *)(param_1 + off + 0x64) + 6) * f5);
    *(short *)(*(undefined4 *)(param_1 + off + 0x64) + 10) =
        (short)(int)((float)((int)s3 - (int)s4) * f5 +
                     (float)*(short *)(*(undefined4 *)(param_1 + off + 0x64) + 6));
    off = off + 4;
  } while (i < 0xb);
  FUN_000f1090(param_1);
  FUN_000f0d84(param_1);
  *(undefined4 *)(param_1 + 0x90) = 0x3f800000;
  *(undefined1 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined1 *)(param_1 + 0xa0) = 0;
  return;
}

/* NEAR MISS: 136/136 words, 86 differ - every difference is the s0/s1 colour of the loop-1 pointer
   (name = s1, off = s0 in retail; name = s0, off = s1 here) plus the matching swap in loop 2
   (tbl = s1, i = s2 in retail) and the float-constant base register (retail `lui a0` interleaved with
   `move v0,s3`). Ruled out: declaration order of i/off/name/obj (four orders compiled, colour
   unchanged), spelling loop 1 as `param_1 + i*4` (mwcc then strength-reduces to a walking POINTER
   `move s0,s3; sw v0,88(s0)`, 135/136 words), and float-vs-pointer argument order in FUN_00103540
   (needs `(int, float)`: with no prototype mwcc promotes to double and calls __extendsfdf2).
   The offset variable must stay in the source: it is a BYTE offset (0,4,8) fed to `addu v1,s3,s0`. */
// near miss from lane fm4 (unreviewed)
