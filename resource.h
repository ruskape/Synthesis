#define PLUG_MFR "MartinFinke"
#define PLUG_NAME "Synthesis"

#define PLUG_CLASS_NAME Synthesis

#define BUNDLE_MFR "MartinFinke"
#define BUNDLE_NAME "Synthesis"

#define PLUG_ENTRY Synthesis_Entry
#define PLUG_VIEW_ENTRY Synthesis_ViewEntry

#define PLUG_ENTRY_STR "Synthesis_Entry"
#define PLUG_VIEW_ENTRY_STR "Synthesis_ViewEntry"

#define VIEW_CLASS Synthesis_View
#define VIEW_CLASS_STR "Synthesis_View"

#define PLUG_VER 0x00010000
#define VST3_VER_STR "1.0.0"


#define PLUG_UNIQUE_ID 'Ipef'
#define PLUG_MFR_ID 'Acme'


#if (defined(AAX_API) || defined(RTAS_API)) && !defined(_PIDS_)
#define _PIDS_
const int PLUG_TYPE_IDS[2] = { 'EFN1', 'EFN2' };
const int PLUG_TYPE_IDS_AS[2] = { 'EFA1', 'EFA2' }; // AudioSuite
#endif

#define PLUG_MFR_PT "MartinFinke\nMartinFinke\nAcme"
#define PLUG_NAME_PT "Synthesis\nIPEF"
#define PLUG_TYPE_PT "Effect"
#define PLUG_DOES_AUDIOSUITE 1

													

#if (defined(AAX_API) || defined(RTAS_API))
#define PLUG_CHANNEL_IO "1-1 2-2"
#else
#define PLUG_CHANNEL_IO "0-1 0-2"
#endif

#define PLUG_LATENCY 0
#define PLUG_IS_INST 1

#define PLUG_DOES_MIDI 1

#define PLUG_DOES_STATE_CHUNKS 0

#define BG_ID         101
#define WHITE_KEY_ID  102
#define BLACK_KEY_ID  103
#define WAVEFORM_ID   104
#define KNOB_ID       105
#define KNOB_SMALL_ID 106
#define FILTERMODE_ID 107

#define BG_FN         "resources/img/bg.png"
#define WHITE_KEY_FN  "resources/img/whitekey.png"
#define BLACK_KEY_FN  "resources/img/blackkey.png"
#define WAVEFORM_FN   "resources/img/waveform.png"
#define KNOB_FN       "resources/img/knob.png"
#define KNOB_SMALL_FN "resources/img/knob_small.png"
#define FILTERMODE_FN "resources/img/filtermode.png"

#define GUI_WIDTH 434
#define GUI_HEIGHT 296

#if defined(SA_API) && !defined(OS_IOS)
#include "app_wrapper/app_resource.h"
#endif


#define EFFECT_TYPE_VST3 "Instrument|Synth"

												