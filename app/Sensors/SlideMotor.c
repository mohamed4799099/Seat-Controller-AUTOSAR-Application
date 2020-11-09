

#include "Rte_SlideMotor.h"




void SlideMotor_Move (StepMotorStepType Step)
{

	if(Step == MOTOR_STEP_PLUS)
	{
		(void)Rte_Call_rpIOSetSlide_IOSetForward();
	}
	if(Step == MOTOR_STEP_MINUS)
	{
		(void)Rte_Call_rpIOSetSlide_IOSetReverse();
	}

}

