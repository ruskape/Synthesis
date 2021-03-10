#ifndef __SYNTHESIS__
#define __SYNTHESIS__

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextra-tokens"
#include "IPlug_include_in_plug_hdr.h"
#pragma clang diagnostic pop

#include "Oscillator.h"
#include "MIDIReceiver.h"
#include "EnvelopeGenerator.h"
#include "Filter.h"

class Synthesis : public IPlug
{
public:
	Synthesis(IPlugInstanceInfo instanceInfo);
	~Synthesis();

	void Reset();//вызываетс€, когда измен€етс€ частота дискретизации
	void OnParamChange(int paramIdx);//вызываетс€ при изменении параметров
	void ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames);//обработка вход€щего аудио
	// to receive MIDI messages:
	void ProcessMidiMsg(IMidiMsg* pMsg);

	// Needed for the GUI keyboard:
	// Should return non-zero if one or more keys are playing.
	inline int GetNumKeys() const { return mMIDIReceiver.getNumKeys(); };
	// Should return true if the specified key is playing.
	inline bool GetKeyStatus(int key) const { return mMIDIReceiver.getKeyStatus(key); };
	static const int virtualKeyboardMinimumNoteNumber = 48;
	int lastVirtualKeyboardNoteNumber;

	inline void onBeganEnvelopeCycle() { mOscillator.setMuted(false); }
	inline void onFinishedEnvelopeCycle() { mOscillator.setMuted(true); }

private://текущие значени€
	double mFrequency;
	void CreatePresets();
	Oscillator mOscillator;
	MIDIReceiver mMIDIReceiver;
	IControl* mVirtualKeyboard;
	void processVirtualKeyboard();
	EnvelopeGenerator mEnvelopeGenerator;

	inline void onNoteOn(const int noteNumber, const int velocity) {
		mEnvelopeGenerator.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_ATTACK);
		mFilterEnvelopeGenerator.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_ATTACK);
	};
	inline void onNoteOff(const int noteNumber, const int velocity) {
		mEnvelopeGenerator.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_RELEASE);
		mFilterEnvelopeGenerator.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_RELEASE);
	};

	Filter mFilter;
	EnvelopeGenerator mFilterEnvelopeGenerator;
	double filterEnvelopeAmount;
};

#endif
