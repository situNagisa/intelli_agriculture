#include "ia/ia.h"


void ia_main()
{
	ia::hw::sensors::temperature* temp = ia::factory::create_temperature();


	NGS_LOGFL(info, "temperature: %f", temp->get());

}