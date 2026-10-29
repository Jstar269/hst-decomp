/* HSTMATCH module=EBOOT.BIN start=0x000bc99c end=0x000bcc88 symbol=FUN_000bc99c lang=c99 data=0x002d53d8 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: result variable r merged at a `done:` label (goto) so the -1 shares the loop counter's register; names and types await human review. Data: its string literals (1 strings, 0x002d53d8-0x002d53e9) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/member_session.h"

/* Wire header of the member packet (field 1 is the total size, field 4 the entry count). */
typedef struct PacketHeader {
  int unk0;
  int size;
  int unk8;
  int unkc;
  int entry_count;
} PacketHeader;

/* One received member entry. */
typedef struct PacketEntry {
  int unk0;
  int unk4;
  int param;
  unsigned char flag;
} PacketEntry;

enum { HEADER_SIZE = 20, ENTRY_SIZE = 16 };

extern MemberName DAT_00338abc;
extern int FUN_0001100c(void *, void *, int);
extern void *FUN_00011090(void *, void *, int);
extern void FUN_000ba3ac(char *);
extern void FUN_000bb888(MemberSession *, PacketEntry *, int, int, int);

void FUN_000bc99c(MemberSession *session, char *src)
{
  int i;
  PacketHeader hdr;
  PacketEntry entry;
  /* clear the member table */
  for (i = 0; i < MEMBER_MAX; i++) {
    session->members[i].name = DAT_00338abc;
    session->members[i].used = 0;
    session->values[i] = 0;
  }
  hdr.unk0 = 0;
  FUN_00011090(&hdr, src, HEADER_SIZE);
  src += HEADER_SIZE;
  if (hdr.size == hdr.entry_count * ENTRY_SIZE + HEADER_SIZE) FUN_000ba3ac("recv mbr pkt ok\n");
  session->count = hdr.entry_count;
  for (i = 0; i < hdr.entry_count; i++) {
    FUN_00011090(&entry, src, ENTRY_SIZE);
    src += ENTRY_SIZE;
    FUN_000bb888(session, &entry, 0, 0, entry.param);
    session->flags[i] = entry.flag;
  }
  {
    MemberName *key = &session->key;
    int n = 0;
    unsigned char *p = (unsigned char *)session;
    int r;
    do {
      if (p[0x5e] != 0 && FUN_0001100c(p + 0x58, key, 6) == 0) {
        r = n;
        goto done;
      }
      n++;
      p += 7;
    } while (n < MEMBER_MAX);
    r = -1;
  done:
    session->found = r;
  }
}
