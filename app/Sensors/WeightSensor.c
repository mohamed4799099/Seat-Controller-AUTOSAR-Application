

#include "Rte_WeightSensor.h"





void WeightSensor_GetWeight (SensorWeightType* Weight)
{
	IoWeightSensorReadingType weight;
Std_ReturnType status;
	/* Server Call Points */
	status=Rte_Call_rpIOGetWeight_IOGet(&weight);

	*Weight = (SensorWeightType)(weight/100);
}



