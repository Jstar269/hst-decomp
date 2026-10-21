/* HSTMATCH module=EBOOT.BIN start=0x00291688 end=0x002917ac symbol=FUN_00291688 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Svc {
  char pad0[0x28];
  unsigned char ready;
  char pad1[0x88 - 0x29];
  int pipe;
  int req_cmd;
  int req_arg;
  unsigned char req_flag;
} Svc;
typedef struct Holder { Svc *svc; } Holder;
extern int DAT_00309db4;
extern Holder *DAT_0034a818;
extern int DAT_0034a81c;
extern char DAT_002ff534[];
extern char DAT_002ff56c[];
extern char DAT_002ff5a4[];
extern void FUN_0028fb44(const char *, ...);
extern int FUN_002b7988(int, void *, int, int, int *);
extern void FUN_0028ff38(Svc *);
extern void FUN_00290ff0(Holder *, int);
extern void FUN_000510c0(void *, int);
extern void FUN_00000a00(void *);

void *FUN_00291688(void *self, short flag)
{
  if (self != 0) {
    int sent;
    Svc *s;
    *(int **)self = &DAT_00309db4;
    s = DAT_0034a818->svc;
    if (s->ready == 0) {
      FUN_0028fb44(DAT_002ff534);
    } else {
      int r;
      s->req_cmd = 0;
      s->req_flag = 0;
      s->req_arg = 0;
      r = FUN_002b7988(s->pipe, &s->req_cmd, 0x48, 0, &sent);
      if (r == -0x7ffdfe4d) {
        FUN_0028fb44(DAT_002ff5a4);
      } else if (r != 0 || sent != 0x48) {
        FUN_0028fb44(DAT_002ff56c, r, sent);
      }
    }
    FUN_0028ff38(DAT_0034a818->svc);
    FUN_00290ff0(DAT_0034a818, 1);
    DAT_0034a81c = 0;
    FUN_000510c0(self, 0);
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
