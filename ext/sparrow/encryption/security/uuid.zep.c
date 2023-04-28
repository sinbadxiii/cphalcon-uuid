
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid)
{
	ZEPHIR_REGISTER_CLASS_EX(Sparrow\\Encryption\\Security, Uuid, sparrow, encryption_security_uuid, sparrow_encryption_security_binarybase_ce, sparrow_encryption_security_uuid_method_entry, 0);

	zend_declare_property_null(sparrow_encryption_security_uuid_ce, SL("uid"), ZEND_ACC_PROTECTED);
	zephir_declare_class_constant_long(sparrow_encryption_security_uuid_ce, SL("TIME_OFFSET_INT"), 0x01B21DD213814000);

	zephir_declare_class_constant_string(sparrow_encryption_security_uuid_ce, SL("TIME_OFFSET_BIN"), "\x01\xb2\x1d\xd2\x13\x81\x40\x00");

	zephir_declare_class_constant_string(sparrow_encryption_security_uuid_ce, SL("NIL"), "00000000-0000-0000-0000-000000000000");

	zephir_declare_class_constant_string(sparrow_encryption_security_uuid_ce, SL("MAX"), "ffffffff-ffff-ffff-ffff-ffffffffffff");

	zephir_declare_class_constant_string(sparrow_encryption_security_uuid_ce, SL("NAMESPACE_DNS"), "6ba7b810-9dad-11d1-80b4-00c04fd430c8");

	zephir_declare_class_constant_string(sparrow_encryption_security_uuid_ce, SL("NAMESPACE_URL"), "6ba7b811-9dad-11d1-80b4-00c04fd430c8");

	zephir_declare_class_constant_string(sparrow_encryption_security_uuid_ce, SL("NAMESPACE_OID"), "6ba7b812-9dad-11d1-80b4-00c04fd430c8");

	zephir_declare_class_constant_string(sparrow_encryption_security_uuid_ce, SL("NAMESPACE_X500"), "6ba7b814-9dad-11d1-80b4-00c04fd430c8");

	return SUCCESS;
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, mac)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *uuid_param = NULL, reUuid, parsed, _6, _8, _9, _10, _1$$3, _2$$3, _3$$3, _4$$3, _7$$4;
	zval uuid;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uuid);
	ZVAL_UNDEF(&reUuid);
	ZVAL_UNDEF(&parsed);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uuid)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uuid_param);
	zephir_get_strval(&uuid, uuid_param);


	ZEPHIR_CALL_SELF(&reUuid, "tostring", &_0, 8, &uuid);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&reUuid) == IS_STRING)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_gettype(&_1$$3, &reUuid);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "mac() expects parameter 1 to be string, %s given");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 9, &_2$$3, &_1$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 512);
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 10, &_3$$3, &_4$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_SELF(&parsed, "parse", &_5, 11, &reUuid);
	zephir_check_call_status();
	zephir_array_fetch_string(&_6, &parsed, SL("version"), PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid.zep", 45);
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_6, 1)) {
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_GET_CONSTANT(&_7$$4, "PHP_VERSION_ID");
		if (ZEPHIR_LT_LONG(&_7$$4, 80000)) {
			RETURN_MM_NULL();
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephir_get_internal_ce(SL("error")), "mac(): Argument #1 ($uuid) UUID DCE TIME expected", "sparrow/Encryption/Security/Uuid.zep", 50);
		return;
	}
	zephir_array_fetch_string(&_8, &parsed, SL("node"), PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid.zep", 53);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "ABCDEF");
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "abcdef");
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 2, &_8, &_9, &_10);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, v1)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *time = NULL, time_sub, *node = NULL, node_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&time_sub);
	ZVAL_UNDEF(&node_sub);
	ZVAL_NULL(&__$null);
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
		node = &__$null;
	}


	object_init_ex(return_value, sparrow_encryption_security_uuid_uuid1_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 12, time, node);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, v3)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *ns, ns_sub, *name_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ns_sub);
	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(ns)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ns, &name_param);
	zephir_get_strval(&name, name_param);


	object_init_ex(return_value, sparrow_encryption_security_uuid_uuid3_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 13, ns, &name);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, v4)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	object_init_ex(return_value, sparrow_encryption_security_uuid_uuid4_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 14);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, v5)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *ns, ns_sub, *name_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ns_sub);
	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(ns)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ns, &name_param);
	zephir_get_strval(&name, name_param);


	object_init_ex(return_value, sparrow_encryption_security_uuid_uuid5_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 15, ns, &name);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, v6)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *time = NULL, time_sub, *node = NULL, node_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&time_sub);
	ZVAL_UNDEF(&node_sub);
	ZVAL_NULL(&__$null);
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
		node = &__$null;
	}


	object_init_ex(return_value, sparrow_encryption_security_uuid_uuid6_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 16, time, node);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, parse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uuid, uuid_sub, matches, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uuid_sub);
	ZVAL_UNDEF(&matches);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(uuid)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uuid);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "{^(?<time_low>[0-9a-f]{8})-(?<time_mid>[0-9a-f]{4})-(?<version>[0-9a-f])(?<time_hi>[0-9a-f]{3})-(?<clock_seq>[0-9a-f]{4})-(?<node>[0-9a-f]{12})$}Di");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "{^(?<time_low>[0-9a-f]{8})-(?<time_mid>[0-9a-f]{4})-(?<version>[0-9a-f])(?<time_hi>[0-9a-f]{3})-(?<clock_seq>[0-9a-f]{4})-(?<node>[0-9a-f]{12})$}Di");
	zephir_preg_match(&_1, &_2, uuid, &matches, 0, 0 , 0 );
	if (!(zephir_is_true(&_1))) {
		RETURN_MM_NULL();
	}
	zephir_create_array(return_value, 4, 0);
	zephir_array_fetch_string(&_3, &matches, SL("time_hi"), PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid.zep", 90);
	zephir_array_fetch_string(&_4, &matches, SL("time_mid"), PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid.zep", 90);
	zephir_array_fetch_string(&_5, &matches, SL("time_low"), PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid.zep", 90);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVVV(&_6, "0", &_3, &_4, &_5);
	zephir_array_update_string(return_value, SL("time"), &_6, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_7, &matches, SL("version"), PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid.zep", 91);
	ZEPHIR_CALL_FUNCTION(&_8, "hexdec", NULL, 17, &_7);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("version"), &_8, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_9, &matches, SL("clock_seq"), PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid.zep", 92);
	ZEPHIR_CALL_FUNCTION(&_8, "hexdec", NULL, 17, &_9);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("clock_seq"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_10);
	zephir_array_fetch_string(&_10, &matches, SL("node"), PH_NOISY, "sparrow/Encryption/Security/Uuid.zep", 94);
	zephir_array_update_string(return_value, SL("node"), &_10, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, format)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long version, ZEPHIR_LAST_CALL_STATUS;
	zval *hash_param = NULL, *version_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19;
	zval hash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hash);
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
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(hash)
		Z_PARAM_LONG(version)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &hash_param, &version_param);
	zephir_get_strval(&hash, hash_param);
	version = zephir_get_intval(version_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 8);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &hash, 0 , 8 , 0);
	ZVAL_LONG(&_3, 8);
	ZVAL_LONG(&_4, 4);
	ZEPHIR_INIT_VAR(&_5);
	zephir_substr(&_5, &hash, 8 , 4 , 0);
	ZVAL_LONG(&_6, 12);
	ZVAL_LONG(&_7, 4);
	ZEPHIR_INIT_VAR(&_8);
	zephir_substr(&_8, &hash, 12 , 4 , 0);
	ZEPHIR_CALL_FUNCTION(&_9, "hexdec", NULL, 17, &_8);
	zephir_check_call_status();
	ZVAL_LONG(&_10, 16);
	ZVAL_LONG(&_11, 4);
	ZEPHIR_INIT_VAR(&_12);
	zephir_substr(&_12, &hash, 16 , 4 , 0);
	ZEPHIR_CALL_FUNCTION(&_13, "hexdec", NULL, 17, &_12);
	zephir_check_call_status();
	ZVAL_LONG(&_14, 20);
	ZVAL_LONG(&_15, 12);
	ZEPHIR_INIT_VAR(&_16);
	zephir_substr(&_16, &hash, 20 , 12 , 0);
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, "%08s-%04s-%04x-%04x-%012s");
	ZVAL_LONG(&_18, (((int) (zephir_get_numberval(&_9)) & 0x0fff) | (version << 12)));
	ZVAL_LONG(&_19, (((int) (zephir_get_numberval(&_13)) & 0x3fff) | 0x8000));
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 9, &_17, &_2, &_5, &_18, &_19, &_16);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, hexToDateTime)
{
	zend_class_entry *_12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _1;
	zval *time = NULL, time_sub, _0, _2, _13, _14, _15, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&time_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(time)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &time);
	ZEPHIR_SEPARATE_PARAM(time);


	ZEPHIR_CALL_FUNCTION(&_0, "hexdec", NULL, 17, time);
	zephir_check_call_status();
	_1 = (zephir_get_numberval(&_0) - 0x01B21DD213814000);
	ZEPHIR_INIT_NVAR(time);
	ZVAL_LONG(time, _1);
	ZEPHIR_CALL_FUNCTION(&_2, "strval", NULL, 18, time);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(time, &_2);
	if (9 > zephir_fast_strlen_ev(time)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_array_fetch_long(&_4$$3, time, 0, PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid.zep", 114);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "-");
		if (ZEPHIR_IS_IDENTICAL(&_5$$3, &_4$$3)) {
			ZVAL_LONG(&_6$$3, 1);
			ZEPHIR_INIT_VAR(&_7$$3);
			zephir_substr(&_7$$3, time, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZVAL_LONG(&_8$$3, 8);
			ZEPHIR_INIT_VAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "0");
			ZVAL_LONG(&_10$$3, 0);
			ZEPHIR_CALL_FUNCTION(&_11$$3, "str_pad", NULL, 19, &_7$$3, &_8$$3, &_9$$3, &_10$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_CONCAT_SV(&_3$$3, "-", &_11$$3);
		} else {
			ZVAL_LONG(&_8$$3, 8);
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "0");
			ZVAL_LONG(&_10$$3, 0);
			ZEPHIR_CALL_FUNCTION(&_3$$3, "str_pad", NULL, 19, time, &_8$$3, &_9$$3, &_10$$3);
			zephir_check_call_status();
		}
		ZEPHIR_CPY_WRT(time, &_3$$3);
	}
	_12 = zephir_fetch_class_str_ex(SL("DateTimeImmutable"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, ".");
	ZVAL_LONG(&_14, -7);
	ZVAL_LONG(&_15, 0);
	ZEPHIR_CALL_FUNCTION(&_2, "substr_replace", NULL, 20, time, &_13, &_14, &_15);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "U.u?");
	ZEPHIR_RETURN_CALL_CE_STATIC(_12, "createfromformat", NULL, 0, &_13, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, dateTimeToHex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *time = NULL, time_sub, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&time_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(time, zephir_get_internal_ce(SL("datetimeinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &time);
	ZEPHIR_SEPARATE_PARAM(time);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_INT_SIZE");
	if (ZEPHIR_GE_LONG(&_0, 8)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Uu0");
		ZEPHIR_CALL_METHOD(&_1$$3, time, "format", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(time);
		ZVAL_LONG(time, zephir_get_intval(&_1$$3));
		ZVAL_LONG(&_3$$3, (zephir_get_numberval(time) + 0x01B21DD213814000));
		ZEPHIR_CALL_FUNCTION(&_4$$3, "dechex", NULL, 21, &_3$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_3$$3, 16);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "0");
		ZVAL_LONG(&_5$$3, 0);
		ZEPHIR_RETURN_CALL_FUNCTION("str_pad", NULL, 19, &_4$$3, &_3$$3, &_2$$3, &_5$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, toString)
{
	zval _3$$3;
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value, value_sub, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);


	_0 = Z_TYPE_P(value) == IS_STRING;
	if (!(_0)) {
		_0 = Z_TYPE_P(value) == IS_NULL;
	}
	_1 = _0;
	if (!(_1)) {
		ZEPHIR_INIT_VAR(&_2);
		if (Z_TYPE_P(value) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_2);
			ZVAL_BOOL(&_2, (zephir_method_exists_ex(value, ZEND_STRL("__tostring")) == SUCCESS));
		} else {
			ZEPHIR_INIT_NVAR(&_2);
			ZVAL_BOOL(&_2, zephir_is_scalar(value));
		}
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		zephir_cast_to_string(&_3$$3, value);
		RETURN_CTOR(&_3$$3);
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, getNodeProvider)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	object_init_ex(return_value, sparrow_encryption_security_uuid_sysnodeprovider_ce);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, __toString)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "uid");
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid, jsonSerialize)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "uid");
}

