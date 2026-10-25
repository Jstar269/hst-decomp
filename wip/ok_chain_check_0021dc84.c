/* HSTMATCH module=EBOOT.BIN start=0x0021dc84 end=0x0021dd0c symbol=FUN_0021dc84 lang=c99 */
/* Hand-written reconstruction from the disassembly; NOT exact (11 of 34 words differ, register naming only). */
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

typedef struct Q_0021dc84 { char pad[0x78]; float f78; } Q_0021dc84;
typedef struct P_0021dc84 { char pad[0x64]; int f64; char pad2[8]; Q_0021dc84 *f70; } P_0021dc84;
typedef struct Obj_0021dc84 {
  char pad[0x16c];
  P_0021dc84 *f16c;
  char pad2[0x1fc - 0x170];
  int f1fc;
  int f200;
} Obj_0021dc84;

int FUN_0021dc84(Obj_0021dc84 *o)
{
  int r = 0;
  if (!(o->f200 < o->f1fc)) {
    P_0021dc84 *p = o->f16c;
    unsigned char res = 1;
    int ok = 1;
    int nz = p != 0;
    if ((nz ^ 1) == 0) {
      if (nz) {
        int b = p->f64 < 0;
        if (!b) {
          if (!(p->f70->f78 <= 0.0f)) ok = 0;
          b = ok;
        }
        nz = b;
      }
      if (!nz) res = 0;
    }
    if (res) r = 1;
  }
  return r;
}
// Near miss, 13 words: control flow, loads and branch layout identical to retail (confirmed with hstdiff); only the temp register naming differs.
// retail: p=a1, nz/b web=a0, ok=a2, res=a3, with `li a2,1` right after the `lw` and `li a3,1` in the bnez delay slot.
// ours:   p=a0, nz/b web=a1, ok=a2, res=a3, and `li a3,1` + `move a2,a3` (the two constant-1 initialisers merge) unless `ok` is declared bool, which instead adds `andi 0xff` at `b = ok`.
// Ruled out (about 50 compiles): all 12 declaration orders of p/nz/ok/res; p declared last/first/at function top (p at top gives nz=a0 but p=a2 and a hoisted lw); `o->f16c` used directly instead of a p local;
// b merged into nz; bool ok / bool res / bool nz; a static inline NotPositive(float) helper for the f78 step (changes the branch shapes); `(p==0)||(f64<0)||(f78<=0)` expression forms (completely different layout).
// The retail structure is `res=1; ok=1; if (((p!=0)^1)==0) { if (p!=0) { b=f64<0; if(!b){ if(f78>0) ok=0; b=ok; } if(!b) res=0; } } if(res) r=1;` with r=0 preset and `if (!(o->f200 < o->f1fc))` first.

// Update (lane sn4): declaring `res` as `unsigned char` (not int) un-merges the two constant-1 initialisers exactly like retail
// (li a2,1 after the lw, li a3,1 in the bnez slot, no `move a2,a3`): 13 -> 11 words. The remaining 11 words are only the p/nz
// colouring: retail p=a1 (lw a1,364(a0)) and nz/b=a0, ours p=a0 and nz=a1. Also ruled out (about 40 more compiles): all 24
// declaration orders of p/res/ok/nz with res uchar, ok/nz/b as int or uchar in all 8 combinations (uchar nz/b adds code),
// wrapping the middle in a static inline Chk(P*) / Chk(Obj*), inline IsNull/Ok helpers (different branch shapes).
// improved by lane sn4 (unreviewed): 12 -> 11 differing words
