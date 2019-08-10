// use of declarations to shorten code via macros

#define FORWARD_DEC(CLASS_VAL) class CLASS_VAL;

// template class types
#define TMP_TYPE(TMP_CLASS_NAME, DERIV_CLASS) template class TMP_CLASS_NAME<DERIV_CLASS>
// declaration of namespace macro
#define NME_DEC(NME_NAME) namespace NME_NAME{}
// for template class types
