#include "StdAfx.h"
#include "InputDataValue.h"

void InputDataValue::setInputData(int value)
{
	InputData=value;

}
int InputDataValue::getInputData()
{


	return	InputData;


}


CPoint InputDataValue::getpoint()
{

	return point;

}

void InputDataValue::setpoint(CPoint _point)
{
	point=_point;
	

}