
#ifndef ZEPHIR_KERNEL_CONCAT_H
#define ZEPHIR_KERNEL_CONCAT_H
#include <php.h>
#include <Zend/zend.h>
#include "kernel/main.h"
#define ZEPHIR_CONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 0);
#define ZEPHIR_SCONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 1);

#define ZEPHIR_CONCAT_SVVV(result, op1, op2, op3, op4) \
	 zephir_concat_svvv(result, op1, sizeof(op1)-1, op2, op3, op4, 0);
#define ZEPHIR_SCONCAT_SVVV(result, op1, op2, op3, op4) \
	 zephir_concat_svvv(result, op1, sizeof(op1)-1, op2, op3, op4, 1);

#define ZEPHIR_CONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 0);
#define ZEPHIR_SCONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 1);

#define ZEPHIR_CONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 0);
#define ZEPHIR_SCONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 1);

#define ZEPHIR_CONCAT_VVS(result, op1, op2, op3) \
	 zephir_concat_vvs(result, op1, op2, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_VVS(result, op1, op2, op3) \
	 zephir_concat_vvs(result, op1, op2, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(result, op1, op2, op3, 0);
#define ZEPHIR_SCONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(result, op1, op2, op3, 1);

#define ZEPHIR_CONCAT_VVVSVSVV(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_vvvsvsvv(result, op1, op2, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, 0);
#define ZEPHIR_SCONCAT_VVVSVSVV(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_vvvsvsvv(result, op1, op2, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, 1);


void zephir_concat_sv(zval *result, const char *op1, uint32_t op1_len, zval *op2, int self_var);
void zephir_concat_svvv(zval *result, const char *op1, uint32_t op1_len, zval *op2, zval *op3, zval *op4, int self_var);
void zephir_concat_vs(zval *result, zval *op1, const char *op2, uint32_t op2_len, int self_var);
void zephir_concat_vv(zval *result, zval *op1, zval *op2, int self_var);
void zephir_concat_vvs(zval *result, zval *op1, zval *op2, const char *op3, uint32_t op3_len, int self_var);
void zephir_concat_vvv(zval *result, zval *op1, zval *op2, zval *op3, int self_var);
void zephir_concat_vvvsvsvv(zval *result, zval *op1, zval *op2, zval *op3, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, zval *op7, zval *op8, int self_var);
void zephir_concat_function(zval *result, zval *op1, zval *op2);
#endif /* ZEPHIR_KERNEL_CONCAT_H */
