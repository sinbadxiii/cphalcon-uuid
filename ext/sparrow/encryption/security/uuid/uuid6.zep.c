
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid_Uuid6)
{
	ZEPHIR_REGISTER_CLASS_EX(Sparrow\\Encryption\\Security\\Uuid, Uuid6, sparrow, encryption_security_uuid_uuid6, sparrow_encryption_security_uuid_ce, sparrow_encryption_security_uuid_uuid6_method_entry, 0);

	zend_declare_property_null(sparrow_encryption_security_uuid_uuid6_ce, SL("node"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);
	zephir_declare_class_constant_long(sparrow_encryption_security_uuid_uuid6_ce, SL("TYPE"), 6);

	zend_class_implements(sparrow_encryption_security_uuid_uuid6_ce, 1, sparrow_encryption_security_uuid_timebaseduidinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid6, __construct)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *time = NULL, time_sub, *node = NULL, node_sub, __$null, uuid1, uuid, _0, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20$$3, _21$$3, _22$$3, _23$$4, _42$$4, _43$$4, seed$$5, _24$$5, _25$$5, _26$$5, _27$$5, _28$$5, _29$$5, _30$$5, _31$$5, _32$$5, _33$$5, _34$$5, _35$$5, _36$$5, _37$$5, _38$$5, _39$$5, _40$$5, _41$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&time_sub);
	ZVAL_UNDEF(&node_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&uuid1);
	ZVAL_UNDEF(&uuid);
	ZVAL_UNDEF(&_0);
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
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_42$$4);
	ZVAL_UNDEF(&_43$$4);
	ZVAL_UNDEF(&seed$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_27$$5);
	ZVAL_UNDEF(&_28$$5);
	ZVAL_UNDEF(&_29$$5);
	ZVAL_UNDEF(&_30$$5);
	ZVAL_UNDEF(&_31$$5);
	ZVAL_UNDEF(&_32$$5);
	ZVAL_UNDEF(&_33$$5);
	ZVAL_UNDEF(&_34$$5);
	ZVAL_UNDEF(&_35$$5);
	ZVAL_UNDEF(&_36$$5);
	ZVAL_UNDEF(&_37$$5);
	ZVAL_UNDEF(&_38$$5);
	ZVAL_UNDEF(&_39$$5);
	ZVAL_UNDEF(&_40$$5);
	ZVAL_UNDEF(&_41$$5);
	ZVAL_UNDEF(&_1);
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
		time = &__$null;
	}
	if (!node) {
		node = &node_sub;
		ZEPHIR_CPY_WRT(node, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(node);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, sparrow_encryption_security_uuid_uuid1_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 12, time, node);
	zephir_check_call_status();
	zephir_cast_to_string(&_1, &_0);
	ZEPHIR_CPY_WRT(&uuid1, &_1);
	ZVAL_LONG(&_2, 15);
	ZVAL_LONG(&_3, 3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_substr(&_4, &uuid1, 15 , 3 , 0);
	ZVAL_LONG(&_5, 9);
	ZVAL_LONG(&_6, 4);
	ZEPHIR_INIT_VAR(&_7);
	zephir_substr(&_7, &uuid1, 9 , 4 , 0);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 1);
	ZEPHIR_INIT_VAR(&_10);
	zephir_substr(&_10, &uuid1, 0 , 1 , 0);
	ZVAL_LONG(&_11, 1);
	ZVAL_LONG(&_12, 4);
	ZEPHIR_INIT_VAR(&_13);
	zephir_substr(&_13, &uuid1, 1 , 4 , 0);
	ZVAL_LONG(&_14, 5);
	ZVAL_LONG(&_15, 3);
	ZEPHIR_INIT_VAR(&_16);
	zephir_substr(&_16, &uuid1, 5 , 3 , 0);
	ZVAL_LONG(&_17, 18);
	ZVAL_LONG(&_18, 6);
	ZEPHIR_INIT_VAR(&_19);
	zephir_substr(&_19, &uuid1, 18 , 6 , 0);
	ZEPHIR_INIT_VAR(&uuid);
	ZEPHIR_CONCAT_VVVSVSVV(&uuid, &_4, &_7, &_10, "-", &_13, "-6", &_16, &_19);
	if (Z_TYPE_P(node) != IS_NULL) {
		ZVAL_LONG(&_20$$3, 24);
		ZEPHIR_INIT_VAR(&_21$$3);
		zephir_substr(&_21$$3, &uuid1, 24 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_22$$3);
		ZEPHIR_CONCAT_VV(&_22$$3, &uuid, &_21$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &_22$$3);
	} else {
		zephir_read_static_property_ce(&_23$$4, sparrow_encryption_security_uuid_uuid6_ce, SL("node"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_23$$4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_24$$5);
			object_init_ex(&_24$$5, sparrow_encryption_security_uuid_randomnodeprovider_ce);
			if (zephir_has_constructor(&_24$$5)) {
				ZEPHIR_CALL_METHOD(NULL, &_24$$5, "__construct", NULL, 0);
				zephir_check_call_status();
			}

			ZEPHIR_CALL_METHOD(&seed$$5, &_24$$5, "getseed", NULL, 73);
			zephir_check_call_status();
			ZVAL_LONG(&_25$$5, 24);
			ZVAL_LONG(&_26$$5, 6);
			ZEPHIR_INIT_VAR(&_27$$5);
			zephir_substr(&_27$$5, &uuid1, 24 , 6 , 0);
			ZEPHIR_INIT_VAR(&_28$$5);
			ZEPHIR_CONCAT_SV(&_28$$5, "00", &_27$$5);
			ZEPHIR_CALL_FUNCTION(&_29$$5, "hex2bin", NULL, 70, &_28$$5);
			zephir_check_call_status();
			ZVAL_LONG(&_30$$5, 30);
			ZEPHIR_INIT_VAR(&_31$$5);
			zephir_substr(&_31$$5, &uuid1, 30 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_VAR(&_32$$5);
			ZEPHIR_CONCAT_SV(&_32$$5, "00", &_31$$5);
			ZEPHIR_CALL_FUNCTION(&_33$$5, "hex2bin", NULL, 70, &_32$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_34$$5);
			ZEPHIR_CONCAT_VV(&_34$$5, &_29$$5, &_33$$5);
			ZEPHIR_INIT_VAR(&_35$$5);
			ZVAL_STRING(&_35$$5, "N2");
			ZEPHIR_CALL_FUNCTION(node, "unpack", NULL, 5, &_35$$5, &_34$$5);
			zephir_check_call_status();
			zephir_array_fetch_long(&_36$$5, &seed$$5, 0, PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid/Uuid6.zep", 32);
			zephir_array_fetch_long(&_37$$5, node, 1, PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid/Uuid6.zep", 32);
			ZEPHIR_INIT_VAR(&_38$$5);
			zephir_bitwise_xor_function(&_38$$5, &_36$$5, &_37$$5);
			zephir_array_fetch_long(&_36$$5, &seed$$5, 1, PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid/Uuid6.zep", 32);
			zephir_array_fetch_long(&_37$$5, node, 2, PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid/Uuid6.zep", 32);
			ZEPHIR_INIT_VAR(&_39$$5);
			zephir_bitwise_xor_function(&_39$$5, &_36$$5, &_37$$5);
			ZEPHIR_INIT_NVAR(&_35$$5);
			ZVAL_STRING(&_35$$5, "%06x%06x");
			ZVAL_LONG(&_40$$5, ((int) (zephir_get_numberval(&_38$$5)) | 0x010000));
			ZEPHIR_CALL_FUNCTION(&_41$$5, "sprintf", NULL, 9, &_35$$5, &_40$$5, &_39$$5);
			zephir_check_call_status();
			zephir_update_static_property_ce(sparrow_encryption_security_uuid_uuid6_ce, ZEND_STRL("node"), &_41$$5);
		}
		ZEPHIR_OBS_VAR(&_42$$4);
		zephir_read_static_property_ce(&_42$$4, sparrow_encryption_security_uuid_uuid6_ce, SL("node"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_43$$4);
		ZEPHIR_CONCAT_VV(&_43$$4, &uuid, &_42$$4);
		zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &_43$$4);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid6, getDateTime)
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
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, 8);
	ZEPHIR_INIT_VAR(&_3);
	zephir_substr(&_3, &_0, 0 , 8 , 0);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("uid"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 9);
	ZVAL_LONG(&_6, 4);
	ZEPHIR_INIT_VAR(&_7);
	zephir_substr(&_7, &_4, 9 , 4 , 0);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("uid"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_9, 15);
	ZVAL_LONG(&_10, 3);
	ZEPHIR_INIT_VAR(&_11);
	zephir_substr(&_11, &_8, 15 , 3 , 0);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_SVVV(&_12, "0", &_3, &_7, &_11);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hextodatetime", NULL, 0, &_12);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid6, getNode)
{
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("uid"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 24);
	zephir_substr(return_value, &_0, 24 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	return;
}

