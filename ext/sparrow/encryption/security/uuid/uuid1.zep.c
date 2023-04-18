
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
#include "kernel/time.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


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
	zval *uuid_param = NULL, *node = NULL, node_sub, __$false, __$null, time$$3, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, clockSeq$$3, _14$$3, _15$$3, _16$$3, _17$$3, _18$$3, _19$$3, _20$$3, _21$$3, _10$$5, _11$$6, _12$$6, _13$$7;
	zval uuid;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uuid);
	ZVAL_UNDEF(&node_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&time$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&clockSeq$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(uuid)
		Z_PARAM_ZVAL_OR_NULL(node)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &uuid_param, &node);
	if (!uuid_param) {
		ZEPHIR_INIT_VAR(&uuid);
	} else {
		zephir_get_strval(&uuid, uuid_param);
	}
	if (!node) {
		node = &node_sub;
		ZEPHIR_CPY_WRT(node, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(node);
	}


	if (ZEPHIR_IS_NULL(&uuid)) {
		ZEPHIR_INIT_VAR(&time$$3);
		zephir_microtime(&time$$3, &__$false);
		ZVAL_LONG(&_0$$3, 11);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_substr(&_1$$3, &time$$3, 11 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZVAL_LONG(&_2$$3, 2);
		ZVAL_LONG(&_3$$3, 7);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_substr(&_4$$3, &time$$3, 2 , 7 , 0);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_VV(&_5$$3, &_1$$3, &_4$$3);
		ZEPHIR_CPY_WRT(&time$$3, &_5$$3);
		ZVAL_LONG(&_6$$3, (zephir_get_numberval(&time$$3) + 0x01B21DD213814000));
		ZEPHIR_CALL_FUNCTION(&_7$$3, "dechex", NULL, 67, &_6$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$3, 16);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "0");
		ZVAL_LONG(&_9$$3, 0);
		ZEPHIR_CALL_FUNCTION(&time$$3, "str_pad", NULL, 19, &_7$$3, &_6$$3, &_8$$3, &_9$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$3, 0x3FFF);
		ZEPHIR_CALL_METHOD(&clockSeq$$3, this_ptr, "number", NULL, 0, &_6$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(node) == IS_NULL) {
			if ((zephir_function_exists_ex(ZEND_STRL("apcu_fetch")) == SUCCESS)) {
				ZEPHIR_INIT_VAR(&_10$$5);
				ZVAL_STRING(&_10$$5, "__phalcon_uuid_node");
				ZEPHIR_CALL_FUNCTION(node, "apcu_fetch", NULL, 68, &_10$$5);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(node)) {
					ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "getnodeprovider", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(node, &_11$$6, "getnode", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&_12$$6);
					ZVAL_STRING(&_12$$6, "__phalcon_uuid_node");
					ZEPHIR_CALL_FUNCTION(NULL, "apcu_store", NULL, 69, &_12$$6, node);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CALL_METHOD(&_13$$7, this_ptr, "getnodeprovider", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(node, &_13$$7, "getnode", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZVAL_LONG(&_6$$3, -8);
		ZEPHIR_INIT_NVAR(&_8$$3);
		zephir_substr(&_8$$3, &time$$3, -8 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZVAL_LONG(&_9$$3, -12);
		ZVAL_LONG(&_14$$3, 4);
		ZEPHIR_INIT_VAR(&_15$$3);
		zephir_substr(&_15$$3, &time$$3, -12 , 4 , 0);
		ZVAL_LONG(&_16$$3, -15);
		ZVAL_LONG(&_17$$3, 3);
		ZEPHIR_INIT_VAR(&_18$$3);
		zephir_substr(&_18$$3, &time$$3, -15 , 3 , 0);
		ZEPHIR_INIT_VAR(&_19$$3);
		ZVAL_STRING(&_19$$3, "%08s-%04s-1%03s-%04x-%012s");
		ZVAL_LONG(&_20$$3, ((int) (zephir_get_numberval(&clockSeq$$3)) | 0x8000));
		ZEPHIR_CALL_FUNCTION(&_21$$3, "sprintf", NULL, 9, &_19$$3, &_8$$3, &_15$$3, &_18$$3, &_20$$3, node);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &_21$$3);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &uuid);
	}
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

