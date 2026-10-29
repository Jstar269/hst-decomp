/* HSTMATCH module=EBOOT.BIN start=0x002905bc end=0x002908cc symbol=FUN_002905bc lang=c++ helpers=FUN_0028fb44@0x0028fb44-0x0028fb70 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/psmf_player.h"

extern "C" {
extern unsigned char DAT_0034a80c;
extern char DAT_002ff5c0;
extern char DAT_002ff5cc;
extern char DAT_002cabbc[];
extern char DAT_002ff408[];
extern char DAT_002ff534[];
extern char DAT_002ff5d8[];
extern char DAT_002ff5f4[];
extern char DAT_002ff620[];
extern char DAT_002ff644[];
extern char DAT_002ff65c[];
extern char DAT_002ff678[];
extern char DAT_002ff690[];
extern char DAT_002ff6b8[];
extern void FUN_000149a8(void *, const char *);
static void FUN_0028fb44(...) { }
extern void FUN_00291868(ServiceSock *);
extern unsigned char FUN_002919e4(ServiceSock *, const char *, void *, void *, int, int, int);
extern void FUN_002b7958(int);
extern int FUN_002b7990(void);
extern int FUN_002b79a8(int);
extern int FUN_002b7eb0(PsmfPlayer *, const char *);
extern int FUN_002b7eb8(PsmfPlayer *, int *, int);
extern int FUN_002b7ed8(PsmfPlayer *);
extern int FUN_002b7ee0(PsmfPlayer *);
}

/* Movie play: sets the file, waits for the player status, creates the display and audio worker threads and starts playback. */
extern "C" int FUN_002905bc(PsmfPlayer *o, const char *file_name, int arg, int start_pts)
{
  int r;
  if (o->ready == 0) {
    FUN_0028fb44(DAT_002ff534, file_name);
    return 0;
  }
  FUN_000149a8(o->unkec, file_name);
  o->unk30 = arg;
  for (;;) {
    if (!(DAT_0034a80c == 0 && (r = FUN_002b7ee0(o)) >= 0 && r != 1)) {
      break;
    }
    FUN_002b7958(PSMF_POLL_DELAY);
  }
  if (DAT_0034a80c != 0) {
    FUN_0028fb44(DAT_002ff5d8);
  } else {
    r = FUN_002b7eb0(o, file_name);
    if (r != 0) {
      FUN_0028fb44(DAT_002ff5f4, r);
    } else {
      for (;;) {
        if (!(DAT_0034a80c == 0 && (r = FUN_002b7ee0(o)) != PSMF_STATUS_STANDBY && r != PSMF_STATUS_PLAYING && r != PSMF_STATUS_FINISHED && r >= 0)) {
          break;
        }
        FUN_0028fb44(DAT_002ff620);
        FUN_002b7958(PSMF_POLL_DELAY);
      }
      if (DAT_0034a80c != 0) {
        FUN_0028fb44(DAT_002ff5d8);
      } else {
        int k = FUN_002b7990();
        if (FUN_002919e4(&o->b, DAT_002ff644, o, &DAT_002ff5c0, k + 1, 0x1000, 0x4000) == 0) {
          FUN_0028fb44(DAT_002ff65c);
        } else {
          if (FUN_002919e4(&o->c, DAT_002ff678, o, &DAT_002ff5cc, 16, 0x1000, 0) == 0) {
            FUN_0028fb44(DAT_002ff65c);
          } else {
            o->video_codec = 0;
            o->video_stream_num = 0;
            o->audio_codec = 1;
            o->audio_stream_num = 0;
            o->play_mode = 0;
            o->play_speed = 1;
            r = FUN_002b7eb8(o, &o->video_codec, start_pts);
            if (r != 0) {
              FUN_0028fb44(DAT_002ff690, r);
            } else {
              FUN_00291868(&o->b);
              FUN_00291868(&o->c);
              o->started = 1;
              FUN_0028fb44(DAT_002ff6b8, file_name);
              return 1;
            }
            if (o->c.handle >= 0) {
              r = FUN_002b79a8(o->c.handle);
              if (r != 0) {
                FUN_0028fb44(DAT_002cabbc, r);
              }
              o->c.handle = -1;
            }
          }
          if (o->b.handle >= 0) {
            r = FUN_002b79a8(o->b.handle);
            if (r != 0) {
              FUN_0028fb44(DAT_002cabbc, r);
            }
            o->b.handle = -1;
          }
        }
      }
      r = FUN_002b7ed8(o);
      if (r != 0) {
        FUN_0028fb44(DAT_002ff408, r);
      }
    }
  }
  return 0;
}

// second pass (sn6): 4 words left (was 8). The prologue copy-order group is FIXED: Ghidra's `FUN_0028fb44(DAT_002ff534)` in the early-failure arm passes the INCOMING a1 (file_name) unchanged, i.e. it is
//  `FUN_0028fb44(DAT_002ff534, file_name)`; using a1 directly before its copy moves `move s1,a1` to the end (the bnez delay slot). Remaining: success arm `lui a0; li v0,1; move a1,s1; addiu a0; jal; sb v0,41(s2)` (sb in the jal slot)
//  vs ours `li v0,1; lui a0; move a1,s1; sb; jal; addiu a0`. Tried again on top of the fix: comma expressions in either argument, `int t = file_name; o->started = 1; return F(fmt, t)`, a `char *fmt` local.
// improved by lane sn6 (unreviewed): 8 -> 4 differing words
