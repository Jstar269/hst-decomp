/* HSTMATCH module=EBOOT.BIN start=0x000bd7a4 end=0x000bd8e0 symbol=FUN_000bd7a4 lang=c++ */
/* Hand-written reconstruction from the disassembly; 77/79 words match (2 words differ); names and types await human review. */

extern "C" {
extern int DAT_002d550c;
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

extern "C" void FUN_000bd7a4(Obj *o, int *indices, int count)
{
  int lim = Min(count, DAT_002d550c);
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
  unsigned char *p = (unsigned char *)o;
  do {
    if (p[94] != 0 && FUN_0001100c(p + 88, key, 6) == 0) {
      o->found = n;
      return;
    }
    n++;
    p += 7;
  } while (n < 16);
  n = -1;
  o->found = n;
}

// Near miss, 2 words differ (EBOOT twin of wip/search_slot_by_key_000bfe40.c in Sharing).
// Everything matches including Min() reference temporary, memcpy of 112-byte buffer,
// 6-byte struct copy loop with lbu/sb of used byte, key hoisted in s3, search loop with index in s1 and cursor in s0.
// Only the fall-out o->found = -1 differs:
//   retail: li s1, -1 ; sw s1, 408(s2)       ours: li v1, -1 ; sw v1, 408(s2)
// i.e. retail keeps -1 in loop counter register s1.
// Ruled out: n = -1, o->found = -1, n -= 17, in-loop break with res, goto FOUND, parameter reuse indices = -1.
// near miss from lane s10172123g4r1-1 (unreviewed)
