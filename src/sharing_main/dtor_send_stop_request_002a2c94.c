/* HSTMATCH module=hstp_trans_main.prx start=0x002a2c94 end=0x002a2db8 symbol=FUN_002a2c94 lang=c99 */
/* Clone of src/eboot/dtor_send_stop_request_00291688.c (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
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
extern int DAT_003b309c;
extern Holder *DAT_003f3b48;
extern int DAT_003f3b4c;
extern char DAT_003a8440[];
extern char DAT_003a8478[];
extern char DAT_003a84b0[];
extern void FUN_002a130c(const char *, ...);
extern int FUN_002c7728(int, void *, int, int, int *);
extern void FUN_002a16b0(Svc *);
extern void FUN_002a26f8(Holder *, int);
extern void FUN_000519d4(void *, int);
extern void FUN_00000a00(void *);

void *FUN_002a2c94(void *self, short flag)
{
  if (self != 0) {
    int sent;
    Svc *s;
    *(int **)self = &DAT_003b309c;
    s = DAT_003f3b48->svc;
    if (s->ready == 0) {
      FUN_002a130c(DAT_003a8440);
    } else {
      int r;
      s->req_cmd = 0;
      s->req_flag = 0;
      s->req_arg = 0;
      r = FUN_002c7728(s->pipe, &s->req_cmd, 0x48, 0, &sent);
      if (r == -0x7ffdfe4d) {
        FUN_002a130c(DAT_003a84b0);
      } else if (r != 0 || sent != 0x48) {
        FUN_002a130c(DAT_003a8478, r, sent);
      }
    }
    FUN_002a16b0(DAT_003f3b48->svc);
    FUN_002a26f8(DAT_003f3b48, 1);
    DAT_003f3b4c = 0;
    FUN_000519d4(self, 0);
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
