/* HSTMATCH module=hstp_trans_main.prx start=0x002a28d4 end=0x002a2988 symbol=FUN_002a28d4 lang=c99 */
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
extern char DAT_003a8440[];
extern char DAT_003a8478[];
extern char DAT_003a84b0[];
extern void FUN_002a130c(const char *, ...);
extern int FUN_002c7728(int, void *, int, int, int *);

int FUN_002a28d4(Svc **param_1)
{
  int sent;
  int r;
  Svc *s = *param_1;
  if (s->ready == 0) {
    FUN_002a130c(DAT_003a8440);
    return 0;
  }
  s->req_cmd = 0;
  s->req_flag = 0;
  s->req_arg = 0;
  r = FUN_002c7728(s->pipe, &s->req_cmd, 0x48, 0, &sent);
  if (r == -0x7ffdfe4d) {
    FUN_002a130c(DAT_003a84b0);
  } else if (r != 0 || sent != 0x48) {
    FUN_002a130c(DAT_003a8478, r, sent);
    return 0;
  }
  return 1;
}
