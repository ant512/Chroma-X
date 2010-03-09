#include "mathtools.h"

// Initialise sine table (stolen from PALib)
const Sint16 MathTools::_sineTable[512] = {
	0x0000,0x0003,0x0006,0x0009,0x000D,0x0010,0x0013,0x0016,	0x0019,0x001C,0x001F,0x0022,0x0026,0x0029,0x002C,0x002F,
	0x0032,0x0035,0x0038,0x003B,0x003E,0x0041,0x0044,0x0047,	0x004A,0x004D,0x0050,0x0053,0x0056,0x0059,0x005C,0x005F,
	0x0062,0x0065,0x0068,0x006B,0x006D,0x0070,0x0073,0x0076,	0x0079,0x007B,0x007E,0x0081,0x0084,0x0086,0x0089,0x008C,
	0x008E,0x0091,0x0093,0x0096,0x0098,0x009B,0x009D,0x00A0,	0x00A2,0x00A5,0x00A7,0x00AA,0x00AC,0x00AE,0x00B1,0x00B3,

	0x00B5,0x00B7,0x00B9,0x00BC,0x00BE,0x00C0,0x00C2,0x00C4,	0x00C6,0x00C8,0x00CA,0x00CC,0x00CE,0x00CF,0x00D1,0x00D3,
	0x00D5,0x00D7,0x00D8,0x00DA,0x00DC,0x00DD,0x00DF,0x00E0,	0x00E2,0x00E3,0x00E5,0x00E6,0x00E7,0x00E9,0x00EA,0x00EB,
	0x00ED,0x00EE,0x00EF,0x00F0,0x00F1,0x00F2,0x00F3,0x00F4,	0x00F5,0x00F6,0x00F7,0x00F8,0x00F8,0x00F9,0x00FA,0x00FA,
	0x00FB,0x00FC,0x00FC,0x00FD,0x00FD,0x00FE,0x00FE,0x00FE,	0x00FF,0x00FF,0x00FF,0x0100,0x0100,0x0100,0x0100,0x0100,

	0x0100,0x0100,0x0100,0x0100,0x0100,0x0100,0x00FF,0x00FF,	0x00FF,0x00FE,0x00FE,0x00FE,0x00FD,0x00FD,0x00FC,0x00FC,
	0x00FB,0x00FA,0x00FA,0x00F9,0x00F8,0x00F8,0x00F7,0x00F6,	0x00F5,0x00F4,0x00F3,0x00F2,0x00F1,0x00F0,0x00EF,0x00EE,
	0x00ED,0x00EB,0x00EA,0x00E9,0x00E7,0x00E6,0x00E5,0x00E3,	0x00E2,0x00E0,0x00DF,0x00DD,0x00DC,0x00DA,0x00D8,0x00D7,
	0x00D5,0x00D3,0x00D1,0x00CF,0x00CE,0x00CC,0x00CA,0x00C8,	0x00C6,0x00C4,0x00C2,0x00C0,0x00BE,0x00BC,0x00B9,0x00B7,

	0x00B5,0x00B3,0x00B1,0x00AE,0x00AC,0x00AA,0x00A7,0x00A5,	0x00A2,0x00A0,0x009D,0x009B,0x0098,0x0096,0x0093,0x0091,
	0x008E,0x008C,0x0089,0x0086,0x0084,0x0081,0x007E,0x007B,	0x0079,0x0076,0x0073,0x0070,0x006D,0x006B,0x0068,0x0065,
	0x0062,0x005F,0x005C,0x0059,0x0056,0x0053,0x0050,0x004D,	0x004A,0x0047,0x0044,0x0041,0x003E,0x003B,0x0038,0x0035,
	0x0032,0x002F,0x002C,0x0029,0x0026,0x0022,0x001F,0x001C,	0x0019,0x0016,0x0013,0x0010,0x000D,0x0009,0x0006,0x0003,

	0x0000,0xFFFD,0xFFFA,0xFFF7,0xFFF3,0xFFF0,0xFFED,0xFFEA,	0xFFE7,0xFFE4,0xFFE1,0xFFDE,0xFFDA,0xFFD7,0xFFD4,0xFFD1,
	0xFFCE,0xFFCB,0xFFC8,0xFFC5,0xFFC2,0xFFBF,0xFFBC,0xFFB9,	0xFFB6,0xFFB3,0xFFB0,0xFFAD,0xFFAA,0xFFA7,0xFFA4,0xFFA1,
	0xFF9E,0xFF9B,0xFF98,0xFF95,0xFF93,0xFF90,0xFF8D,0xFF8A,	0xFF87,0xFF85,0xFF82,0xFF7F,0xFF7C,0xFF7A,0xFF77,0xFF74,
	0xFF72,0xFF6F,0xFF6D,0xFF6A,0xFF68,0xFF65,0xFF63,0xFF60,	0xFF5E,0xFF5B,0xFF59,0xFF56,0xFF54,0xFF52,0xFF4F,0xFF4D,

	0xFF4B,0xFF49,0xFF47,0xFF44,0xFF42,0xFF40,0xFF3E,0xFF3C,	0xFF3A,0xFF38,0xFF36,0xFF34,0xFF32,0xFF31,0xFF2F,0xFF2D,
	0xFF2B,0xFF29,0xFF28,0xFF26,0xFF24,0xFF23,0xFF21,0xFF20,	0xFF1E,0xFF1D,0xFF1B,0xFF1A,0xFF19,0xFF17,0xFF16,0xFF15,
	0xFF13,0xFF12,0xFF11,0xFF10,0xFF0F,0xFF0E,0xFF0D,0xFF0C,	0xFF0B,0xFF0A,0xFF09,0xFF08,0xFF08,0xFF07,0xFF06,0xFF06,
	0xFF05,0xFF04,0xFF04,0xFF03,0xFF03,0xFF02,0xFF02,0xFF02,	0xFF01,0xFF01,0xFF01,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,

	0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF01,0xFF01,	0xFF01,0xFF02,0xFF02,0xFF02,0xFF03,0xFF03,0xFF04,0xFF04,
	0xFF05,0xFF06,0xFF06,0xFF07,0xFF08,0xFF08,0xFF09,0xFF0A,	0xFF0B,0xFF0C,0xFF0D,0xFF0E,0xFF0F,0xFF10,0xFF11,0xFF12,
	0xFF13,0xFF15,0xFF16,0xFF17,0xFF19,0xFF1A,0xFF1B,0xFF1D,	0xFF1E,0xFF20,0xFF21,0xFF23,0xFF24,0xFF26,0xFF28,0xFF29,
	0xFF2B,0xFF2D,0xFF2F,0xFF31,0xFF32,0xFF34,0xFF36,0xFF38,	0xFF3A,0xFF3C,0xFF3E,0xFF40,0xFF42,0xFF44,0xFF47,0xFF49,

	0xFF4B,0xFF4D,0xFF4F,0xFF52,0xFF54,0xFF56,0xFF59,0xFF5B,	0xFF5E,0xFF60,0xFF63,0xFF65,0xFF68,0xFF6A,0xFF6D,0xFF6F,
	0xFF72,0xFF74,0xFF77,0xFF7A,0xFF7C,0xFF7F,0xFF82,0xFF85,	0xFF87,0xFF8A,0xFF8D,0xFF90,0xFF93,0xFF95,0xFF98,0xFF9B,
	0xFF9E,0xFFA1,0xFFA4,0xFFA7,0xFFAA,0xFFAD,0xFFB0,0xFFB3,	0xFFB6,0xFFB9,0xFFBC,0xFFBF,0xFFC2,0xFFC5,0xFFC8,0xFFCB,
	0xFFCE,0xFFD1,0xFFD4,0xFFD7,0xFFDA,0xFFDE,0xFFE1,0xFFE4,	0xFFE7,0xFFEA,0xFFED,0xFFF0,0xFFF3,0xFFF7,0xFFFA,0xFFFD
};

Sint16 MathTools::sin(Sint16 angle) {
	return _sineTable[angle & 511];
}

Sint16 MathTools::cos(Sint16 angle) {
	return _sineTable[(angle + 128) & 511];
}

Sint16 MathTools::sinShifted(Sint16 angle) {
	return sin(angle) >> 8;
}

Sint16 MathTools::cosShifted(Sint16 angle) {
	return cos(angle) >> 8;
}
