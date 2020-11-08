

#include "Rte_SlideSensor.h"




void SlideSensor_GetPosition (SensorPositionType* position)
{
	Std_ReturnType status;
	IoPositionSensorReadingType position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetSlide_IOGet(&position);

	if(position == 0)
		*position = SENSOR_POSITION_STEP_1;
	if(position > 0 && position <= 64)
		*position = SENSOR_POSITION_STEP_1;
	if(position > 64 && position <= 192)
		*position = SENSOR_POSITION_STEP_2;
	if(position > 192 && position <= 255)
		*position = SENSOR_POSITION_STEP_3;
}
