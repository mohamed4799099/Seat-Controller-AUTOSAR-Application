

#include "Rte_SlideSensor.h"




void SlideMotor_Move (StepMotorStepType Step)
{
    Std_ReturnType status;
	if(Step == MOTOR_STEP_PLUS)
	{
		status=Rte_Call_rpIOSetSlide_IOSetForward();
	}
	else if(Step == MOTOR_STEP_MINUS)
	{
		status=Rte_Call_rpIOSetSlide_IOSetReverse();
	}
	else
	{
		/* do nothing */
	}
}

