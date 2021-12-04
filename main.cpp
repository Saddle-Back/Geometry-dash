#define CAC_PROJ_NAME "no-wave-pulse"
#include <Cacao>

class $redirect(PlayerObject) {
public:
		void update(float a) {
			$PlayerObject::update(a);

			$PlayerObject::_waveStreak()->m_pulseSize = 1.0;
			
		}
} hook1;

$apply();