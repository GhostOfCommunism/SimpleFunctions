/*
 * SimpleFunctions.h
 *
 *  Created on: Mar 18, 2020
 *      Author: user
 */

#ifndef SIMPLEFUNCTIONS_H_
#define SIMPLEFUNCTIONS_H_

// Limited numbers processing:

/** @brief  Limited number creation.
  * @param  TYPE variable type.
  * @param  NAME name of variable.
  * @retval None
  */
#define LIM_NUM_CREATE(TYPE, NAME) \
			    struct\
			    { \
			      TYPE Val; \
			      TYPE Max; \
			      TYPE Min; \
			      TYPE Step; \
			    } NAME

/** @brief  Limited number initialization.
  * @param  NAME name of variable.
  * @param  VAL variable value
  * @param  MAX maximum variable value
  * @param  MIN minimum variable value
  * @param  STEP minimum allowed variable step
  * @retval None
  */
#define LIM_NUM_INIT(NAME, VAL, MAX, MIN, STEP) \
			    NAME.Val = VAL; \
			    NAME.Max = MAX; \
			    NAME.Min = MIN; \
			    NAME.Step = STEP

/** @brief  Limited number copy.
  * @param  NAME name of variable.
  * @param  VAL variable value
  * @param  MAX maximum variable value
  * @param  MIN minimum variable value
  * @param  STEP minimum allowed variable step
  * @retval None
  */
#define LIM_NUM_COPY(NAME1, NAME2) \
		     {NAME1.Val = NAME2.Val; \
		     NAME1.Max = NAME2.Max; \
		     NAME1.Min = NAME2.Min; \
		     NAME1.Step = NAME2.Step;}

/** @brief  Limited number creation.
  * @param  TYPE variable type.
  * @param  NAME name of variable.
  * @param  VAL variable value
  * @param  MAX maximum variable value
  * @param  MIN minimum variable value
  * @param  STEP minimum allowed variable step
  * @retval None
  */
#define LIM_NUM_CREATE_INIT(TYPE, NAME, VAL, MAX, MIN, STEP) \
			    LIM_NUM_CREATE(TYPE, NAME); \
			    NAME.Val = VAL; \
			    NAME.Max = MAX; \
			    NAME.Min = MIN; \
			    NAME.Step = STEP

/** @brief  Limited number loading with allowed step and limits control.
  * @param  NUM Variable.
  * @param  VAL new variable value.
  * @retval None
  */
#define LIM_NUM_PUT(NUM, VAL) \
  if((VAL <= NUM.Max)&&(VAL >= NUM.Min)) \
     NUM.Val = (VAL % NUM.Step) ? VAL / NUM.Step : VAL

/** @brief  Limited number increment with allowed limits control.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_INC(NUM) \
  if(NUM.Val <= NUM.Max - NUM.Step) \
     NUM.Val += NUM.Step

/** @brief  Limited number decrement with allowed limits control.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_DEC(NUM) \
  if(NUM.Val >= NUM.Min + NUM.Step) \
     NUM.Val -= NUM.Step

/** @brief  Limited number increment with allowed limits control and limits reaching guaranteed.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_INC_LIM(NUM) \
  if(NUM.Val <= NUM.Max - NUM.Step) \
   NUM.Val += NUM.Step; \
  else \
   NUM.Val = NUM.Max

/** @brief  Limited number decrement with allowed limits control and limits reaching guaranteed.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_DEC_LIM(NUM) \
  if(NUM.Val >= NUM.Min + NUM.Step) \
   NUM.Val -= NUM.Step; \
  else \
   NUM.Val = NUM.Min

/** @brief  Limited number increment with allowed limits control. Overflow allowed.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_INC_OVER(NUM) \
  if(NUM.Val <= NUM.Max - NUM.Step) \
     NUM.Val += NUM.Step; \
  else NUM.Val = NUM.Min

/** @brief  Limited number decrement with allowed limits control. Overflow allowed.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_DEC_OVER(NUM) \
  if(NUM.Val >= NUM.Min + NUM.Step) \
     NUM.Val -= NUM.Step; \
  else NUM.Val = NUM.Max

unsigned char ByteFlip(unsigned char);

#endif /* SIMPLEFUNCTIONS_H_ */
