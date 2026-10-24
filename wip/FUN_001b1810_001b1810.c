/* HSTMATCH module=EBOOT.BIN start=0x001b1810 end=0x001b1b20 symbol=FUN_001b1810 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned char bool;

extern char s_SOUND_volume_setting_002e980c[];
extern char s_warning__SOUND_volume_setting_fi_002e9888[];
extern char s_data_sound_resvol_csv_002e9824[];
extern char s_data_sound_movievol_csv_002e98bc[];
extern char s_filename_002e9840[];
extern char s_volume_002e984c[];
extern char s___28s_____3f_002e9854[];
extern char s___28s___error__unknown_filename_002e9864[];
extern char s_warning__movie_vol_buffer_over___002e98d4[];
extern char DAT_002e983c[];
extern char DAT_002e9900[];
extern char DAT_003070bc[];
extern char *PTR_s_BGM_bgm_title_sgh_002c5a34[];
extern float DAT_002e515c[];
extern float DAT_002e58c4[];

extern void FUN_001b1b20();
extern int FUN_000649c0();
extern int FUN_00064a08();
extern int FUN_000650e0();
extern int FUN_000651b8();
extern int FUN_000652e8();
extern void FUN_00066338();
extern int FUN_0006569c();
extern float FUN_000655f8();
extern int FUN_00014934();
extern int FUN_0008c230();

void FUN_001b1810(void)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  float *pfVar5;
  char **ppcVar7;
  uint uVar6;
  int iVar8;
  float fVol;
  undefined1 auStack_10[16];
  undefined1 auStack_20[16];
  undefined4 local_30[4];

  FUN_001b1b20(s_SOUND_volume_setting_002e980c);
  pfVar5 = DAT_002e515c;
  uVar6 = 0;
  do {
    uVar6 = uVar6 + 1;
    *pfVar5 = 1.0f;
    pfVar5 = pfVar5 + 1;
  } while (uVar6 < 0x1da);
  FUN_000649c0(local_30);
  local_30[0] = (undefined4)&DAT_003070bc;
  FUN_0008c230(auStack_20);
  FUN_0008c230(auStack_10);
  iVar2 = FUN_000651b8(local_30, s_data_sound_resvol_csv_002e9824, 0, 1, DAT_002e983c);
  if (iVar2 != 0) {
    iVar8 = 1;
    iVar2 = FUN_000650e0(local_30);
    if (1 < iVar2) {
      do {
        bVar1 = 0;
        iVar2 = FUN_0006569c(local_30, iVar8, s_filename_002e9840);
        if (iVar2 != 0) {
          uVar6 = 0;
          ppcVar7 = PTR_s_BGM_bgm_title_sgh_002c5a34;
          pfVar5 = DAT_002e515c;
          do {
            if ((iVar2 != 0) && (iVar3 = FUN_00014934(iVar2, *ppcVar7), iVar3 == 0)) {
              fVol = FUN_000655f8(local_30, iVar8, s_volume_002e984c);
              *pfVar5 = fVol;
              FUN_001b1b20(s___28s_____3f_002e9854, iVar2, fVol);
              bVar1 = 1;
            }
            uVar6 = uVar6 + 1;
            ppcVar7 = ppcVar7 + 1;
            pfVar5 = pfVar5 + 1;
          } while (uVar6 < 0x1da);
        }
        if (!bVar1) {
          FUN_001b1b20(s___28s___error__unknown_filename_002e9864, iVar2);
        }
        iVar8 = iVar8 + 1;
        iVar2 = FUN_000650e0(local_30);
      } while (iVar8 < iVar2);
    }
  }
  else {
    FUN_001b1b20(s_warning__SOUND_volume_setting_fi_002e9888);
  }
  uVar6 = 0;
  pfVar5 = DAT_002e58c4;
  do {
    uVar6 = uVar6 + 1;
    *pfVar5 = 1.0f;
    pfVar5 = pfVar5 + 1;
  } while (uVar6 < 4);
  FUN_000652e8(local_30);
  iVar2 = FUN_000651b8(local_30, s_data_sound_movievol_csv_002e98bc, 0, 1, DAT_002e983c);
  if (iVar2 != 0) {
    iVar8 = 1;
    iVar2 = FUN_000650e0(local_30);
    if (1 < iVar2) {
      do {
        pcVar4 = (char *)FUN_0006569c(local_30, iVar8, s_filename_002e9840);
        if (3 < iVar8 - 1U) {
          if (pcVar4 == (char *)0x0) {
            pcVar4 = DAT_002e9900;
          }
          FUN_001b1b20(s_warning__movie_vol_buffer_over___002e98d4, pcVar4, 4);
          break;
        }
        fVol = FUN_000655f8(local_30, iVar8, s_volume_002e984c);
        (&DAT_002e58c4[0])[iVar8 - 1U] = fVol;
        FUN_001b1b20(s___28s_____3f_002e9854, pcVar4, fVol);
        iVar8 = iVar8 + 1;
        iVar2 = FUN_000650e0(local_30);
      } while (iVar8 < iVar2);
    }
  }
  *(undefined4 *)(void *)local_30 = (undefined4)&DAT_003070bc;
  FUN_00066338(auStack_10, 0);
  FUN_00066338(auStack_20, 0);
  FUN_00064a08(local_30, 0);
  return;
}

// NEAR MISS 0x001b1810: 194/196 words, 114 words differ, first diff at +0x8:
// we save one extra GPR (s6). Everything else about the shape is right -
// frame 0x50, handle at sp+0x20, the two 16-byte objects at sp+0x30/sp+0x40
// (so they must be declared BEFORE the handle: mwcc lays locals out in reverse
// declaration order), the 474-entry 1.0f fill loop, both CSV passes, the
// variadic float argument going through __extendsfdf2 (0x20f5c), and the tail
// FUN_00066338/FUN_00064a08 pair.
// Open issue: mwcc hoists the `&DAT_003070bc` constant used by both
// `local_30[0] = &DAT_003070bc` statements into s6 and keeps it across the
// calls; retail re-materializes `lui v0,0x30; addiu v0,v0,28860` inline at
// each of the two sites. Ruled out: writing the address as
// `*(undefined4 *)(void *)local_30 = ...` (sinks the store into the first
// delay slot, 125 differ) and as `&DAT_003070bc[0]` / `(undefined4)DAT_003070bc`
// (identical tree, still CSE'd). Next idea: give the second store its own
// symbol line for 0x003070bc (two distinct extern declarations at one address
// are what the retail source most likely had), which stops the CSE.
// Also still swapped: our 1.0f fill loop keeps the counter in a0 and the
// pointer in a1; retail has the counter in a1 and the pointer in a0.
// Second pass: the two-symbol idea was tried (a `DAT_003070bc_end` extern at
// the same 0x003070bc, via a temporary symbol line) - the constant is still
// CSE'd, 182 words differ, so that is NOT the fix; reverted.
// near miss from lane fm10 (unreviewed)
