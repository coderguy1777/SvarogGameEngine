#include <assert.h>
#include <stdexcept>
#include <bitset>
#define FORWARD_DEC(CLASS_VAL) class CLASS_VAL;
#define TMP_TYPE(TMP_CLASS_NAME, DERIV_CLASS) template class TMP_CLASS_NAME<DERIV_CLASS>
#define MULT_TMP_TYPE(TMP_CLASS_NAME, DERIV_CLASS_1, DERIV_CLASS_2) template class TMP_CLASS_NAME<DERIV_CLASS_1, DERIV_CLASS_2>;
#define NME_DEC(NME_NAME) namespace NME_NAME{}
#define ASSERT_EQUAL(OBJECT, PARAM) assert(OBJECT==PARAM)
#define ASSERT_NONEQ(OBJECT, PARAM) assert(OBJECT!=PARAM)
#define EXCEPTION(MSG) throw std::invalid_argument(MSG)
#define BIT(X) (1>>X)