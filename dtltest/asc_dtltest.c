#include <stdio.h>

#include <ascend/general/platform.h>
#include <ascend/utilities/error.h>

#include <ascend/compiler/extfunc.h>
 
ExtBBoxInitFunc dtltest_compprop_prepare;
ExtBBoxFunc dtltest_compprop_calc;


#ifndef ASC_EXPORT
# error "Where is ASC_EXPORT?"
#endif

extern
ASC_EXPORT int dtltest_register(){
	const char *dtltest_compprop_help = "This is a test of the dynamic user packages functionality";
	int result = 0;

	ERROR_REPORTER_HERE(ASC_PROG_NOTE,"Initialising DTLTEST...\n");

	(void)CONSOLE_DEBUG("EVALUATION FUNCTION AT %p",dtltest_compprop_calc);

	result += CreateUserFunctionBlackBox("add_one"
		, dtltest_compprop_prepare
		, dtltest_compprop_calc /* value */
		, (ExtBBoxFunc*)NULL /* deriv */
		, (ExtBBoxFunc*)NULL /* deriv2 */
		, (ExtBBoxFinalFunc*)NULL /* final */
		, 1,1 /* inputs, outputs */
		, dtltest_compprop_help
		, 0.0
	); /* returns 0 on success */

	if(result){
		ERROR_REPORTER_HERE(ASC_PROG_NOTE,"CreateUserFunction result = %d\n",result);
	}
	return result;
}

int dtltest_compprop_prepare(struct BBoxInterp *slv_interp,
	   struct Instance *data,
	   struct gl_list_t *arglist
){
	const char *mystring = "MY STRING IS HERE";

	ERROR_REPORTER_HERE(ASC_PROG_NOTE,"PREPARING PKG EXTFNTEST...\n");
	slv_interp->user_data = (void *)mystring;

	return 0;
}

/* return 0 on success */
int dtltest_compprop_calc(struct BBoxInterp *slv_interp,
		int ninputs, int noutputs,
		double *inputs, double *outputs,
		double *jacobian
){
	if(noutputs != 1)return -1;
	if(ninputs != 1)return -2;
	if(inputs==NULL)return -3;
	if(outputs==NULL)return -4;
	if(slv_interp==NULL)return -5;

	outputs[0] = inputs[0] + 1;

	return 0;
}