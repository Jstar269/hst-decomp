/* HSTMATCH module=EBOOT.BIN start=0x002911cc end=0x00291280 symbol=FUN_002911cc lang=c99 */
/* Clone of src/sharing_main/send_stop_request_002a28d4.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (the out-of-line copy of the stop request that src/sharing_main/dtor_send_stop_request_002a2c94.c inlines; the "request is full" warning arm falls through to the shared final `return 1`, which gives retail its own out-of-line `li v0,1` block and the copied `b; li v0,1`); exact match verified; names and types await human review. */
typedef struct Svc {
  char pad0[0x28];
  unsigned char ready;
  char pad1[0x88 - 0x29];
  int pipe;
  int req_cmd;
  int req_arg;
  unsigned char req_flag;
} Svc;
extern char DAT_002ff534[];
extern char DAT_002ff56c[];
extern char DAT_002ff5a4[];
extern void FUN_0028fb44(const char *, ...);
extern int FUN_002b7988(int, void *, int, int, int *);

int FUN_002911cc(Svc **param_1)
{
  int sent;
  int r;
  Svc *s = *param_1;
  if (s->ready == 0) {
    FUN_0028fb44(DAT_002ff534);
    return 0;
  }
  s->req_cmd = 0;
  s->req_flag = 0;
  s->req_arg = 0;
  r = FUN_002b7988(s->pipe, &s->req_cmd, 0x48, 0, &sent);
  if (r == -0x7ffdfe4d) {
    FUN_0028fb44(DAT_002ff5a4);
  } else if (r != 0 || sent != 0x48) {
    FUN_0028fb44(DAT_002ff56c, r, sent);
    return 0;
  }
  return 1;
}
