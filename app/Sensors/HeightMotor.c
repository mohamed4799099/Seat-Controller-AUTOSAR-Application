

#include "Rte_HeightMotor.h"




void HeightMotor_Move (StepMotorStepType Step)
{

	if(Step == MOTOR_STEP_PLUS)
	{
		(void)Rte_Call_rpIOSetHeight_IOSetForward();
	}
	if(Step == MOTOR_STEP_MINUS)
	{
		(void)Rte_Call_rpIOSetHeight_IOSetReverse();
	}

}


