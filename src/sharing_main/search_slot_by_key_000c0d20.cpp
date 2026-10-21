/* HSTMATCH module=hstp_trans_main.prx start=0x000c0d20 end=0x000c0e5c symbol=FUN_000c0d20 lang=c++ */
/* Clone of src/eboot/search_slot_by_key_000bd7a4.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the not-found result is assigned to a separate res and both paths meet at one store via goto L); names and types await human review. */

extern "C" {
extern int DAT_0037be5c;
extern int FUN_0001100c(const void *, const void *, unsigned);
extern void *FUN_00011090(void *, const void *, unsigned);
}

template <class T>
inline const T& Min(const T &a, const T &b) {
  return b < a ? b : a;
}

struct Str6 {
  char c[6];
};

struct Slot {
  Str6 name;
  unsigned char used;
};

struct Obj {
  char pad0[56];
  Str6 key;
  char pad1[26];
  Slot slots[16];
  char pad2[208];
  int found;
};

extern "C" void FUN_000c0d20(Obj *o, int *indices, int count)
{
  int lim = Min(count, DAT_0037be5c);
  Slot buf[16];
  FUN_00011090(buf, o->slots, 112);

  int i = 0;
  if (lim > 0) {
    char *cur = (char *)o;
    do {
      int idx = *indices;
      if (idx >= 0) {
        char *t2 = (char *)&buf[idx];
        char *t1 = cur + 88;
        cur += 7;
        *(Str6 *)t1 = *(Str6 *)t2;
        ((unsigned char *)t1)[6] = ((unsigned char *)t2)[6];
      }
      i++;
      indices++;
    } while (i < lim);
  }

  char *key = (char *)o + 56;
  int n = 0;
  int res;
  unsigned char *p = (unsigned char *)o;
  do {
    if (p[94] != 0 && FUN_0001100c(p + 88, key, 6) == 0) {
      res = n;
      goto L;
    }
    n++;
    p += 7;
  } while (n < 16);
  res = -1;
L:
  o->found = res;
}
