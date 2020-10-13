

#include "Rte_WeightSensor.h"





void WeightSensor_GetWeight (SensorWeightType* Weight)
{
	IoWeightSensorReadingType weight;

	/* Server Call Points */
	(void)Rte_Call_rpIOGetWeight_IOGet(&weight);

	*Weight = (SensorWeightType)(weight/100);
}



