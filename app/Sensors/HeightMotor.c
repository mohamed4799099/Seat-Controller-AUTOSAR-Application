

#include "Rte_HeightMotor.h"




void HeightMotor_Move (StepMotorStepType Step)
{
    Std_ReturnType status;
	if(Step == MOTOR_STEP_PLUS)
	{
		status=Rte_Call_rpIOSetHeight_IOSetForward();
	}
	else if(Step == MOTOR_STEP_MINUS)
	{
		status=Rte_Call_rpIOSetHeight_IOSetReverse();
	}
	else
	{
		/* do nothing */
	}
}


