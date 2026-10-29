/* HSTMATCH module=EBOOT.BIN start=0x0010192c end=0x00101c18 symbol=FUN_0010192c lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_002d8ad4;
extern undefined DAT_002d8ad8;
extern char DAT_002d8ab4[];
extern char DAT_002d8adc[];
extern char DAT_002d8ae8[];
extern char DAT_002d8af0[];
extern int FUN_00000bcc(int);
extern int FUN_00014a40(int);
extern char * FUN_00014d64(int, void *);
extern void FUN_001006b0(const char *);
struct Tag {};
struct PVec;
extern void FUN_00107130(PVec *, undefined4 *const *, Tag);
}
struct PVec {
  undefined4 **data;
  unsigned size;
  unsigned cap;
  undefined4 *&at(unsigned i) { return data[i]; }
  undefined4 *&back() { return at(size - 1); }
  void push_back(undefined4 *const &x, Tag)
  {
    if (size < cap) {
      ++size;
      back() = x;
    } else {
      FUN_00107130(this, &x, Tag());
    }
  }
};
struct Mgr {
  int pad0;
  undefined4 *table;
  int f8;
  int padc;
  PVec vec;
  undefined1 flag;
};
struct Callback {
  virtual void p0() = 0;
  virtual void method_0c(int) = 0;
  virtual void method_10(int) = 0;
  virtual void p14() = 0;
  virtual void method_18() = 0;
};

extern "C" undefined4 * FUN_0010192c(Mgr *param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined2 param_5, undefined2 param_6,undefined2 param_7,undefined2 param_8,undefined4 uStackX_0, undefined4 uStackX_4,undefined4 uStackX_8,int iStackX_c)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *local_4;
  undefined4 first_value;
  
  if (param_1->f8 == 0) {
    FUN_001006b0(DAT_002d8ab4);
  }
  local_4 = (undefined4 *)FUN_00000bcc(0x2c);
  *(undefined2 *)(local_4 + 1) = param_4;
  *(undefined2 *)((int)local_4 + 6) = param_5;
  *(undefined2 *)(local_4 + 2) = param_6;
  *(undefined2 *)((int)local_4 + 10) = param_7;
  *(undefined2 *)(local_4 + 3) = param_8;
  *(undefined2 *)((int)local_4 + 0xe) = 0;
  local_4[8] = uStackX_8;
  local_4[4] = uStackX_4;
  local_4[5] = 0;
  local_4[6] = 0;
  if (param_2 < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = param_1->table[param_2];
  }
  local_4[7] = uVar3;
  {
    undefined4 *record = local_4;
    *(ushort *)((int)record + 0xe) = *(ushort *)((int)record + 0xe) & 0xfffe;
    if ((Callback *)record[8] != 0) {
      ((Callback *)record[8])->method_0c(0);
    }
  }
  {
    undefined4 *record = local_4;
    *(ushort *)((int)record + 0xe) = *(ushort *)((int)record + 0xe) & 0xfffd;
    if ((Callback *)record[8] != 0) {
      ((Callback *)record[8])->method_10(0);
    }
  }
  first_value = uStackX_0;
  {
    undefined4 *record2 = local_4;
    record2[9] = param_3;
    record2[10] = param_3;
    *record2 = first_value;
  }
  if ((Callback *)local_4[8] != 0) {
    ((Callback *)local_4[8])->method_18();
  }
  if (iStackX_c != 0) {
    iVar1 = FUN_00014a40(iStackX_c);
    if (iVar1 != 0) {
      iVar1 = 0;
      do {
        if (FUN_00014d64(iStackX_c,&DAT_002d8ad4) != 0) {
          *(ushort *)((int)local_4 + 0xe) = *(ushort *)((int)local_4 + 0xe) | 0x800;
        }
        else if (FUN_00014d64(iStackX_c,&DAT_002d8ad8) != 0) {
          *(ushort *)((int)local_4 + 0xe) = *(ushort *)((int)local_4 + 0xe) | 0x1000;
        }
        if (FUN_00014d64(iStackX_c,DAT_002d8adc) != 0) {
          *(ushort *)((int)local_4 + 0xe) = *(ushort *)((int)local_4 + 0xe) | 0x2000;
        }
        else if (FUN_00014d64(iStackX_c,DAT_002d8ae8) != 0) {
          *(ushort *)((int)local_4 + 0xe) = *(ushort *)((int)local_4 + 0xe) | 0x4000;
        }
        else if (FUN_00014d64(iStackX_c,DAT_002d8af0) != 0) {
          *(ushort *)((int)local_4 + 0xe) = *(ushort *)((int)local_4 + 0xe) | 0x8000;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 2);
    }
  }
  param_1->vec.push_back(local_4, Tag());
  param_1->flag = 1;
  return local_4;
}
// sy1: 187/187 words, 7 differing words (was 187 words, 84 differing). Solved: (1) `if (iStackX_c != 0) { if (FUN_00014a40(c) != 0) { loop } }`
// with ONE push_back after it (the Ghidra copy of `uVar4 = size` into both arms was wrong); (2) the string chain is
// `if (cmp(..ad4) != 0) f |= 0x800; else if (cmp(..ad8) != 0) f |= 0x1000;` and `if (cmp(adc)) f |= 0x2000; else if (cmp(ae8)) f |= 0x4000;
// else if (cmp(af0)) f |= 0x8000;` (Ghidra had the arms inverted); (3) the manager is a struct `Mgr{pad; table; f8; pad; PVec vec; flag}`
// with an inline `PVec::push_back(T *const&, Tag)` using `++size; back() = x;` and grow `FUN_00107130(this, &x, Tag())`.
// Open: the block `record2[9]=p3; record2[10]=p3; *record2 = first_value;` - retail reloads local_4 (60(sp)) BEFORE the third store and
// loads first_value into a1 right after the first reload (`lw v0,60(sp); lw a1,64(sp); sw s3,36(v0); sw s3,40(v0); lw v0,60(sp);
// sw a1,0(v0)`), ours keeps one pointer in v1 and loads the value into v0. `*local_4 = first_value`, store-order swaps and direct uStackX_0 did not help.
// near miss from lane sy1 (unreviewed)
