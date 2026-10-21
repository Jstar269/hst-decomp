/* HSTMATCH module=hstp_trans_main.prx start=0x000bfe40 end=0x000c012c symbol=FUN_000bfe40 lang=c99 */
/* Clone of src/eboot/search_slot_by_key_000bc99c.c (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: result variable r merged at a `done:` label (goto) so the -1 shares the loop counter's register; names and types await human review. */
typedef struct { char c[6]; } Str6;
typedef struct { Str6 name; unsigned char used; } Slot;
typedef struct {
  char pad[0x38];
  Str6 key;
  char pad1[0x58 - 0x3e];
  Slot slots[16];
  int vals[16];
  char pad2[0x190 - 0x108];
  int count;
  int pad3;
  int found;
  char pad4[0x21c - 0x19c];
  unsigned char flags[16];
} Obj;
typedef struct { int f0, f1, f2, f3, f4; } Hdr;
typedef struct { int f0, f1, f2; unsigned char f3; } Item;
extern Str6 DAT_003e1dfc;
extern char DAT_0037bd0c[];
extern int FUN_0001100c(void *, void *, int);
extern void *FUN_00011090(void *, void *, int);
extern void FUN_000bd6f0(char *);
extern void FUN_000becfc(Obj *, Item *, int, int, int);

void FUN_000bfe40(Obj *o, char *src)
{
  int i;
  Hdr h;
  Item it;
  for (i = 0; i < 16; i++) {
    o->slots[i].name = DAT_003e1dfc;
    o->slots[i].used = 0;
    o->vals[i] = 0;
  }
  h.f0 = 0;
  FUN_00011090(&h, src, 20);
  src += 20;
  if (h.f1 == h.f4 * 16 + 20) FUN_000bd6f0(DAT_0037bd0c);
  o->count = h.f4;
  for (i = 0; i < h.f4; i++) {
    FUN_00011090(&it, src, 16);
    src += 16;
    FUN_000becfc(o, &it, 0, 0, it.f2);
    o->flags[i] = it.f3;
  }
  {
    char *key = (char *)o + 0x38;
    int n = 0;
    unsigned char *p = (unsigned char *)o;
    int r;
    do {
      if (p[0x5e] != 0 && FUN_0001100c(p + 0x58, key, 6) == 0) {
        r = n;
        goto done;
      }
      n++;
      p += 7;
    } while (n < 16);
    r = -1;
  done:
    o->found = r;
  }
}
