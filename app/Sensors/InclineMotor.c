

#include "Rte_InclineMotor.h"


/**
 *
 * Runnable InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Move
 *
 */

void InclineMotor_Move (StepMotorStepType Step)
{
    Std_ReturnType status;
	if(Step == MOTOR_STEP_PLUS)
	{
		status=Rte_Call_rpIOSetIncline_IOSetForward();
	}
	else if(Step == MOTOR_STEP_MINUS)
	{
		status=Rte_Call_rpIOSetIncline_IOSetReverse();
	}
	else
	{
		/* do nothing */
	}
}

