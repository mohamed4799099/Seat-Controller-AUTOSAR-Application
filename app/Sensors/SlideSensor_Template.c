

#include "Rte_SlideSensor.h"




void SlideMotor_Move (StepMotorStepType Step)
{
	if(Step == MOTOR_STEP_PLUS)
	{
		(void)Rte_Call_rpIOSetSlide_IOSetForward();
	}
	else if(Step == MOTOR_STEP_MINUS)
	{
		(void)Rte_Call_rpIOSetSlide_IOSetReverse();
	}
	else
	{
		/* do nothing */
	}
}

