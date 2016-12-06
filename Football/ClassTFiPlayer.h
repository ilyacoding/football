//---------------------------------------------------------------------------

#ifndef ClassTFiPlayerH
#define ClassTFiPlayerH
#include <FMX.Objects.hpp>
class TFiPlayer {
	public:
		int Speed;
		float mouseX, mouseY;
		bool InGame;
		TImage* Img;
		TText* Txt;
};
//---------------------------------------------------------------------------
#endif
