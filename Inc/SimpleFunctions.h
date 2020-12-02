/*
 * SimpleFunctions.h
 *
 *  Created on: Dec 03, 2020
 *      Author: GhostOfCommunism
 */

#ifndef SIMPLEFUNCTIONS_H_
#define SIMPLEFUNCTIONS_H_

// Limited numbers processing:

/** @brief  Limited number definition.
  * @param  TYPE variable type.
  * @param  NAME name of variable.
  * @retval None
  */
#define LIM_NUM_DEF(TYPE, NAME) \
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
				do \
				{ \
					(NAME).Val = (VAL); \
					(NAME).Max = (MAX); \
					(NAME).Min = (MIN); \
					(NAME).Step = (STEP); \
				}while(0)

/** @brief  Limited number copy.
  * @param  NAME name of variable.
  * @param  VAL variable value
  * @param  MAX maximum variable value
  * @param  MIN minimum variable value
  * @param  STEP minimum allowed variable step
  * @retval None
  */
#define LIM_NUM_COPY(NAME1, NAME2) \
				do \
				{ \
					(NAME1).Val = (NAME2).Val; \
					(NAME1).Max = (NAME2).Max; \
					(NAME1).Min = (NAME2).Min; \
					(NAME1).Step = (NAME2).Step; \
				}while(0)

/** @brief  Limited number definition and initialization.
  * @param  TYPE variable type.
  * @param  NAME name of variable.
  * @param  VAL variable value
  * @param  MAX maximum variable value
  * @param  MIN minimum variable value
  * @param  STEP minimum allowed variable step
  * @retval None
  */
#define LIM_NUM_DEF_INIT(TYPE, NAME, VAL, MAX, MIN, STEP) \
				do \
				{ \
			    LIM_NUM_CREATE(TYPE, NAME); \
			    (NAME).Val = (VAL); \
			    (NAME).Max = (MAX); \
			    (NAME).Min = (MIN); \
			    (NAME).Step = (STEP); \
				}while(0)

/** @brief  Limited number loading with allowed step and limits control.
  * @param  NUM Variable.
  * @param  VAL new variable value.
  * @retval None
  */
#define LIM_NUM_PUT(NUM, VAL) \
				do \
				{	\
					if((VAL <= (NUM).Max)&&(VAL >= (NUM).Min)) \
						 (NUM).Val = (VAL % (NUM).Step) ? VAL / (NUM).Step : VAL; \
				}while(0)

/** @brief  Limited number increment with allowed limits control.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_INC(NUM) \
				do \
				{	\
					if((NUM).Val <= (NUM).Max - (NUM).Step) \
					 (NUM).Val += (NUM).Step; \
				}while(0)

/** @brief  Limited number decrement with allowed limits control.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_DEC(NUM) \
				do \
				{	\
					if((NUM).Val >= (NUM).Min + (NUM).Step) \
						 (NUM).Val -= (NUM).Step; \
				}while(0)

/** @brief  Limited number increment with allowed limits control and limits reaching guaranteed.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_INC_LIM(NUM) \
				do \
				{	\
					if((NUM).Val <= (NUM).Max - (NUM).Step) \
					 (NUM).Val += (NUM).Step; \
					else \
					 (NUM).Val = (NUM).Max; \
				}while(0)

/** @brief  Limited number decrement with allowed limits control and limits reaching guaranteed.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_DEC_LIM(NUM) \
				do \
				{	\
					if((NUM).Val >= (NUM).Min + (NUM).Step) \
					 (NUM).Val -= (NUM).Step; \
					else \
					 (NUM).Val = (NUM).Min; \
				}while(0)

/** @brief  Limited number increment with allowed limits control. Overflow allowed.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_INC_OVER(NUM) \
				do \
				{	\
					if((NUM).Val <= (NUM).Max - (NUM).Step) \
						 (NUM).Val += (NUM).Step; \
					else (NUM).Val = (NUM).Min; \
				}while(0)

/** @brief  Limited number decrement with allowed limits control. Overflow allowed.
  * @param  NUM Variable.
  * @retval None
  */
#define LIM_NUM_DEC_OVER(NUM) \
				do \
				{	\
					if((NUM).Val >= (NUM).Min + (NUM).Step) \
						 (NUM).Val -= (NUM).Step; \
					else (NUM).Val = (NUM).Max; \
				}while(0)

unsigned char ByteFlip(unsigned char);

#endif /* SIMPLEFUNCTIONS_H_ */
