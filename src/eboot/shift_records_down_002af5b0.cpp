/* HSTMATCH module=EBOOT.BIN start=0x002af5b0 end=0x002af6ec symbol=FUN_002af5b0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#define RECORD_COUNT 100  /* records in the list */
struct F2 { float x, y; };
struct Rec {
  char unk00[16];
  F2 pos;           /* 0x10 */
  char unk18[21];
  float unk30;
  int unk34;
  int unk38;
  char unk3c[75];
  int unk88;
  int unk8c;
  int unk90;
  int unk94;
  int unk98;
  int unk9c;
  float unka0;
  float unka4;
  int unka8;
  int unkac;
  Rec() {}
};
/* Remove record index from the list at base by moving every later record down one place. */
extern "C" void FUN_002af5b0(int base, int index)
{
  Rec *src;
  Rec *dst = (Rec *)(base + index * sizeof(Rec));
  Rec *end = (Rec *)(base + RECORD_COUNT * sizeof(Rec));
  for (src = dst + 1; src < end; ++src, ++dst) {
    *dst = *src;
  }
}
