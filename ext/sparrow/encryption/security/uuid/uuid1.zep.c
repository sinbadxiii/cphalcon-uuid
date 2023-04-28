
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid_Uuid1)
{
	ZEPHIR_REGISTER_CLASS_EX(Sparrow\\Encryption\\Security\\Uuid, Uuid1, sparrow, encryption_security_uuid_uuid1, sparrow_encryption_security_uuid_ce, sparrow_encryption_security_uuid_uuid1_method_entry, 0);

	zend_declare_property_null(sparrow_encryption_security_uuid_uuid1_ce, SL("clockSeq"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);
	zephir_declare_class_constant_long(sparrow_encryption_security_uuid_uuid1_ce, SL("TYPE"), 1);

	zend_class_implements(sparrow_encryption_security_uuid_uuid1_ce, 1, sparrow_encryption_security_uuid_timebaseduidinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid1, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *time = NULL, time_sub, *node = NULL, node_sub, __$null, _0, _1, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _2$$5, _3$$6, _4$$6, _5$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&time_sub);
	ZVAL_UNDEF(&node_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(time, zephir_get_internal_ce(SL("datetimeinterface")))
		Z_PARAM_ZVAL_OR_NULL(node)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &time, &node);
	if (!time) {
		time = &time_sub;
		ZEPHIR_CPY_WRT(time, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(time);
	}
	if (!node) {
		node = &node_sub;
		ZEPHIR_CPY_WRT(node, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(node);
	}


	if (Z_TYPE_P(time) == IS_NULL) {
		ZEPHIR_INIT_NVAR(time);
		object_init_ex(time, zephir_get_internal_ce(SL("datetimeimmutable")));
		ZEPHIR_CALL_METHOD(NULL, time, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "datetimetohex", NULL, 0, time);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(time, &_0);
	ZVAL_LONG(&_1, 0x3FFF);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "number", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_static_property_ce(sparrow_encryption_security_uuid_uuid1_ce, ZEND_STRL("clockSeq"), &_0);
	if (Z_TYPE_P(node) == IS_NULL) {
		if ((zephir_function_exists_ex(ZEND_STRL("apcu_fetch")) == SUCCESS)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "__phalcon_uuid_node");
			ZEPHIR_CALL_FUNCTION(node, "apcu_fetch", NULL, 67, &_2$$5);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(node)) {
				ZEPHIR_CALL_METHOD(&_3$$6, this_ptr, "getnodeprovider", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(node, &_3$$6, "getnode", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_4$$6);
				ZVAL_STRING(&_4$$6, "__phalcon_uuid_node");
				ZEPHIR_CALL_FUNCTION(NULL, "apcu_store", NULL, 68, &_4$$6, node);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CALL_METHOD(&_5$$7, this_ptr, "getnodeprovider", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(node, &_5$$7, "getnode", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZVAL_LONG(&_1, -8);
	ZEPHIR_INIT_VAR(&_6);
	zephir_substr(&_6, time, -8 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZVAL_LONG(&_7, -12);
	ZVAL_LONG(&_8, 4);
	ZEPHIR_INIT_VAR(&_9);
	zephir_substr(&_9, time, -12 , 4 , 0);
	ZVAL_LONG(&_10, -15);
	ZVAL_LONG(&_11, 3);
	ZEPHIR_INIT_VAR(&_12);
	zephir_substr(&_12, time, -15 , 3 , 0);
	zephir_read_static_property_ce(&_13, sparrow_encryption_security_uuid_uuid1_ce, SL("clockSeq"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "%08s-%04s-1%03s-%04x-%012s");
	ZVAL_LONG(&_15, ((int) (zephir_get_numberval(&_13)) | 0x8000));
	ZEPHIR_CALL_FUNCTION(&_0, "sprintf", NULL, 9, &_14, &_6, &_9, &_12, &_15, node);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid1, getDateTime)
{
	zval _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("uid"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 15);
	ZVAL_LONG(&_2, 3);
	ZEPHIR_INIT_VAR(&_3);
	zephir_substr(&_3, &_0, 15 , 3 , 0);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("uid"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 9);
	ZVAL_LONG(&_6, 4);
	ZEPHIR_INIT_VAR(&_7);
	zephir_substr(&_7, &_4, 9 , 4 , 0);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("uid"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, 8);
	ZEPHIR_INIT_VAR(&_11);
	zephir_substr(&_11, &_8, 0 , 8 , 0);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_SVVV(&_12, "0", &_3, &_7, &_11);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hextodatetime", NULL, 0, &_12);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid1, getNode)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("uid"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "mac", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

