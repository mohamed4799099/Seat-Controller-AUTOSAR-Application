

#include "Rte_SlideSensor.h"




void SlideSensor_GetPosition (SensorPositionType* position)
{

	IoPositionSensorReadingType position;

	/* Server Call Points */
	(void) Rte_Call_rpIOGetSlide_IOGet(&position);

	if(position == 0){
		*position = SENSOR_POSITION_STEP_1;
	}
	else if(position > 0 && position <= 64){
		*position = SENSOR_POSITION_STEP_1;
	}
	else if(position > 64 && position <= 192){
		*position = SENSOR_POSITION_STEP_2;
	}
	else{
		*position = SENSOR_POSITION_STEP_3;
}

}
