/* HSTMATCH module=hstp_trans_main.prx start=0x002a2e74 end=0x002a2efc symbol=FUN_002a2e74 lang=c99 data=0x003a88c8 */
/* Clone of src/eboot/handle_setup_00291868.c (hstclone.py tag c034907): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003a88c8-0x003a88e7) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a7/v21) corrected by hand: replaced raw offsets with a struct and recovered the dropped argument of FUN_002c7748; exact match verified; names and types await human review. */
typedef struct Obj { char pad[0x14]; int fd; } Obj;

extern char DAT_003a88e8[];
extern void FUN_002a130c();
extern int FUN_002c7678();
extern void FUN_002c7748(int);

int FUN_002a2e74(Obj *self)
{
  Obj *local_4;
  int r;

  if (self->fd < 0) {
    FUN_002a130c("ERROR: thread is not created.\n");
    r = 0;
  } else {
    local_4 = self;
    if (FUN_002c7678(self->fd, 4, &local_4) < 0) {
      FUN_002a130c(DAT_003a88e8, self->fd);
      if (self->fd >= 1) {
        FUN_002c7748(self->fd);
        self->fd = -1;
      }
      r = 0;
    } else {
      r = 1;
    }
  }
  return r;
}
