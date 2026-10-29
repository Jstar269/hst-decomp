/* HSTMATCH module=EBOOT.BIN start=0x00153aac end=0x00153b98 symbol=FUN_00153aac lang=c99 data=0x002dc7e8 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc7e8-0x002dc802) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py candidate FUN_00153aac) corrected by hand: pointer-typed parameters and byte globals, ternary for the message pick; readability pass; exact match verified; names and types await human review. */
extern unsigned char DAT_003402f0; /* script trace flag */
extern unsigned char DAT_00341d80;
extern char DAT_002dc7c8[];
extern char DAT_002dc430[];
extern char DAT_002dc440[];
extern int DAT_0034a114;
extern void FUN_000143b0(char *, char *, int);
extern void FUN_0014d044(void *);
extern void FUN_0014fd94(char *, int, char *);
extern void FUN_001cc784(int, char *);
extern void FUN_001cc99c(int, int, int, int, int);

#define MATCH_OPTION_PAIR 2 /* option value that selects the paired match */

/* Actor the command flags; only one byte is written. */
typedef struct MatchActor {
  char pad00[0x59];
  unsigned char unk59;   /* 0x59 */
} MatchActor;

/* Running context: the actor is at 0x0c and a done flag at 0x10. */
typedef struct MatchCtx {
  char pad00[0xc];
  MatchActor *actor;     /* 0x0c */
  unsigned char done;    /* 0x10 */
} MatchCtx;

/* Command record of "EventMatch": stage id, option and region flag. */
typedef struct MatchCmd {
  char pad00[8];
  int stage;             /* 0x08 */
  int option;            /* 0x0c */
  int region;            /* 0x10 */
  int unk14;             /* 0x14 */
} MatchCmd;

/* Script command "EventMatch": announce the stage and start the match with the given options. */
int FUN_00153aac(MatchCmd *cmd, MatchCtx *ctx)
{
  char name[32];
  int region;

  FUN_000143b0(name, DAT_002dc7c8, cmd->stage);
  FUN_001cc784(DAT_0034a114, name);
  DAT_00341d80 = cmd->option == 1;
  region = cmd->region == 1;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    FUN_0014fd94("EventMatch(Opt:%d Reg:%s\n", cmd->option, region ? DAT_002dc430 : DAT_002dc440);
  }
  FUN_001cc99c(DAT_0034a114, cmd->option == MATCH_OPTION_PAIR, 1, cmd->unk14, region);
  ctx->actor->unk59 = 1;
  ctx->done = 1;
  return 0;
}
