# samsons-layout-with-navigator — ZSA Voyager (Colemak)

Source of truth: the Oryx layout
<https://configure.zsa.io/voyager/layouts/GeMxQ/wO3ZLd/0> — edit there,
re-export ("Download source"), and refresh this folder. Exported 2026-08-17
(compiled by Oryx 2025-12-16, firmware v24).

## Files

| File | What |
| --- | --- |
| `keymap.c` `config.h` `rules.mk` `i18n.h` `keymap.json` | Oryx-generated QMK source |
| `firmware/zsa_voyager_GeMxQ.bin` (+`.md5`) | the flashed firmware, as built by Oryx |
| `firmware/zsa_voyager_samsons-layout_*.bin` | previous layout revisions (Sep 2024, pre-navigator) |
| `oryx-manual.pdf` | Oryx configurator manual |

## Building

⚠️ This fork's base (Oct 2022 mainline) predates the Voyager — the keymap does
**not** compile from this tree. The Voyager lives in **ZSA's QMK fork**:

```bash
git clone -b firmware24 https://github.com/zsa/qmk_firmware zsa-qmk
cp -r $(dirname $0) zsa-qmk/keyboards/zsa/voyager/keymaps/samsons_layout_with_navigator
cd zsa-qmk && qmk compile -kb zsa/voyager -km samsons_layout_with_navigator
```

Flashing without building: use Keymapp (or `qmk flash`) with
`firmware/zsa_voyager_GeMxQ.bin`.
