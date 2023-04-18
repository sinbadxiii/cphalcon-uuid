
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid_Uuid5)
{
	ZEPHIR_REGISTER_CLASS_EX(Sparrow\\Encryption\\Security\\Uuid, Uuid5, sparrow, encryption_security_uuid_uuid5, sparrow_encryption_security_uuid_ce, sparrow_encryption_security_uuid_uuid5_method_entry, 0);

	zephir_declare_class_constant_long(sparrow_encryption_security_uuid_uuid5_ce, SL("TYPE"), 5);

	return SUCCESS;
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid5, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *ns, ns_sub, *name_param = NULL, hash, _0, _1, _2, _3, _4, _5, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ns_sub);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(ns, zephir_get_internal_ce(SL("sparrow\\encryption\\security\\uuid")))
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ns, &name_param);
	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, ns, ZEND_STRL("uid"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "-");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	zephir_fast_str_replace(&_0, &_2, &_3, &_1);
	ZEPHIR_CALL_FUNCTION(&_4, "hex2bin", NULL, 70, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VV(&_5, &_4, &name);
	ZEPHIR_CALL_FUNCTION(&hash, "sha1", NULL, 72, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_7, 5);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "format", NULL, 0, &hash, &_7);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &_6);
	ZEPHIR_MM_RESTORE();
}

