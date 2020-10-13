

#include "Rte_SeatManager.h"

static boolean IsMotorAdjustNeeded(SensorPositionType Position, SensorWeightType Weight, StepMotorStepType* Step)
{
	boolean adjustMotor = FALSE;

	switch(Position)
	{
		case SENSOR_POSITION_STEP_0:
			if(Weight > 60)
			{
				*Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			break;

		case SENSOR_POSITION_STEP_1:
			if(Weight > 80)
			{
				*Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			else if(Weight <= 80 && Weight >= 60)
			{
				/* Position OK */
			}
			else
			{
				*Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;

		case SENSOR_POSITION_STEP_2:
			if(Weight > 100)
			{
				*Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			else if(Weight <= 100 && Weight >= 80)
			{
				/* Position OK */
			}
			else
			{
				*Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;

		case SENSOR_POSITION_STEP_3:
			if(Weight < 100)
			{
				*Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;

		default:
			break;
	}

	return adjustMotor;
}



void SeatManager_SetHeight (void)
{
	MultiStateBtnType HeightBtnState;

	(void)Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);

	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
	{
		(void)Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		(void)Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	}
}



void SeatManager_SetIncline (void)
{
	MultiStateBtnType InclineBtnState;

	(void)Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);

	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
	{
		(void)Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
	{
		(void)Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
	}
}




void SeatManager_SetSlide (void)
{
	MultiStateBtnType SlideBtnState;

	(void)Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);

	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
	{
		(void)Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
	{
		(void)Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
	}
}



void SeatManager_AutoHeight (void)
{
	StepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean adjustMotor;

	(void)Rte_Call_rpHeightSensor_GetPosition(&Position);
	(void)Rte_Call_rpWeightSensor_GetWeight(&Weight);

	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	if(adjustMotor)
	{
		(void)Rte_Call_rpHeightMotor_Move(Step);
	}
}


void SeatManager_AutoSlide (void)
{
	StepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean adjustMotor;

	(void)Rte_Call_rpSlideSensor_GetPosition(&Position);
	(void)Rte_Call_rpWeightSensor_GetWeight(&Weight);

	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	if(adjustMotor)
	{
		(void)Rte_Call_rpSlideMotor_Move(Step);
	}
}




void SeatManager_AutoIncline (void)
{
	StepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean adjustMotor;

	(void)Rte_Call_rpInclineSensor_GetPosition(&Position);
	(void)Rte_Call_rpWeightSensor_GetWeight(&Weight);

	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	if(adjustMotor)
	{
		(void)Rte_Call_rpInclineMotor_Move(Step);
	}
}
