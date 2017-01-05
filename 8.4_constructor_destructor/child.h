//
// Created by Sandro on 05.01.2017.
//

#ifndef ADV_CPP_HS16_CHILD_H
#define ADV_CPP_HS16_CHILD_H

#include "parent.h"

class child : public parent
{
	public:
		child();
		virtual ~child() override;

		virtual void simulateCalculations() override;
};


#endif //ADV_CPP_HS16_CHILD_H
