/* HSTMATCH module=EBOOT.BIN start=0x000969c0 end=0x00096a90 symbol=FUN_000969c0 lang=c99 */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern float DAT_00338720;
extern float DAT_00338724;
extern float DAT_00338728;
extern float DAT_0033872c;
extern float DAT_00338730;
extern float DAT_00338734;
extern float DAT_00338738;
extern float DAT_0033873c;
extern float DAT_00338740;
extern float DAT_00338744;
extern float DAT_00338748;
extern float DAT_0033874c;
extern undefined4 DAT_00338750;
extern undefined2 DAT_00338754;
extern undefined DAT_00338756;
extern undefined DAT_00338757;
extern undefined4 DAT_00338758;

void FUN_000969c0(int param_1)
{
  {
    float x = *(float *)(param_1 + 0xf0);
    float y = *(float *)(param_1 + 0xf4);
    float z = *(float *)(param_1 + 0xf8);
    float w = *(float *)(param_1 + 0xfc);
    DAT_0033872c = w; DAT_00338724 = y; DAT_00338728 = z; DAT_00338720 = x;
  }
  {
    float x = *(float *)(param_1 + 0x100);
    float y = *(float *)(param_1 + 0x104);
    float z = *(float *)(param_1 + 0x108);
    float w = *(float *)(param_1 + 0x10c);
    DAT_0033873c = w; DAT_00338734 = y; DAT_00338738 = z; DAT_00338730 = x;
  }
  DAT_00338740 = *(float *)(param_1 + 0x110);
  DAT_00338744 = *(float *)(param_1 + 0x114);
  DAT_00338748 = *(float *)(param_1 + 0x118);
  DAT_0033874c = *(float *)(param_1 + 0x11c);
  DAT_00338750 = *(undefined4 *)(param_1 + 0x120);
  DAT_00338754 = *(undefined2 *)(param_1 + 0x124);
  DAT_00338756 = *(undefined1 *)(param_1 + 0x126);
  DAT_00338757 = *(undefined1 *)(param_1 + 0x127);
  DAT_00338758 = *(undefined4 *)(param_1 + 0x128);
}

// Near miss: retail stores f3 to DAT_00338720 before f0 to DAT_0033872c; this source reverses those two stores.
// The same final-store reversal remains for DAT_00338730 and DAT_0033873c. Typed +0x120 word access is matched.
// Tried 24 common row-store orders plus scoped aggregate and scalar-local forms; other orders disturb the row loads.
// near miss from lane u2r1-0 (unreviewed)
